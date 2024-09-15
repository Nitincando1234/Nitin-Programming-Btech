#include<stdio.h>
#include<unistd.h>	// for others like getpid() :)
#include<stdlib.h>	// for exit()
#include <sys/wait.h>	// for waitpid()
#include <sys/types.h>	// for pid_t
int main(){
	pid_t pid_child[3], pid_wait;
	int status = 0;
	printf("\nCreating 3 Child Processes !\n");

	for(int i = 0; i < 3; i++){
		pid_child[i] = fork();
		printf("\nChild Process pid: %ld", (long)getpid());
		if(pid_child[i] < 0){
			printf("\nChild Process Creation Failed !\n");
			exit(-1);
		}
		else if(pid_child[i] == 0){
			printf("\nChild Process with pid: %ld and parent's pid: %ld\n", (long)getpid(), (long)getppid());
            sleep(2);
			exit(0);
		}
		else{
			printf("\nParent process with pid: %ld\n", (long)getpid());
			sleep(2);
		}
	}
	for(int i = 0; i < 3; i++){
		pid_wait = waitpid(pid_child[i], &status, 0);

		if(pid_wait == -1) printf("\nFailed to Wait !\n");
		else if(WIFEXITED(status)){
			printf("\nChild process with pid: %ld exited !\n", (long)pid_wait);
		}
		else{
			printf("\nChild process exited abnormally !\n");
		}
	}
	sleep(2);
	printf("\n\n\nExiting main !!!\n\n");

}
