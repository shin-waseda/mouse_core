/*
 * crc32.h
 * CRC32(Python の zlib.crc32 と同じ．多項式 0xEDB88320，初期値と最後の反転 0xFFFFFFFF)．第88回．
 * 走行ログのページが壊れていないかを PC で確かめるのに使う(docs/design/log_format.md)．
 */
#ifndef LOGIC_CRC32_H
#define LOGIC_CRC32_H

#include "global.h"

uint32_t Crc32(const uint8_t *data, uint32_t len);

#endif /* LOGIC_CRC32_H */
