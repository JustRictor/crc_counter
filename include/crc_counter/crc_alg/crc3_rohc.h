#ifndef __CRC3_ROHC_H_
#define __CRC3_ROHC_H_

#include <stdint.h>

/**
 * \brief crc3 algorithm with poly 0x03
 * \param data [in] data array
 * \param len  [in] array len
 * \return crc
 * \note poly specification
 *      * Name:     CRC-3/ROHC
 *      * Width:    3
 *      * Poly:     0x03
 *      * Init:     0x07
 *      * RefIn:    True
 *      * RefOut:   True
 *      * XorOut:   0x00
 *      * Check:    0x06
 */
uint8_t crc3_rohc(uint8_t const* data, uint64_t len);

#endif//__CRC3_ROHC_H_
