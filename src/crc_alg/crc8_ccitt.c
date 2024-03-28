#include "crc_counter/crc_alg/crc8_ccitt.h"
#include "crc_counter/crc_polynomes.h"

uint8_t crc8(const uint8_t *data, uint64_t len)
{
    uint8_t crc = 0x00;
    while(len--)
    {
        crc ^= *data++;
        for(uint8_t i = 0; i < 8; i++)
        {
            crc = ( crc & (1 << 7) ) ? ( crc << 1 ) ^ __CRC8_CCITT_POLY
                                     :   crc << 1 ;
        }
    }
    return crc;
}
