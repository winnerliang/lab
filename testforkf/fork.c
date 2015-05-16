#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int glob = 6;
char buf[] = "a write to stdio";

int main(void )
{
	int var;
	pid_t pid;

	var =100;
	if((pid = fork())< 0)
	{
		printf("fork error!");
	}
	else if(pid == 0)
	{
		var++;
		glob++;
		printf("child process");
	}
	else
	{
		sleep(2);
		printf("parent process");
	}
	printf("pid = %d, glob= %d, var =%d", getpid(), glob, var);
}
