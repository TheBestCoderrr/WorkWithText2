#include <iostream>
#include "FindCountStr.h"
#include "Sizes.h"

void PrintWithoutLastStr(FILE* readid, FILE* writeid) {
	int countstr = FindCountStr(readid);
	char str[TEXTSIZE];
	fseek(readid, 0, SEEK_SET);
	for (int i = 0; i < countstr - 1; i++) {
		fgets(str, TEXTSIZE, readid);
		fprintf(writeid, "%s", str);
	}
}