#include "myShell.h"
int main(int argc, char ** argv){
  std::vector<char *>dir_stack;
  while(1){
    printPrompt();
    char cmdLine[256];
    std::cin.getline(cmdLine, 256);
    if(isExitCommand(cmdLine) || std::cin.eof()){
      std::cout << "exit" << std::endl;
      /**************************************************/
      //free the memory allocated in dir_stack
      if(!dir_stack.empty()){
          for(unsigned i = 0; i < dir_stack.size();i++){
              delete [] dir_stack[i];
          }
      }
      /**************************************************/
      return EXIT_SUCCESS;
    }
    executeCommand(cmdLine, dir_stack);
  }
}
