// helpers.h
//
// @brief Contains helper functions.
//

#ifndef _HELPERS_H
#define _HELPERS_H

#include "card.h"

// Insertion sort algorithm used in Deck object sort() to sort the deck by suit or value.
// Sorts a certain range of the deck array from deck[start] to deck[end-1].
// Not a Deck object.
//
// @param[in] deck[]        The deck array containing 52 cards.
// @param[in] start         The deck array is sorted starting from deck[start].
// @param[in] end           The deck array is sorted until deck[end-1].
// @param[in] sortBySuit    true if the deck is sorted by suits and false if sorted by value.
void insertion_sort(Card deck[], int start, int end, bool sortBySuit = false);

#endif