#ifndef __MYSTRING_H__
#define __MYSTRING_H__

void print_string(char* T, int n);
void BF_matching(char* T, int n, char* P, int m);
void FSM_matching(char* T, int n, char* P, int m);
void FSM_Preprocessing(int (*delta)[], char* P, int m);
void KMP_matching(char* T, int n, char* P, int m);
void Shift_and_matching(char* T, int n, char* P, int m);

#endif
