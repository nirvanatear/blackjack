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
int int_to_card(int a){
	a = (a % 13) + 1;
	if (a == 1) return 11;
	else if (a >= 10) return 10;
	else return a;
}

int random_card(vector<int> dealt) {
	int rnd = std::rand() % (NUM_DECK * 52);
	while (std::find(dealt.begin(), dealt.end(), rnd) != dealt.end()) {
		rnd = std::rand() % (NUM_DECK * 52);
	}
	return rnd;
}

double score_hand_stand(vector<int> player_cards, vector<int> dealer_cards, vector<int> dealt){
	int player_sum = boost::accumulate(player_cards, 0);
	int dealer_sum = boost::accumulate(dealer_cards, 0);
	double total_score = 0; int total_deals = 0;
	
	for (int i = 0; i < NUM_DECK * 52; i++){
		if (std::find(dealt.begin(), dealt.end(), i) == dealt.end()) {
			int card = int_to_card(i);
			cout << "dealt" << dealer_cards << "card" << card << '\n';
			if (dealer_sum + card > 21) {
				total_score += 1; 
				total_deals += 1;
			}
			else if (dealer_sum + card >= 17) {
				if (dealer_sum + card > player_sum) {
					total_score += -1;
					total_deals += 1;
				}
				else if (dealer_sum + card == player_sum) {
					total_score += 0;
					total_deals += 1;
				}
				else  {
					total_score += 1;
					total_deals += 1;
				}
			}
			else if (dealer_sum + card > player_sum) {
				total_score += -1;
				total_deals += 1;
			}
			else {
				vector<int> new_dealer_cards = dealer_cards; new_dealer_cards.push_back(card);
				vector<int> new_dealt = dealer_cards;  new_dealt.push_back(i);
				total_score += score_hand_stand(player_cards, new_dealer_cards, new_dealt);
				total_deals += 1;
			}
		}
	}
	
	return total_score/total_deals;
}

