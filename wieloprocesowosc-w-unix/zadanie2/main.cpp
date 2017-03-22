#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int liczbaDzieci = 0;
int drzewo(int dzieci){

	int pid = fork();
	
	if(pid == 0){
		printf( "Proces: %d           Rodzic: %d\n",  getpid(), getppid() );
		if(dzieci>0){
			printf( "dzieci: %d\n",dzieci);
			if(dzieci >0){
				drzewo(dzieci -1);
			}
			 
		} else {
			sleep(10);
		}
		
		
	} else {
		int p2 = fork();
		if(p2 == 0){
			if(dzieci >0){
				drzewo(dzieci -1);
			}
			if(dzieci == 0) {
			sleep(10);
			}
		} else {
			waitpid( pid, NULL, 0 );
			waitpid( p2, NULL, 0 );		
		}
		return 0;
	}
	printf( "Proces %d kończy działanie\n",getpid());
	return pid;
}

int main(){
	printf( "\n\n\n\n");
	drzewo(3);
}
