
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void duplicate_insert(struct unique * current, char* newpath, int numberofduplicates) 
/* places a duplicate at end for a given unique node and then allocates space in memory for a new node to be formed */
{
    
    struct duplicate * new_node = NULL;
    new_node = (struct duplicate*) malloc(sizeof(struct duplicate));

    if (!numberofduplicates) {
        current -> copy = new_node; //new node is made head of linkedlist
    }

    else
    {
        struct duplicate * duplicate_node = current ->copy; 
        while (duplicate_node -> dcopy != NULL)//iterates until no more copies left
         
        {
            duplicate_node = duplicate_node ->dcopy;
        }
        duplicate_node ->dcopy = new_node;
    }
    new_node ->dcopy = NULL;
    new_node ->path = newpath; 
    
}


void insert_list(char*name, char* hash,char*path ,int memory,struct unique* head, int* hasduplicates)
{
    char* newpath = malloc(strlen(path+1));  //string for reformatting path 
    if(newpath != NULL) 
        strcpy(newpath, path); //'newpath' is destination array where string 'path' is being copied to
   

    struct unique* new_node = NULL; //forms a new node
    new_node = (struct unique*) malloc(sizeof(struct unique)); //memory allocation
    struct unique *current = NULL;

    if (head->next == NULL) //gives value held by 'next' to head and checks that that's null
    {  
        
        head ->name = "head";
        head ->hash = "head";
        head ->path = "head";

        head ->next = new_node;
        head ->memory = 0;
        head ->n_dups = 0;
        
        head ->copy = NULL;
        current = head;
    }

    else 
    {   
        current = head;
        while (1)
        {
             if (!strcmp(current -> hash, hash)) // should the hash be the same with the hash's of the other current nodes, add it to duplicates 
            
            {
                *hasduplicates = 1; //for -q implementation
                duplicate_insert(current, newpath,current -> n_dups);

                (current -> n_dups)++;
                return;
            } 
            if (current ->next == NULL) //if reached the end of the loop break
             {
                break;
             }
            current = current->next;
           
        }
    }
    current->next = new_node; 
    
    //newly formed node gets added to the end of the linkedlist

    new_node -> name = name;
    new_node -> hash = hash;
    new_node -> path = newpath;

    new_node -> memory = memory;
    new_node -> n_dups = 0;
    
    
    new_node -> copy = NULL;
    new_node -> next = NULL;
   
    return;
}
