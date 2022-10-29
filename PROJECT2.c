#include "header.h"

int main(int argc, char *argv[]){
    char *string = malloc(strlen(strSHA2(argv[1]))+1);
    printf("%s", string);
    return 0;
}