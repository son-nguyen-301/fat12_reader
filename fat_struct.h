#include <stdint.h>

typedef struct
{
  uint8_t filename[8];
  uint8_t ext[3];
  uint8_t attributes;
  uint8_t reserved[10];
  uint16_t modify_time;
  uint16_t modify_date;
  uint16_t starting_cluster;
  uint32_t file_size;
} RootDirectoryEntry;