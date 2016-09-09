#include "myShell.h"
char *  getPATH(char * cmdLine){
  char * currentPath = getenv("PATH");
  
  char * pch;
  pch = strtok(currentPath, ":");
  std::vector<char *> v;
  v.push_back(pch);
  while(pch != NULL){
    pch = strtok(NULL, ":");
    if(pch != NULL){
      v.push_back(pch);
    }
  }
  char currentdir[512];
  getcwd(currentdir,512);
  for(std::vector<char *>::iterator it = v.begin(); it != v.end(); it++){
    struct stat statbuffer;
    DIR * dp; //pointer to dir stream
    struct dirent * entry; //next entry
    char * dir = *it;
    if((dp = opendir(dir)) == NULL){
      continue;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL){
      if(lstat(entry->d_name, &statbuffer) != 0){
	continue;
      }
      if(S_IFDIR & statbuffer.st_mode){
	continue;
      }
      std::string str(entry->d_name);
      std::string str2(cmdLine);
      if(str == str2){
	char fullpath[512];
	getcwd(fullpath,512);
	strcat(fullpath, "/");
	strcat(fullpath, entry->d_name);
	chdir(currentdir);
	std::string str(fullpath);
	char * ch = strdup(str.c_str());
	return ch;
      }
    }
     closedir(dp);
  }
  chdir(currentdir);
  std::cout << "Command " << cmdLine << " not found" << std::endl;
  return NULL;
}
