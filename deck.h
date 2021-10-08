// deck.h
//
// @brief A class that represents a deck of playing cards
//
// @details
// This class is responsible for shuffling and dealing a deck of cards. The deck should
// contain 52 cards 2 - 10, Jack,Queen, King, Ace of four suits, but no jokers.
//

#include <iostream>
#include <string>
#include <stdlib.h>  // For srand()
#include <algorithm> // For random_shuffle() and swap()
#include "card.h"

using namespace std;

class Deck
{
public:

  // Initialize the size of the deck
  static const int deck_size = 52;
  
  // Constructor
	Deck();

  // Destructor
	~Deck();

  // Prints N sets of M cards.
  //
  // @param[in] sets  The number representing how many sets to print.
  // @param[in] cards The number of cards in each set.
	void deal_hand(int sets, int cards);

  // Prints the entire deck to standard out.
  // Prints 4 rows of 13 cards each.
	void print_deck();

  // Shuffles the deck randomly using a seedable random number generator.
  //
  // @param[in] seed  A number used to initialize a random number generator.
	void shuffle(int seed);

  // Sorts the deck from lowest to highest by suit then by card face value.
	void sort();
	
private:

  Card deck[deck_size]; // Initialize an array of size 52 to create an array of cards.
};