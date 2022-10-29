#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

struct unique{
    char* name;
    char* path;
    char* hash;
    int n_dups; 
    int memory;
    struct unique* next;
    struct duplicate* copy;
};

struct duplicate
{
    char* path;
    struct duplicate* dcopy;
};

void duplicate_insert(struct unique * current, char* newpath, int numberofduplicates);
void insert_list(char*name, char* hash,char*path ,int memory, struct unique* head, int* hasduplicates);



#endif
