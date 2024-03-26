#include "crc_counter/crc_alg/crc4_itu.h"

uint8_t crc4_itu(uint8_t const* data, uint64_t len)
{
    uint8_t crc = 0x0;
    while(len--)
    {
        crc ^= *data++;
        for (uint8_t i = 0; i < 8; i++)
        {
              crc = crc & 0x01 ? ( crc >> 1 ) ^ CRC4_ITU_POLY_REV
                               :   crc >> 1 ;
        }
    }
    return crc;
}
