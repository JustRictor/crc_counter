#include "crc_counter/crc_alg/crc5_epc.h"
#include "crc_counter/crc_polynomes.h"

uint8_t crc5_epc(uint8_t const* data, uint64_t len)
{
    ///\todo fixme
    uint8_t crc = 0x09;
    while(len--)
    {
        crc ^= *data++;
        for (uint8_t i = 0; i < 8; i++)
        {
              crc = ( crc & (1 << 4) ) ? ( crc << 1 ) ^ __CRC5_EPC_POLY
                                       :   crc << 1 ;
        }
    }
    return crc;
}
