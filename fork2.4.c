#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void userInput(){
  char name[20];
  printf("Please enter your name: ");
  scanf("%[^\n]&*c",name);
  printf("Your name : %s \n", name);
  printf("\n");
}

void jobParent(){
 printf("JOB IS DONE \n");
}

int main(){
//name = userInput();
for (int i =0 ;i <4;i++){ 
   pid_t pid = fork();

   if (pid == 0){    	   
     //printf("Child process => PPID%d,PID=%d \n",getppid(),getpid());
     userInput();
     exit(0);
    }
   else {
     //printf("Parent process => PID=%d \n",getpid());
     //printf("Waiting for child processes to finish.... \n");
     wait(NULL);
   } 
 }
jobParent();  
return EXIT_SUCCESS;
}
