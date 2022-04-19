#pragma once
#include <iostream>
#include <iterator>
#include <vector>

#include "Leaf.h"
#include "CompositeLeaf.h"
#include "Leaf_TerminalWrite.h"
#include "Leaf_SleepFor.h"

class BehaviourTree
{
	public:
		bool tick();
		void addLeaf(Leaf* leaf);

	private:
		int currentIndex = 0;
		Leaf* activeLeaf = NULL;
		std::vector<Leaf*> leaves;

		bool getNextLeaf();
};