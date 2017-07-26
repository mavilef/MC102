#include <stdio.h>
#include <string.h>

int removePadrao(char str[], char padrao[], char targetStr[]);
int removeBloco(char str[], char c, char targetStr[]);
int substituiPadrao(char str[], char padrao[], char novoPadrao[], char targetStr[]);

#define MAX_MOVES 35

int main(void) {
	
	char seq[MAX_MOVES];
	char auxSeq[MAX_MOVES];

	fgets(seq, 30, stdin);
	int len = strlen(seq);
	seq[len-1] = '\0';

	while (1) {
		int seqAlterada = 0;
		int res = removeBloco(seq, '*', auxSeq);
		if (res) {
			printf("removeBloco(*): %s\n", auxSeq);
			strcpy(seq, auxSeq);
			seqAlterada++;
		}

		res = removePadrao(seq, "**", auxSeq);
		if (res) {
			printf("removePadrao(**): %s\n", auxSeq);
			strcpy(seq, auxSeq);
			seqAlterada++;
		}

		res = removePadrao(seq, "+-", auxSeq);
		if (res) {
			printf("removePadrao(+-): %s\n", auxSeq);
			strcpy(seq, auxSeq);
			seqAlterada++;
		}

		res = removePadrao(seq, "-+", auxSeq);
		if (res) {
			printf("removePadrao(-+): %s\n", auxSeq);
			strcpy(seq, auxSeq);
			seqAlterada++;
		}

		res = substituiPadrao(seq, "+*+", "*-*", auxSeq);
		if (res) {
			printf("substituiPadrao(+*+, *-*): %s\n", auxSeq);
			strcpy(seq, auxSeq);
			seqAlterada++;
		}

		res = substituiPadrao(seq, "-*-", "*+*", auxSeq);
		if (res) {
			printf("substituiPadrao(-*-, *+*): %s\n", auxSeq);
			strcpy(seq, auxSeq);
			seqAlterada++;
		}
		if (!seqAlterada) {
			break;
		}
	}

	len = strlen(seq);

	if ( (len == 0) || ((len == 1) && (strcmp(seq, "*") == 0)) )  {
		printf("Cordas terminam separadas!\n");
	} else {
		printf("Cordas terminam emaranhadas!\n");
	}

	return 0;
}
