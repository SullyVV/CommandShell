#include "myShell.h"

void changeDir(char * dir){
  //1. absolute path
  //2. relative path
  int a = 0;
  
  if((dir[0] == '/') || (dir[0] == '.' && dir[1] == '.')){
    if((a = chdir(dir)) != 0){
      perror("Failed to change Directory");
      return;
    };
  }else{
    char cwd[512];
    getcwd(cwd,512);
    strcat(cwd,"/");
    strcat(cwd,dir);
    if((a = chdir(cwd)) != 0){
      perror("Failed to change Directory");
      return;
    };
  } 
}

void pushd(char * dir, std::vector<char *> &v){
  
  char * old_dir = new char[512];
  getcwd(old_dir,512);
  v.push_back(old_dir);
  old_dir = NULL;
  changeDir(dir);
}

void popd(std::vector< char *>&v){
  if(v.empty()){
    std::cout << "empty directory stack" << std::endl;
    return;
  }else{
    char * dir = v.back();
    chdir(dir);
    delete[] dir;
    v.pop_back();
  }
}

void dirstack(std::vector<char *> &v){
  std::vector<char *>::iterator it = v.begin();
  if(it == v.end()){
    std::cout << "empty directory stack" << std::endl;
    return;
  }
  while(it != v.end()){
    std::cout << *it << std::endl;
    ++it;
  }
}

