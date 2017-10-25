#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void* faktorijal(void *jal)
{
 int jaljal = (int) jal;
 int b;
 int c=1;
 for (b=jaljal;b>0;b--) c*=b;
 printf(" %d! = %d\n",jaljal,c);
}

int main (int argc, char** argv)
{
 int nilai[argc];
 pthread_t threadid[argc];
 int a;
 int status;
 for (a=1;a<argc;a++)
 {
 int apajal = atoi(argv[a]);
 pthread_create(&(threadid[a]),NULL,&faktorijal,(void*) apajal);
 }

 for (a = argc; a>0; a--) pthread_join(threadid[a],NULL);

 exit(EXIT_SUCCESS);

}
