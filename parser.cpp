#include "myShell.h"
std::vector<std::string> parser(char * cmdLine){
  std::vector<std::string> v;
  std::string s;
  char * ptr = cmdLine;
  while(*ptr != '\0'){
    if(*ptr == ' '){
      if(s == ""){
          ptr++;
      }else{
          v.push_back(s);
          s = "";
      }
    }else{
      if(*ptr == '\\'){
          ptr++;
          if(*ptr == ' '){
              s.push_back(*ptr);
              ptr++;
          }else{
              s.push_back(*(--ptr));
          }
      }else{
          s.push_back(*ptr);
          ptr++;
      }
    } 
  }
  if(s != ""){
    v.push_back(s);
  }
  return v;
}	  
