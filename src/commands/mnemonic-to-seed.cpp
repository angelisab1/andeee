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

#include <bitcoin/explorer/commands/mnemonic-to-seed.hpp>

#include <iostream>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/explorer/define.hpp>
#include <bitcoin/explorer/primitives/base16.hpp>

using namespace bc;
using namespace bc::explorer;
using namespace bc::explorer::commands;
using namespace bc::explorer::primitives;

console_result mnemonic_to_seed::invoke(std::ostream& output,
    std::ostream& error)
{
    // Bound parameters.
    const auto& language = get_language_option();
    const auto& passphrase = get_passphrase_option();
    const auto& words = get_words_argument();

    const auto word_count = words.size();

    if ((word_count % mnemonic_word_multiple) != 0)
    {
        error << BX_EC_MNEMONIC_TO_SEED_LENGTH_INVALID_SENTENCE << std::endl;
        return console_result::failure;
    }

    bool valid;
    if (language)
        valid = validate_mnemonic(words, *language);
    else
        valid = validate_mnemonic(words);

    if (!valid)
    {
        // This warning is non-fatal,
        // since the mnemonic may be valid in a language we don't know:
        error << BX_EC_MNEMONIC_TO_SEED_INVALID_SENTENCE << std::endl;
    }

    const auto seed = decode_mnemonic(words, passphrase);

    output << base16(seed) << std::endl;
    return console_result::okay;
}
