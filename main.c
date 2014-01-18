#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "string_matching.h"

/* length of Target string, since T is created dynamically */
#define MAX_LEN 100
/* length of Charset sigma */
#define CHARSET_LEN 2


/* return a random integer in range of [a,b] */
__attribute__((always_inline))
int Randint(int a, int b)
{
	return (a + rand() % (b-a+1));
}

char Charset[] = "AB";
int Indexhash[26];
int SIGMA = CHARSET_LEN;

int main()
{
	srand(time(NULL));
	int i;
	char P[] = "ABABA";
	char T[MAX_LEN];
	for(i = 0; i < CHARSET_LEN; i++)
		Indexhash[Charset[i] - 'A'] = i;
	for(i = 0; i < MAX_LEN; i++)
		T[i] = Charset[Randint(0,1)];

	printf("Original string:\n");
	print_string(T, MAX_LEN);
	printf("Brute force method:\n");
	BF_matching(T, MAX_LEN, P, strlen(P));
	printf("FSM method:\n");
	FSM_matching(T, MAX_LEN, P, strlen(P));
	printf("KMP method:\n");
	KMP_matching(T, MAX_LEN, P, strlen(P));
	printf("Shift_and method:\n");
	Shift_and_matching(T, MAX_LEN, P, strlen(P));

	return 0;
}
