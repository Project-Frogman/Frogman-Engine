// Copyright © from 2024 to present, UNKNOWN STRYKER (Hojin Lee / Joey). All Rights Reserved. 
#include <FE/framework/reflection/private/load_reflection_data.hxx> 
#include <FE/framework.hxx> 
#include <memory>

#include <C:\Users\leeho\OneDrive\문서\GitHub\Frogman-Engine\SDK\Tests\FHT-Test\NamespaceTest.hpp>




void load_reflection_data()
{

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::Color >("::FE::Test::Color",
    {
        { ::FE::Test::Color::Red, "Red" },
        { ::FE::Test::Color::Green, "Green" },
        { ::FE::Test::Color::Blue, "Blue" },
        { ::FE::Test::Color::Yellow, "Yellow" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::ByteStatus >("::FE::Test::ByteStatus",
    {
        { ::FE::Test::ByteStatus::Idle, "Idle" },
        { ::FE::Test::ByteStatus::Running, "Running" },
        { ::FE::Test::ByteStatus::Paused, "Paused" },
        { ::FE::Test::ByteStatus::Stopped, "Stopped" },
        { ::FE::Test::ByteStatus::Error, "Error" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::LongCode >("::FE::Test::LongCode",
    {
        { ::FE::Test::LongCode::MinValue, "MinValue" },
        { ::FE::Test::LongCode::Zero, "Zero" },
        { ::FE::Test::LongCode::MaxValue, "MaxValue" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::SingleValue >("::FE::Test::SingleValue",
    {
        { ::FE::Test::SingleValue::Only, "Only" }
    });

    ::FE::framework::framework_base::get_framework().get_enum_reflection().register_enum_struct< ::FE::Test::EmptyEnum >("::FE::Test::EmptyEnum",
    {
        { ::FE::Test::EmptyEnum::_, "_" }
    });
}
