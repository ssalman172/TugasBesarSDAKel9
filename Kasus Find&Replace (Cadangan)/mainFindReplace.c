#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coord.h"
#include "FindReplace.h"

#define FILE_MAX_WORD 1000

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int counterJumlahKata;
int main() {
	int menu;
	
	do{
			printf("|------------------------------------------|\n");
			printf("|               FIND & REPLACE             |\n");
			printf("|------------------------------------------|\n");
			printf("|1. Case Sensitive Find & Replace          |\n");                       
			printf("|2. Case Insensitive Find & Replace        |\n");
			printf("|0. Exit                                   |\n");
			printf("|------------------------------------------|\n");
			printf("|Masukkan Pilihan :                        |\n");
			printf("|------------------------------------------|\n");	
			gotoxy(20,10); scanf("%d", &menu);
			
			switch(menu){
				case 1 :
					gotoxy(1,12);
					input();
					sensitiveCase();
					system("pause");
					break;
					
				case 2 :
					gotoxy(1,12);
					input();
					insensitiveCase();
					system("pause");
					break;		
				
				case 0 :
					system("exit");
					break;
			}
			system("cls");
		}while (menu != 0);

    return 0;
}

