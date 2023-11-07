/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-explorer.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <bitcoin/explorer/commands/qrcode.hpp>

#include <iostream>
#include <bitcoin/explorer/define.hpp>

using namespace bc::explorer;
using namespace bc::explorer::commands;

console_result qrcode::invoke(std::ostream& output, std::ostream& error)
{
    // Bound parameters.
    //const auto& address = get_bitcoin_address_argument();

    error << BX_QRCODE_NOT_IMPLEMENTED << std::endl;
    return console_result::failure;
}

//#!/bin/bash
//if [ $# -ne 2 ]; then
//    echo "Usage: qrcode ADDRESS FILENAME"
//    exit 1
//fi
//command -v qrencode >/dev/null 2>&1 || { echo >&2 "Please install 'qrencode'."; exit 1; }
//ADDR=$1
//FILE=$2
//qrencode bitcoin:$ADDR -o $FILE -s 10
//
