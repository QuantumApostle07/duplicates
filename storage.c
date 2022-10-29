#include "storage.h"
#include "strSHA2.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>


void store_directory(char * path, int include_hidden, struct unique* head, int* hasduplicates)

{
//searches every path recursively
  struct stat stats;

  DIR * cdir = opendir(path); //opens path, returns NULL otherwise
  if(cdir==NULL)
  return;

  struct dirent * entry; 

  while ((entry = readdir(cdir)) != NULL) //goes through the directory
  {
    if(entry-> d_type != DT_DIR) //if it happens not to be a directory
    {
      if (include_hidden || (entry->d_name[0] !='.')) //includes hidden if flag is on
      {
        char f_path[255];
        sprintf(f_path, "%s/%s", path, entry->d_name); //creates a path for the hash function
        char *hash_val = strSHA2(f_path); 

        stat(f_path, &stats); //obtains path stats
        int memory_size = stats.st_size;
        insert_list(entry->d_name,hash_val, path,memory_size,head, hasduplicates);
      } 
    }
    else if(entry -> d_type == DT_DIR && strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0 ) // ignores hidden files "." & ".." if its a directory.
    {
      char d_path[255]; 
      sprintf(d_path, "%s/%s", path, entry->d_name);

      store_directory(d_path, include_hidden,head, hasduplicates); // recursively enters, completes
      
    }
  }
    closedir(cdir); 
}

int isDirectoryExists(const char *path)
{
    struct stat stats;

  //if directory exists, returns 1
    stat(path, &stats);
    // Checks for the files existence in the directory
    if (S_ISDIR(stats.st_mode))
        return 1;
    return 0;
}
