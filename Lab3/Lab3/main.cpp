#include <string>
#include <iostream>

#include "card.h"
#include "deck.h"
#include "hand.h"

using namespace std;
using namespace SDI_REVIEW;

int main(int argc, char* argv[])
{
	Deck myDeck;
	/*myDeck.printSize();
	for (int c = 0; c < 52; ++c)
	{
		cout << myDeck.nextCard().toString() << endl;
	}*/
	Hand myHand(myDeck);
	myHand.printHand();

	return 0;
}