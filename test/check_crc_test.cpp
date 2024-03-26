#include <catch2/catch_test_macros.hpp>
extern "C" {
#include "crc_counter/crc_counter.h"
}

TEST_CASE("Check for crc1 algorithm", "[check]")
{
    uint8_t str[] = "123456789";
    uint64_t strLen = sizeof( str ) - 1;
    CHECK( crc1     ( str, strLen ) == 0x01 );
    CHECK( crc3_rohc( str, strLen ) == 0x06 );
    CHECK( crc4_itu ( str, strLen ) == 0x07 );
}
