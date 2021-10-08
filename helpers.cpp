#include "helpers.h"

void insertion_sort(Card deck[], int start, int end, bool sortBySuit)
{
    for (int i = start; i < end - 1; i++)
    {
        for (int j = i + 1; j > start; j--)
        {
            // If we are sorting the deck by suits
            if (sortBySuit)
            {
                // Get the suits of the current and the next cards
                Card::Suit suit_1 = deck[j - 1].get_suit();
                Card::Suit suit_2 = deck[j].get_suit();
                // If the suit of the current card is greater than the suit of the next card, swap the two cards.
                if (suit_1 > suit_2)
                {
                    swap(deck[j - 1], deck[j]);
                }
                // If the suit of the current card is less than the suit of the next card, proceed to analyze the next card as the current card.
                else
                {
                    break;
                }
                // If we are sorting the deck by value and the current card is greater than the next card, swap the two cards.
            }
            else if (deck[j - 1] > deck[j])
            {
                swap(deck[j - 1], deck[j]);
            }
            // If the value of the current card is less than the value of the next card, proceed to analyze the next card as the current card.
            else
            {
                break;
            }
        }
    }
}