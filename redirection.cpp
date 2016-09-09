#include "myShell.h"
void redirection(char ** argv, std::vector<std::string> &argv_v){
        //stdin
      unsigned cntin = 0;
      for(unsigned i = 0; i < argv_v.size(); i++){
	if(strcmp(argv[i],"<") == 0){
	  cntin = i;
	  break;
	}
      }
      if(cntin != 0){
	if(argv[cntin+1] == NULL){
	  printf("No file provided.\n");
	  //free(argv,argv_v);
	  exit(EXIT_FAILURE);
	  }
	int newin = open(argv[cntin+1], O_RDONLY);
	if(newin == -1){
	  perror("Failed to open the file");
	  // free(argv,argv_v);
	  exit(EXIT_FAILURE);
	}
	int a = 0;
	if((a = dup2(newin,STDIN_FILENO)) == -1){
	  perror("Failed to duplicate the file descriptor");
	  //free(argv,argv_v);
	  exit(EXIT_FAILURE);
	}
	close(newin);
      }
      
      
      //stdout
      unsigned cntout = 0;
      for(unsigned i = 0; i < argv_v.size(); i++){
	if(strcmp(argv[i], ">") == 0){
	  cntout = i;
	  break;
	}
      }
      if(cntout != 0){
	if(argv[cntin+1] == NULL){
	  printf("No file provided.\n");
	  //free(argv,argv_v);
	  exit(EXIT_FAILURE);
	 }
	int newout = open(argv[cntout+1], O_WRONLY|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);
	if(newout == -1) {
	  perror("Failed to open the file");
	  //free(argv, argv_v);
	  exit(EXIT_FAILURE);
	}
	int a = 0;
	if((a = dup2(newout, STDOUT_FILENO)) == -1){
	  perror("Failed to duplicate the file descriptor");
	  //free(argv,argv_v);
	  exit(EXIT_FAILURE);
	}
	close(newout);
      }
      //stderr
      unsigned cnterr = 0;
      for(unsigned i = 0; i < argv_v.size(); i++){
	if(strcmp(argv[i], "2>") == 0){
	  cnterr = i;
	  break;
	}
      }
      if(cnterr != 0){
	if(argv[cntin+1] == NULL){
	  printf("No file provided.\n");
	  //free(argv,argv_v);
	  exit(EXIT_FAILURE);
	 }
	int newerr = open(argv[cntout+1], O_WRONLY|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);
	if(newerr == -1){
	  perror("Failed to open the file");
	  //free(argv, argv_v);
	  exit(EXIT_FAILURE);
	}
	int a = 0;
	if((a = dup2(newerr,STDERR_FILENO)) == -1){
	  perror("Failed to duplicate the file descriptor");
	  //free(argv,argv_v);
	  exit(EXIT_FAILURE);
	} 
	close(newerr);
      }
}
