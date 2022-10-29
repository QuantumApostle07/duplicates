#ifndef ITERATE_HEADER
#define ITERATE_HEADER
#include "linkedlist.h"

void iterate_list(struct unique* head);
int search(char* hash, struct unique* head);
void searchfile(char* fpath,struct unique* head);
void listdups(struct unique* head);

#endif
