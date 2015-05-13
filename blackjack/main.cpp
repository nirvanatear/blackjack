//This is a blackjack game and its strategy development
//I'm mostly practising vectors

#include "blackjack.h"

int main() {
	vector<int> cards = { 10,10 };
	vector<int> dealer = { 11,4 };
	vector<int> dealt = { 0,3,11,12};

	std::map<int, int> prob_table = init_prob_table(4);
	prob_table = update_prob_table(update_prob_table(update_prob_table(update_prob_table(prob_table, 4), 11), 10), 10);
	cout << score_hand_stand_2(cards, dealer, prob_table) <<'\n';

	cout << score_hand_stand(cards, dealer, dealt) << '\n';
	cin.get();
	cin.get();
	return 0;
	}