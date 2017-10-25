#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

void* cari(void *arg){
	char c = (char) arg;
	char o[1000001];
	FILE *novel;
	novel=fopen("/tmp/Novel.txt", "r");
	char d;
	int e=0, i;
	while((d = fgets(o, 1000001, novel) != EOF)){
		int test = strcmp(c,o);
		if(test==0) e++;
	}
	printf("%s : %d\n", c, e);
}

int main(int argc, char *argv[]){
	int nilai[argc];
	pthread_t tid[argc];
	int i;
	int z;
	for(i=1; i<argc; i++){
		int v = atoi(argv[i]);
		z=pthread_create(&(tid[i]),NULL,&cari,(void*) v);
	}
	int j;
	for(j=argc; j>0; j--){
		pthread_join(tid[j],NULL);
	}
	return 0;
}
