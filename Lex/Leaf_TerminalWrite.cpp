#include "Leaf_TerminalWrite.h"

Leaf_TerminalWrite::Leaf_TerminalWrite(std::string whatToSay)
{
	Leaf::Leaf();
	this->whatToSay = whatToSay;
}

void Leaf_TerminalWrite::tick()
{
	Leaf::tick();

	std::cout << this->whatToSay << std::endl;

	this->setStateComplete();
	this->setOutcomeSuccess();
}