#include "myShell.h"

void printPrompt(){
  char cwd[256];
  getcwd(cwd, 256);
  std::cout << "myShell:" << cwd << " $ " ;
}
