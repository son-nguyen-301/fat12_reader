#include <stdio.h>
#include "fat_rd.h"

void main()
{
  FILE *fp = fopen("floppy.img", "rb");

  findRootDirectoryEntry(fp);
}