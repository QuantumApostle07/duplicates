#ifndef STORAGE_HEADER
#define STORAGE_HEADER
#include "linkedlist.h"


void store_directory(char * path, int inc_hidden, struct unique* head, int* hasduplicates);
int isDirectoryExists(const char *path);

#endif
