#include <Windows.h>
#include "BehaviourTree.h"

bool isRunning = true;

int main()
{
	BehaviourTree *bt = new BehaviourTree();
	bt->addLeaf(new Leaf_TerminalWrite("terminal write leaf 1"));
	bt->addLeaf(new Leaf_TerminalWrite("Terminal write leaf 2"));

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