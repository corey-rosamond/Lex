#include "Leaf.h"

Leaf::Leaf()
{
	this->setStateIdle();
	this->setOutcomeUndefined();
}

void Leaf::tick()
{
	if (this->isStateIdle())
	{
		this->setStateRunning();
	}
}

void Leaf::reset()
{
	this->setStateIdle();
	this->setOutcomeUndefined();
}

bool Leaf::isStateIdle()
{
	return this->state == Leaf_State::IDLE;
}

bool Leaf::isStateRunning()
{
	return this->state == Leaf_State::RUNNING;
}

bool Leaf::isStateComplete()
{
	return this->state == Leaf_State::COMPLETE;
}

bool Leaf::isOutcomeUndefined()
{
	return this->outcome == Leaf_Outcome::UNDEFINED;
}

bool Leaf::isOutcomeSuccess()
{
	return this->outcome == Leaf_Outcome::SUCCESS;
}

bool Leaf::isOutcomeFailure()
{
	return this->outcome == Leaf_Outcome::FAILURE;
}

void Leaf::setStateIdle()
{
	this->state = Leaf_State::IDLE;
}

void Leaf::setStateRunning()
{
	this->state = Leaf_State::RUNNING;
}

void Leaf::setStateComplete()
{
	this->state = Leaf_State::COMPLETE;
}

void Leaf::setOutcomeUndefined()
{
	this->outcome = Leaf_Outcome::UNDEFINED;
}

void Leaf::setOutcomeSuccess()
{
	this->outcome = Leaf_Outcome::SUCCESS;
}

void Leaf::setOutcomeFailure()
{
	this->outcome = Leaf_Outcome::FAILURE;
}