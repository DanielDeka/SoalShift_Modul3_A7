#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <string.h>

void nambahSENJATA();
int main() { 

key_t key=1234; 
int shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666); 
int* jmlSenjata = (int*)shmat(shmid, NULL, 0);

int pilihan;
printf("PILIH MENU :\n 1. Lihat STOCK Senjata (ketik LIHAT)\n 2. Tambah STOCK Senjata (ketik TAMBAH)\n 3. STOP\n");

char namaSenjata[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};

while (pilihan!=3)
{
	pilihan=0;
	scanf("%d",&pilihan);
	if (pilihan==1){
		if(jmlSenjata[0]>0) printf("MP4A1 %d\n",jmlSenjata[0]);
		if(jmlSenjata[1]>0) printf("PM2-V1 %d\n",jmlSenjata[1]);
		if(jmlSenjata[2]>0) printf("SPR-3 %d\n",jmlSenjata[2]);
		if(jmlSenjata[3]>0) printf("SS2-V5 %d\n",jmlSenjata[3]);
		if(jmlSenjata[4]>0) printf("SPG1-V3 %d\n",jmlSenjata[4]);
		if(jmlSenjata[5]>0) printf("MINE %d\n",jmlSenjata[5]);
	}

	else if (pilihan==2){
		int a;
		char senjataDICARI[10];
		int jumlahDITAMBAH;
		scanf("%s", &senjataDICARI[10]);
		scanf("%d", &jumlahDITAMBAH);
		
			if (strcmp(senjataDICARI,"MP4A1")) jmlSenjata[0] += jumlahDITAMBAH;
			else if (strcmp(senjataDICARI,"PM2-V1")) jmlSenjata[1] += jumlahDITAMBAH;
			else if (strcmp(senjataDICARI,"SPR-3")) jmlSenjata[2] += jumlahDITAMBAH;
			else if (strcmp(senjataDICARI,"SS2-V5")) jmlSenjata[3] += jumlahDITAMBAH;
			else if (strcmp(senjataDICARI,"SPG1-V3")) jmlSenjata[4] += jumlahDITAMBAH;
			else if (strcmp(senjataDICARI,"MINE")) jmlSenjata[5] += jumlahDITAMBAH;
	}

	else printf("ERROR");
}

shmdt(jmlSenjata);
shmctl(shmid, IPC_RMID, NULL);
	
}
