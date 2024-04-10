#include "Header.h"




int main(void)
{
	int cardFreqP[13] = { 0 };
	int cardFreqD[13] = { 0 };

	//possible idea for judging point values?
	int ComboListP[7] = { 0 };
	int ComboListD[7] = { 0 };

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
	//checking combos
	ComboListP[0] = check_pair(cardFreqP, face);
	ComboListD[0] = check_pair(cardFreqD, face);
	ComboListP[1] = check_two_pair(cardFreqP, face);
	ComboListD[1] = check_two_pair(cardFreqD, face);
	ComboListP[2] = check_trio(cardFreqP, face);
	ComboListD[2] = check_trio(cardFreqD, face);
	ComboListP[3] = check_house(cardFreqP, face);
	ComboListD[3] = check_house(cardFreqP, face);

	return 0;
}
