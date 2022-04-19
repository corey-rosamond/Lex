#pragma once
#include <iostream>
#include "Leaf_State.h"
#include "Leaf_Outcome.h"

class Leaf
{
	public:

		Leaf();
		virtual void tick();
		virtual void reset();



		bool isStateIdle();
		bool isStateRunning();
		bool isStateComplete();

		bool isOutcomeUndefined();
		bool isOutcomeSuccess();
		bool isOutcomeFailure();

	protected:

		void setStateIdle();
		void setStateRunning();
		void setStateComplete();
			
		void setOutcomeUndefined();
		void setOutcomeSuccess();
		void setOutcomeFailure();

	private:
		Leaf_State state = Leaf_State::IDLE;
		Leaf_Outcome outcome = Leaf_Outcome::UNDEFINED;

};