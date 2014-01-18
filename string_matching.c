#include <stdio.h>
#include "string_matching.h"
#include "string.h"

void print_string(char* T, int n)
{
	int i = 0;
	while(i < n)
		printf("%c", T[i++]);
	printf("\n");
}

/* string matching using brute force algorithm */
void BF_matching(char* T, int n, char* P, int m)
{
	int i,j,k;
	int count = 0;
	for(i = 0; i <= n-m; i++)
	{
		for(j = 0; j < m; j++)
		{
			count++;   // benchmark
			if(P[j] != T[i+j])
				break;
		}
		if(j == m) // MATCH!
		{
			for(k = 0; k < i; k++)
				printf("%c", ' ');
			for(k = i; k < i + m; k++)
				printf("%c", T[k]);
			printf("\n");
		}
		else
			count++;
	}
	printf("%d times of comparision.\n", count);
}

extern int SIGMA;
extern char Charset[];
extern int Indexhash[];

/* A helper function used by FSM algorithm, it builds the prefix array and the FSM. */
void FSM_Preprocessing(int (*delta)[SIGMA], char* P, int m)
{
	int pi[m];
	int q,k,a;
	/* compute the pi[] array */
	pi[0] = 0;
	k = 0;
	for(q = 2; q <= m; q++)
	{
		while(k > 0 && P[k] != P[q-1])
			k = pi[k-1];
		if(P[k] == P[q-1])
			k++;
		pi[q-1] = k;
	}
	/* preprocessing, compute the delta[][] array */
	for(a = 0; a < SIGMA; a++)
		delta[0][a] = (P[0] == Charset[a])? 1:0;

	for(q = 1; q <= m; q++)
	{
		for(a = 0; a < SIGMA; a++)
		{
			if(q == m || P[q] != Charset[a])
				delta[q][a] = delta[pi[q-1]][a];
			else
				delta[q][a] = q+1;
		}
	}
}

/* String matching using Deterministic Finite Automaton(DFA) algorithm */
void FSM_matching(char* T, int n, char* P, int m)
{
	int i,k;
	int q = 0; // initial state
	int delta[m+1][SIGMA];
	FSM_Preprocessing(delta, P, m);
	for(i = 0; i < n; i++)
	{
		q = delta[q][Indexhash[T[i]-'A']];  // previous state q, input T[i], convert to next state delta[q][T[i]]
		if(q == m) // MATCH!
		{
			for(k = 0; k <= i-m; k++)
				printf("%c", ' ');
			for(k = i-m+1; k<=i; k++)
				printf("%c", T[k]);
			printf("\n");
		}
	}
}


/* String matching using KMP algorithm */
void KMP_matching(char* T, int n, char* P, int m)
{
	int pi[m];
	pi[0] = 0;
	int k = 0;
	int q,i;
	/* Compute prefix array pi[] */
	for(q = 2; q <= m; q++)
	{
		while(k > 0 && P[k] != P[q-1])
			k = pi[k-1];
		if(P[k] == P[q-1])
			k++;
		pi[q-1] = k;
	}
	q = 0;
	for(i = 0; i < n; i++)
	{
		while(q > 0 && P[q] != T[i])
			q = pi[q-1];
		if(P[q] == T[i])
			q++;
		if(q == m) // Match!
		{
			for(k = 0; k <= i-m; k++)
				printf("%c", ' ');
			for(k = i-m+1; k<=i; k++)
				printf("%c", T[k]);
			printf("\n");
			/* For the next match */
			q = pi[q-1];
		}
	}
}

/* String matching using bit hacks to simulate FSM, as long as length(P) = m <= 32 
   (or 64 depending on the address length of your machine) */
void Shift_and_matching(char* T, int n, char* P, int m)
{
	int B[SIGMA];
	memset(B, 0, sizeof(int)*SIGMA);
	int i,j;
	/* Compute B[] array */
	for(j = 0; j < m; j++)
		B[Indexhash[P[j] - 'A']] |= (1 << j);

	int D = 0;
	int mask = 1 << (m-1);
	for(i = 0; i < n; i++)
	{
		D = (D << 1 | 1) & B[Indexhash[T[i] - 'A']];
		if(D & mask)      // MATCH!
		{
			for(j = 0; j <= i-m; j++)
				printf("%c", ' ');
			for(j = i-m+1; j<=i; j++)
				printf("%c", T[j]);
			printf("\n");
			// D &= ~mask;  // this is unnecessary, actually.
		}
	}
}
