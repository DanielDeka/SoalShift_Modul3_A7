#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <string.h>

int main() { 

key_t key=1234; 
int shmid = shmget(key, 6*sizeof(int), IPC_EXCL); 
int* jmlSenjata = shmat(shmid, NULL, 0);

int pilihan;
printf("PILIH MENU :\n 1. Lihat STOCK Senjata (ketik LIHAT)\n 2. Beli STOCK Senjata (ketik TAMBAH)\n 3. STOP\n");

char namaSenjata[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};

while (pilihan!=3)
{
	pilihan=0;
	scanf("%d",&pilihan);
	if (pilihan==1){
		printf("MP4A1 %d\n",jmlSenjata[0]);
		printf("PM2-V1 %d\n",jmlSenjata[1]);
		printf("SPR-3 %d\n",jmlSenjata[2]);
		printf("SS2-V5 %d\n",jmlSenjata[3]);
		printf("SPG1-V3 %d\n",jmlSenjata[4]);
		printf("MINE %d\n",jmlSenjata[5]);
	}

	else if (pilihan==2){
		int a;
		char senjataDICARI[10];
		int jumlahDIBELI;
		scanf("%s", &senjataDICARI[10]);
		scanf("%d", &jumlahDIBELI);
		
			if (strcmp(senjataDICARI,"MP4A1")) {
				if ((jmlSenjata[0] -= jumlahDIBELI)<0)
				{ 
					printf("Barang di stock tidak cukup\n");
					jmlSenjata[0] += jumlahDIBELI;
				}
			}

			else if (strcmp(senjataDICARI,"PM2-V1")) {
				if ((jmlSenjata[1] -= jumlahDIBELI)<0)
				{ 
					printf("Barang di stock tidak cukup\n");
					jmlSenjata[1] += jumlahDIBELI;
				}
			}

			else if (strcmp(senjataDICARI,"SPR-3")) {
				if ((jmlSenjata[2] -= jumlahDIBELI)<0)
				{ 
					printf("Barang di stock tidak cukup\n");
					jmlSenjata[2] += jumlahDIBELI;
				}
			}

			else if (strcmp(senjataDICARI,"SS2-V5")) {
				if ((jmlSenjata[3] -= jumlahDIBELI)<0)
				{ 
					printf("Barang di stock tidak cukup\n");
					jmlSenjata[3] += jumlahDIBELI;
				}
			}

			else if (strcmp(senjataDICARI,"SPG1-V3")) {
				if ((jmlSenjata[4] -= jumlahDIBELI)<0)
				{ 
					printf("Barang di stock tidak cukup\n");
					jmlSenjata[4] += jumlahDIBELI;
				}
			}

			else if (strcmp(senjataDICARI,"MINE")) {
				if ((jmlSenjata[5] -= jumlahDIBELI)<0)
				{ 
					printf("Barang di stock tidak cukup\n");
					jmlSenjata[5] += jumlahDIBELI;
				}
			}

	}

	else printf("ERROR");
}

shmdt(jmlSenjata);
shmctl(shmid, IPC_RMID,NULL);
}
