#include "iterate.h"
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include <stdlib.h>
#include "strSHA2.h"

void iterate_list(struct unique* head)
{
    int totalunique = -1; 
    int totalwithduplicates = 0;
    int totalmemory = 0;
    int uniquememory = 0;

    if (head == NULL)
    {
        return;
    }
    struct unique* current  = head; 
    while(1)
    {
    
        totalunique++;
        totalwithduplicates += current ->n_dups;
        uniquememory += current -> memory;
        totalmemory += current->memory * current ->n_dups;
        if (current ->next == NULL)
            {
                break;
            }
        current = current->next;
    } 
 
    totalwithduplicates += totalunique; //add duplicates to total number
    totalmemory += uniquememory;

    printf("total files = %d\n", totalwithduplicates);
    printf("total size = %d\n", totalmemory);
    printf("unique files = %d\n", totalunique);
    printf("unique files size = %d\n", uniquememory);;
}   


int search(char* hash, struct unique* head) // goes through and finds similar hashes, if there are any print them out
    {
    
    struct unique *current = head;
    while (1)
        {
            if(!strcmp(current ->hash, hash))
            {
                if (current->n_dups>0)
                {
                    struct duplicate *currentdup = current ->copy;
                    while(1)
                    {
                        printf("%s\n",currentdup->path);
                        if (currentdup->dcopy == NULL)
                            break;
                        currentdup = currentdup->dcopy;
                    }
                }
                return EXIT_SUCCESS;
            }
            if (current->next==NULL)
                break;
            current = current->next;
        }
    return 0;
    }


void searchfile(char* fpath, struct unique* head)
{
    //simply finds the hash of the chosen file
    if (fopen(fpath,"r") == 0)
        return;
    char *hash_val = strSHA2(fpath);

    search(hash_val, head);
    return;
}


void listdups(struct unique* head){//list all the duplicates found
    

    struct unique *current = head;
    while (1)
    {
        if (current->n_dups>0)
        {
            printf("file: %s:   %s", current->name, current->path);
            struct duplicate *currentdup = current ->copy; 
            while(1)
            {
                printf("\t%s",currentdup->path);
                if (currentdup->dcopy == NULL)
                    break;
                currentdup = currentdup->dcopy;
            }
            printf("\n");
        }
        if (current->next == NULL)
            break;
        current = current->next;
    }
    return;
}
