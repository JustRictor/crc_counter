#ifndef __CRC5_EPC_H_
#define __CRC5_EPC_H_

#include <stdint.h>

/**
 * \brief crc5 algorithm with poly 0x09
 * \param data [in] data array
 * \param len  [in] array len
 * \return crc
 * \note crc specification
 *      * Name:     CRC-5/EPC
 *      * Width:    5
 *      * Poly:     0x09
 *      * Init:     0x09
 *      * RefIn:    False
 *      * RefOut:   False
 *      * XorOut:   0x00
 *      * Check:    0x00
 */
uint8_t crc5_epc(uint8_t const* data, uint64_t len);

#endif//__CRC5_EPC_H_
