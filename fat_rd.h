#include <stdio.h>
#include <stdint.h>

#define HOUR_MASK 0xF800
#define MINUTE_MASK 0x07E0
#define SECOND_MASK 0x001F
#define YEAR_MASK 0xFE00
#define MONTH_MASK 0x01E0
#define DAY_MASK 0x001F
#define FILE_STATUS_MASK 0xFF00000000000000
#define LONG_FILE_NAME_ATTRS_POSITION 0x0B
#define IS_LONG_FILE_NAME_MASK 0x0F
#define LFN_1ST_SEQUENCE_POSITION 0x01
#define LFN_2ND_SEQUENCE_POSITION 0x0E
#define LFN_3RD_SEQUENCE_POSITION 0x1C
#define BLOCK_SIZE 512

uint16_t getRootDirectoryBlock(FILE *fp);
void getAllFolderEntries(FILE *fp, uint16_t rootDirectoryAddress);