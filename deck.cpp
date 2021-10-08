#include "deck.h"

// Insertion sort algorithm used in Deck object sort() to sort the deck by suit or value.
// Sorts a certain range of the deck array from deck[start] to deck[end-1].
// Not a Deck object.
//
// @param[in] deck[]  The deck array containing 52 cards.
// @param[in] start   The deck array is sorted starting from deck[start].
// @param[in] end     The deck array is sorted until deck[end-1].
// @param[in] suit    1 if the deck is sorted by suits and 0 if sorted by value.
void insertion_sort(Card deck[], int start, int end, int suit)
{
  for (int i = start; i < end-1; i++)
  {
    for (int j = i+1; j > start; j--)
    {
      // If we are sorting the deck by suits
      if (suit)
      {
        // Get the suits of the current and the next cards
        Card::Suit suit_1 = deck[j-1].get_suit();
        Card::Suit suit_2 = deck[j].get_suit();
        // If the suit of the current card is greater than the suit of the next card, swap the two cards.
        if (suit_1 > suit_2)
        {
          swap(deck[j-1], deck[j]);
        }
        // If the suit of the current card is less than the suit of the next card, proceed to analyze the next card as the current card.
        else
        {
          break;
        }
      // If we are sorting the deck by value and the current card is greater than the next card, swap the two cards.
      }
      else if (deck[j-1] > deck[j])
      {
        swap(deck[j-1], deck[j]);
      }
      // If the value of the current card is less than the value of the next card, proceed to analyze the next card as the current card.
      else
      {
        break;
      }
    }
  }
}

// Constructor
Deck::Deck()
{
  int value = 1;  // Initialize the value of the card to be 1 (ACE).
  int suit = 0;   // Initialize the suit of the card to be 0 (DIAMONDS).
  for (int i = 0; i < deck_size; i++)
  {
    // Create a card with a value of 'value' and 'suit'.  
    Card card(value, suit);
    // Store the card in the deck array.
    deck[i] = card;
    // If the value of the card is 13, set the value to zero and increment the suit.
    if (value == 13)
    {
      value = 0;
      suit++;
    }
    // Increment the value of the card.
    value++;
  }
}

// Destructor
Deck::~Deck()
{
}

//
// Deck::deal_hand
//
void Deck::deal_hand(int sets, int cards)
{
  for (int i = 0; i < sets; i++)
  {
    int itr_cards = 0; // Counts the number of cards printed in each set.
    while (itr_cards < cards)
    {
      // Print the cards in each hand(set).
      deck[i+(itr_cards*sets)].print();
      // Increment the counter.
      itr_cards++;
    }
    // Print a newline character after each set.
    cout << "\n";
  }
}

//
// Deck::print_deck
//
void Deck::print_deck()
{
  for (int i = 1; i <= deck_size; i++)
  {
    // Print each card to std out.
    deck[i-1].print();
    // Print a newline character every 13 cards.
    if (i % 13 == 0)
    {
      cout << "\n";
    }
  }
}

//
// Deck::shuffle
//
void Deck::shuffle(int seed)
{
  // Initialize random number generator using 'seed'.
  srand(seed);
  // Rearrange elements in deck array randomly (generated from 'seed').
  random_shuffle(&deck[0], &deck[deck_size]);
}

//
// Deck::sort
//
void Deck::sort()
{
  // Sort the deck by suit.
  insertion_sort(deck, 0, deck_size, 1);
  
  // Sort the deck by value.
  for (int i = 0; i < 4; i++)
  {
    insertion_sort(deck, i*13, (i+1)*13, 0);
  }
}
