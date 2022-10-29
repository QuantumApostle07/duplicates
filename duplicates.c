//  CITS2002 Project 2 2021
//  Name(s):             Chukwuebuka Anwasi, Charlie Teo
//  Student number(s):   22990144 , 22978954

#include "storage.h"
#include "iterate.h"
#include "linkedlist.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv)
{
  
  int include_hidden = 0;
  int hasduplicates = 0;
  struct unique* head = (struct unique*)malloc(sizeof(struct unique));

  int o; //provides the output for getopt
  extern char *optarg;
  extern int optind, optopt;
  int primaryarg = 0; //for finding the primary argument
  

  while((o = getopt(argc, argv, "aAf:h:lmq")) != -1)
  {
    if (o == 'a')
        include_hidden =1;
        
    if (o ==  'A')
      return(EXIT_SUCCESS);

    if(o == '?')
    {
      printf("%c is an invalid options\n", optopt );
      return(EXIT_FAILURE);
    }
  }

  //stores the path names for all the directories
  for (int i = optind; i<argc; i++)
  {
    if (isDirectoryExists(argv[i]))
    {
        store_directory(argv[i], include_hidden,head, &hasduplicates);
    } 
  
    else 
    {
      perror("Error: ");
      return(EXIT_FAILURE);
    }
  }

  optind = 1; //this resets getopt
  
  while((o = getopt(argc, argv, "aAf:h:lmq")) != -1)
  { 
    if (primaryarg != 1)  //sets the primary argument as the first argument thats succesfully read
    {
      primaryarg  =1; 
      switch(o)
      {
        case 'a':
        include_hidden =1;
        iterate_list(head);
        return (EXIT_SUCCESS);

        case 'A': 
        return(EXIT_SUCCESS);
        
        case 'f': 
        searchfile(optarg,head);//goes through chosen directory and searches for files with same file name
        return (EXIT_SUCCESS);
        

        case 'h':
        // goes through lists and finds matching hashes
        search(optarg,head);
        return (EXIT_SUCCESS);
        
        case 'l':
        // provides a list of all found duplicates
        listdups(head);
        return (EXIT_SUCCESS);
      
        case 'm':
        return(EXIT_FAILURE);
        
        case 'q':
        //simply checks if there are any duplicates or not
        if (hasduplicates)
        return(EXIT_FAILURE);
        else
        return(EXIT_SUCCESS);
        
        case':':
          if (optopt == 'f' || optopt == 'h')
          {
          printf("missing argument for %c \n", optopt);
          perror("Error: ");
          }
          //doesn't need to be called under the assumption that directory is the argument 
          return(EXIT_FAILURE);

        case'?':
          perror("Error: ");
          return(EXIT_FAILURE);
      }
    }
  }

  iterate_list(head);
  return 0;
}
