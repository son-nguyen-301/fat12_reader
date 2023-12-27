#include <stdio.h>
#include <stdint.h>
#include "fat_struct.h"
#include "fat_rd.h"

static FileEntryStruct rootDirectoryEntry;

static uint8_t getFileCreationHour(uint16_t time)
{
  return (time & HOUR_MASK) >> 11;
}

static uint8_t getFileCreationMinute(uint16_t time)
{
  return (time & MINUTE_MASK) >> 5;
}

static uint8_t getFileCreationSecond(uint16_t time)
{
  return (time & SECOND_MASK) * 2;
}

static uint16_t getFileCreationYear(uint16_t date)
{
  return ((date & YEAR_MASK) >> 9) + 1980;
}

static uint8_t getFileCreationMonth(uint16_t date)
{
  return (date & MONTH_MASK) >> 5;
}

static uint8_t getFileCreationDay(uint16_t date)
{
  return date & DAY_MASK;
}

static uint8_t getFileStatus(uint64_t fileName)
{
  return (fileName & FILE_STATUS_MASK) >> 56;
}

uint64_t getFileName()
{

  if (rootDirectoryEntry.filename[LONG_FILE_NAME_ATTRS_POSITION] == IS_LONG_FILE_NAME_MASK)
  {
    printf("1st: %x\n", rootDirectoryEntry.filename[LFN_2ND_SEQUENCE_POSITION]);
  }
}

static uint16_t getFATSize(FILE *fp)
{
  uint16_t FATSize;

  fseek(fp, 0x16, SEEK_SET);
  fread(&FATSize, sizeof(FATSize), 1, fp);

  return FATSize;
}

static uint8_t getNumberOfFAT(FILE *fp)
{
  uint16_t numberOfFAT;

  fseek(fp, 0x10, SEEK_SET);
  fread(&numberOfFAT, sizeof(numberOfFAT), 1, fp);

  return numberOfFAT;
}

uint16_t getRootDirectoryBlock(FILE *fp)
{
  return getNumberOfFAT(fp) * getFATSize(fp) + 1;
}

void getAllFolderEntries(FileEntryStruct *entries, FILE *fp, uint16_t folderBlock)
{
  FileEntryStruct *entry = malloc(sizeof(FileEntryStruct));
}