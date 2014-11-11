#include "Player.h"
#include "PlayerQueue.h"
#include <iostream>

	using std::cout;
	using std::endl;

int main(){


	Player grant("Grant");
	Player david("David");
	Player anders("Anders");
	Player steve("Steve");
	Player chris("Chris");

	PlayerQueue queue;
	
	queue.enqueue(grant);
	queue.enqueue(david);
	queue.enqueue(chris);
	queue.enqueue(steve);
	queue.enqueue(anders);
	queue.printQueue();
	queue.dumpQueue();
	cout<<"dumping queue: "<<endl;
	cout<<"size: "<<queue.getSize()<<endl;
	queue.enqueue(david);
	queue.testPrint();
	queue.printQueue();
	queue.enqueue(grant);
	queue.printQueue();


	return 0;

}