#include "myShell.h"

void runcmd1_new(std::vector<std::string> argv_v1 , int newpipe[], int oldpipe[]){
  int pid;
  char ** cmd1 = StrToChar(argv_v1);
  pid = fork();
  if(pid < 0){
    perror("Failed to fork");
    return;
  }else if(pid == 0){
    //stdin replaced by read end of pipe
    if(oldpipe[0] != 0){
      dup2(oldpipe[0], STDIN_FILENO);
      close(oldpipe[1]);
    }
    //STDIN replace by a file
    if(oldpipe[0] == 0 && oldpipe[1] == 0){
      int cntin = 0;
      //IF it's the first program of cmd
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
    }
    dup2(newpipe[1], STDOUT_FILENO);
    close(newpipe[0]);
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
