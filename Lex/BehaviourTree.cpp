#include "BehaviourTree.h"


bool BehaviourTree::tick()
{
	if (this->leaves.empty())
	{
		std::cout << "The Behaviour Tree is Empty!" << std::endl;
		return false;
	}

	if (this->activeLeaf == NULL)
	{
		this->activeLeaf = this->leaves.at(this->currentIndex);
	}

	if (this->activeLeaf->isStateComplete())
	{
		if (!this->getNextLeaf())
		{
			// Decide what to do when there is not a next leaf;
			return false;
		}
	}

	this->activeLeaf->tick();
	return true;
}

void BehaviourTree::addLeaf(Leaf* leaf)
{
	this->leaves.push_back(leaf);
}

bool BehaviourTree::getNextLeaf()
{
	if ((this->currentIndex + 1) >= this->leaves.size())
	{
		return false;
	}
	this->currentIndex++;
	this->activeLeaf = this->leaves.at(this->currentIndex);
	return true;
}