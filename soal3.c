#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int statusKepiting=100,statusLohan=100;

void fungsiKepiting(void *tambahKepiting)
{
	while (1)
	{
		sleep (20);
		statusKepiting -= 10;
	}
}

void fungsiLohan(void *tambahLohan)
{
	while (1)
	{
		sleep (10);
		statusLohan -= 15;
	}
}

void fungsiCek(void* terserah)
{
	while(1)
	{
		sleep(5);
		system("clear");
		printf("STATUS KEPITING = %d\n",statusKepiting);
		printf("STATUS LOHAN = %d\n",statusLohan);
		printf("Press any key to feed");
	}
}

void fungsiMain()
{
	int pilihan;
	int tambahKepiting = 10;
	int tambahLohan = 10;
	printf("PILIH ANGKA!!!\n1. Beri makan LOHAN\n2. Beri makan KEPITING\n");
	scanf ("%d",&pilihan);
	while (1)
	{
		printf("1. Beri makan LOHAN\n2. Beri makan KEPITING\n");
		scanf ("%d",&pilihan);

		if (pilihan==1)
		{
			statusLohan += tambahLohan;
			fungsiCek(NULL);
		}

		else if (pilihan==2)
		{
			statusKepiting += tambahKepiting;
			fungsiCek(NULL);
		}

		if (statusKepiting<=0 || statusKepiting>100) break;
		if (statusLohan<=0 || statusLohan>100) break;		
	}

	printf("GAME BERAKHIR\n");
	exit ();
}

int main ()
{
	pthread_t threadKepiting,threadLohan,threadCek,threadMain;

	pthread_create(&(threadKepiting),NULL,&fungsiKepiting,(void*) statusKepiting);
	pthread_create(&(threadLohan),NULL,&fungsiLohan,(void*) statusLohan);
	pthread_create(&(threadCek),NULL,&fungsiCek,NULL);
	pthread_create(&(threadMain),NULL,&fungsiMain,NULL);
	pthread_join(threadMain,NULL);
	pthread_join(threadKepiting,NULL);
	pthread_join(threadLohan,NULL);
	pthread_join(threadCek,NULL);

	return 0;
}
