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
#include "program_options.hpp"

// FE.Core string algorithm
#include <FE/algorithm/string.hxx>




program_options::program_options(FE::int32 argc_p, FE::ASCII** argv_p) noexcept
	:	base(argc_p, argv_p),
		m_path_options({
		{ "-path-to-copyright-notice=", "\0" },
		{ "-path-to-project=", "\0" }
		}),

		m_bool_options({
		{ "-fno-reflection-helper", false },
		{ "-fno-op", false },
		{ "-frequire-reflection-marker", false }
		}),
		
		m_macro_map(),

		m_argc(argc_p),
		m_argv(argv_p)
{
	for (var::int32 i = 0; i < argc_p; ++i)
	{
		FE::boolean l_is_path_option = __parse_path_options(argv_p[i]);
		if (l_is_path_option == true)
		{ // successfully parsed as a path option
			continue; // iterate to the next argument
		}

		auto l_result = m_bool_options.find(argv_p[i]);
		if (l_result != m_bool_options.end())
		{
			l_result->second = true;
			continue;
		}

		FE::boolean l_is_macro_definition = __parse_macro_definition(argv_p[i]);
		if (l_is_macro_definition == true)
		{ // successfully parsed as a macro definition
			continue; // iterate to the next argument
		}
	}
}

FE::boolean program_options::__parse_path_options(FE::ASCII* const option_p) noexcept
{
	auto l_symbol = FE::algorithm::string::find_the_first<var::ASCII>(option_p, '=');
	if (l_symbol == std::nullopt)
	{
		return false;
	}

	auto l_result = m_path_options.find_ks(option_p, l_symbol->_end);
	if (m_path_options.end() == l_result)
	{
		return false;
	}

	l_result.value().assign(option_p + l_symbol->_end);
	return true;
}

FE::boolean program_options::__parse_macro_definition(FE::ASCII* const option_p) noexcept
{
	constexpr FE::ASCII* l_macro_definition_prefix_clang_style = "-D";
	constexpr FE::ASCII* l_macro_definition_prefix_msvc_style = "/D";
	constexpr FE::size l_macro_definition_prefix_length = 2;

	FE::boolean l_is_clang_style = FE::algorithm::string::compare_ranged(option_p, { 0, l_macro_definition_prefix_length }, l_macro_definition_prefix_clang_style, { 0, l_macro_definition_prefix_length });
	FE::boolean l_is_msvc_style = FE::algorithm::string::compare_ranged(option_p, { 0, l_macro_definition_prefix_length }, l_macro_definition_prefix_msvc_style, { 0, l_macro_definition_prefix_length });

	if (l_is_clang_style == false && l_is_msvc_style == false)
	{
		return false;
	}


	FE::ASCII* const l_option_begin = option_p + l_macro_definition_prefix_length; // skip the prefix

	auto l_value_assignment_operator_pos = FE::algorithm::string::find_the_first(l_option_begin, '=');
	std::string_view l_key = l_option_begin;

	if (l_value_assignment_operator_pos != std::nullopt) // the macro has a value. Map it
	{
		l_key.remove_suffix(FE::algorithm::string::length(l_option_begin) - l_value_assignment_operator_pos->_begin);

		std::string l_value = l_option_begin + l_value_assignment_operator_pos->_end;
		m_macro_map.emplace(l_key, std::move(l_value));
		return true;
	}
	
	m_macro_map[l_key] = "1";
	return true;
}
