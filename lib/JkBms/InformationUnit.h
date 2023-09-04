// Copyright (c) 2023 Ronald Rink
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>

#include "Identifier.h"

#include "Identifier/CellVoltage.h"

namespace JkBms
{
    #pragma pack(push, 1)
    struct tagInformationUnit
    {
        Identifier Identifier;
        uint8_t* Data;
    };
    #pragma pack(pop)

    using InformationUnit = tagInformationUnit;
}
