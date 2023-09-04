// Copyright (c) 2023 Ronald Rink
// Licensed under the MIT License. See LICENSE file in the project root for full license information.
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>

namespace Endian
{
    #pragma pack(push, 1)
    /// @brief Represents a BYTE.
    union tagByte
    {
        uint8_t Value;
    };
    #pragma pack(pop)

    using Byte = tagByte;
}
