#include <iostream>
#include <string.h>
#include "FindCountStr.h"
#include "Sizes.h"

void PrintLongestStr(FILE* readid) {
	int countstr = FindCountStr(readid);
	char longeststr[TEXTSIZE], str1[TEXTSIZE], str2[TEXTSIZE];
	fseek(readid, 0, SEEK_SET);
	for (int i = 0; i < countstr / 2; i++) {
		fgets(str1, TEXTSIZE, readid);
		fgets(str2, TEXTSIZE, readid);
		if (strcmp(str1, str2) == 0)
			strcpy_s(longeststr, TEXTSIZE, str1);
		else if (strcmp(str1, str2) == 1)
			strcpy_s(longeststr, TEXTSIZE, str1);
		else
			strcpy_s(longeststr, TEXTSIZE, str2);
	}
	if(countstr == 1)
		fgets(longeststr, TEXTSIZE, readid);
	printf("%s", longeststr);
}