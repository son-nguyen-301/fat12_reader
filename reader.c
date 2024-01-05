#include <stdio.h>
#include <stdlib.h>

// Define the size of the file system structure
#define SECTOR_SIZE 512
#define ROOT_ENTRIES 224
#define FILE_NAME_LENGTH 11

// Structure representing a directory entry in the FAT12 file system
struct DirectoryEntry
{
  char name[FILE_NAME_LENGTH];
  char attributes;
  char reserved[10];
  unsigned short time;
  unsigned short date;
  unsigned short cluster;
  unsigned int size;
};

// Function to read a sector from the file system
void read_sector(FILE *file, int sector_number, void *buffer)
{
  fseek(file, sector_number * SECTOR_SIZE, SEEK_SET);
  fread(buffer, 1, SECTOR_SIZE, file);
}

// Function to read a directory entry from the file system
void read_directory_entry(FILE *file, int entry_number, struct DirectoryEntry *entry)
{
  fseek(file, ROOT_ENTRIES * SECTOR_SIZE + entry_number * sizeof(struct DirectoryEntry), SEEK_SET);
  fread(entry, 1, sizeof(struct DirectoryEntry), file);
}

int main()
{
  FILE *file = fopen("floppy.img", "rb");

  if (!file)
  {
    perror("Error opening file");
    return 1;
  }

  // Read the root directory
  struct DirectoryEntry entry;
  for (int i = 0; i < ROOT_ENTRIES; ++i)
  {
    read_directory_entry(file, i, &entry);

    // Check if the entry is valid
    if (entry.name[0] == 0x00 || entry.name[0] == 0xE5)
    {
      continue;
    }

    // Print information about the file
    printf("File Name: %s\n", entry.name);
    printf("Attributes: %d\n", entry.attributes);
    printf("Size: %u bytes\n", entry.size);

    // You can add more logic here to read and print the content of the file if needed
  }

  fclose(file);

  return 0;
}