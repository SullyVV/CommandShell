#include <errno.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <algorithm>
#include <fcntl.h>
#include <stdio.h>

extern char ** environ;
void printPrompt();
bool isExitCommand(char * cmdLine);
char * getPATH(char * cmdLine);
std::vector<std::string> parser(char * cmdLine);
void executeCommand(char * cmd, std::vector< char *> & dir_stack);
char ** StrToChar (std::vector<std::string>);
void changeDir(char * dir);
void pushd(char * dir, std::vector< char *> &v);
void popd(std::vector< char *>&v);
void dirstack(std::vector< char *> &v);
void free(char ** argv, std::vector<std::string> &argv_v);
void redirection(char ** v,std::vector<std::string> &argv_v);
//void pipe(std::vector<std::string> argv_v);
//void runcmd1(int pfd[], std::vector<std::string> argv_v1);
//void runcmd2(int pfd[], std::vector<std::string> argv_v2);

void pipe_new(std::vector<std::string> argv_v);
void pipe_helper(int oldpipe[], std::vector<std::string> argv);
void runcmd1_new(std::vector<std::string> argv_v1, int newpipe[], int oldpipe[]);
void runcmd2_new(std::vector<std::string> argv_v2, int newpipe[]);
bool PipeCmdChecker(std::vector<std::string> argv_v);

