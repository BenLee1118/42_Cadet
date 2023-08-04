#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int signal)
{	
	static int i;
	static char c;


	if (signal == SIGUSR1)
	{
		c += (1 << i);
		i++;
	}
	if (signal == SIGUSR2)
		i++;
	if (i == 8)
	{
		putchar(c);
		i = 0;
		c = 0;
	}
}

int main(void)
{
	int pid;
	char c;
	int c = 65;
	int a = 0;
	int b = 0;
	int i = 0;
	a += (1 << 6); //00000000 + 01000000 = 01000000
	a += (1 << 0); //01000000 + 00000001 = 	01000001
											10000000	
	

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	
	while(1)
	{
	}
}