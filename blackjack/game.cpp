#include "blackjack.h"


template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last)
			out << ", ";
	}
	out << "]";
	return out;
}

std::map<int, int> init_prob_table(int NUM_DECK){
	std::map<int, int> table;
	
	table[11] = NUM_DECK * 4;
	table[10] = NUM_DECK * 4 * 4;
	table[9]  = NUM_DECK * 4;
	table[8]  = NUM_DECK * 4;
	table[7]  = NUM_DECK * 4;
	table[6]  = NUM_DECK * 4;
	table[5]  = NUM_DECK * 4;
	table[4]  = NUM_DECK * 4;
	table[3]  = NUM_DECK * 4;
	table[2]  = NUM_DECK * 4;
	table[0]  = NUM_DECK * 4 * 13;
	return table;
}

std::map<int, int> update_prob_table(std::map<int, int> prob_table, int card){
	prob_table[card] -= 1;
	prob_table[0] -= 1;
	return prob_table;
}


double score_hand_stand(vector<int> player_cards, vector<int> dealer_cards, std::map<int, int> prob_table){
	int player_sum = boost::accumulate(player_cards, 0);
	int dealer_sum = boost::accumulate(dealer_cards, 0);
	double total_score = 0; 

	for (int card = 2; card <= 11; card++){
		float card_prob = (double)prob_table[card] / (double)prob_table[0];
		cout << "dealt" << dealer_cards << "card" << card << "prob" << card_prob << '\n';
		if (dealer_sum + card > 21) {
			total_score += card_prob;
		}
		else if (dealer_sum + card >= 17) {
			if (dealer_sum + card > player_sum) {
				total_score += -card_prob;
			}
			else if (dealer_sum + card == player_sum) {
				total_score += 0;
			}
			else  {
				total_score += card_prob;
			}
		}
		else if (dealer_sum + card > player_sum) {
			total_score += -card_prob;
		}
		else {
			vector<int> new_dealer_cards = dealer_cards; new_dealer_cards.push_back(card);
			std::map<int, int> new_prob_table = update_prob_table(prob_table, card);
			total_score += card_prob * score_hand_stand(player_cards, new_dealer_cards, new_prob_table);
		}
	}

	return total_score;
}