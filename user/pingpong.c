#include "kernel/types.h"
#include "user/user.h"

int main(){
	int p1[2];
	int p2[2];
	pipe(p1);
	pipe(p2);

	if(fork() == 0){		
		read(p1[0],"ping\n",5);
		printf("%d: received ping\n",getpid());
		write(p2[1],"pong\n",5);
		close(p1[0]);
		close(p2[1]);
		exit();
	}
	write(p1[1],"ping\n",5);
	read(p2[0],"pong\n",5);
	printf("%d: received pong\n",getpid());
	close(p1[1]);
	close(p2[0]);
	wait();
	exit();
}