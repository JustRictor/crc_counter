#include "crc_counter/crc_alg/crc1.h"
#include "crc_counter/crc_polynomes.h"

uint8_t crc1(uint8_t const* data, uint64_t len)
{
    uint8_t crc = 0x00;
    while(len--)
    {
        crc ^= *data++;
        for(uint8_t i = 0; i < 8; i++)
        {
            crc = crc & 0x01 ? ( crc >> 1 ) ^ __CRC1_POLY_REV
                             :   crc >> 1 ;
        }
    }
    return crc & 0x1;
}
