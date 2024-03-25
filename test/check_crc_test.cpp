#include <catch2/catch_test_macros.hpp>
extern "C" {
#include "crc_counter/crc_counter.h"
}

TEST_CASE("Check for crc1 algorithm", "[check]")
{
    CHECK( crc1( (uint8_t*)"123456789", 9 ) == 0x01);
}
