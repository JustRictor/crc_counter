#ifndef __CRC5_ITU_H_
#define __CRC5_ITU_H_

#include <stdint.h>

/**
 * \brief crc5 algorithm with poly 0x15
 * \param data [in] data array
 * \param len  [in] array len
 * \return crc
 * \note crc specification
 *      * Name:     CRC-5/ITU
 *      * Width:    5
 *      * Poly:     0x15
 *      * Init:     0x00
 *      * RefIn:    True
 *      * RefOut:   True
 *      * XorOut:   0x00
 *      * Check:    0x07
 */
uint8_t crc5_itu(uint8_t const* data, uint64_t len);

#endif//__CRC5_ITU_H_
