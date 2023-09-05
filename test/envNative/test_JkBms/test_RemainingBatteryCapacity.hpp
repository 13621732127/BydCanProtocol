// Copyright (c) 2023 Ronald Rink
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
// SPDX-License-Identifier: MIT

#include <unity.h>

#include <Identifiers/RemainingBatteryCapacity.h>

namespace test::envNative::test_JkBms
{
    using namespace JkBms;
    using namespace JkBms::Identifiers;
    
    void TestingRemainingBatteryCapacityIdentifierSucceeds(void)
    {
        std::vector<std::uint8_t> data 
        {
            0x85,
            0x00
        };

        auto sut = reinterpret_cast<RemainingBatteryCapacity*>(data.data());

        auto result = sut->Identifier.Value;

        TEST_ASSERT_EQUAL_UINT8(Id::RemainingBatteryCapacity, result);
    }

    void TestingRemainingBatteryCapacityReturnsZero(void)
    {
        std::vector<std::uint8_t> data 
        {
            0x85,
            0x00
        };

        auto sut = reinterpret_cast<RemainingBatteryCapacity*>(data.data());

        auto result = sut->ToPercent();

        TEST_ASSERT_EQUAL_FLOAT(0, result.Value.GetValue());
    }

    void RemainingBatteryCapacityReturns32(void)
    {
        std::vector<std::uint8_t> data 
        {
            0x85,
            0x20
        };

        auto sut = reinterpret_cast<RemainingBatteryCapacity*>(data.data());

        auto result = sut->ToPercent();

        TEST_ASSERT_EQUAL_FLOAT(0.32, result.Value.GetValue());
    }

    void RemainingBatteryCapacityReturns100(void)
    {
        std::vector<std::uint8_t> data 
        {
            0x85,
            0x64 // 100%
        };

        auto sut = reinterpret_cast<RemainingBatteryCapacity*>(data.data());

        auto result = sut->ToPercent();

        TEST_ASSERT_EQUAL_FLOAT(1.00, result.Value.GetValue());
    }

    void RemainingBatteryCapacityThrows(void)
    {
        std::vector<std::uint8_t> data 
        {
            0x85,
            0x65 // 101%
        };

        auto sut = reinterpret_cast<RemainingBatteryCapacity*>(data.data());

        try
        {
            auto _ = sut->ToPercent();
        }
        catch(...)
        {
            TEST_PASS();
            return;
        }
        TEST_FAIL();
    }
}
