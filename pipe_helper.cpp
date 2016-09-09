#include "myShell.h"

void pipe_helper(int oldpipe[], std::vector<std::string> argv_v){
  if(std::find(argv_v.begin(), argv_v.end(),"|") != argv_v.end()){
    int newpipe[2] = {0};
    pipe(newpipe);
    std::vector<std::string> argv_v1(argv_v.begin(), std::find(argv_v.begin(),argv_v.end(),"|"));
    argv_v.erase(argv_v.begin(),++std::find(argv_v.begin(),argv_v.end(),"|"));
    std::vector<std::string> argv_v2(argv_v.begin(), argv_v.end());

    runcmd1_new(argv_v1, newpipe, oldpipe);
    if(oldpipe[0] != 0 && oldpipe[1] != 0){
      close(oldpipe[0]);
      close(oldpipe[1]);
    }
    if(std::find(argv_v2.begin(), argv_v2.end(),"|") != argv_v2.end()){
      pipe_helper(newpipe, argv_v2);
    }else{
      runcmd2_new(argv_v2, newpipe);
    }
    close(newpipe[0]);
    close(newpipe[1]);
  }
}
