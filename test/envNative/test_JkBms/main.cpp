/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#include <unity.h>

#include "test_Rs485.hpp"
#include "test_IsValid.hpp"

extern "C"
{
    namespace test::envNative::test_JkBms
    {
        using namespace JkBms;
        
        void setUp(void)
        {
            // N/A
        }

        void tearDown(void)
        {
            // N/A
        }

        int runUnityTests()
        {
            UNITY_BEGIN();

            // #include "test_Rs485.hpp"
            RUN_TEST(CreatingInstanceFromVectorSucceeds);
            RUN_TEST(CreatingInstanceFromUniquePtrVectorSucceeds);
            RUN_TEST(AccessingDataWithInvalidIndexThrows);
            RUN_TEST(GettingLengthSucceeds);
            RUN_TEST(GettingDataSucceeds);
            RUN_TEST(InstantiatingMovesVectorMemory);

            // #include "test_IsValid.hpp"
            RUN_TEST(IsValidFails);
            RUN_TEST(IsValidWithInvalidMinimumLengthFails);
            RUN_TEST(IsValidWithInvalidLengthFails);
            RUN_TEST(IsValidWithValidLengthSucceeds);
            RUN_TEST(IsValidWithInvalidChecksumFails);
            RUN_TEST(IsValidWithValidChecksumSucceeds);
            RUN_TEST(IsValidWithInvalidIdentifierFails);

            RUN_TEST(TestingCellVoltageSucceeds);
            
            RUN_TEST(ValdiatingNumberSucceeds);
            RUN_TEST(ValdiatingIdentifierSucceeds);
            RUN_TEST(ValdiatingIdentifierFails);

            return UNITY_END();
        }

        void app_main() 
        {
            runUnityTests();
        }

        int main(int argc, char **argv)
        {
            return runUnityTests();
        }
    }
}
