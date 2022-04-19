#include "Leaf_SleepFor.h"

Leaf_SleepFor::Leaf_SleepFor(int milliseconds)
{
	this->sleepFor = milliseconds;
}

void Leaf_SleepFor::tick()
{
	if (this->isStateIdle())
	{
		this->setStateRunning();
	}
	if (this->startTime == NULL)
	{
		this->startTime = this->timeSinceEpochMilliseconds();
	}
	if ((this->startTime + this->sleepFor) <= this->timeSinceEpochMilliseconds())
	{
		this->setStateComplete();
		this->setOutcomeSuccess();
	}
	else {
		std::cout << "sleeping" << std::endl;
	}
}

int Leaf_SleepFor::timeSinceEpochMilliseconds()
{
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}