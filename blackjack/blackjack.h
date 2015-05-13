#include <iostream>
#include <vector>
#include <cstdlib>
#include<boost/range/numeric.hpp>

using namespace std;

//number of decks
const int NUM_DECK = 1;

int int_to_card(int a);

int random_card();
double score_hand_stand(vector<int> player_cards, vector<int> dealer_cards, vector<int> dealt);
double score_hand_hit();
double score_hand_split();
bool dealer_deal(vector<int> dealt, int dealer_card, int player_score);