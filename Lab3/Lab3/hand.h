#ifndef SDI_HAND_H
#define SDI_HAND_H

#include <vector>

#include "card.h"
#include "deck.h"

namespace SDI_REVIEW
{
	class Hand
	{
	private:
		std::vector<Card> theHand_;
		int handValue;
	public:
		Hand(Deck &mydeck);
		void drawCard(Deck &deck);
		void printHand();
	};
}//namespace
#endif