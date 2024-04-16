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



int menu(float current_bill);
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card dealer[], Card player[], Card rerollsP[], Card rerollsD[]);
void displayHand(const char* wFace[], const char* wSuit[], Card handP[], Card handD[]);
void CardFrequency(Card hand[], int CardFreq[], const char* wFace[]);
int check_pair(int cardFreq[], char* wFace[]);
int check_two_pair(int cardFreq[], char* wFace[]);
int check_trio(int cardFreq[], char* wface[]);
int check_four(int cardFreq[], char* wface[]);
int check_house(int cardFreq[], char* wface[]);
int check_flush(Card hand[]);
int check_straight(Card hand[], char* wFace);
int compare_hands(int ComboListP[], int ComboListD[], Card player[], Card dealer[], const char* wFace[], const char* wSuit[]);
void redrawCards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card hand[], Card dealer[], Card reroll[]);
int DealerAI(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card dealer[], Card reroll[], int ComboListD[], int CardFreqD[]);

//Extra functions for fun! :)
int betting(int wager, int victor);