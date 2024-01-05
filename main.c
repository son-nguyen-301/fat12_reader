#include <stdio.h>
#include "fat_rd.h"
#include "fat_struct.h"

void main()
{
  FILE *fp = fopen("floppy.img", "rb");

  uint16_t rootDirectoryBlock = getRootDirectoryBlock(fp);

  getAllFolderEntries(fp, rootDirectoryBlock);

  fclose(fp);
}