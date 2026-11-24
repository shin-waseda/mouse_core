/*
 * crc32.c
 * CRC32(第88回)．4 ビットずつの表(16 個)で計算する(表が小さく，1 バイトずつより速い)．
 */
#include "logic/crc32.h"

static const uint32_t table[16] = {
  0x00000000u, 0x1DB71064u, 0x3B6E20C8u, 0x26D930ACu, 0x76DC4190u, 0x6B6B51F4u, 0x4DB26158u, 0x5005713Cu,
  0xEDB88320u, 0xF00F9344u, 0xD6D6A3E8u, 0xCB61B38Cu, 0x9B64C2B0u, 0x86D3D2D4u, 0xA00AE278u, 0xBDBDF21Cu,
};

uint32_t Crc32(const uint8_t *data, uint32_t len)
{
  uint32_t c = 0xFFFFFFFFu;
  for (uint32_t i = 0; i < len; i++)
  {
    c ^= data[i];
    c = (c >> 4) ^ table[c & 0x0F];
    c = (c >> 4) ^ table[c & 0x0F];
  }
  return c ^ 0xFFFFFFFFu;
}
