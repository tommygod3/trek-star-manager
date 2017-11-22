#ifndef SDI_HAND_CPP
#define SDI_HAND_CPP

#include <vector>
#include <iostream>

#include "card.h"
#include "deck.h"
#include "hand.h"

namespace SDI_REVIEW
{
	Hand::Hand(Deck &mydeck)
	{
		handValue = 0;
		drawCard(mydeck);
		drawCard(mydeck);
	}

	void Hand::drawCard(Deck &deck)
	{
		Card draw = deck.nextCard();
		theHand_.push_back(draw);
		handValue = handValue + draw.getValue();
	}

	void Hand::printHand()
	{
		for (int i = 0; i < theHand_.size(); i++)
		{
			std::cout << theHand_[i].toString() << std::endl;
		}
		std::cout << "Size is: " << handValue << std::endl;
	}

}//namespace
#endif