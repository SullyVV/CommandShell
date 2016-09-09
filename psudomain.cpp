
int main(int argc, char ** argc){
  while(1){
    int childpid;
    char * cmdLine;
    printPrompt;
    cmdLine = readCommandLine();
    cmd = parseCommand(cmdLine);
    record command in history list;
    if(isExitCommand(cmd)){
      exit;
    }
    if(isBuiltInCommand(cmd)){
      executeBuiltInCommand(cmd);
    }else{
      childpid = fork();
      if(childPid == 0){
	executeCommand(cmd);
      }else{
	if(isBackgroundJob(cmd)){
	  record in list of background job
	    }else{
	  waitpid(childpid);
	}
      }
    }
  }
}
