// Copyright © from 2024 to present, UNKNOWN STRYKER (Hojin Lee / Joey). All Rights Reserved. 
#include <FE/framework/reflection/private/load_reflection_data.hxx> 
#include <FE/framework.hxx> 
#include <memory>

#include <C:\Users\leeho\OneDrive\문서\GitHub\Frogman-Engine\SDK\Tests\FHT-Test\SymbolCountingTest.hpp>




void load_reflection_data()
{
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalComponent*(::GlobalComponent*)> >("construct ::GlobalComponent", &::std::construct_at<::GlobalComponent>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalComponent*)> >("destruct ::GlobalComponent", &::std::destroy_at<::GlobalComponent>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalSingleton*(::GlobalSingleton*)> >("construct ::GlobalSingleton", &::std::construct_at<::GlobalSingleton>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalSingleton*)> >("destruct ::GlobalSingleton", &::std::destroy_at<::GlobalSingleton>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::SimpleClass*(::SimpleClass*)> >("construct ::SimpleClass", &::std::construct_at<::SimpleClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::SimpleClass*)> >("destruct ::SimpleClass", &::std::destroy_at<::SimpleClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FullAccessClass*(::FullAccessClass*)> >("construct ::FullAccessClass", &::std::construct_at<::FullAccessClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FullAccessClass*)> >("destruct ::FullAccessClass", &::std::destroy_at<::FullAccessClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::DerivedClass*(::DerivedClass*)> >("construct ::DerivedClass", &::std::construct_at<::DerivedClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::DerivedClass*)> >("destruct ::DerivedClass", &::std::destroy_at<::DerivedClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::NonCopyableClass*(::NonCopyableClass*)> >("construct ::NonCopyableClass", &::std::construct_at<::NonCopyableClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::NonCopyableClass*)> >("destruct ::NonCopyableClass", &::std::destroy_at<::NonCopyableClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::StaticClass*(::StaticClass*)> >("construct ::StaticClass", &::std::construct_at<::StaticClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::StaticClass*)> >("destruct ::StaticClass", &::std::destroy_at<::StaticClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::ConstClass*(::ConstClass*)> >("construct ::ConstClass", &::std::construct_at<::ConstClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::ConstClass*)> >("destruct ::ConstClass", &::std::destroy_at<::ConstClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::MultipleBaseA*(::MultipleBaseA*)> >("construct ::MultipleBaseA", &::std::construct_at<::MultipleBaseA>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::MultipleBaseA*)> >("destruct ::MultipleBaseA", &::std::destroy_at<::MultipleBaseA>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::MultipleInheritance*(::MultipleInheritance*)> >("construct ::MultipleInheritance", &::std::construct_at<::MultipleInheritance>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::MultipleInheritance*)> >("destruct ::MultipleInheritance", &::std::destroy_at<::MultipleInheritance>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::VirtualDerivedA*(::VirtualDerivedA*)> >("construct ::VirtualDerivedA", &::std::construct_at<::VirtualDerivedA>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::VirtualDerivedA*)> >("destruct ::VirtualDerivedA", &::std::destroy_at<::VirtualDerivedA>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::DiamondInheritance*(::DiamondInheritance*)> >("construct ::DiamondInheritance", &::std::construct_at<::DiamondInheritance>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::DiamondInheritance*)> >("destruct ::DiamondInheritance", &::std::destroy_at<::DiamondInheritance>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::ConcreteImplementation*(::ConcreteImplementation*)> >("construct ::ConcreteImplementation", &::std::construct_at<::ConcreteImplementation>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::ConcreteImplementation*)> >("destruct ::ConcreteImplementation", &::std::destroy_at<::ConcreteImplementation>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::CallingConventionClass*(::CallingConventionClass*)> >("construct ::CallingConventionClass", &::std::construct_at<::CallingConventionClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::CallingConventionClass*)> >("destruct ::CallingConventionClass", &::std::destroy_at<::CallingConventionClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalPoint*(::GlobalPoint*)> >("construct ::GlobalPoint", &::std::construct_at<::GlobalPoint>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalPoint*)> >("destruct ::GlobalPoint", &::std::destroy_at<::GlobalPoint>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::GlobalTransform*(::GlobalTransform*)> >("construct ::GlobalTransform", &::std::construct_at<::GlobalTransform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::GlobalTransform*)> >("destruct ::GlobalTransform", &::std::destroy_at<::GlobalTransform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Point2D*(::Point2D*)> >("construct ::Point2D", &::std::construct_at<::Point2D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Point2D*)> >("destruct ::Point2D", &::std::destroy_at<::Point2D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Point3D*(::Point3D*)> >("construct ::Point3D", &::std::construct_at<::Point3D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Point3D*)> >("destruct ::Point3D", &::std::destroy_at<::Point3D>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Transform*(::Transform*)> >("construct ::Transform", &::std::construct_at<::Transform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Transform*)> >("destruct ::Transform", &::std::destroy_at<::Transform>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::Configuration*(::Configuration*)> >("construct ::Configuration", &::std::construct_at<::Configuration>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::Configuration*)> >("destruct ::Configuration", &::std::destroy_at<::Configuration>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::VolatileData*(::VolatileData*)> >("construct ::VolatileData", &::std::construct_at<::VolatileData>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::VolatileData*)> >("destruct ::VolatileData", &::std::destroy_at<::VolatileData>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::Nested::NestedClass*(::FE::Test::Nested::NestedClass*)> >("construct ::FE::Test::Nested::NestedClass", &::std::construct_at<::FE::Test::Nested::NestedClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::Nested::NestedClass*)> >("destruct ::FE::Test::Nested::NestedClass", &::std::destroy_at<::FE::Test::Nested::NestedClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::Nested::NestedPoint*(::FE::Test::Nested::NestedPoint*)> >("construct ::FE::Test::Nested::NestedPoint", &::std::construct_at<::FE::Test::Nested::NestedPoint>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::Nested::NestedPoint*)> >("destruct ::FE::Test::Nested::NestedPoint", &::std::destroy_at<::FE::Test::Nested::NestedPoint>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::Nested::Deep::DeepClass*(::FE::Test::Nested::Deep::DeepClass*)> >("construct ::FE::Test::Nested::Deep::DeepClass", &::std::construct_at<::FE::Test::Nested::Deep::DeepClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::Nested::Deep::DeepClass*)> >("destruct ::FE::Test::Nested::Deep::DeepClass", &::std::destroy_at<::FE::Test::Nested::Deep::DeepClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::Nested::Deep::DeepStruct*(::FE::Test::Nested::Deep::DeepStruct*)> >("construct ::FE::Test::Nested::Deep::DeepStruct", &::std::construct_at<::FE::Test::Nested::Deep::DeepStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::Nested::Deep::DeepStruct*)> >("destruct ::FE::Test::Nested::Deep::DeepStruct", &::std::destroy_at<::FE::Test::Nested::Deep::DeepStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::EdgeCases::OuterClass*(::FE::Test::EdgeCases::OuterClass*)> >("construct ::FE::Test::EdgeCases::OuterClass", &::std::construct_at<::FE::Test::EdgeCases::OuterClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::EdgeCases::OuterClass*)> >("destruct ::FE::Test::EdgeCases::OuterClass", &::std::destroy_at<::FE::Test::EdgeCases::OuterClass>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::EdgeCases::ComplexPointers*(::FE::Test::EdgeCases::ComplexPointers*)> >("construct ::FE::Test::EdgeCases::ComplexPointers", &::std::construct_at<::FE::Test::EdgeCases::ComplexPointers>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::EdgeCases::ComplexPointers*)> >("destruct ::FE::Test::EdgeCases::ComplexPointers", &::std::destroy_at<::FE::Test::EdgeCases::ComplexPointers>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::EdgeCases::KitchenSink*(::FE::Test::EdgeCases::KitchenSink*)> >("construct ::FE::Test::EdgeCases::KitchenSink", &::std::construct_at<::FE::Test::EdgeCases::KitchenSink>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::EdgeCases::KitchenSink*)> >("destruct ::FE::Test::EdgeCases::KitchenSink", &::std::destroy_at<::FE::Test::EdgeCases::KitchenSink>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::EdgeCases::OuterStruct*(::FE::Test::EdgeCases::OuterStruct*)> >("construct ::FE::Test::EdgeCases::OuterStruct", &::std::construct_at<::FE::Test::EdgeCases::OuterStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::EdgeCases::OuterStruct*)> >("destruct ::FE::Test::EdgeCases::OuterStruct", &::std::destroy_at<::FE::Test::EdgeCases::OuterStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::EdgeCases::ArrayStruct*(::FE::Test::EdgeCases::ArrayStruct*)> >("construct ::FE::Test::EdgeCases::ArrayStruct", &::std::construct_at<::FE::Test::EdgeCases::ArrayStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::EdgeCases::ArrayStruct*)> >("destruct ::FE::Test::EdgeCases::ArrayStruct", &::std::destroy_at<::FE::Test::EdgeCases::ArrayStruct>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<::FE::Test::EdgeCases::FunctionPointers*(::FE::Test::EdgeCases::FunctionPointers*)> >("construct ::FE::Test::EdgeCases::FunctionPointers", &::std::construct_at<::FE::Test::EdgeCases::FunctionPointers>);
    ::FE::framework::framework_base::get_framework().get_method_reflection().register_task< ::FE::c_style_task<void(::FE::Test::EdgeCases::FunctionPointers*)> >("destruct ::FE::Test::EdgeCases::FunctionPointers", &::std::destroy_at<::FE::Test::EdgeCases::FunctionPointers>);

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::GlobalStatus >("::GlobalStatus",
    {
        { ::GlobalStatus::Inactive, "Inactive" },
        { ::GlobalStatus::Active, "Active" },
        { ::GlobalStatus::Pending, "Pending" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::GlobalErrorCode >("::GlobalErrorCode",
    {
        { ::GlobalErrorCode::Success, "Success" },
        { ::GlobalErrorCode::GeneralError, "GeneralError" },
        { ::GlobalErrorCode::InvalidInput, "InvalidInput" },
        { ::GlobalErrorCode::OutOfMemory, "OutOfMemory" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::GlobalPriority >("::GlobalPriority",
    {
        { ::GlobalPriority::Low, "Low" },
        { ::GlobalPriority::Medium, "Medium" },
        { ::GlobalPriority::High, "High" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::Color // >("::Color //",
    {
        { ::Color //::Red, "Red" },
        { ::Color //::Green, "Green" },
        { ::Color //::Blue, "Blue" },
        { ::Color //::Yellow, "Yellow" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::ByteStatus >("::ByteStatus",
    {
        { ::ByteStatus::Idle, "Idle" },
        { ::ByteStatus::Running, "Running" },
        { ::ByteStatus::Paused, "Paused" },
        { ::ByteStatus::Stopped, "Stopped" },
        { ::ByteStatus::Error, "Error" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::LongCode >("::LongCode",
    {
        { ::LongCode::MinValue, "MinValue" },
        { ::LongCode::Zero, "Zero" },
        { ::LongCode::MaxValue, "MaxValue" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::SingleValue >("::SingleValue",
    {
        { ::SingleValue::Only, "Only" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::Nested::NestedColor >("::FE::Test::Nested::NestedColor",
    {
        { ::FE::Test::Nested::NestedColor::Cyan, "Cyan" },
        { ::FE::Test::Nested::NestedColor::Magenta, "Magenta" },
        { ::FE::Test::Nested::NestedColor::Yellow, "Yellow" },
        { ::FE::Test::Nested::NestedColor::Black, "Black" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::Nested::Deep::DeepEnum >("::FE::Test::Nested::Deep::DeepEnum",
    {
        { ::FE::Test::Nested::Deep::DeepEnum::Value1, "Value1" },
        { ::FE::Test::Nested::Deep::DeepEnum::Value2, "Value2" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::EdgeCases::LargeEnum >("::FE::Test::EdgeCases::LargeEnum",
    {
        { ::FE::Test::EdgeCases::LargeEnum::Zero, "Zero" },
        { ::FE::Test::EdgeCases::LargeEnum::Small, "Small" },
        { ::FE::Test::EdgeCases::LargeEnum::Medium, "Medium" },
        { ::FE::Test::EdgeCases::LargeEnum::Large, "Large" },
        { ::FE::Test::EdgeCases::LargeEnum::VeryLarge, "VeryLarge" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::EdgeCases::Fake >("::FE::Test::EdgeCases::Fake",
    {
        { ::FE::Test::EdgeCases::Fake::NerfThis, "NerfThis" }
    });
}
