#include "myShell.h"

void runcmd1new(int npfd[], int pfd[], std::vector<std::string> argv_v1){
  int pid;
  pid = fork();
  int cntin = 0;
  char ** cmd1 = StrToChar(argv_v1);
  if(pid < 0){
    perror("Faield to fork");
    return;
  }else if(pid == 0){
    //child
    for(unsigned i = 0; i < argv_v1.size(); i++){
      if(strcmp(cmd1[i],"<") == 0){
	cntin = i;
	break;
      }
    }
    if(cntin != 0){
      if(cmd1[cntin+1] == NULL){
	printf("No file provided.\n");
	exit(EXIT_FAILURE);
      }
      int newin = open(cmd1[cntin+1],O_RDONLY);
      if(newin == -1){
	perror("Failed to open the file");
	exit(EXIT_FAILURE);
      }
      dup2(newin,STDIN_FILENO);
      close(newin);
    }
    dup2(pfd[1],STDOUT_FILENO);
    close(pfd[0]);
    int a = 0;
    if((a = execvp(cmd1[0], cmd1)) == -1){
      perror("Failed to execute");
      exit(EXIT_FAILURE);
    }
  }else{
    free(cmd1, argv_v1);
    return;
  }
}
