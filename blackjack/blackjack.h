#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include<boost/range/numeric.hpp>

using namespace std;

//number of decks
const int NUM_DECK = 4;

double score_hand_hit();
double score_hand_split();

std::map<int, int> init_prob_table(int NUM_DECK);
std::map<int, int> update_prob_table(std::map<int, int> prob_table, int card);
double score_hand_stand(vector<int> player_cards, vector<int> dealer_cards, std::map<int, int> prob_table);