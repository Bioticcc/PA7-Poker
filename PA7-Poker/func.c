#include "Header.h"
int menu(float current_bill) {
	printf("\x1B[1;33m|-------------------------------------------------------------------------------------|\n");
	printf("| __        __   _                            _____       ____       _             _  |\n");
	printf("| \\ \\      / /__| | ___ ___  _ __ ___   ___  |_   _|__   |  _ \\ ___ | | _____ _ __| | |\n");
	printf("|  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\   | |/ _ \\  | |_) / _ \\| |/ / _ \\ '__| | |\n");
	printf("|   \\ V  V /  __/ | (_| (_) | | | | | |  __/   | | (_) | |  __/ (_) |   <  __/ |  |_| |\n");
	printf("|    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|   |_|\\___/  |_|   \\___/|_|\\_\\___|_|  (_) |\n");
	printf("|-------------------------------------------------------------------------------------|\x1B[0;37m\n\n\n");
	printf("\x1B[1;31m|-----------------------------------------RULES---------------------------------------|\n");
	printf("|1. Begin the game by shuffling (wont worry, we do it for you!) your deck.            |\n");
	printf("|2. The dealer will give you and itself 5 random cards, of whitch you can reroll 3!   |\n");
	printf("|3. After you and the dealer finish with your final hand, compare who has the highest |\n");
	printf("|   value, or most valuable hand! This is done through a variety of different combos! |\n");
	printf("|4. These combos, are as such: pair, two pairs, three of a kind, four of a kind,      |\n");
	printf("|   full house, flush, and straight! Each is worth more then the last, and whoever    |\n");
	printf("|   has the better set of cards wins! Good luck!                                      |\n");
	printf("|-------------------------------------------------------------------------------------|\x1B[0;37m\n\n\n");

	printf("\x1B[1;33m");
	int wager = 0;
	int a = 0;
	printf("|--------WAGER-------->\n");
	printf("|current pool: $%0.2f    \n", current_bill);
	printf("|bet: ");
	scanf("%d", &wager);
	printf("\n|(1) cash out\n");
	printf("|(2) continue playing \n");
	printf("|Enter: ");
	scanf("%d", &a);
	if (a == 1) {
		if(current_bill < 0){
			printf("\x1B[0;31m");
			printf("Due to your outstanding balance,\nas per the rules outlined in our contract\nyou will now be employed for work at the casino until you pay off your debt.\n\nWelcome to new south wales, sir. Your home away from home.\n");
			exit(0);
		}
		else if (current_bill >= 0) {
			printf("\x1B[1;33m");
			printf("As per our agreement, here are your winnings: $%0.2f\nHave a good night!", current_bill);
			exit(0);
		}
	}
	system("pause");
	system("cls");
	printf("\x1B[0;37m");
	return wager;

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
	printf("\x1B[0;92m");
	printf("|-----Player-Hand-----|\n");
	printf("\x1B[0;37m");

	for (int i = 0; i < 5; i++) {
		printf("\x1B[0;32m");
		//printf("%5s of %-8s%c\n", wFace[hand[i].face], wSuit[hand[i].suit]);
		printf("|(%d) %s of %s\n",i+1, wFace[handP[i].face], wSuit[handP[i].suit]);
	}
	printf("\x1B[1;31m");
	printf("|-----Dealer-Hand-----|\n");
	for (int i = 0; i < 5; i++) {
		printf("\x1B[1;31m");
		printf("|(%d) %s of %s\n", i + 1, wFace[handD[i].face], wSuit[handD[i].suit]);
		printf("\x1B[0;37m");
	}
}

//redraws cards
void redrawCards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card hand[], Card dealer[], Card reroll[]) {
	char a = '\0';
	char b = '\0';
	int t = 0;
	int c = 1;
	int i = 0;
	printf("\x1B[1;33m");
	printf("\nDo yo wish to redraw any of your cards? (y/n): ");
	do {
		scanf(" %c", &a);
	} while (a!='y' && a!='Y' && a!='n' && a!='N');
	system("cls");
	displayHand(wFace, wSuit, hand, dealer);
	if (a == 'Y' || a == 'y'){
		while (1) {
			system("cls");
			displayHand(wFace, wSuit, hand, dealer);
			printf("\x1B[1;33m");
			printf("\nPlease choose a card to redraw from your deck (1-5): \n");
			scanf("%d", &t);
			switch (t)
			{
			case 1:
				//means they want to replace the first card in their hand
				hand[0].face = reroll[i].face;
				hand[0].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);
				printf("\x1B[0;37m");
				break;
			case 2:
				hand[1].face = reroll[i].face;
				hand[1].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);
				printf("\x1B[0;37m");
				break;
			case 3:
				hand[2].face = reroll[i].face;
				hand[2].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);
				printf("\x1B[0;37m");
				break;
			case 4:
				hand[3].face = reroll[i].face;
				hand[3].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);
				printf("\x1B[0;37m");
				break;
			case 5:
				hand[4].face = reroll[i].face;
				hand[4].suit = reroll[i].suit;
				printf("New card drawn: %s of %s\n", wFace[reroll[i].face], wSuit[reroll[i].suit]);
				printf("\x1B[0;37m");
				break;
			}
			i++;
			if (c != 3) {
				printf("\x1B[1;33m");
				printf("Would you like to redraw another card? (y/n): \n");
				do {
					scanf(" %c", &b);
				} while (b != 'y' && b != 'Y' && b != 'n' && b != 'N');
				printf("\x1B[0;37m");
				if (b == 'y' || b == 'Y') {
					c++;
				}
				else if (b == 'N' || b == 'n') {
					c == 3;
					printf("\x1B[1;33m");
					system("cls");
					displayHand(wFace, wSuit, hand, dealer);
					printf("\x1B[1;31m");
					system("pause");
					printf("\x1B[0;37m");
					break;
				}
			}
			else if (c == 3) {
				printf("\x1B[1;33m");
				system("cls");
				displayHand(wFace, wSuit, hand, dealer);
				printf("\x1B[1;31m");
				system("pause");
				printf("\x1B[0;37m");
				return 1; }
		}

	}
	if (a == 'n' || a == 'N') {
		printf("\x1B[1;33m");
		system("cls");
		displayHand(wFace, wSuit, hand, dealer);
		printf("\x1B[1;31m");
		system("pause");
		printf("\x1B[0;37m");
		
	}


}

//dealer ai 
int DealerAI(const int wDeck[][13], const char* wFace[], const char* wSuit[], Card dealer[], Card reroll[], int ComboListD[], int CardFreqD[]) {
	printf("\x1B[1;31m");
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

		dealer[card3].face = reroll[2].face;
		dealer[card3].suit = reroll[2].suit;

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

		dealer[card3].face = reroll[2].face;
		dealer[card3].suit = reroll[2].suit;

		printf("The dealer, having \"Pair\", has decided to redraw 3 of his cards.\nNew cards:\n%s of %s\n%s of %s\n%s of %s\n\n", wFace[reroll[0].face], wSuit[reroll[0].suit], wFace[reroll[1].face], wSuit[reroll[1].suit], wFace[reroll[2].face], wSuit[reroll[2].suit]);
		return 1;
	}
	else {
		int card1 = 0;
		int card2 = 0;
		int card3 = 0;

		dealer[card1].face = reroll[0].face;
		dealer[card1].suit = reroll[0].suit;

		dealer[card2].face = reroll[1].face;
		dealer[card2].suit = reroll[1].suit;

		dealer[card3].face = reroll[2].face;
		dealer[card3].suit = reroll[2].suit;

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
				if (cardFreq[j] == 3) {
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
int compare_hands(int ComboListP[], int ComboListD[], Card player[], Card dealer[], const char* wFace[], const char* wSuit[]) {
	//first, lets see if anyone has any combos!
	printf("\x1B[1;33m");

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
		printf("\nPLAYER WINS!\n"); return 2;
	}

	if (D == 1) {
		printf("\nDEALER WINS!\n"); return 1;
	}

	
	//now that ive decided whos got what when where and how, lets take a peek at what happens when both player and dealer have the same combo!
	if (PD||c) {
		//gotta sort hand first
		int minI = 0;
		int maxI = 0;
		Card temp;
		//so this should sort the dealers hand!
		for (int i = 0; i < 5; i++) {
			minI = i;
			for (int j = i + 1; j < 5; j++) {
				if (dealer[j].face <= dealer[minI].face) {
					minI = j;
				}
			}
			if (minI != i) {
				temp = dealer[i];
				dealer[i] = dealer[minI];
				dealer[minI] = temp;
			}
		}
		//so this should sort the players hand!
		for (int i = 0; i < 5; i++) {
			minI = i;
			for (int j = i + 1; j < 5; j++) {
				if (player[j].face <= player[minI].face) {
					minI = j;
				}
			}
			if (minI != i) {
				temp = player[i];
				player[i] = player[minI];
				player[minI] = temp;
			}
		}
		//now that they are sorted compare their 4th indexes to each other
		//first check the highest card in their deck, hand[4]
		if (dealer[4].face > player[4].face) {
			printf("Dealer has the highest card!\nWinning card: %s of %s\n", wFace[dealer[4].face], wSuit[dealer[4].suit]);
			return 1;
		}
		else if (dealer[4].face < player[4].face) {
			printf("Player has the highest card!\nWinning card: %s of %s\n", wFace[player[4].face], wSuit[player[4].suit]);
			return 2;
		}
		else if (dealer[4].face == player[4].face) {
			if (dealer[3].face > player[3].face) {
				printf("Dealer has the highest card!\nWinning card: %s of %s\n", wFace[dealer[3].face], wSuit[dealer[3].suit]);
				return 1;
			}
			else if (dealer[3].face < player[3].face) {
				printf("Player has the highest card!\nWinning card: %s of %s\n", wFace[player[3].face], wSuit[player[3].suit]);
				return 2;
			}
			else if (dealer[3].face == player[3].face) {
				if (dealer[2].face > player[2].face) {
					printf("Dealer has the highest card!\nWinning card: %s of %s\n", wFace[dealer[2].face], wSuit[dealer[2].suit]);
					return 1;
				}
				else if (dealer[2].face < player[2].face) {
					printf("Player has the highest card!\nWinning card: %s of %s\n", wFace[player[2].face], wSuit[player[2].suit]);
					return 2;
				}
				else if (dealer[2].face == player[2].face) {
					if (dealer[1].face > player[1].face) {
						printf("Dealer has the highest card!\nWinning card: %s of %s\n", wFace[dealer[1].face], wSuit[dealer[1].suit]);
						return 1;
					}
					else if (dealer[1].face < player[1].face) {
						printf("Player has the highest card!\nWinning card: %s of %s\n", wFace[player[1].face], wSuit[player[1].suit]);
						return 2;
					}
					else if (dealer[1].face == player[0].face) {
						if (dealer[0].face > player[0].face) {
							printf("Dealer has the highest card!\nWinning card: %s of %s\n", wFace[dealer[0].face], wSuit[dealer[0].suit]);
							return 1;
						}
						else if (dealer[0].face < player[0].face) {
							printf("Player has the highest card!\nWinning card: %s of %s\n", wFace[player[0].face], wSuit[player[0].suit]);
							return 2;
						}
						else if (dealer[0].face == player[0].face) {
							printf("Somehow, the dealer and player have identical hands! congratulations!\nYou have unlocked the secret ending! WAHOO!\n");
							return 3;
						}
					}
				}
			}
		}
		
	}


}

//betting function! makes the game more fun :)
int betting(int wager, int victor) {
	float bill = 0;
	if (victor == 1) {
		//dealer won, so total pool is deacreased by wager * 1.10
		bill =  -wager;
		return bill;
	}
	else if (victor == 2) {
		//player won, so total pool is increased by wager 
		bill = (float)wager * 1.3;
		return bill;
	}
	else if (victor == 3) {
		//identical hands, become god ig
		bill = 1000000;
		return bill;
	}
}