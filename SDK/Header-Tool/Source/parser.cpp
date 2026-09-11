/*
Copyright © from 2024 to present, UNKNOWN STRYKER (Hojin Lee / Joey). All Rights Reserved.

Licensed under the Frogman Engine License (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	https://github.com/UnknownStryker-Interactive-Technologies/Frogman-Engine-License/blob/release/LICENSE.md

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "header_tool.hpp"
#include "error_code.hpp"
#include "parser.hpp"
#include "symbol_counter.hpp"




namespace FHT::parser
{
	_FE_NODISCARD_ header_file_root build_reflextree(const directory_t& file_path_p, const std::pmr::list<token>& token_list_p)
	{
		FHT::symbol_counter::symbol_count l_total_nums = FHT::symbol_counter::try_count_all_symbols(token_list_p.begin(), token_list_p.cend());
		{
			static std::mutex l_s_log_lock;
			std::lock_guard<std::mutex> l_guard(l_s_log_lock);
			std::wcout << L"Frogman Engine Header Tool: In the file located at '" << file_path_p.c_str() << "'\n";
			std::cout << "Frogman Engine Header Tool: the total number of namespaces is " << l_total_nums._namespaces << '\n';
			std::cout << "Frogman Engine Header Tool: the total number of classes is " << l_total_nums._classes << '\n';
			std::cout << "Frogman Engine Header Tool: the total number of structs is " << l_total_nums._structs << "\n";
			std::cout << "Frogman Engine Header Tool: the total number of enum structs is " << l_total_nums._enum_structs << "\n";
			std::cout << "Frogman Engine Header Tool: the total number of the Frogman Engine ECS system methods is " << l_total_nums._systems << "\n\n";
		}

		header_file_root l_root = 
		{ 
			._path_to_the_header_file = file_path_p,
			._namespaces{	framework::get_framework().get_memory_resource()},
			._classes{		framework::get_framework().get_memory_resource()},
			._structs{		framework::get_framework().get_memory_resource()},
			._enum_structs{	framework::get_framework().get_memory_resource()},
			._system_fptrs{	framework::get_framework().get_memory_resource()}
		};

		l_root._namespaces.reserve(l_total_nums._namespaces);
		l_root._classes.reserve(l_total_nums._classes);
		l_root._structs.reserve(l_total_nums._structs);
		l_root._enum_structs.reserve(l_total_nums._enum_structs);
		l_root._system_fptrs.reserve(l_total_nums._systems);


		context_stack_t l_context_stack{ 1, FHT::Context::_Global, framework::get_framework().get_memory_resource() };

		for (auto iterator = token_list_p.begin(); iterator != token_list_p.end(); ++iterator)
		{
			switch (iterator->_vocabulary)
			{
			case Vocabulary::_FrogmanEngineSystemMacro:
				l_root._system_fptrs.emplace_back(build_ecs_system_node(u8"::", iterator, token_list_p.end()));
				break;


			case Vocabulary::_BeginNamespace:
				_FE_FALLTHROUGH_;
			case Vocabulary::_Namespace:
				l_root._namespaces.emplace_back(build_namespace_node_recursive(u8"::", iterator, token_list_p.end(), l_context_stack));
				break;

			case Vocabulary::_Class:
				l_context_stack.push_back(Context::_Class);
				l_root._classes.emplace_back(build_class_node(u8"::", iterator, token_list_p.end()));
				l_context_stack.pop_back();
				break;

			case Vocabulary::_Struct:
				l_context_stack.push_back(Context::_Struct);
				l_root._structs.emplace_back(build_struct_node(u8"::", iterator, token_list_p.end()));
				l_context_stack.pop_back();
				break;

			case Vocabulary::_EnumStructIdentifier:
				l_root._enum_structs.emplace_back(build_enum_struct_node(u8"::", iterator, token_list_p.end()));
				break;


			default:
				break;
			}
		}

		return l_root;
	}

	_FE_NODISCARD_ namespace_node build_namespace_node_recursive(const identifier& parent_namespace_p, typename std::pmr::list<token>::const_iterator& out_token_iterator_p, typename std::pmr::list<token>::const_iterator end_p, context_stack_t& context_stack_p)
	{
		namespace_node l_node = 
		{
				._target_namespace_name{ framework::get_framework().get_memory_resource() },
				._nested_namespaces{ framework::get_framework().get_memory_resource() },
				._classes{ framework::get_framework().get_memory_resource() },
				._structs{ framework::get_framework().get_memory_resource() },
				._enum_structs{ framework::get_framework().get_memory_resource() },
				._system_fptrs{ framework::get_framework().get_memory_resource() }
		};

		FHT::symbol_counter::symbol_count l_total_nums = FHT::symbol_counter::try_count_the_current_scope_level_symbols(out_token_iterator_p, end_p);
		l_node._nested_namespaces.reserve(l_total_nums._namespaces);
		l_node._classes.reserve(l_total_nums._classes);
		l_node._structs.reserve(l_total_nums._structs);
		l_node._enum_structs.reserve(l_total_nums._enum_structs);
		l_node._system_fptrs.reserve(l_total_nums._systems);


		switch (out_token_iterator_p->_vocabulary)
		{
		case Vocabulary::_BeginNamespace:
			while (out_token_iterator_p->_vocabulary != Vocabulary::_NamespaceIdentifier)
			{
				++out_token_iterator_p;
			}

			l_node._target_namespace_name = parent_namespace_p;

			while (out_token_iterator_p->_vocabulary != Vocabulary::_RightParen)
			{
				l_node._target_namespace_name += out_token_iterator_p->_code;
				++out_token_iterator_p;
			}
			l_node._target_namespace_name += u8"::";
			break;


		case Vocabulary::_Namespace:
			while (out_token_iterator_p->_vocabulary != Vocabulary::_NamespaceIdentifier)
			{
				++out_token_iterator_p;
			}

			l_node._target_namespace_name = parent_namespace_p;

			while (out_token_iterator_p->_vocabulary != Vocabulary::_LeftCurlyBracket)
			{
				l_node._target_namespace_name += out_token_iterator_p->_code;
				++out_token_iterator_p;
			}
			l_node._target_namespace_name += u8"::";
			break;


		_FE_NODEFAULT_;
		}


		while (out_token_iterator_p != end_p)
		{
			switch (out_token_iterator_p->_vocabulary)
			{
			case Vocabulary::_RightCurlyBracket:
				_FE_FALLTHROUGH_;
			case Vocabulary::_EndNamespace:
				return l_node;


			case Vocabulary::_FrogmanEngineSystemMacro:
				if (context_stack_p.back() == Context::_Class || context_stack_p.back() == Context::_Struct)
				{
					break; // skip the system macro if it is inside a class or struct.
				}
				l_node._system_fptrs.emplace_back(build_ecs_system_node(l_node._target_namespace_name, out_token_iterator_p, end_p));
				break;


			case Vocabulary::_BeginNamespace:
				_FE_FALLTHROUGH_;
			case Vocabulary::_Namespace:
				l_node._nested_namespaces.emplace_back(build_namespace_node_recursive(l_node._target_namespace_name, out_token_iterator_p, end_p, context_stack_p));
				break;

			case Vocabulary::_Class:
				context_stack_p.push_back(Context::_Class);
				l_node._classes.emplace_back(build_class_node(l_node._target_namespace_name, out_token_iterator_p, end_p));
				context_stack_p.pop_back();
				break;

			case Vocabulary::_Struct:
				context_stack_p.push_back(Context::_Struct);
				l_node._structs.emplace_back(build_struct_node(l_node._target_namespace_name, out_token_iterator_p, end_p));
				context_stack_p.pop_back();
				break;

			case Vocabulary::_EnumStructIdentifier:
				l_node._enum_structs.emplace_back(build_enum_struct_node(l_node._target_namespace_name, out_token_iterator_p, end_p));
				break;


			default:
				++out_token_iterator_p;
				break;
			}
		}

		return l_node;
	}




	_FE_NODISCARD_ class_node build_class_node(const identifier& parent_namespace_p, typename std::pmr::list<token>::const_iterator& out_token_iterator_p, typename std::pmr::list<token>::const_iterator end_p)
	{
		FE_ASSERT(out_token_iterator_p->_vocabulary == Vocabulary::_Class);
		class_node l_node = 
		{
			._this_class_name{ out_token_iterator_p->_code, framework::get_framework().get_memory_resource() },
			._base_class_name{ framework::get_framework().get_memory_resource() }
		};


		{	// trim 'class'
			constexpr auto l_class = u8"class";
			auto l_class_keyword_len = l_node._this_class_name.find(l_class);
			THROW_CPP_SYNTAX_ERROR(l_class_keyword_len == std::string::npos, "Frogman Engine C++ Syntax Error: 'class' keyword is missing from a class");

			l_class_keyword_len += FE::algorithm::string::length(l_class);
			l_node._this_class_name.erase(0, l_class_keyword_len);
		}

		auto l_attr_pos = l_node._this_class_name.rfind(u8']');
		if (l_attr_pos != std::string::npos) // has attributes
		{
			l_node._this_class_name.erase(0, l_attr_pos + 1); // remove the attributes
		}

		{	// trim spaces at front
			var::uint64 l_space_length = 0;
			for (auto character : l_node._this_class_name)
			{
				if ((character <= ' ') == false)
				{
					break;
				}
				++l_space_length;
			}
			l_node._this_class_name.erase(0, l_space_length);
		}

		{
			auto l_class_extension = l_node._this_class_name.find(':');
			if (l_class_extension != std::string::npos)
			{
				l_node._base_class_name.assign(l_node._this_class_name.c_str() + (l_class_extension + 1));
				l_node._this_class_name.erase(l_class_extension, l_node._this_class_name.length() - l_class_extension);
			}
		}


		auto l_final_keyword_pos = l_node._this_class_name.find(u8"final");
		if (l_final_keyword_pos != std::string::npos)
		{
			if (l_node._this_class_name[l_final_keyword_pos-1] <= ' ')
			{
				l_node._this_class_name.erase(l_final_keyword_pos, FE::algorithm::string::compiletime::length("final"));
			}
		}

		while (l_node._this_class_name.length() > 0)
		{
			if (l_node._this_class_name.back() <= ' ')
			{
				l_node._this_class_name.pop_back();
				continue;
			}
			break;
		}

		l_node._this_class_name.insert(0, parent_namespace_p);


		std::pmr::vector<Vocabulary> l_stack{ framework::get_framework().get_memory_resource() };
		++out_token_iterator_p;
		do
		{
			switch (out_token_iterator_p->_vocabulary)
			{
			case Vocabulary::_LeftCurlyBracket:
				l_stack.push_back(out_token_iterator_p->_vocabulary);
				break;

			case Vocabulary::_RightCurlyBracket:
				l_stack.pop_back();
				break;

			case Vocabulary::_AnyDecl:
				{
					--out_token_iterator_p;
					Vocabulary l_prev_token = out_token_iterator_p->_vocabulary;
					++out_token_iterator_p;
					if (l_prev_token != Vocabulary::_Virtual) // break if it does not contain "virtual"; and
					{
						break;
					}

					auto l_it = out_token_iterator_p->_code.rbegin();
					while (*l_it != u8')')
					{
						if (l_it == out_token_iterator_p->_code.rend())
						{
							break;
						}
						++l_it;
					}

					if (FE::algorithm::string::space_insensitive_contains(l_it.operator->(), l_it.operator->() - out_token_iterator_p->_code.begin().operator->(), u8"=0") == false) // break if it does not contain "=0".
					{
						break;
					}
					l_node._has_pure_virtual = true;
				}
				break;

			default:
				THROW_CPP_SYNTAX_ERROR(out_token_iterator_p == end_p, "FHT C++ Syntax Error C1075: the curly braces in the current header file are not closed or properly organized; reached the end of the token stream while parsing a struct declaration.");
				break;
			}
			++out_token_iterator_p;
		} 
		while (l_stack.size() > 0);
		return l_node;
	}

	_FE_NODISCARD_ struct_node build_struct_node(const identifier& parent_namespace_p, typename std::pmr::list<token>::const_iterator& out_token_iterator_p, typename std::pmr::list<token>::const_iterator end_p)
	{
		FE_ASSERT(out_token_iterator_p->_vocabulary == Vocabulary::_Struct);
		struct_node l_node =
		{
			._identifier{ out_token_iterator_p->_code, framework::get_framework().get_memory_resource() }
		};

		{
			{	// trim 'struct'
				constexpr auto l_struct = u8"struct";
				auto l_struct_keyword_len = l_node._identifier.find(l_struct);
				THROW_CPP_SYNTAX_ERROR(l_struct_keyword_len == std::string::npos, "Frogman Engine C++ Syntax Error: 'struct' keyword is missing from a struct");

				l_struct_keyword_len += FE::algorithm::string::length(l_struct);
				l_node._identifier.erase(0, l_struct_keyword_len);
			}

			auto l_attr_pos = l_node._identifier.rfind(u8']');
			if (l_attr_pos != std::string::npos) // has attributes
			{
				l_node._identifier.erase(0, l_attr_pos + 1); // remove the attributes
			}

			{	// trim spaces at front
				var::uint64 l_space_length = 0;
				for (auto character : l_node._identifier)
				{
					if ((character <= ' ') == false)
					{
						break;
					}
					++l_space_length;
				}
				l_node._identifier.erase(0, l_space_length);
			}

			THROW_CPP_SYNTAX_ERROR(l_node._identifier.find(':') != std::string::npos, "Frogman Engine C++ Syntax Error: structs must not be polymorphic.");

			while (l_node._identifier.length() > 0)
			{
				if (l_node._identifier.back() <= ' ')
				{
					l_node._identifier.pop_back();
					continue;
				}
				break;
			}
	
			l_node._identifier.insert(0, parent_namespace_p);
		}


		std::pmr::vector<Vocabulary> l_stack{ framework::get_framework().get_memory_resource() };
		++out_token_iterator_p;
		do
		{
			switch (out_token_iterator_p->_vocabulary)
			{
			case Vocabulary::_LeftCurlyBracket:
				l_stack.push_back(out_token_iterator_p->_vocabulary);
				break;
				
			case Vocabulary::_RightCurlyBracket:
				l_stack.pop_back();
				break;

			default:
				THROW_CPP_SYNTAX_ERROR(out_token_iterator_p == end_p, "FHT C++ Syntax Error C1075: the curly braces in the current header file are not closed or properly organized; reached the end of the token stream while parsing a struct declaration.");
				break;
			}
			++out_token_iterator_p;
		} 
		while (l_stack.size() > 0);
		return l_node;
	}

	_FE_NODISCARD_ enum_struct_node build_enum_struct_node(const identifier& parent_namespace_p, typename std::pmr::list<token>::const_iterator& out_token_iterator_p, typename std::pmr::list<token>::const_iterator end_p)
	{
		FE_ASSERT(out_token_iterator_p->_vocabulary == Vocabulary::_EnumStructIdentifier, "Assertion Failed: Enum struct identifier is missing.");
		enum_struct_node l_node =
		{
			._target_enum_struct_name{ out_token_iterator_p->_code, framework::get_framework().get_memory_resource() },
			._enum_struct_fields{ framework::get_framework().get_memory_resource() }
		};

		{	// trim spaces at front
			var::uint64 l_space_length = 0;
			for (auto character : l_node._target_enum_struct_name)
			{
				if ((character <= ' ') == false)
				{
					break;
				}
				++l_space_length;
			}
			l_node._target_enum_struct_name.erase(0, l_space_length);
		}

		while (l_node._target_enum_struct_name.length() > 0)
		{
			if (l_node._target_enum_struct_name.back() <= ' ')
			{
				l_node._target_enum_struct_name.pop_back();
				continue;
			}
			break;
		}
		

		l_node._target_enum_struct_name.insert(0, parent_namespace_p);


		while (out_token_iterator_p != end_p)
		{
			if (out_token_iterator_p->_vocabulary == Vocabulary::_RightCurlyBracket)
			{
				++out_token_iterator_p;
				return l_node;
			}

			if (out_token_iterator_p->_vocabulary == Vocabulary::_EnumStructField)
			{
				l_node._enum_struct_fields.emplace_back(out_token_iterator_p->_code);
			}
			++out_token_iterator_p;
		}

		return l_node;
	}

	_FE_NODISCARD_ system_node build_ecs_system_node(const identifier& parent_namespace_p, typename std::pmr::list<token>::const_iterator& out_token_iterator_p, typename std::pmr::list<token>::const_iterator end_p)
	{
		system_node l_node;
		while (out_token_iterator_p != end_p)
		{
			switch (out_token_iterator_p->_vocabulary)
			{
			case Vocabulary::_FrogmanEngineSystemMacro:
				_FE_FALLTHROUGH_;
			case Vocabulary::_LeftParen:
				_FE_FALLTHROUGH_;
			case Vocabulary::_Comma:
				++out_token_iterator_p;
				break;

			case Vocabulary::_RightParen:
				++out_token_iterator_p;
				goto ExitLoop;

			case Vocabulary::_FrogmanEngineSystemArgSysCallPhase:
				l_node._syscall_phase = out_token_iterator_p->_code;
				++out_token_iterator_p;
				break;

			case Vocabulary::_FrogmanEngineSystemArgWorldTagEnum:
				l_node._world_tag_enum = out_token_iterator_p->_code;
				++out_token_iterator_p;
				break;

			default:
				THROW_CPP_SYNTAX_ERROR(true, "Frogman Engine C++ Reflection Syntax Error: the FE_SYSTEM() macro argument order is incorrect, or is ill-formed.");
				break;
			}
		}
	ExitLoop:
		while (out_token_iterator_p->_vocabulary != Vocabulary::_AnyDecl
			&& out_token_iterator_p->_vocabulary != Vocabulary::_ClassStructEnumMethodForwardDeclaration)
		{
			++out_token_iterator_p;
		}

		THROW_CPP_SYNTAX_ERROR(out_token_iterator_p->_code.starts_with(u8"void") == false, "Frogman Engine C++ Reflection Syntax Error: this function cannot be qualified as the Frogman Engine ECS system method; the function signature requirement is: void(::FE::world&).");
		l_node._sysname = out_token_iterator_p->_code;

		constexpr auto l_void_keyword = u8"void";
		auto l_void_pos = l_node._sysname.find(l_void_keyword);
		FE_ASSERT(l_void_pos != identifier::npos);
		l_node._sysname.erase(0, l_void_pos + FE::algorithm::string::length(l_void_keyword));

		THROW_CPP_SYNTAX_ERROR(FE::algorithm::string::space_insensitive_contains(l_node._sysname.c_str(), l_node._sysname.length(), u8"world&") == false, "Frogman Engine C++ Reflection Syntax Error: this function cannot be qualified as the Frogman Engine ECS system method; the function signature requirement is: void(::FE::world&).");

		var::uint64 l_space_length = 0;
		for (auto i = 0; i < l_node._sysname.length(); ++i)
		{
			if (l_node._sysname[i] <= ' ')
			{
				++l_space_length;
				continue;
			}
			break;
		}
		l_node._sysname.erase(0, l_space_length);

		auto l_end_of_fn_name_pos = l_node._sysname.find('(');
		THROW_CPP_SYNTAX_ERROR(l_end_of_fn_name_pos == identifier::npos, "Frogman Engine C++ Reflection Syntax Error: this function cannot be qualified as the Frogman Engine ECS system method; the function signature requirement is: void(::FE::world&).");

		l_node._sysname.erase(l_end_of_fn_name_pos, l_node._sysname.length() - l_end_of_fn_name_pos);
		l_node._sysname.insert(0, parent_namespace_p);
		return l_node;
	}
}