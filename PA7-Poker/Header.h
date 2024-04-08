/*
Author: Adam Ward
Date: 
Description: 
*/


// Authors: Deitel & Deitel - C How to Program
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
	int suit;
	int face;
}Card;


void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card dealer[], Card player[]);
