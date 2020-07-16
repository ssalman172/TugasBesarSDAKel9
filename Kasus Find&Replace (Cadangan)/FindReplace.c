#include "FindReplace.h"

void input{
	FILE * filePointer;
    FILE * fileTemp;
    char path[50];
    
    char file[FILE_MAX_WORD];
    char oldWord[100], newWord[100];

    printf("~Alamat dan Nama File~");
    printf("\nContoh: namaFolder/namaFile.txt ");
    printf("\nCukup nama file jika file terdapat di folder sama \nEntry: ");
    scanf("%s", path);

    /*  Open all required files */
    filePointer  = fopen(path, "r");
    
    /* fopen() return NULL if unable to open file in given mode. */
    if (filePointer == NULL || fileTemp == NULL) {
        /* Unable to open file hence exit */
        printf("\nFile Tidak Ditemukan.\n");
        exit(EXIT_SUCCESS);
    }
    
    printf("\nMasukkan kata yang ingin diganti: ");
    scanf("%s", oldWord);
     
    printf("\nGanti semua kata '%s' dengan: ", oldWord);
    scanf("%s", newWord);
    
    fileTemp = fopen("file.tmp", "w"); 
}

void sensitiveCase {
    /*
     * Read line from source file and write to destination 
     * file after replacing given word.
     */
    while ((fgets(file, FILE_MAX_WORD, filePointer)) != NULL) {
        // Replace all occurrence of word from current line
        replaceSemuaKata(file, oldWord, newWord);

        // After replacing write it to temp file.
        fputs(file, fileTemp);
    }

    /* Close all files to release resource */
    fclose(filePointer);
    fclose(fileTemp);
    
    /* Delete original source file */
    remove(path);

    /* Rename temp file as original file */
    rename("file.tmp", path);

    printf("\nSemua kata '%s' (terdapat %d) telah diganti menjadi '%s'.", oldWord, counterJumlahKata, newWord);
}

void sensitiveCase {
    /*
     * Read line from source file and write to destination 
     * file after replacing given word.
     */
    while ((fgets(file, FILE_MAX_WORD, filePointer)) != NULL) {
        // Replace all occurrence of word from current line
        replaceSemuaKata(file, oldWord, newWord);

        // After replacing write it to temp file.
        fputs(file, fileTemp);
    }

    /* Close all files to release resource */
    fclose(filePointer);
    fclose(fileTemp);
    
    /* Delete original source file */
    remove(path);

    /* Rename temp file as original file */
    rename("file.tmp", path);

    printf("\nSemua kata '%s' (terdapat %d) telah diganti menjadi '%s'.", oldWord, counterJumlahKata, newWord);
}

void replaceSemuaKata(char *teks, const char *oldWord, const char *newWord) {
    char *kataYangDiganti, temp[FILE_MAX_WORD];
    int index = 0;
    int oldWordLength;

    oldWordLength = strlen(oldWord);

    /*
     * Repeat till all occurrences are replaced. 
     */
    while ((kataYangDiganti = strstr(teks, oldWord)) != NULL) {
    	if(strstr(teks, oldWord)){
    		counterJumlahKata++;
		}
        // Bakup current line
        strcpy(temp, teks);

        // Index of current found word
        index = kataYangDiganti - teks;

        // Terminate str after word found index
        teks[index] = '\0';

        // Concatenate str with new word 
        strcat(teks, newWord);
        
        // Concatenate str with remaining words after 
        // oldword found index.
        strcat(teks, temp + index + oldWordLength);
    }
