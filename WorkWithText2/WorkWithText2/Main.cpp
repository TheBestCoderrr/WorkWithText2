#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Exersize1.h"
#include "Exersize2.h"
#include "Exersize3.h"
#include "Exersize4.h"
#include "Sizes.h"

int main() {
	FILE* readid, * writeid, * appendid;
	readid = fopen("G:\\Text\\Text.txt", "r");
	writeid = fopen("G:\\Text\\NewText.txt", "w");

	if (readid != NULL && writeid != NULL) {
		PrintWithoutLastStr(readid, writeid);
		fclose(readid);
		fclose(writeid);
	}
	
	readid = fopen("G:\\Text\\Text.txt", "r");

	if (readid != NULL) {
		PrintLongestStr(readid);
		fclose(readid);
	}
	
	readid = fopen("G:\\Text\\Text.txt", "r");

	if (readid != NULL) {
		char UserWord[WORDSIZE];
		printf("\nEnter word: ");
		scanf("%s", &UserWord);
		printf("Count words = %i", CountUserWord(readid, UserWord));
		fclose(readid);
	}
	
	readid = fopen("G:\\Text\\Text.txt", "r");
	writeid = fopen("G:\\Text\\NewText.txt", "w");

	if (readid != NULL && writeid != NULL) {
		char UserWord[WORDSIZE];
		printf("\nEnter word: ");
		scanf("%s", &UserWord);

		char UserSwapWord[WORDSIZE];
		printf("Enter swap word: ");
		scanf("%s", &UserSwapWord);
		
		SwapUserWord(readid, writeid, UserWord, UserSwapWord);
		fclose(readid);
	}

}