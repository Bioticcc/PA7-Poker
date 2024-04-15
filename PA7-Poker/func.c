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
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card dealer[], Card player[], Card rerollsP[], Card rerollsD[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int i = 0;
	int D = 0;
	int P = 0;
	/* deal each of the 52 cards */
	for (card = 1; card <= 16; card++)
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

					//so the way ill handle extra cards for rerolling, is to just deal out 16 cards so i have 6 extra, 3 for the player and 3 for the dealer.
					if (card > 10) {
						//printf("\n%d", r);
						if (card % 2 == 0) {
							rerollsP[P].suit = row;
							rerollsP[P].face = column;
							P++;
						}
						else {
							rerollsD[D].suit = row;
							rerollsD[D].face = column;
							D++;
						}
						
					}
					if (card <= 10) {
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
void displayHand(const char* wFace[], const char* wSuit[], Card handP[], Card handD[]) {
	printf("|-----Player-Hand-----|\n");
	for (int i = 0; i < 5; i++) {
		//printf("%5s of %-8s%c\n", wFace[hand[i].face], wSuit[hand[i].suit]);
		printf("|(%d) %s of %s\n",i+1, wFace[handP[i].face], wSuit[handP[i].suit]);
	}
	printf("|-----Dealer-Hand-----|\n");
	for (int i = 0; i < 5; i++) {
		printf("|(%d) %s of %s\n", i + 1, wFace[handD[i].face], wSuit[handD[i].suit]);
	}
}


//redraws cards
void redrawCards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card hand[], Card dealer[], Card reroll[]) {
	char a = '\0';
	char b = '\0';
	int t = 0;
	int c = 1;
	int i = 0;
	printf("\nDo you wish to redraw any of your cards? (y/n): ");
	do {
		scanf(" %c", &a);
	} while (a!='y' && a!='Y' && a!='n' && a!='N');

	if (a == 'n' || a == 'N') { return 0; }
	else {
		while (1) {
			system("cls");
			displayHand(wFace, wSuit, hand, dealer);
			printf("\nPlease choose a card to redraw from your deck (1-5): \n");
			scanf("%d", &t);
			switch (t)
			{
			case 1:
				//means they want to replace the first card in their hand
				hand[0].face = reroll[i].face;
				hand[0].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);

				break;
			case 2:
				hand[1].face = reroll[i].face;
				hand[1].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);

				break;
			case 3:
				hand[2].face = reroll[i].face;
				hand[2].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);

				break;
			case 4:
				hand[3].face = reroll[i].face;
				hand[3].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);

				break;
			case 5:
				hand[4].face = reroll[i].face;
				hand[4].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);

				break;
			}
			i++;
			if (c != 3) {
				printf("Would you like to redraw another card? (y/n): \n");
				do {
					scanf(" %c", &b);
				} while (b != 'y' && b != 'Y' && b != 'n' && b != 'N');
				if (b == 'y' || b == 'Y') {
					c++;
				}
				else if (b=='N' || b=='n'){
					c == 3;
					break;
				}
			}
			else if (c == 3) { return 1; }
		}
	}

}

int DealerAI(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card dealer[], Card reroll[], int ComboListD[], int CardFreqD[]) {
	
	int rerolls = 0;
	//rather then this nonsense from before, im instead just gonna do a shit ton of if statements! yay!
	if (ComboListD[6] == 1) {
		//perfect! no rerolls needed.
		//on second thought this is the 4 of a kind one so actually could be a good idea to reroll one of his cards. 
		for (int i = 0; i < 13; i++) {
			if (CardFreqD[i] >= 4) {
				//okay so i want to reroll the card in his hand that ISNT 4 of a kind.
				for (int j = 0; j < 5; j++) {
					if (dealer[j].face != i) {
						reroll = j; //so i think this should be the index of the card in my hand that ISNT in the 4 of a kind
					}
				}
			}
		}
		printf("The dealer, having a \"4 of a kind\", has chosen to redraw one of their cards!\nNew card: %s of %s.\n", wFace[reroll[0].face], wSuit[reroll[0].suit]);
		dealer[rerolls].face = reroll[0].face;
		dealer[rerolls].suit = reroll[0].suit;
		return 1;
	}
	else if (ComboListD[5] == 1) {

		//too be honest this one is perfectly fine, and could fuck up his points so i think rerolling for house would be a bad idea overall
		printf("The dealer has decided to not redraw any of his cards.\n");
		return 1;
	}
	else if (ComboListD[4] == 1) {

		//maybe im just bad at poker, but the straight and house just seem like bad choices to reroll. both of their points require having
		//all 5 cards in the hand be apart of it, so there isnt a safe way to really reroll without loss of points. 
		//anyway thats my justification for not doing rerolls for either of these two!
		printf("The dealer has decided to not redraw any of his cards.\n");
		return 1;
	}
	else if (ComboListD[3] == 1) {

		//huh well too be honest straight doesnt feel like it should be redrawn either but at this point id be essentially skipping this part
		//of the assignment, so ill redraw for a straight. (still feels like a bad idea but again ive never gambled lol)
		//well if its a straight, I spose ill just reroll the two lowest face values in the set. might as well try for more points
		int minCard = 0;
		int minCard2 = 0;
		//im pretttttttty sure by this point ive already sorted the dealers hand from min to max, and tbh i do NOT remeber if i have or not for sure, so imma go with yes
		//in that case min and min2 should just be indexes 0 and 1 in the dealer hand
		minCard = 0;
		minCard2 = 1;
		dealer[0].face = reroll[0].face;
		dealer[0].suit = reroll[0].suit;

		dealer[1].face = reroll[1].face;
		dealer[1].suit = reroll[1].suit;
		printf("The dealer, having a \"Straight\", has decided to redraw 2 of his cards.\nNew cards:\n%s of %s.\n%s of %s\n", wFace[reroll[0].face], wSuit[reroll[0].suit], wFace[reroll[1].face], wSuit[reroll[1].suit]);
		return 1;
	}
	else if(ComboListD[2] == 1) {

		int reroll1 = 0;
		int reroll2 = 0;
		//trio? yea this ones easy just gon reroll the 2 cards in my hand that arent in the trio lol
		for (int i = 0; i < 13; i++) {
			if (CardFreqD[i] >= 3) {
				for (int j = 0; j < 5; j++) {
					if (dealer[j].face != i) {
						reroll1 = j;
						for (int k = 0; k < 5; k++) {
							if (dealer[k].face != i && k != j) {
								reroll2 = k;
							}
						}
					}
				}
			}
		}

		dealer[reroll1].face = reroll[0].face;
		dealer[reroll1].suit = reroll[0].suit;

		dealer[reroll2].face = reroll[1].face;
		dealer[reroll2].suit = reroll[1].suit;

		printf("The dealer, having a \"Three of a kind\", has decided to redraw 2 of his cards.\nNew cards:\n%s of %s.\n%s of %s\n", wFace[reroll[0].face], wSuit[reroll[0].suit], wFace[reroll[1].face], wSuit[reroll[1].suit]);
		return 1;
	}
	else if (ComboListD[1] == 1) {

		int card1 = 0;
		int card2 = 0;
		int card3 = 0;
		//well he got two pairs, so imma just reroll the lower face value pair + the non paired face
		int pair1 = 0;
		int pair2 = 0;

		for (int i = 0; i < 13; i++) {
			if (CardFreqD[i] >= 2) {
				pair1 = i;
				for (int j = 0; j < 13; j++) {
					if (CardFreqD[j] >= 2 && j != pair1) {
						pair2 = j;
					}
				}
			}
		} 
		//finding first card to reroll (the one not in either pair)
		for (int k = 0; k < 5; k++) {
			if (dealer[k].face != CardFreqD[pair1] && dealer[k].face != CardFreqD[pair2]) {
				card1 = k;
			}
		}
		int pair = 1;
		//deciding whitch of the the two pais to redraw
		if (CardFreqD[pair1] >= CardFreqD[pair2]) {
			pair = 2;
		}
		if (pair == 2) {
			for (int l = 0; l < 5; l++) {
				if (dealer[l].face == CardFreqD[pair2]) { 
					card2 = l; 
					for (int a = 0; a < 5; a++) {
						if (dealer[a].face == CardFreqD[pair2] && dealer[a].face != card2) {
							card3 = a;
						}
					}
				}

			}
		}

		//now replace dealer indexes card1, 2, and 3 with reroll indexes 0, 1, 2
		dealer[card1].face = reroll[0].face;
		dealer[card1].suit = reroll[0].suit;

		dealer[card2].face = reroll[1].face;
		dealer[card2].suit = reroll[1].suit;

		dealer[card3].face = reroll[3].face;
		dealer[card3].suit = reroll[3].suit;

		printf("The dealer, having \"Double pair\", has decided to redraw 3 of his cards.\nNew cards:\n%s of %s\n%s of %s\n%s of %s", wFace[reroll[0].face], wSuit[reroll[0].suit], wFace[reroll[1].face], wSuit[reroll[1].suit], wFace[reroll[2].face], wSuit[reroll[2].suit]);
		return 1;
	}
	else if (ComboListD[0] == 1) {
		int pair = 0;
		int card1 = 0;
		int card2 = 0;
		int card3 = 0;
		//means weve got a pair, simply going to reroll all 3 of the cards that are not in the pair.
		for (int i = 0; i < 13; i++) {
			if (CardFreqD[i] >= 2) {
				pair = i;
			}
		}
		for (int j = 0; j < 5; j++) {
			if (dealer[j].face != pair) {
				card1 = j;
				for (int l = 0; l < 5; l++) {
					if (dealer[l].face != card1 && dealer[l].face != pair) {
						card2 = l;
					}
					for (int a = 0; a < 5; a++) {
						if (dealer[a].face != card1 && dealer[a].face != pair && dealer[a].face != card2) {
							card3 = a;
						}
					}
				}
			}
		}
		dealer[card1].face = reroll[0].face;
		dealer[card1].suit = reroll[0].suit;

		dealer[card2].face = reroll[1].face;
		dealer[card2].suit = reroll[1].suit;

		dealer[card3].face = reroll[3].face;
		dealer[card3].suit = reroll[3].suit;

		printf("The dealer, having \"Pair\", has decided to redraw 3 of his cards.\nNew cards:\n%s of %s\n%s of %s\n%s of %s\n\n", wFace[reroll[0].face], wSuit[reroll[0].suit], wFace[reroll[1].face], wSuit[reroll[1].suit], wFace[reroll[2].face], wSuit[reroll[2].suit]);
		return 1;
	}
	else {
		int card1 = dealer[0].face;
		int card2 = dealer[1].face;
		int card3 = dealer[2].face;

		dealer[card1].face = reroll[0].face;
		dealer[card1].suit = reroll[0].suit;

		dealer[card2].face = reroll[1].face;
		dealer[card2].suit = reroll[1].suit;

		dealer[card3].face = reroll[3].face;
		dealer[card3].suit = reroll[3].suit;

		printf("The dealer, having \"No combo\", has decided to redraw 3 of his cards.\nNew cards:\n%s of %s\n%s of %s\n%s of %s\n\n", wFace[reroll[0].face], wSuit[reroll[0].suit], wFace[reroll[1].face], wSuit[reroll[1].suit], wFace[reroll[2].face], wSuit[reroll[2].suit]);
		return 1;
	}
	
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
	//printf("\nFour of a kind not found.");
	return 0;
}
//checking for full house
int check_house(int cardFreq[], char* wface[]) {
	int pair = 0;
	int trio = 0;
	for (int i = 0; i < 13; i++) {
		if (cardFreq[i] == 2) {
			pair = i;
			for (int j = 0; j < 13; j++) {
				if (cardFreq[j] == 3 && j != pair) {
					trio = j;
					//printf("\nFull house found!");
					return 1;
				}
			}
		}
	}
	//printf("\nNo full house found.");
	return 0;
}
//checking for flush
int check_flush(Card hand[]) {
	int flush = 1;
	for (int i = 1; i < 5; i++) {
		//goes through each card in the hand, checking if its suit is the same as the last
		if (hand[i].suit == hand[0].suit) {
			flush++;
		}
	}
	if (flush == 5) {
		//printf("\nFlush found!");
		return 1;
	}
	else { return 0;  }
}
//checking for straight
int check_straight(Card hand[], char* wFace) {
	//gotta sort hand first
	int minI = 0;
	int maxI = 0;
	Card temp;
	for(int i = 0; i < 5; i++){
		minI = i;
		for (int j = i+1; j < 5; j++) {
			if (hand[j].face <= hand[minI].face) {
				minI = j;
			}
		}
		if (minI != i) {
			temp = hand[i];
			hand[i] = hand[minI];
			hand[minI] = temp;
		}
	}
	//only works if hand is sorted!
	int in_a_row = 1; //increments by one everytime the face value of i is 1 greater then the face value of i-1
	for (int i = 1; i < 5; i++) {
		if (hand[i].face - hand[i - 1].face == 1) {
			in_a_row++;
		}
		else { in_a_row = 1; } 
	}
	if (in_a_row == 5) {
		//printf("\nStraight found!");
		return 1;
	}
	else {
		//printf("\nNo straight found.");
		return 0;
	}
}
//oomparing player to dealers hand
int compare_hands(int ComboListP[], int ComboListD[], Card player[], Card dealer[]) {
	//first, lets see if anyone has any combos!
	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < 7; i++) {
		if (ComboListP[i] > 0 ) {
			a = 1; //player has at least one combo in hand!
		}
		if (ComboListD[i] > 0) {
			b = 1; //dealer has at least one combo in hand!
		}
		if (a && b) {
			//both hands have at least one combo, we can continue!
			printf("\nBOTH HANDS HAVE A COMBO! PREPARE TO DECIDE THE WINNER!\n");
			break;
		}
	}
	if (a == 0 & b == 0) {
		//both hands have nothing, so do high card
		c = 1;
	}
	int P = 0;
	int D = 0;
	int PD = 0;
	//If both the player and the dealer have a combo somewhere in their hand, I now need to determine if one has a higher combo then the other!
	for (int i = 6; i > -1; i--) {
		//starting from the largest index, (aka the highest tier of combo) we check if either has it and the other has a zero!
		if (ComboListP[i] == 1 || ComboListD[i] == 1) {
			//confirms one of the two has a combo at that index. but who has it?
			if (ComboListP[i] == 1 && ComboListD[i] == 0) {
				//means player has higher combo, since it goes from top down. Player wins!
				P = 1;
				//printf("Test 1");
				break;
			}
			if (ComboListP[i] == 0 && ComboListD[i] == 1) {
				//means dealer has higher combo, since it goes from top down. Dealer wins!
				D = 1;
				//printf("Test 2");
				break;
			}
			else if (ComboListP[i] == 1 && ComboListD[i] == 1) {
				//means both dealer and player have a combo of such heights! wowzers (need to do high card very sad)
				PD = 1;
				break;
			}
		}
	}
	if (P == 1) {
		printf("\nPLAYER WINS!\n"); return 1;
	}

	if (D == 1) {
		printf("\nDEALER WINS!\n"); return 1;
	}

	
	//now that ive decided whos got what when where and how, lets take a peek at what happens when both player and dealer have the same combo!
	if (PD||c) {
		int highestP = -1;
		int highestD = -1;
		//ineffecient way to do it, i know but meh it works
		int SecondHighestP = -1;
		int SecondHighestD = -1;
		int ThirdHighestP = -1;
		int ThirdHighestD = -1;
		int FourthHighestP = -1;
		int FourthHighestD = -1;
		int FifthHighestP = -1;
		int FifthHighestD = -1;

		for (int i = 0; i < 5; i++) {
			//gotta look through each card in the player and dealer hands, determinig who has the higher card value for their single BEST card
			if (player[i].face > highestP) { 
				FifthHighestP = FourthHighestP;
				FourthHighestP = ThirdHighestP;
				ThirdHighestP = SecondHighestP;
				SecondHighestP = highestP;
				highestP = player[i].face; 
			}
			else if (player[i].face > SecondHighestP && player[i].face != highestP) {
				FifthHighestP = FourthHighestP;
				FourthHighestP = ThirdHighestP;
				ThirdHighestP = SecondHighestP;
				SecondHighestP = player[i].face;
			}
			else if (player[i].face > ThirdHighestP && player[i].face != SecondHighestP) {
				FifthHighestP = FourthHighestP;
				FourthHighestP = ThirdHighestP;
				ThirdHighestP = player[i].face;
			}
			else if (player[i].face > FourthHighestP && player[i].face != ThirdHighestP) {
				FifthHighestP = FourthHighestP;
				FourthHighestP = player[i].face;
			}
			else if (player[i].face > FifthHighestP && player[i].face != FourthHighestP) {
				FifthHighestP = player[i].face;
			}
		}
		for (int i = 0; i < 5; i++) {
			//gotta look through each card in the player and dealer hands, determinig who has the higher card value for their single BEST card
			if (dealer[i].face > highestD) {
				FifthHighestD = FourthHighestD;
				FourthHighestD = ThirdHighestD;
				ThirdHighestD = SecondHighestD;
				SecondHighestD = highestD;
				highestD = dealer[i].face;
			}
			else if (dealer[i].face > SecondHighestD && dealer[i].face != highestD) {
				FifthHighestD = FourthHighestD;
				FourthHighestD = ThirdHighestD;
				ThirdHighestD = SecondHighestD;
				SecondHighestD = dealer[i].face;
			}
			else if (dealer[i].face > ThirdHighestD && dealer[i].face != SecondHighestD) {
				FifthHighestD = FourthHighestD;
				FourthHighestD = ThirdHighestD;
				ThirdHighestD = dealer[i].face;
			}
			else if (dealer[i].face > FourthHighestD && dealer[i].face != ThirdHighestD) {
				FifthHighestD = FourthHighestD;
				FourthHighestD = dealer[i].face;
			}
			else if (dealer[i].face > FifthHighestD && dealer[i].face != FourthHighestD) {
				FifthHighestD = dealer[i].face;
			}
		}
		

		if (highestP > highestD) printf("\nPLAYER WINS! by highest card\n");
		if (highestD > highestP) printf("\nDEALER WINS! by highest card\n");
		if (highestP == highestD) {
			//sigh
			if (SecondHighestP > SecondHighestD) printf("\nPLAYER WINS! by highest card\n");
			if (SecondHighestD > SecondHighestP) printf("\nDEALER WINS! by highest card\n");
			if (SecondHighestP == SecondHighestD) {
				//really?? what are the odds >:(
				if (ThirdHighestP > ThirdHighestD) printf("\nPLAYER WINS! by highest card\n");
				if (ThirdHighestD > ThirdHighestP) printf("\nDEALER WINS! by highest card\n");
				if (ThirdHighestP == ThirdHighestD) {
					//gonna commit some crimes if this continues
					if (FourthHighestP > FourthHighestD) printf("\nPLAYER WINS! by highest card\n");
					if (FourthHighestD > FourthHighestP) printf("\nDEALER WINS! by highest card\n");
					if (FourthHighestP == FourthHighestD) {
						//bruh.
						if (FifthHighestP > FifthHighestD) printf("\nPLAYER WINS! by highest card\n");
						if (FifthHighestD > FifthHighestP) printf("\nDEALER WINS! by highest card\n");
						if (FifthHighestP == FifthHighestD) {
							//i didnt think it possible, but somehow you have an identical hand to the dealer! congrats! (internal screaming)
							printf("\nSECRET ENDING! - NO ONE WINS! Congratulations, you both had identical hands!\nNow aint that somethin? bit wacky, if you ask me O>O\nAnyway, congrats! Now go buy a lottery ticket or something ;3\n");
						}	
					}
				}
			}
		}
	}


}
