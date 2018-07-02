#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc,char *argv[]){
  DIR *pdir = opendir("");
  if (pdir ==   NULL){
      perror("opendir");
      exit(1);
  }
  
  struct dirent *p = NULL;
  while ( (p = readdir(pdir)) != NULL ){
      printf("%s\n", p->d_name);

  }
  closedir(pdir);
}
