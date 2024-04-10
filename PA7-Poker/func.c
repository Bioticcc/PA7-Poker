#include "Header.h"
void menu() {
	printf("|-------------------------------------------------------------------------------------|\n");
	printf("| __        __   _                            _____       ____       _             _  |\n");
	printf("| \\ \\      / /__| | ___ ___  _ __ ___   ___  |_   _|__   |  _ \\ ___ | | _____ _ __| | |\n");
	printf("|  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   | |/ _ \\  | |_) / _ \\| |/ / _ \\ '__| | |\n");
	printf("|   \\ V  V /  __/ | (_| (_) | | | | | |  __/   | | (_) | |  __/ (_) |   <  __/ |  |_| |\n");
	printf("|    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|   |_|\\___/  |_|   \\___/|_|\\_\\___|_|  (_) |\n");

	printf("|-------------------------------------------------------------------------------------|\n\n\n");
	printf("|-----------------------------------------RULES---------------------------------------|\n");
	printf("|1. Begin the game by shuffling (wont worry, we do it for you!) your deck.            |\n");
	printf("|2. The dealer will give you and itself 5 random cards, of whitch you can reroll 3!   |\n");
	printf("|3. After you and the dealer finish with your final hand, compare who has the highest |\n");
	printf("|   value, or most valuable hand! This is done through a variety of different combos! |\n");
	printf("|4. These combos, are as such: pair, two pairs, three of a kind, four of a kind,      |\n");
	printf("|   full house, flush, and straight! Each is worth more then the last, and whoever    |\n");
	printf("|   has the better set of cards wins! Good luck!                                      |\n");
	printf("|-------------------------------------------------------------------------------------|\n");

	system("pause");
	system("cls");
}



/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card dealer[], Card player[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int i = 0;

	/* deal each of the 52 cards */
	for (card = 1; card <= 10; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					//every other card, its assigned the current index of the dealers hand the current row/column aka the current card face and suit
					if (card % 2 == 0) {
						//Player's hand
						player[i].suit = row;
						player[i].face = column;
						i++;
					}
					else {
						//dealers hand
						dealer[i].suit = row;
						dealer[i].face = column;
					}
				}
			}
		}
	}
	//just for dramatic effect!
	/*printf("Your dealer is shuffling... \n\n");
	system("pause");
	system("cls");
	printf("Done! Your dealer is now dealing your cards!\n\n");
	system("pause\n");
	system("cls");*/
}

//displays hand
void displayHand(const char* wFace[], const char* wSuit[], Card hand[]) {
	printf("|-----Player-Hand-----|\n");
	for (int i = 0; i < 5; i++) {
		//printf("%5s of %-8s%c\n", wFace[hand[i].face], wSuit[hand[i].suit]);
		printf("|(%d) %s of %s\n",i+1, wFace[hand[i].face], wSuit[hand[i].suit]);
	}
	printf("|-----Dealer-Hand-----|\n");
	for (int i = 0; i < 5; i++) {
		printf("|(%d)???\n", i+1);
	}
}


//redraws cards
void redrawCards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card hand[]) {
	printf("\n Do you wish to redraw any of your cards?");
}

//checks frequency of each card appearing
void CardFrequency(Card hand[], int cardFreq[], const char* wFace[]) {
	for (int i = 0; i < 5; i++) { //iterating through every card in the hand, incrementing its corresponding index in card Freq by 1 every times its found.
								  //so if theres a pair, that cards face index in cardFreq will be 2! makes it easier for the rest of my checks
		switch (hand[i].face) {
			case(0): //means its an ace cause thats the corresponding index in wFace[]
				cardFreq[0]++;
				break;
			case(1): //deuce
				cardFreq[1]++;
				break;
			case(2): //three
				cardFreq[2]++;
				break;
			case(3): //four
				cardFreq[3]++;
				break;
			case(4): //five
				cardFreq[4]++;
				break;
			case(5): //six
				cardFreq[5]++;
				break;
			case(6): //seven
				cardFreq[6]++;
				break;
			case(7): //eight
				cardFreq[7]++;
				break;
			case(8): //nine
				cardFreq[8]++;
				break;
			case(9): //ten
				cardFreq[9]++;
				break;
			case(10): //jack
				cardFreq[10]++;
				break;
			case(11): //queen
				cardFreq[11]++;
				break;
			case(12): //king
				cardFreq[12]++;
				break;
		}
	}
	//REMOVE WHEN GAME ACTUALLY IS MADE JUST FOR TESTING
	for (int i = 0; i < 13; i++) {
		if (cardFreq[i] >= 1) {
			printf("%d copies of %s\n", cardFreq[i], wFace[i]);
		}
	}
}
//checks for combos!

//checks for pair
int check_pair(int cardFreq[], char* wFace[]) {
	for (int i = 0; i < 13; i++) {
		if (cardFreq[i] >= 2) {
			//printf("\nPair found!");
			return 1;
		}
	}
	//printf("\nPair not found.");
	return 0;
}
//checks for two pairs
int check_two_pair(int cardFreq[], char* wFace[]) {
	int pair1 = 0;
	int pair2 = 0;

	for (int i = 0; i < 13; i++) {
		if (cardFreq[i] >= 2) {
			//finds the first pair
			pair1 = i;
			for (int j = 0; j < 13; j++) {
				if (cardFreq[j] >= 2 && j != pair1) {
					//finds second pair, ensuring its in a different spot then the first.
					pair2 = j;
					//printf("\nDouble pair found!");
					return 1;
				}
			}
		}
		
	}
	//printf("\nDouble pair not found.");
	return 0;
}

//checking for three of a kind! :)
int check_trio(int cardFreq[], char* wface[]) {
	for (int i = 0; i < 13; i++) {
		if (cardFreq[i] >= 3) {
			//printf("\nThree of a kind found!");
			return 1;
		}
	}
	//printf("\nNo three of a kind found.");
	return 0;
}
//checking for four of a kind
int check_four(int cardFreq[], char* wface[]) {
	for (int i = 0; i < 13; i++) {
		if (cardFreq[i] >= 4) {
			//printf("\nFour of a kind found!");
			return 1;
		}
	}
	printf("\nFour of a kind not found.");
	return 0;
}

int check_house(int cardFreq[], char* wface[]) {
	int pair = 0;
	int trio = 0;
	for (int i = 0; i < 13; i++) {
		if (cardFreq[i] == 2) {
			pair = i;
			for (int j = 0; j < 13; j++) {
				if (cardFreq[j] == 3 && j != pair) {
					trio = j;
					printf("\nFull house found!");
					return 1;
				}
			}
		}
	}
	//printf("\nNo full house found.");
	return 0;
}

int check_flush(Card hand[]) {
	int flush = 1;
	for (int i = 1; i < 5; i++) {
		//goes through each card in the hand, checking if its suit is the same as the last
		if (hand[i].suit == hand[0].suit) {
			flush++;
		}
	}
	if (flush == 5) {
		printf("\nFlush found!");
		return 1;
	}
}
