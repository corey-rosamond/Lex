#include <Windows.h>
#include "BehaviourTree.h"

bool isRunning = true;

int main()
{
	BehaviourTree *bt = new BehaviourTree();
	CompositeLeaf *cl = new CompositeLeaf();
	cl->addLeaf(new Leaf_TerminalWrite("terminal write leaf 1"));
	cl->addLeaf(new Leaf_SleepFor(100));
	cl->addLeaf(new Leaf_TerminalWrite("Terminal write leaf 2"));
	cl->addLeaf(new Leaf_SleepFor(1000));
	cl->addLeaf(new Leaf_TerminalWrite("Terminal write leaf 3"));
	cl->addLeaf(new Leaf_SleepFor(10000));
	cl->addLeaf(new Leaf_TerminalWrite("Terminal write leaf 4"));
	bt->addLeaf(cl);

	do {
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			isRunning = false;
			continue;
		}
		bt->tick();
	} while (isRunning);
	return 0;
}