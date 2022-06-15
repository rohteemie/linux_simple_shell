#include "shell.h"
#include <unistd.h>
#include <stdio.h>
 
/*call_cmd funtion returnType of int changed to void*/
void call_cmd(char *prog, char **args)
{
	execve(prog, args, NULL);
	perror("./shell");
}

/* i just did add a return of zero to main. */
int main()
{
	char *args[] = {"/bin/sh", NULL};
	call_cmd(args[0], args);

	return (0);
}
