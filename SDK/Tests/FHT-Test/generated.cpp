// Copyright © from 2024 to present, UNKNOWN STRYKER (Hojin Lee / Joey). All Rights Reserved. 
#include <FE/framework/reflection/private/load_reflection_data.hxx> 
#include <FE/framework.hxx> 
#include <memory>

#include <C:\Users\leeho\OneDrive\문서\GitHub\Frogman-Engine\SDK\Tests\FHT-Test\SymbolCountingTest.hpp>




void load_reflection_data()
{
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalEntity*(::GlobalEntity*)> >("construct ::GlobalEntity", &::std::construct_at<::GlobalEntity>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalEntity*)> >("destruct ::GlobalEntity", &::std::destroy_at<::GlobalEntity>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalRenderComponent*(::GlobalRenderComponent*)> >("construct ::GlobalRenderComponent", &::std::construct_at<::GlobalRenderComponent>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalRenderComponent*)> >("destruct ::GlobalRenderComponent", &::std::destroy_at<::GlobalRenderComponent>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalSingleton final*(::GlobalSingleton final*)> >("construct ::GlobalSingleton final", &::std::construct_at<::GlobalSingleton final>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalSingleton final*)> >("destruct ::GlobalSingleton final", &::std::destroy_at<::GlobalSingleton final>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::SimpleClass*(::SimpleClass*)> >("construct ::SimpleClass", &::std::construct_at<::SimpleClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::SimpleClass*)> >("destruct ::SimpleClass", &::std::destroy_at<::SimpleClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::PublicClass*(::PublicClass*)> >("construct ::PublicClass", &::std::construct_at<::PublicClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::PublicClass*)> >("destruct ::PublicClass", &::std::destroy_at<::PublicClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FullAccessClass*(::FullAccessClass*)> >("construct ::FullAccessClass", &::std::construct_at<::FullAccessClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FullAccessClass*)> >("destruct ::FullAccessClass", &::std::destroy_at<::FullAccessClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::DerivedClass*(::DerivedClass*)> >("construct ::DerivedClass", &::std::construct_at<::DerivedClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::DerivedClass*)> >("destruct ::DerivedClass", &::std::destroy_at<::DerivedClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FinalClass final*(::FinalClass final*)> >("construct ::FinalClass final", &::std::construct_at<::FinalClass final>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FinalClass final*)> >("destruct ::FinalClass final", &::std::destroy_at<::FinalClass final>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::NonCopyableClass*(::NonCopyableClass*)> >("construct ::NonCopyableClass", &::std::construct_at<::NonCopyableClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::NonCopyableClass*)> >("destruct ::NonCopyableClass", &::std::destroy_at<::NonCopyableClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FriendClass;

class ClassWithFriend*(::FriendClass;

class ClassWithFriend*)> >("construct ::FriendClass;

class ClassWithFriend", &::std::construct_at<::FriendClass;

class ClassWithFriend>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FriendClass;

class ClassWithFriend*)> >("destruct ::FriendClass;

class ClassWithFriend", &::std::destroy_at<::FriendClass;

class ClassWithFriend>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::StaticClass*(::StaticClass*)> >("construct ::StaticClass", &::std::construct_at<::StaticClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::StaticClass*)> >("destruct ::StaticClass", &::std::destroy_at<::StaticClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::ThreadLocalClass*(::ThreadLocalClass*)> >("construct ::ThreadLocalClass", &::std::construct_at<::ThreadLocalClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::ThreadLocalClass*)> >("destruct ::ThreadLocalClass", &::std::destroy_at<::ThreadLocalClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::ConstClass*(::ConstClass*)> >("construct ::ConstClass", &::std::construct_at<::ConstClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::ConstClass*)> >("destruct ::ConstClass", &::std::destroy_at<::ConstClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::NoexceptClass*(::NoexceptClass*)> >("construct ::NoexceptClass", &::std::construct_at<::NoexceptClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::NoexceptClass*)> >("destruct ::NoexceptClass", &::std::destroy_at<::NoexceptClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::MultipleInheritance*(::MultipleInheritance*)> >("construct ::MultipleInheritance", &::std::construct_at<::MultipleInheritance>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::MultipleInheritance*)> >("destruct ::MultipleInheritance", &::std::destroy_at<::MultipleInheritance>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::VirtualBase*(::VirtualBase*)> >("construct ::VirtualBase", &::std::construct_at<::VirtualBase>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::VirtualBase*)> >("destruct ::VirtualBase", &::std::destroy_at<::VirtualBase>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::VirtualDerivedA*(::VirtualDerivedA*)> >("construct ::VirtualDerivedA", &::std::construct_at<::VirtualDerivedA>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::VirtualDerivedA*)> >("destruct ::VirtualDerivedA", &::std::destroy_at<::VirtualDerivedA>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::VirtualDerivedB*(::VirtualDerivedB*)> >("construct ::VirtualDerivedB", &::std::construct_at<::VirtualDerivedB>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::VirtualDerivedB*)> >("destruct ::VirtualDerivedB", &::std::destroy_at<::VirtualDerivedB>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::DiamondInheritance*(::DiamondInheritance*)> >("construct ::DiamondInheritance", &::std::construct_at<::DiamondInheritance>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::DiamondInheritance*)> >("destruct ::DiamondInheritance", &::std::destroy_at<::DiamondInheritance>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::ConcreteImplementation*(::ConcreteImplementation*)> >("construct ::ConcreteImplementation", &::std::construct_at<::ConcreteImplementation>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::ConcreteImplementation*)> >("destruct ::ConcreteImplementation", &::std::destroy_at<::ConcreteImplementation>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::OperatorClass*(::OperatorClass*)> >("construct ::OperatorClass", &::std::construct_at<::OperatorClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::OperatorClass*)> >("destruct ::OperatorClass", &::std::destroy_at<::OperatorClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::CallingConventionClass*(::CallingConventionClass*)> >("construct ::CallingConventionClass", &::std::construct_at<::CallingConventionClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::CallingConventionClass*)> >("destruct ::CallingConventionClass", &::std::destroy_at<::CallingConventionClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::NestedClass*(::NestedClass*)> >("construct ::NestedClass", &::std::construct_at<::NestedClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::NestedClass*)> >("destruct ::NestedClass", &::std::destroy_at<::NestedClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::DeepClass*(::DeepClass*)> >("construct ::DeepClass", &::std::construct_at<::DeepClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::DeepClass*)> >("destruct ::DeepClass", &::std::destroy_at<::DeepClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::OuterClass*(::OuterClass*)> >("construct ::OuterClass", &::std::construct_at<::OuterClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::OuterClass*)> >("destruct ::OuterClass", &::std::destroy_at<::OuterClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::ComplexPointers*(::ComplexPointers*)> >("construct ::ComplexPointers", &::std::construct_at<::ComplexPointers>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::ComplexPointers*)> >("destruct ::ComplexPointers", &::std::destroy_at<::ComplexPointers>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::KitchenSink final*(::KitchenSink final*)> >("construct ::KitchenSink final", &::std::construct_at<::KitchenSink final>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::KitchenSink final*)> >("destruct ::KitchenSink final", &::std::destroy_at<::KitchenSink final>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalPoint*(::GlobalPoint*)> >("construct ::GlobalPoint", &::std::construct_at<::GlobalPoint>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalPoint*)> >("destruct ::GlobalPoint", &::std::destroy_at<::GlobalPoint>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalVector*(::GlobalVector*)> >("construct ::GlobalVector", &::std::construct_at<::GlobalVector>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalVector*)> >("destruct ::GlobalVector", &::std::destroy_at<::GlobalVector>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalTransform*(::GlobalTransform*)> >("construct ::GlobalTransform", &::std::construct_at<::GlobalTransform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalTransform*)> >("destruct ::GlobalTransform", &::std::destroy_at<::GlobalTransform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Point2D*(::Point2D*)> >("construct ::Point2D", &::std::construct_at<::Point2D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Point2D*)> >("destruct ::Point2D", &::std::destroy_at<::Point2D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Rectangle*(::Rectangle*)> >("construct ::Rectangle", &::std::construct_at<::Rectangle>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Rectangle*)> >("destruct ::Rectangle", &::std::destroy_at<::Rectangle>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Point3D*(::Point3D*)> >("construct ::Point3D", &::std::construct_at<::Point3D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Point3D*)> >("destruct ::Point3D", &::std::destroy_at<::Point3D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Vector3D*(::Vector3D*)> >("construct ::Vector3D", &::std::construct_at<::Vector3D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Vector3D*)> >("destruct ::Vector3D", &::std::destroy_at<::Vector3D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Transform*(::Transform*)> >("construct ::Transform", &::std::construct_at<::Transform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Transform*)> >("destruct ::Transform", &::std::destroy_at<::Transform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::PhysicsTransform*(::PhysicsTransform*)> >("construct ::PhysicsTransform", &::std::construct_at<::PhysicsTransform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::PhysicsTransform*)> >("destruct ::PhysicsTransform", &::std::destroy_at<::PhysicsTransform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Configuration*(::Configuration*)> >("construct ::Configuration", &::std::construct_at<::Configuration>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Configuration*)> >("destruct ::Configuration", &::std::destroy_at<::Configuration>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Flags*(::Flags*)> >("construct ::Flags", &::std::construct_at<::Flags>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Flags*)> >("destruct ::Flags", &::std::destroy_at<::Flags>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::VolatileData*(::VolatileData*)> >("construct ::VolatileData", &::std::construct_at<::VolatileData>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::VolatileData*)> >("destruct ::VolatileData", &::std::destroy_at<::VolatileData>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::PointerData*(::PointerData*)> >("construct ::PointerData", &::std::construct_at<::PointerData>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::PointerData*)> >("destruct ::PointerData", &::std::destroy_at<::PointerData>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::NestedPoint*(::NestedPoint*)> >("construct ::NestedPoint", &::std::construct_at<::NestedPoint>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::NestedPoint*)> >("destruct ::NestedPoint", &::std::destroy_at<::NestedPoint>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::DeepStruct*(::DeepStruct*)> >("construct ::DeepStruct", &::std::construct_at<::DeepStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::DeepStruct*)> >("destruct ::DeepStruct", &::std::destroy_at<::DeepStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::ArrayStruct*(::ArrayStruct*)> >("construct ::ArrayStruct", &::std::construct_at<::ArrayStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::ArrayStruct*)> >("destruct ::ArrayStruct", &::std::destroy_at<::ArrayStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FunctionPointers*(::FunctionPointers*)> >("construct ::FunctionPointers", &::std::construct_at<::FunctionPointers>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FunctionPointers*)> >("destruct ::FunctionPointers", &::std::destroy_at<::FunctionPointers>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::EdgeCases::BraceInjectionAttackClass
{
	char _bowoh = '}';
	const char* _waer = "asdadsa}d";
};*(::FE::Test::EdgeCases::BraceInjectionAttackClass
{
	char _bowoh = '}';
	const char* _waer = "asdadsa}d";
};*)> >("construct ::FE::Test::EdgeCases::BraceInjectionAttackClass
{
	char _bowoh = '}';
	const char* _waer = "asdadsa}d";
};", &::std::construct_at<::FE::Test::EdgeCases::BraceInjectionAttackClass
{
	char _bowoh = '}';
	const char* _waer = "asdadsa}d";
};>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::EdgeCases::BraceInjectionAttackClass
{
	char _bowoh = '}';
	const char* _waer = "asdadsa}d";
};*)> >("destruct ::FE::Test::EdgeCases::BraceInjectionAttackClass
{
	char _bowoh = '}';
	const char* _waer = "asdadsa}d";
};", &::std::destroy_at<::FE::Test::EdgeCases::BraceInjectionAttackClass
{
	char _bowoh = '}';
	const char* _waer = "asdadsa}d";
};>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::EdgeCases::InnerStruct*(::FE::Test::EdgeCases::InnerStruct*)> >("construct ::FE::Test::EdgeCases::InnerStruct", &::std::construct_at<::FE::Test::EdgeCases::InnerStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::EdgeCases::InnerStruct*)> >("destruct ::FE::Test::EdgeCases::InnerStruct", &::std::destroy_at<::FE::Test::EdgeCases::InnerStruct>);
}
