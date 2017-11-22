#ifndef SDI_CARD_H
#define SDI_CARD_H

#include <vector>
#include <string>

namespace SDI_REVIEW
{
	class Card
	{
		// data members
	private:
		int suit_;
		int faceValue_;
		int gameValue_;
		std::vector<std::string> suitNames = { "Hearts", "Clubs", "Diamonds", "Spades" };
		std::vector<std::string> faceNames = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
		
		//interface functions
	public:
		Card(int cardNum);		//Constructor (parameterised)
		std::string toString();
		int getValue();

		//private functions
	private:
		std::string suitName(int suitNum);
		std::string faceName(int faceVal);
	};

}  //namespace
#endif