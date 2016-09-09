#include "myShell.h"

bool PipeCmdChecker(std::vector<std::string> argv_v){
  
  std::vector<std::string> argv_v1(argv_v.begin(), std::find(argv_v.begin(),argv_v.end(),"|"));
  if(std::find(argv_v1.begin(), argv_v1.end(),">") != argv_v1.end()){
    std::cout << "error: > in first program in pipe." << std::endl;
    return false;
  }
  argv_v.erase(argv_v.begin(),++std::find(argv_v.begin(),argv_v.end(),"|"));
  std::reverse(argv_v.begin(), argv_v.end());
  std::vector<std::string> argv_v2(argv_v.begin(), std::find(argv_v.begin(),argv_v.end(),"|"));
  if(std::find(argv_v2.begin(), argv_v2.end(),"<") != argv_v2.end()){
    std::cout << "error: < in last program in pipe." << std::endl;
    return false;
  }
  if(std::find(argv_v.begin(),argv_v.end(),"|") != argv_v.end()){
    argv_v.erase(argv_v.begin(),++std::find(argv_v.begin(),argv_v.end(),"|"));
    if((std::find(argv_v.begin(),argv_v.end(),"<") != argv_v.end()) || (std::find(argv_v.begin(), argv_v.end(), ">") != argv_v.end())){
      std::cout << "error: redirection in middle programs of pipe." << std::endl;
      return false;
    }
  }
  return true;
}
