//This is a blackjack game and its strategy development
//I'm mostly practising vectors

#include "blackjack.h"

int main() {
	vector<int> cards = { 10,9 };
	vector<int> dealer = { 6 };
	vector<int> dealt = { 6, 9, 10 };

	cout << score_hand_stand(cards, dealer, dealt);

	cin.get();
	cin.get();
	return 0;
	}