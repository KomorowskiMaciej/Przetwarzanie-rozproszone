#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


/*


	Do wyświetlenia drzewa procesu ----ps -u mac -l --forest


*/

int main(){


    int pid = fork();
    if(pid ==0){
        printf("potomny1 pid:%d ppid:%d\n", getpid(), getppid());
        int pid2 = fork();

        if(pid2 ==0){
            printf("potomny2 pid:%d ppid:%d\n", getpid(), getppid());
            int pid5 = fork();
            if(pid5 ==0){
                printf("potomny5 pid:%d ppid:%d\n", getpid(), getppid());
                sleep(10);
                return 0;
            } else {
                waitpid(pid5, NULL,0);
                return 0;
            }
        } else {
            int pid4= fork();

            if(pid4 ==0){
                printf("potomny4 pid:%d ppid:%d\n", getpid(), getppid());
                sleep(10);
                return 0;
            } else {
                waitpid(pid4, NULL,0);
                waitpid(pid2, NULL,0);
                return 0;
            }
        }
    } else {
        printf("macierzysty pid:%d ppid:%d\n", getpid(), getppid());
        int pid3 = fork();

        if(pid3 ==0){
            printf("potomny3 pid:%d ppid:%d\n", getpid(), getppid());
            sleep(10);
            return 0;
        } else {
        	int pid6 = fork();

	        if(pid6 ==0){
	                printf("potomny6 pid:%d ppid:%d\n", getpid(), getppid());
	                int pid7 = fork();
	                if(pid7 == 0){
	                	printf("potomny7 pid:%d ppid:%d\n", getpid(), getppid());
	                	sleep(10);
	                	return 0;	
	                } else {
	                	waitpid(pid7, NULL,0);
	                	return 0;
	            	}
	            	return 0;
	        } else {
	        	waitpid(pid6,NULL,0);
	        	waitpid(pid3,NULL,0);
	        	waitpid(pid,NULL,0);
	            printf("skonczyl\n");
	            return 0;
	        }

		}

    }
}
