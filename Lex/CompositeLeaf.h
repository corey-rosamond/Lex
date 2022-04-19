#pragma once
#include <vector>
#include "Leaf.h"

class CompositeLeaf: public Leaf
{
	public:
		void tick() override;
		void addLeaf(Leaf* leaf);
		
	protected:
		bool getNextLeaf();

	private:
		int currentIndex = 0;
		Leaf *currentLeaf = NULL;
		std::vector<Leaf*> leaves;
};

