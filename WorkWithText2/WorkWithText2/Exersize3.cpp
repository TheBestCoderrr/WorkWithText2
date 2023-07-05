#include <iostream>
#include <string.h>
#include "FindCountStr.h"
#include "Sizes.h"

int CountUserWord(FILE* readid, char UserWord[]) {
	int countstr = FindCountStr(readid), countword = 0;
	char str[TEXTSIZE], pattern[] = { " \n.,!?[]{}()@$%^&*<>\\|/;:\'\"`=+_" };
	char *word, * string = NULL;
	fseek(readid, 0, SEEK_SET);
	for (int i = 0; i < countstr; i++) {
		fgets(str, TEXTSIZE, readid);
		word = strtok_s(str, pattern, &string);
		do {
			if (strcmp(word, UserWord) == 0)
				countword++;
			word = strtok_s(NULL, pattern, &string);
		} while (word != NULL);
	}
	return countword;
}