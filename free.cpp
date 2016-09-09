#include "myShell.h"
void free(char ** argv, std::vector<std::string> & argv_v){
  //free the memory allocated in child process;
  //1. for argv[i] 2.argv (whose size can be obtained from argv_v)
  unsigned size = argv_v.size();
  for(unsigned i = 0; i < size; i++){
    delete []  argv[i];
  }
  delete [] argv;
}
