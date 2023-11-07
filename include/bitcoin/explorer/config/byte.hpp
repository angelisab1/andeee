/**
 * Copyright (c) 2011-2019 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BX_BYTE_HPP
#define BX_BYTE_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <bitcoin/explorer/define.hpp>

namespace libbitcoin {
namespace explorer {
namespace config {

// This is necessary because the stream cannot read a single byte as a number.

class BCX_API byte
{
public:
    typedef uint8_t type;

    byte();
    byte(const byte& other);
    byte(const std::string& token);
    byte(const type& value);

    operator const type&() const;

    friend std::istream& operator>>(std::istream& input, byte& argument);
    friend std::ostream& operator<<(std::ostream& output,
        const byte& argument);

private:
    type value_;
};

} // namespace explorer
} // namespace config
} // namespace libbitcoin

#endif
