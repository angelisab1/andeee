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
#ifndef BX_TRANSACTION_HPP
#define BX_TRANSACTION_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <boost/program_options.hpp>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/explorer/define.hpp>

/* NOTE: don't declare 'using namespace foo' in headers. */

namespace libbitcoin {
namespace explorer {
namespace primitives {

/**
 * Serialization helper to convert between serialized and deserialized satoshi 
 * transaction.
 */
class transaction
{
public:

    /**
     * Default constructor.
     */
    BCX_API transaction();

    /**
     * Initialization constructor.
     * @param[in]  hexcode  The value to initialize with.
     */
    BCX_API transaction(const std::string& hexcode);

    /**
     * Initialization constructor.
     * @param[in]  value  The value to initialize with.
     */
    BCX_API transaction(const tx_type& value);

    /**
     * Copy constructor.
     * @param[in]  other  The object to copy into self on construct.
     */
    BCX_API transaction(const transaction& other);

    /**
     * Return a reference to the data member.
     * @return  A reference to the object's internal data.
     */
    BCX_API tx_type& data();

    /**
     * Overload cast to internal type.
     * @return  This object's value cast to internal type.
     */
    BCX_API operator const tx_type&() const;

    /**
     * Overload stream in. Throws if input is invalid.
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    BCX_API friend std::istream& operator>>(std::istream& input,
        transaction& argument);

    /**
     * Overload stream out.
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    BCX_API friend std::ostream& operator<<(std::ostream& output,
        const transaction& argument);

private:

    /**
     * The state of this object's transaction data.
     */
    tx_type value_;
};

} // namespace explorer
} // namespace primitives
} // namespace libbitcoin

#endif