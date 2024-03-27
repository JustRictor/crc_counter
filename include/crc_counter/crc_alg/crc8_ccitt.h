#ifndef __CRC8_CCITT_H_
#define __CRC8_CCITT_H_

#include <stdint.h>

/**
 * \brief crc8 algorithm with poly 0x07
 * \param data [in] data array
 * \param len  [in] array len
 * \return crc
 * \note poly specification
 *      * Name:     CRC-8/CCITT
 *      * Width:    8
 *      * Poly:     0x07
 *      * Init:     0x00
 *      * RefIn:    False
 *      * RefOut:   False
 *      * XorOut:   0x00
 *      * Check:    0xF4
 */
uint8_t crc8_ccitt(uint8_t const* data, uint64_t len);

#endif//__CRC8_CCITT_H_
