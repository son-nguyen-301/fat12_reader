#include <stdio.h>
#include "fat_struct.h"

static RootDirectoryEntry rootDirectoryEntry;

// FAT12 find root directory entry
void findRootDirectoryEntry(FILE *fp)
{
  // Read the first root directory entry
  fseek(fp, 0x2600, SEEK_SET);
  fread(&rootDirectoryEntry, sizeof(rootDirectoryEntry), 1, fp);

  // Print the first root directory entry
  printf("Root directory entry:\n");
  printf("    Filename: %s\n", rootDirectoryEntry.filename);
  printf("    Extension: %s\n", rootDirectoryEntry.ext);
  printf("    Attributes: %d\n", rootDirectoryEntry.attributes);
  printf("    Reserved: %d\n", rootDirectoryEntry.reserved);
  printf("    Creation time: %d\n", rootDirectoryEntry.modify_time);
  printf("    Creation date: %d\n", rootDirectoryEntry.modify_date);
  printf("    Starting cluster: %d\n", rootDirectoryEntry.starting_cluster);
  printf("    File size: %d\n", rootDirectoryEntry.file_size);

  fclose(fp);
}