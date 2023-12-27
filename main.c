#include <stdio.h>
#include "fat_rd.h"

void main()
{
  FILE *fp = fopen("floppy.img", "rb");

  uint8_t fatSize = getFATSize(fp);
  uint8_t numberOfFAT = getNumberOfFAT(fp);
  uint16_t rootDirectoryBlock = getRootDirectoryBlock(fp);

  printf("FAT size: %x\n", fatSize);
  printf("Number of FAT: %x\n", numberOfFAT);
  printf("Root directory block: %x\n", rootDirectoryBlock);

  getRootDirectory(fp, 0x13);

  fclose(fp);
}