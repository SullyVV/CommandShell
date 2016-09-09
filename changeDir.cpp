#include "myShell.h"

void changeDir(char * dir){
  //1. absolute path
  //2. relative path
  int a = 0;
  if((dir[0] == '/') || (dir[0] == '.' && dir[1] == '.')){
    a = chdir(dir);
  }else{
    char cwd[512];
    getcwd(cwd,512);
    strcat(cwd,"/");
    strcat(cwd,dir);
    a = chdir(cwd);
  } 
  if(a != 0){
    std::cout << "Failed to change Directory." << std::endl;
  }
}
