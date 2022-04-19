#include "CompositeLeaf.h"

void CompositeLeaf::tick()
{
	if (this->isStateIdle())
	{
		this->setStateRunning();
	}

	if (this->leaves.empty())
	{
		std::cout << "Leaves vector is empty!" << std::endl;
	}
	else
	{
		if (this->currentLeaf == NULL)
		{
			this->currentLeaf = this->leaves.at(this->currentIndex);
		}

		if (this->currentLeaf->isStateComplete())
		{
			if (!this->getNextLeaf())
			{
				this->setStateComplete();
				this->setOutcomeSuccess();
			}
		}

		if(this->isStateRunning())
		{
			this->currentLeaf->tick();
		}
	}
}

void CompositeLeaf::addLeaf(Leaf* leaf)
{
	this->leaves.push_back(leaf);
}

bool CompositeLeaf::getNextLeaf()
{
	if ((this->currentIndex + 1) >= this->leaves.size())
	{
		return false;
	}
	this->currentIndex++;
	this->currentLeaf = this->leaves.at(this->currentIndex);
	return true;
}