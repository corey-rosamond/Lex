#pragma once
#include <string>


#include "Leaf.h"

class Leaf_TerminalWrite : public Leaf
{
	public:
		Leaf_TerminalWrite(std::string whatToSay);

		void tick() override;


	private:
		std::string whatToSay;
};