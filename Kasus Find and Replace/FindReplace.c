/*  
>>>>>  PROGRAM FIND AND REPLACE WORD IN A FILE  <<<<<
Input 	: 	Sebuah file Teks
			Kata yang akan diganti
			Kata pengganti
Output 	: 	Teks baru dengan kata tertentu telah diganti oleh kata baru, simpan ke file teks

		DISUSUN OLEH 
ALEX SINAGA        ( 191524033 ) 		| 	1B - D4  2020
SALMAN SHALAHUDDIN ( 191524059 )		| TEKNIK INFORMATIKA

	    	TUGAS BESAR
MATA KULIAH STRUKTUR DATA ALGORITMA 

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coord.h"
#define FILE_MAX_WORD 1000

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// FUNCTION LIST
void replaceKata(char *teks, const char *oldWord, const char *newWord);
void findReplace();
void tataCara();
void keterangan();
void tentangKami();

//VARIABLE
FILE * filePointer;
FILE * fileTemp;

char file[FILE_MAX_WORD];
char oldWord[50], newWord[50];

int counterJumlahKata;

// MAIN CLASS
int main() {	
	int menu;
	do{
			printf("|------------------------------------------|\n");
			printf("|      FIND & REPLACE WORD IN A FILE       |\n");
			printf("|------------------------------------------|\n");
			printf("|1. Find & Replace                         |\n");                       
			printf("|2. Tata Cara                              |\n");
			printf("|3. Keterangan                             |\n");
			printf("|4. Tentang Kami                           |\n");
			printf("|0. Exit                                   |\n");
			printf("|------------------------------------------|\n");
			printf("|Masukkan Pilihan :                        |\n");
			printf("|------------------------------------------|\n");	
			gotoxy(20,9); scanf("%d", &menu);
			
			switch(menu){
				case 1 :
					findReplace();
					break;
					
				case 2 :
					tataCara();
					break;		
				
				case 3 :
					keterangan();
					break;			
				
				case 4 :
					tentangKami();
					break;						
							
				case 0 :
					system("exit");
					break;
			}
			system("cls");
		}while (menu != 0);

    return 0;
}

//FUNGSI PROSES UNTUK MENIMPA SEMUA KATA SESUAI INPUT
void replaceKata(char *teks, const char *oldWord, const char *newWord) {
	char *kataYangDiganti, temp[FILE_MAX_WORD];
	int index = 0;
	int oldWordLength;
	
	oldWordLength = strlen(oldWord);
	
	//PERULANGAN MENIMPA SETIAP KATA
	while ((kataYangDiganti = strstr(teks, oldWord)) != NULL) {
		
		//COUNTER KATA YANG DITIMPA
	    if(strstr(teks, oldWord)){
	    	counterJumlahKata++;
		}
		
	    //TEMPORARY VARIABLE UNTUK MENAMPUNG TEKS DALAM FILE
	    strcpy(temp, teks);
	
	    //INDEKS KETIKA KATA YANG DICARI DITEMUKAN
	    index = kataYangDiganti - teks;
	
	    //MENGHENTIKAN PEMBACAAN FILE TEKS DENGAN INDEKS 'index'
	    teks[index] = '\0';
	
	    //MENAMBAHKAN KATA PENGGANTI KE DALAM TEKS FILE
	    strcat(teks, newWord);
	        
	    // MENAMBAHKAN SETIAP KATA SETELAH KATA YANG DIGANTI
	    strcat(teks, temp + index + oldWordLength);
	}

}

// MENU FIND AND REPLACE ( 1 )
void findReplace(){
	char path[50];
	
	system("cls");
	printf("|----------------------------------------------------------------------|\n");
	printf("|                            FIND AND REPLACE                          |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|                   Guide                  |        Your Input         |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|1. Masukkan alamat dan/atau nama file     |                           |\n");  
	printf("|                                          |                           |\n");
	printf("|2. Masukkan kata yang ingin diganti       |                           |\n"); 
	printf("|                                          |                           |\n");
	printf("|3. Masukkan kata pengganti                |                           |\n");
	printf("|                                          |                           |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("| Notifikasi :                                                         |\n");
	printf("|----------------------------------------------------------------------|\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|                                                                      |\n");
	printf("|----------------------------------------------------------------------|\n");		

		// INPUT NAMA FILE
		gotoxy(45, 5); printf(">"); gotoxy(47,5); scanf("%s", path); 
		
	    //OPEN FILE DENGAN INPUT path
	    filePointer  = fopen(path, "r");
	    
	    // PROSES JIKA FILE KOSONG ATAU TIDAK DITEMUKAN
	    if (filePointer == NULL) {
	        gotoxy(15, 12); printf("File Tidak Ditemukan.");
	        gotoxy(2, 14); printf("Akan kembali ke menu...");
			gotoxy(2, 17); system("pause"); system("cls");
			main();
	    }
	    
	    // INPUT KATA YANG INGIN DIGANTI
	    gotoxy(45, 7); printf(">"); gotoxy(47,7); scanf("%s", oldWord); 
	    
	    // INPUT KATA PENGGANTI
	    gotoxy(45, 9); printf(">"); gotoxy(47,9); scanf("%s", newWord); 
	    
	    // MEMBUAT FILE TEMPORARY UNTUK MENAMPUNG TEKS FILE ASLI KEMUDIAN
	    fileTemp = fopen("file.tmp", "w"); 
	    
	    while ((fgets(file, FILE_MAX_WORD, filePointer)) != NULL) {
	        // MENIMPA SETIAP KATA SESUAI INPUT
	        replaceKata(file, oldWord, newWord);
	
	        // SETELAH SELESAI MENIMPA SETIAP KATA SESUAI INPUT , DIPINDAHKAN KE FILE TEMPORARY
	        fputs(file, fileTemp);
	    }
	
	    // CLOSE FILE
	    fclose(filePointer);
	    fclose(fileTemp);
	    
	    // DELETE ORIGINAL SOURCE FILE
	    remove(path);
	
	    // FILE TEMPORARY DIUBAH MENJADI FILE TEKS ASLI DENGAN MENGUBAH NAMA FILE TEMPORARY PERSIS SEPERTI FILE ASLI SEBELUMNYA
	    rename("file.tmp", path);
		
		gotoxy(15, 12); printf("Kata sukses diganti.");
	    gotoxy(2, 14); printf("Semua kata '%s' (terdapat %d)", oldWord, counterJumlahKata);
	    gotoxy(2, 15); printf("Telah diganti menjadi '%s'", newWord);
	    gotoxy(2, 17); system("pause");
}

// MENU TATA CARA ( 2 )
void tataCara(){
	system("cls");
	printf("|------------------------------------------|\n");
	printf("|        TATA CARA MEMAKAI PROGRAM         |\n");
	printf("|------------------------------------------|\n");
	printf("|1. Masukkan Alamat dan Nama File          |\n");                       
	printf("|   Contoh: namaFolder/namaFile.txt        |\n");
	printf("|                                          |\n");
	printf("|2. Jika file terdapat di folder sama      |\n");
	printf("|   dengan file program, cukup ketikkan    |\n");
	printf("|   nama filenya saja (namaFile.txt)       |\n");
	printf("|                                          |\n");
	printf("|3. Masukkan kata yang ingin diganti       |\n");
	printf("|                                          |\n");
	printf("|4. Masukkan kata ganti                    |\n");
	printf("|                                          |\n");
	printf("|5. Selesai                                |\n");
	printf("|------------------------------------------|\n");
	system("pause");	
}	

// MENU KETERANGAN ( 3 )
void keterangan(){
	system("cls");
	printf("|------------------------------------------|\n");
	printf("|                KETERANGAN                |\n");
	printf("|------------------------------------------|\n");
	printf("|1. Pencarian kata bersifat Case Sensitive |\n"); 
	printf("|                                          |\n");
	printf("|2. Jika melakukan replace sebuah kata     |\n");
	printf("|   maka seluruh kata yang sama dalam file |\n");
	printf("|   akan terganti                          |\n");
	printf("|                                          |\n");
	printf("|3. Program akan menampilkan jumlah kata   |\n");
	printf("|   tersebut                               |\n");
	printf("|------------------------------------------|\n");
	system("pause");	
}

// MENU TENTANG KAMI ( 4 )
void tentangKami(){
	system("cls");
	printf("|------------------------------------------|\n");
	printf("|               TENTANG KAMI               |\n");
	printf("|------------------------------------------|\n");
	printf("|         KELOMPOK 9 KELAS 1B - D4         |\n");
	printf("|------------------------------------------|\n");
	printf("|                                          |\n");
	printf("|1. Alex Sinaga (191524033)                |\n"); 
	printf("|                                          |\n");
	printf("|2. Salman Shalahuddin (191524059)         |\n");
	printf("|                                          |\n");
	printf("|------------------------------------------|\n");
	system("pause");	
}
