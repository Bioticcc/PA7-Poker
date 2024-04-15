#include "Header.h"




int main(void)
{
	while (1) {
		int cardFreqP[13] = { 0 };
		int cardFreqD[13] = { 0 };
		
		int ComboListP[7] = { 0 };
		int ComboListD[7] = { 0 };
		Card possibleCardRerollsP[4] = { 0 };
		Card possibleCardRerollsD[4] = { 0 };
		Card player[5] = { 0 };
		Card dealer[5] = { 0 };
		const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		const char* face[13] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King","Ace" };
		int deck[4][13] = { 0 };
		srand((unsigned)time(NULL));

		//actual game stuff
		menu();
		shuffle(deck);
		deal(deck, face, suit, dealer, player, possibleCardRerollsP, possibleCardRerollsD);
		displayHand(face, suit, player, dealer);

		//allows for player and dealer to reroll up to 3 of their cards
		redrawCards(deck, face, suit, player, dealer, possibleCardRerollsP);
		printf("\nDEALERS TURN TO REDRAW CARDS...\n");
		
		
		
		printf("-------DEALER CARD FREQUENCIES-------\n");
		CardFrequency(dealer, cardFreqD, face);
		ComboListP[0] = check_pair(cardFreqP, face);
		ComboListD[0] = check_pair(cardFreqD, face);
		ComboListP[1] = check_two_pair(cardFreqP, face);
		ComboListD[1] = check_two_pair(cardFreqD, face);
		ComboListP[2] = check_trio(cardFreqP, face);
		ComboListD[2] = check_trio(cardFreqD, face);
		ComboListP[6] = check_four(cardFreqP, face);
		ComboListD[6] = check_four(cardFreqP, face);
		ComboListP[5] = check_house(cardFreqP, face);
		ComboListD[5] = check_house(cardFreqP, face);
		ComboListP[4] = check_flush(player);
		ComboListD[4] = check_flush(dealer);
		ComboListP[3] = check_straight(player, face);
		ComboListD[3] = check_straight(dealer, face);
		//dealer AI
		DealerAI(deck, face, suit, dealer, possibleCardRerollsD, ComboListD, cardFreqD);
		system("pause");
		system("cls");
		displayHand(face, suit, player, dealer);

		//quickly reseting dealers frequency array
		for (int i = 0; i < 13; i++) {
			cardFreqD[i] = 0;
		}

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
		ComboListP[6] = check_four(cardFreqP, face);
		ComboListD[6] = check_four(cardFreqP, face);
		ComboListP[5] = check_house(cardFreqP, face);
		ComboListD[5] = check_house(cardFreqP, face);
		ComboListP[4] = check_flush(player);
		ComboListD[4] = check_flush(dealer);
		ComboListP[3] = check_straight(player, face);
		ComboListD[3] = check_straight(dealer, face);

		//comparing hands to decide victor of round
		compare_hands(ComboListP, ComboListD, player, dealer);

		system("pause");
		system("cls");

	}
}
