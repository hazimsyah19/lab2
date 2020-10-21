#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char **argv){
	int pid;


	switch(pid = fork()){
	
		case 0:
			printf("I am the child process: %d \n",getpid());
			break;

		default:
			printf("I am the parent process: %d \n",getpid());
			break;

		case -1:
			perror("fork");
			exit(1);
	}
	exit(0);
}
