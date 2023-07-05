#include <iostream>
#include <string.h>
#include "FindCountStr.h"
#include "Sizes.h"

void SwapUserWord(FILE* readid, FILE* writeid, char UserWord[], char UserSwapWord[]) {
	int countstr = FindCountStr(readid), counter = 0, a;
	char str[TEXTSIZE], pattern[] = { " \n.,!?[]{}()@$%^&*<>\\|/;:\'\"`=+_" }, letter;
	char* word, * string = NULL;
	bool value;
	fseek(readid, 0, SEEK_SET);
	for (int i = 0; i < countstr; i++) {
		fgets(str, TEXTSIZE, readid);
		a = strlen(str);
		fseek(readid, -a, SEEK_CUR);
		word = strtok_s(str, pattern, &string);
		fseek(readid, strlen(word), SEEK_CUR);
		do {
			if (strcmp(word, UserWord) == 0) 
				fprintf(writeid, "%s", UserSwapWord);
			else
				fprintf(writeid, "%s", word);

			do {
				value = false;
				letter = fgetc(readid);
				for (int j = 0; j < strlen(pattern); j++) {
					if (letter == pattern[j]) {
						fprintf(writeid, "%c", letter);
						value = true;
					}
				}
			} while (value);
			fseek(readid, -1, SEEK_CUR);

			word = strtok_s(NULL, pattern, &string);
			if(word != NULL)
				fseek(readid, strlen(word), SEEK_CUR);
		} while (word != NULL);
	}
}