#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){
void parentTask(){
  printf("JOB IS DONE");
}
for (int i =0 ;i <5;i++){
   pid_t pid = fork();
   char str[20];

   if (pid == 0){
     printf("Child process => PPID%d,PID=%d \n",getppid(),getpid());
     exit(0);
    }
   else if(i == 3){
   printf("Enter your name");
   scanf("%[^\n]%*c",str);
   printf("Your name is %s\n",str);
   }
   else {
     printf("Parent process => PID=%d \n",getpid());
     printf("Waiting for child processes to finish.... \n");
     wait(NULL);
     printf("child process finished \n");
   }
 }
return EXIT_SUCCESS;
}
