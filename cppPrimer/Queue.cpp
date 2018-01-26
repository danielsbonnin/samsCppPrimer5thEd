#include "stdafx.h"
#include "Queue.h"
#include <cstdlib>
Queue::Queue(int qs) : qsize(qs)    // initialize qsize to qs
{
	front = rear = NULL;
	items = 0;
}


Queue::~Queue()
{
	Node * temp;
	while (front != NULL)    // while queue is not  yet empty
	{
		temp = front;        // save address of front item
		front = front->next; // reset pointer to next item
		delete temp;         // delete former front
	}
}

bool Queue::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node;   // create node
	if (add == NULL)
		return false;        // quit if none available
	add->item = item;        // set node ointers
	add->next = NULL;
	items++;
	if (front == NULL)       // if queue is empty,
		front = add;         // place item at front
	else
		rear->next = add;    // else place at reat
	rear = add;              // have rear point to new node
	return true;
}

bool Queue::dequeue(Item & item)
{
	if (front == NULL)
		return false;
	item = front->item;        // set item to first item in queue
	items--;
	Node * temp = front;       // save location of first item
	front = front->next;       // reset front to next item
	delete temp;               // delete former first item
	if (items == 0)
		rear = NULL;
	return true;
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

// customer methods

// when is the time at whcih the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}