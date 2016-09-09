myShell: main.cpp myShell.h printPrompt.cpp isExitCommand.cpp getPATH.cpp parser.cpp executeCommand.cpp Directories.cpp free.cpp redirection.cpp pipe_new.cpp runcmd2_new.cpp runcmd1_new.cpp pipe_helper.cpp PipeCmdChecker.cpp
	g++ -o myShell -ggdb3 -Wall -Werror -pedantic -std=gnu++98 main.cpp printPrompt.cpp isExitCommand.cpp getPATH.cpp parser.cpp executeCommand.cpp Directories.cpp StrToChar.cpp free.cpp redirection.cpp pipe_new.cpp pipe_helper.cpp runcmd1_new.cpp runcmd2_new.cpp PipeCmdChecker.cpp

clean:
	rm myShell *~