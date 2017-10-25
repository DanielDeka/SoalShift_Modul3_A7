#include <stdio.h>
#include <pthread.h>

int statusKepiting=100,statusLohan=100;

void fungsiKepiting(void *tambahKepiting)
{
 while (1)
 {
  sleep (20);
  statusKepiting -= 10;
  
  if (statusKepiting<=0 || statusKepiting>100)
  {
   goto : selesai;
   break;
  }
 }
}

void fungsiLohan(void *tambahLohan)
{
 while (1)
 {
  sleep (10);
  statusLohan -= 15;
  
  if (statusLohan<=0 || statusLohan>100)
  {
   goto : selesai;
   break;
  }
 }
}

void fungsiCek(void *tambahCek)
{
 while(1)
 {
  sleep(5);
  printf("STATUS KEPITING = %d\n",statusKepiting);
  printf("STATUS LOHAN = %d\n",statusLohan);
 }
}

int main ()
{
 int pilihan;
 int tambahKepiting = 10;
 int tambahLohan = 10;
 pthread_t threadKepiting,threadLohan,threadCek;

 pthread_create(&(threadKepiting),NULL,&fungsiKepiting,(void*) statusKepiting);
 pthread_create(&(threadLohan),NULL,&fungsiLohan,(void*) statusLohan);
 pthread_create(&(threadCek),NULL,&fungsiCek,(void*) cek);
 pthread_join(threadKepiting,NULL);
 pthread_join(threadLohan,NULL);
 pthread_join(threadCek,NULL);

 while (1)
 {
  printf("1. Beri makan LOHAN\n2. Beri makan KEPITING\n");
  scanf ("%d",&pilihan);

  if (pilihan==1)
  {
   statusLohan += tambahLohan;
  }

  if (pilihan==2)
  {
   statusKepiting += tambahKepiting;
  }
 }

 selesai :
 printf("GAME BERAKHIR\n");
}
