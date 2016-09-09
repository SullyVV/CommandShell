#include "myShell.h"

void single_pipe(std::vector<std::string> argv_v){
  int pid;
  int status;
  int pfd[2];
  pipe(pfd);
  std::vector<std::string> argv_v1(argv_v.begin(), std::find(argv_v.begin(),argv_v.end(),"|"));
  if(std::find(argv_v1.begin(), argv_v1.end(),">") != argv_v1.end()){
    std::cout << "error: > in left of pipe." << std::endl;
    return;
  }
  runcmd1(pfd,argv_v1);
  argv_v.erase(argv_v.begin(),++std::find(argv_v.begin(),argv_v.end(),"|"));
  std::vector<std::string> argv_v2(argv_begin, argv_v.end());
  if(std::find(argv_v2.begin(), argv_v2.end(), "|") == argv_v2.end()){
    if(std::find(argv_v2.begin(),argv_v2.end(),"<") != argv_v2.end()){
      std::cout << "error: < in right of pipe." << std::endl;
      return;
    }
    runcmd2(pfd,argv_v2);
    close(pfd[0]);
    close(pfd[1]);
    while((pid = wait(&status)) != -1){
      fprintf(stderr, "process %d exits with %d\n", pid, WEXITSTATUS(status));
    }
  }else{
    multiple_pipe(pfd,argv_v);
  }
}
