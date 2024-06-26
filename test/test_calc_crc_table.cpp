#include <catch2/catch_test_macros.hpp>
extern "C" {
#include "crc_counter/crc_polynomes.h"
#include "crc_counter/tools/calc_crc_table.h"
}

template<typename T>
bool compTables(T const* t1, T const* t2)
{
    for(uint16_t i = 0; i < 256; i++)
        if (*t1++ != *t2++) return false;
    return true;
}

TEST_CASE("Test calcCrc8Table for CRC-4/ITU", "[check]")
{
    uint8_t const _crcTableValid[256] = {
        0x0, 0x7, 0xe, 0x9, 0x5, 0x2, 0xb, 0xc, 0xa, 0xd, 0x4, 0x3, 0xf, 0x8, 0x1, 0x6,
        0xd, 0xa, 0x3, 0x4, 0x8, 0xf, 0x6, 0x1, 0x7, 0x0, 0x9, 0xe, 0x2, 0x5, 0xc, 0xb,
        0x3, 0x4, 0xd, 0xa, 0x6, 0x1, 0x8, 0xf, 0x9, 0xe, 0x7, 0x0, 0xc, 0xb, 0x2, 0x5,
        0xe, 0x9, 0x0, 0x7, 0xb, 0xc, 0x5, 0x2, 0x4, 0x3, 0xa, 0xd, 0x1, 0x6, 0xf, 0x8,
        0x6, 0x1, 0x8, 0xf, 0x3, 0x4, 0xd, 0xa, 0xc, 0xb, 0x2, 0x5, 0x9, 0xe, 0x7, 0x0,
        0xb, 0xc, 0x5, 0x2, 0xe, 0x9, 0x0, 0x7, 0x1, 0x6, 0xf, 0x8, 0x4, 0x3, 0xa, 0xd,
        0x5, 0x2, 0xb, 0xc, 0x0, 0x7, 0xe, 0x9, 0xf, 0x8, 0x1, 0x6, 0xa, 0xd, 0x4, 0x3,
        0x8, 0xf, 0x6, 0x1, 0xd, 0xa, 0x3, 0x4, 0x2, 0x5, 0xc, 0xb, 0x7, 0x0, 0x9, 0xe,
        0xc, 0xb, 0x2, 0x5, 0x9, 0xe, 0x7, 0x0, 0x6, 0x1, 0x8, 0xf, 0x3, 0x4, 0xd, 0xa,
        0x1, 0x6, 0xf, 0x8, 0x4, 0x3, 0xa, 0xd, 0xb, 0xc, 0x5, 0x2, 0xe, 0x9, 0x0, 0x7,
        0xf, 0x8, 0x1, 0x6, 0xa, 0xd, 0x4, 0x3, 0x5, 0x2, 0xb, 0xc, 0x0, 0x7, 0xe, 0x9,
        0x2, 0x5, 0xc, 0xb, 0x7, 0x0, 0x9, 0xe, 0x8, 0xf, 0x6, 0x1, 0xd, 0xa, 0x3, 0x4,
        0xa, 0xd, 0x4, 0x3, 0xf, 0x8, 0x1, 0x6, 0x0, 0x7, 0xe, 0x9, 0x5, 0x2, 0xb, 0xc,
        0x7, 0x0, 0x9, 0xe, 0x2, 0x5, 0xc, 0xb, 0xd, 0xa, 0x3, 0x4, 0x8, 0xf, 0x6, 0x1,
        0x9, 0xe, 0x7, 0x0, 0xc, 0xb, 0x2, 0x5, 0x3, 0x4, 0xd, 0xa, 0x6, 0x1, 0x8, 0xf,
        0x4, 0x3, 0xa, 0xd, 0x1, 0x6, 0xf, 0x8, 0xe, 0x9, 0x0, 0x7, 0xb, 0xc, 0x5, 0x2
    };
    uint8_t crcTableRecv[256];
    calc_crc8_table(crcTableRecv, __CRC4_ITU_POLY_REV, true, 4);
    CHECK( compTables(_crcTableValid,crcTableRecv) == true );
}

TEST_CASE("Test calcCrc8Table for CRC-8/MAXIM", "[check]")
{
    uint8_t const _crcTableValid[256] = {
        0x00, 0x5E, 0xBC, 0xE2, 0x61, 0x3F, 0xDD, 0x83,
        0xC2, 0x9C, 0x7E, 0x20, 0xA3, 0xFD, 0x1F, 0x41,
        0x9D, 0xC3, 0x21, 0x7F, 0xFC, 0xA2, 0x40, 0x1E,
        0x5F, 0x01, 0xE3, 0xBD, 0x3E, 0x60, 0x82, 0xDC,
        0x23, 0x7D, 0x9F, 0xC1, 0x42, 0x1C, 0xFE, 0xA0,
        0xE1, 0xBF, 0x5D, 0x03, 0x80, 0xDE, 0x3C, 0x62,
        0xBE, 0xE0, 0x02, 0x5C, 0xDF, 0x81, 0x63, 0x3D,
        0x7C, 0x22, 0xC0, 0x9E, 0x1D, 0x43, 0xA1, 0xFF,
        0x46, 0x18, 0xFA, 0xA4, 0x27, 0x79, 0x9B, 0xC5,
        0x84, 0xDA, 0x38, 0x66, 0xE5, 0xBB, 0x59, 0x07,
        0xDB, 0x85, 0x67, 0x39, 0xBA, 0xE4, 0x06, 0x58,
        0x19, 0x47, 0xA5, 0xFB, 0x78, 0x26, 0xC4, 0x9A,
        0x65, 0x3B, 0xD9, 0x87, 0x04, 0x5A, 0xB8, 0xE6,
        0xA7, 0xF9, 0x1B, 0x45, 0xC6, 0x98, 0x7A, 0x24,
        0xF8, 0xA6, 0x44, 0x1A, 0x99, 0xC7, 0x25, 0x7B,
        0x3A, 0x64, 0x86, 0xD8, 0x5B, 0x05, 0xE7, 0xB9,
        0x8C, 0xD2, 0x30, 0x6E, 0xED, 0xB3, 0x51, 0x0F,
        0x4E, 0x10, 0xF2, 0xAC, 0x2F, 0x71, 0x93, 0xCD,
        0x11, 0x4F, 0xAD, 0xF3, 0x70, 0x2E, 0xCC, 0x92,
        0xD3, 0x8D, 0x6F, 0x31, 0xB2, 0xEC, 0x0E, 0x50,
        0xAF, 0xF1, 0x13, 0x4D, 0xCE, 0x90, 0x72, 0x2C,
        0x6D, 0x33, 0xD1, 0x8F, 0x0C, 0x52, 0xB0, 0xEE,
        0x32, 0x6C, 0x8E, 0xD0, 0x53, 0x0D, 0xEF, 0xB1,
        0xF0, 0xAE, 0x4C, 0x12, 0x91, 0xCF, 0x2D, 0x73,
        0xCA, 0x94, 0x76, 0x28, 0xAB, 0xF5, 0x17, 0x49,
        0x08, 0x56, 0xB4, 0xEA, 0x69, 0x37, 0xD5, 0x8B,
        0x57, 0x09, 0xEB, 0xB5, 0x36, 0x68, 0x8A, 0xD4,
        0x95, 0xCB, 0x29, 0x77, 0xF4, 0xAA, 0x48, 0x16,
        0xE9, 0xB7, 0x55, 0x0B, 0x88, 0xD6, 0x34, 0x6A,
        0x2B, 0x75, 0x97, 0xC9, 0x4A, 0x14, 0xF6, 0xA8,
        0x74, 0x2A, 0xC8, 0x96, 0x15, 0x4B, 0xA9, 0xF7,
        0xB6, 0xE8, 0x0A, 0x54, 0xD7, 0x89, 0x6B, 0x35
    };
    uint8_t crcTableRecv[256];
    calc_crc8_table(crcTableRecv, __CRC8_DALLAS_POLY_REV, true, 8);
    CHECK( compTables(_crcTableValid,crcTableRecv) == true );
}

TEST_CASE("Test calcCrc16Table for CRC-16/XMODEM", "[check]")
{
    uint16_t const _crcTableValid[256] = {
        0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
        0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
        0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
        0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
        0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
        0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
        0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
        0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
        0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
        0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
        0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
        0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
        0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
        0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
        0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
        0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
        0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
        0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
        0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
        0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
        0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
        0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
        0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
        0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
        0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
        0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
        0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
        0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
        0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
        0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
        0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
        0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
    };
    uint16_t crcTableRecv[256];
    calc_crc16_table(crcTableRecv, __CRC16_CCITT_POLY, false, 16);
    CHECK( compTables(_crcTableValid,crcTableRecv) == true );
}

TEST_CASE("Test calcCrc16Table for CRC-16/ARC", "[check]")
{
    uint16_t const _crcTableValid[256] = {
        0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
        0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
        0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
        0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
        0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
        0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
        0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
        0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
        0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
        0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
        0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
        0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
        0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
        0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
        0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
        0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
        0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
        0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
        0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
        0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
        0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
        0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
        0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
        0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
        0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
        0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
        0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
        0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
        0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
        0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
        0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
        0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
    };
    uint16_t crcTableRecv[256];
    calc_crc16_table(crcTableRecv, __CRC16_IBM_POLY_REV, true, 16);
    CHECK( compTables(_crcTableValid,crcTableRecv) == true );
}

TEST_CASE("Test calcCrc32Table for CRC-32/zlib", "[check]")
{
    uint32_t const _crcTableValid[256] = {
        0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
        0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
        0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
        0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
        0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
        0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
        0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,
        0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
        0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
        0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
        0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940,
        0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
        0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116,
        0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
        0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
        0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
        0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A,
        0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
        0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818,
        0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
        0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
        0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
        0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C,
        0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
        0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
        0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
        0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
        0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
        0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086,
        0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
        0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4,
        0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
        0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
        0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
        0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
        0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
        0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE,
        0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
        0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
        0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
        0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252,
        0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
        0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60,
        0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
        0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
        0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
        0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04,
        0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
        0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A,
        0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
        0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
        0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
        0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E,
        0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
        0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
        0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
        0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
        0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
        0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0,
        0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
        0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6,
        0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
        0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
        0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
    };
    uint32_t crcTableRecv[256];
    calc_crc32_table(crcTableRecv,__CRC32_IEEE_POLY_REV, true, 32);
    CHECK( compTables(_crcTableValid,crcTableRecv) == true );
}

TEST_CASE("Test calcCrc32Table for CRC-32/Q", "[check]")
{
    uint32_t const _crcTableValid[256] = {
        0x0, 0x814141ab, 0x83c3c2fd, 0x2828356,
        0x86c6c451, 0x78785fa, 0x50506ac, 0x84444707,
        0x8cccc909, 0xd8d88a2, 0xf0f0bf4, 0x8e4e4a5f,
        0xa0a0d58, 0x8b4b4cf3, 0x89c9cfa5, 0x8888e0e,
        0x98d8d3b9, 0x19999212, 0x1b1b1144, 0x9a5a50ef,
        0x1e1e17e8, 0x9f5f5643, 0x9dddd515, 0x1c9c94be,
        0x14141ab0, 0x95555b1b, 0x97d7d84d, 0x169699e6,
        0x92d2dee1, 0x13939f4a, 0x11111c1c, 0x90505db7,
        0xb0f0e6d9, 0x31b1a772, 0x33332424, 0xb272658f,
        0x36362288, 0xb7776323, 0xb5f5e075, 0x34b4a1de,
        0x3c3c2fd0, 0xbd7d6e7b, 0xbfffed2d, 0x3ebeac86,
        0xbafaeb81, 0x3bbbaa2a, 0x3939297c, 0xb87868d7,
        0x28283560, 0xa96974cb, 0xabebf79d, 0x2aaab636,
        0xaeeef131, 0x2fafb09a, 0x2d2d33cc, 0xac6c7267,
        0xa4e4fc69, 0x25a5bdc2, 0x27273e94, 0xa6667f3f,
        0x22223838, 0xa3637993, 0xa1e1fac5, 0x20a0bb6e,
        0xe0a08c19, 0x61e1cdb2, 0x63634ee4, 0xe2220f4f,
        0x66664848, 0xe72709e3, 0xe5a58ab5, 0x64e4cb1e,
        0x6c6c4510, 0xed2d04bb, 0xefaf87ed, 0x6eeec646,
        0xeaaa8141, 0x6bebc0ea, 0x696943bc, 0xe8280217,
        0x78785fa0, 0xf9391e0b, 0xfbbb9d5d, 0x7afadcf6,
        0xfebe9bf1, 0x7fffda5a, 0x7d7d590c, 0xfc3c18a7,
        0xf4b496a9, 0x75f5d702, 0x77775454, 0xf63615ff,
        0x727252f8, 0xf3331353, 0xf1b19005, 0x70f0d1ae,
        0x50506ac0, 0xd1112b6b, 0xd393a83d, 0x52d2e996,
        0xd696ae91, 0x57d7ef3a, 0x55556c6c, 0xd4142dc7,
        0xdc9ca3c9, 0x5ddde262, 0x5f5f6134, 0xde1e209f,
        0x5a5a6798, 0xdb1b2633, 0xd999a565, 0x58d8e4ce,
        0xc888b979, 0x49c9f8d2, 0x4b4b7b84, 0xca0a3a2f,
        0x4e4e7d28, 0xcf0f3c83, 0xcd8dbfd5, 0x4cccfe7e,
        0x44447070, 0xc50531db, 0xc787b28d, 0x46c6f326,
        0xc282b421, 0x43c3f58a, 0x414176dc, 0xc0003777,
        0x40005999, 0xc1411832, 0xc3c39b64, 0x4282dacf,
        0xc6c69dc8, 0x4787dc63, 0x45055f35, 0xc4441e9e,
        0xcccc9090, 0x4d8dd13b, 0x4f0f526d, 0xce4e13c6,
        0x4a0a54c1, 0xcb4b156a, 0xc9c9963c, 0x4888d797,
        0xd8d88a20, 0x5999cb8b, 0x5b1b48dd, 0xda5a0976,
        0x5e1e4e71, 0xdf5f0fda, 0xdddd8c8c, 0x5c9ccd27,
        0x54144329, 0xd5550282, 0xd7d781d4, 0x5696c07f,
        0xd2d28778, 0x5393c6d3, 0x51114585, 0xd050042e,
        0xf0f0bf40, 0x71b1feeb, 0x73337dbd, 0xf2723c16,
        0x76367b11, 0xf7773aba, 0xf5f5b9ec, 0x74b4f847,
        0x7c3c7649, 0xfd7d37e2, 0xffffb4b4, 0x7ebef51f,
        0xfafab218, 0x7bbbf3b3, 0x793970e5, 0xf878314e,
        0x68286cf9, 0xe9692d52, 0xebebae04, 0x6aaaefaf,
        0xeeeea8a8, 0x6fafe903, 0x6d2d6a55, 0xec6c2bfe,
        0xe4e4a5f0, 0x65a5e45b, 0x6727670d, 0xe66626a6,
        0x622261a1, 0xe363200a, 0xe1e1a35c, 0x60a0e2f7,
        0xa0a0d580, 0x21e1942b, 0x2363177d, 0xa22256d6,
        0x266611d1, 0xa727507a, 0xa5a5d32c, 0x24e49287,
        0x2c6c1c89, 0xad2d5d22, 0xafafde74, 0x2eee9fdf,
        0xaaaad8d8, 0x2beb9973, 0x29691a25, 0xa8285b8e,
        0x38780639, 0xb9394792, 0xbbbbc4c4, 0x3afa856f,
        0xbebec268, 0x3fff83c3, 0x3d7d0095, 0xbc3c413e,
        0xb4b4cf30, 0x35f58e9b, 0x37770dcd, 0xb6364c66,
        0x32720b61, 0xb3334aca, 0xb1b1c99c, 0x30f08837,
        0x10503359, 0x911172f2, 0x9393f1a4, 0x12d2b00f,
        0x9696f708, 0x17d7b6a3, 0x155535f5, 0x9414745e,
        0x9c9cfa50, 0x1dddbbfb, 0x1f5f38ad, 0x9e1e7906,
        0x1a5a3e01, 0x9b1b7faa, 0x9999fcfc, 0x18d8bd57,
        0x8888e0e0, 0x9c9a14b, 0xb4b221d, 0x8a0a63b6,
        0xe4e24b1, 0x8f0f651a, 0x8d8de64c, 0xccca7e7,
        0x44429e9, 0x85056842, 0x8787eb14, 0x6c6aabf,
        0x8282edb8, 0x3c3ac13, 0x1412f45, 0x80006eee
    };
    uint32_t crcTableRecv[256];
    calc_crc32_table(crcTableRecv,__CRC32_Q_POLY, false, 32);
    CHECK( compTables(_crcTableValid,crcTableRecv) == true );
}
