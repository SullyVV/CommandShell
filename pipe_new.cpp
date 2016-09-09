#include "myShell.h"

void pipe_new(std::vector<std::string> argv_v){
  int pid;
  int status;
  int oldpipe[2] = {0};
  if(PipeCmdChecker(argv_v)){
    pipe_helper(oldpipe, argv_v);
    while((pid = wait(&status)) != -1){
      //not report the status of each programs in pipe.
      /*
      if(WIFEXITED(status)){
	//child process exit normally
	int exit = WEXITSTATUS(status);
	std::cout << "Program exited with status " << exit << std::endl;
      }else{
	//child process exit by some signals
	if(WIFSIGNALED(status)){
	  int signal = WTERMSIG(status);
	  std::cout << "Program was killed by signal " << signal << std::endl;
	}
      }
      */
    }
  }
}
