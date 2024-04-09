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
#include <windows.h>

typedef struct card {
	int suit;
	int face;
}Card;



void menu();
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card dealer[], Card player[]);
void displayHand(const char* wFace[], const char* wSuit[], Card hand[]);
void CardFrequency(Card hand[], int CardFreq[], const char* wFace[]);
void redrawCards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card hand[]);