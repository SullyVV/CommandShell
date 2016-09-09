#include "myShell.h"

bool isExitCommand(char * cmdLine){
  if(strcmp(cmdLine,"") != 0){
    std::vector<std::string> cmd = parser(cmdLine);
    if(!cmd.empty()){
      if(cmd[0]  == "exit" ){
          return true;
      }
      return false;
    }
  }
  return false;
}
