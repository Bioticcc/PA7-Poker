#include "Header.h"




int main(void)
{
	int cardFreqP[13] = { 0 };
	int cardFreqD[13] = { 0 };

	Card player[5] = { 0 };
	Card dealer[5] = { 0 };
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	int deck[4][13] = { 0 };
	srand((unsigned)time(NULL));


	//actual game stuff
	menu();
	shuffle(deck);
	deal(deck, face, suit, dealer, player);
	displayHand(face, suit, player);
	printf("-------PLAYER CARD FREQUENCIES-------\n");
	CardFrequency(player, cardFreqP, face);
	printf("-------DEALER CARD FREQUENCIES-------\n");
	CardFrequency(dealer, cardFreqD, face);
	return 0;
}
