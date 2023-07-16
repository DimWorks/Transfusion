#pragma once

#define MAX_NUM_OF_TRAN 10

//extern int max_of_tran = MAX_NUM_OF_TRAN;

typedef struct tran
{
	int val;
	int inc;
	int tara;
	char trans[MAX_NUM_OF_TRAN];
} transf;

void trans(const int baseVal, const int bigVal, const int smallVal, const int disVal);