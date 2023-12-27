#include <stdio.h>
#include <stdint.h>
#include "fat_struct.h"
#include "fat_rd.h"

static RootDirectoryEntry rootDirectoryEntry;

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

static void validateFileName(uint64_t fileName)
{
}

void getRootDirectory(FILE *fp, uint16_t rootDirectoryBlock)
{
  fseek(fp, rootDirectoryBlock * 512, SEEK_SET);
  fread(&rootDirectoryEntry, sizeof(rootDirectoryEntry), 1, fp);

  uint64_t *fileName = (uint64_t *)rootDirectoryEntry.filename;

  printf("File status: %x\n", getFileStatus(*fileName));
  printf("File name: %s\n", rootDirectoryEntry.filename);
}