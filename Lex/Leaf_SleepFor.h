#pragma once
#include <chrono>
#include "Leaf.h"

class Leaf_SleepFor : public Leaf
{
	public:
		Leaf_SleepFor(int milliseconds);
		void tick() override;

	protected:


	private:
		int startTime = NULL;
		int sleepFor = 0;
		int timeSinceEpochMilliseconds();

};