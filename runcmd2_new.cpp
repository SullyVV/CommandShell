#include "myShell.h"

void runcmd2_new(std::vector<std::string> argv_v2, int newpipe[]){
  int pid;
  pid = fork();
  char ** cmd2 = StrToChar(argv_v2);
  if(pid < 0){
    perror("Failed to fork");
    return;
  }else if(pid == 0 ){
    int cntout = 0;
    for(unsigned i = 0; i < argv_v2.size(); i++){
      if(strcmp(cmd2[i],">") == 0){
	cntout = i;
	break;
      }
    }
    if(cntout != 0){
      if(cmd2[cntout+1] == NULL){
	printf("No file provided.\n");
	exit(EXIT_FAILURE);
      }
      int newout = open(cmd2[cntout+1], O_WRONLY|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);
      if(newout == -1){
	perror("Failed to open the file");
	exit(EXIT_FAILURE);
      }
      dup2(newout,STDOUT_FILENO);
      close(newout);
    }
    dup2(newpipe[0],STDIN_FILENO);
    close(newpipe[1]);
    int a = 0;
    if((a = execvp(cmd2[0], cmd2)) == -1){
      perror("Failed to execute");
      exit(EXIT_FAILURE);
    }
  }
  else{
    free(cmd2, argv_v2);
    return;
  }
}
