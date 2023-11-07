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

#include "command.hpp"

BX_USING_NAMESPACES()

BOOST_AUTO_TEST_SUITE(network)
BOOST_AUTO_TEST_SUITE(fetch_stealth__invoke)

#define BX_FETCH_STEALTH_HEIGHT0_PREFIX10101010101_INFO \
"stealth\n" \
"{\n" \
"    match\n" \
"    {\n" \
"        ephemeral_public_key 024f4101000199071b753d68747470733a2f2f6370722e736d2f50647334476956\n" \
"        paid_address 1AEDp5EtdMg9ZUZhyB47ZZupwfdVCnG5bS\n" \
"        transaction_hash 2b8024d6d4c1c333ecd8d0d8af44aed676c8624cf1503340b37e9465cad415f5\n" \
"    }\n" \
"    match\n" \
"    {\n" \
"        ephemeral_public_key 026f7072657475726e2e6e696e6a61202d20707573682073746420747873202877\n" \
"        paid_address 1B8BnC4dP6vKVhndSLCPMG2Lq9AyoRUKXq\n" \
"        transaction_hash 02854c79fb685e2f9551b7c0e5e0074429ecc73aebfc5df558714cdfe6e07467\n" \
"    }\n" \
"    match\n" \
"    {\n" \
"        ephemeral_public_key 02a9b4d9e2115b3a6d18651f2d5e920a9c5c8b4f54a7882cd75a1b1a93752347a5\n" \
"        paid_address 1NsN2ihdRijVsFKEMhrw9ZjQTZawtgh7kh\n" \
"        transaction_hash f6cc0174f09f6583ec42817ba1172030609f418d78598e9bd7b8152be4100f55\n" \
"    }\n" \
"    match\n" \
"    {\n" \
"        ephemeral_public_key 024f41010001021b753d68747470733a2f2f6370722e736d2f6f647454475a3434\n" \
"        paid_address 17t15PKUr2GCDY5ufaq3QQgcmfRzYEnoLg\n" \
"        transaction_hash 1623d01142f80a2900e7b323ae5a36d864e0bceee85f2018bc601d1721bb82fd\n" \
"    }\n" \
"}\n"

// requires libbitcoin-server.
BOOST_AUTO_TEST_CASE(fetch_stealth__invoke_mainnet_height_0__okay)
{
    BX_DECLARE_NETWORK_COMMAND(fetch_stealth);
    command.set_mainnet_url_setting({ BX_MAINNET_SERVER });
    BX_REQUIRE_OKAY(command.invoke(output, error));
}

// requires libbitcoin-server.
BOOST_AUTO_TEST_CASE(fetch_stealth__invoke_mainnet_height_323557__okay)
{
    BX_DECLARE_NETWORK_COMMAND(fetch_stealth);
    command.set_height_option(323557);
    command.set_mainnet_url_setting({ BX_MAINNET_SERVER });
    BX_REQUIRE_OKAY(command.invoke(output, error));
}

// requires libbitcoin-server.
// This test is fragile, will eventually break.
////BOOST_AUTO_TEST_CASE(fetch_stealth__invoke_mainnet_height_0_prefix_10101010101__okay_output)
////{
////    BX_DECLARE_NETWORK_COMMAND(fetch_stealth);
////    command.set_format_option({ "info" });
////    command.set_height_option(0);
////    command.set_prefix_argument({ "10101010101" });
////    command.set_mainnet_url_setting({ BX_MAINNET_SERVER });
////    BX_REQUIRE_OKAY(command.invoke(output, error));
////    BX_REQUIRE_OUTPUT(BX_FETCH_STEALTH_HEIGHT0_PREFIX10101010101_INFO);
////}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
