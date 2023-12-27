#include <stdio.h>
#include <stdint.h>

#define HOUR_MASK 0xF800
#define MINUTE_MASK 0x07E0
#define SECOND_MASK 0x001F
#define YEAR_MASK 0xFE00
#define MONTH_MASK 0x01E0
#define DAY_MASK 0x001F
#define FILE_STATUS_MASK 0xFF00000000000000

uint16_t getFATSize(FILE *fp);
uint8_t getNumberOfFAT(FILE *fp);
uint16_t getRootDirectoryBlock(FILE *fp);
void getRootDirectory(FILE *fp, uint16_t rootDirectoryAddress);