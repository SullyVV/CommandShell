#include "myShell.h"
//memory allocated here is cleaned up by free()
char ** StrToChar(std::vector<std::string> v){
  //char ** argv = new char * [v.size()];
  char ** argv = new char * [v.size() + 1];
  for(unsigned i = 0; i < v.size(); i++){
    argv[i] = new char [v[i].size()+1];
    strcpy(argv[i], v[i].c_str());
  }
  argv[v.size()] = NULL;
  return argv;
}
