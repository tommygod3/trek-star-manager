#ifndef SDI_DECK_CPP
#define SDI_DECK_CPP

#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ctime>

#include "card.h"
#include "deck.h"


namespace SDI_REVIEW
{

		Deck::Deck()
		{
			for (int cardNum = 0; cardNum < 52; ++cardNum)
			{
				theDeck_.push_back(Card(cardNum));
			}
			Deck::shuffle();
		}

		void Deck::shuffle()
		{
			std::srand(std::time(0));
			std::random_shuffle(theDeck_.begin(), theDeck_.end());
		}

		void Deck::printSize()
		{
			int counter = 0;
			for (int i = 0; i < theDeck_.size(); i++)
			{
				counter++;
			}
			std::cout <<"The size of the deck is " << counter << std::endl;
		}

		Card Deck::nextCard()
		{
			assert(! theDeck_.empty());
			Card result = theDeck_.back();
			theDeck_.pop_back();
			return result;
		}

}  //namespace
#endif