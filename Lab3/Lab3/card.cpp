#ifndef SDI_CARD_CPP
#define SDI_CARD_CPP

#include <string>
#include <cassert>
#include <vector>

#include "card.h"

namespace SDI_REVIEW
{

		Card::Card(int cardNum)
		{
			assert(cardNum < 52);
			faceValue_ = cardNum % 13;
			if (faceValue_ >= 11)
			{
				gameValue_ = 10;
			}
			else
			{
				gameValue_ = faceValue_ + 1;
			}
			suit_ = cardNum / 13;
		}

		int Card::getValue()
		{
			return gameValue_;
		}

		std::string Card::toString()
		{
			std::string result;
			result = faceName(faceValue_);
			result += " of ";
			result += suitName(suit_);
			return result;
		}

		std::string Card::suitName(int suitNum)
		{
			assert(suitNum < 4);
			return (suitNames[suitNum]);
		}

		std::string Card::faceName(int faceVal)
		{
			assert(faceVal < 13);
			return (faceNames[faceVal]);
		}

}  //namespace
#endif