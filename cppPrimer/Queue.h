#pragma once
class Customer
{
private:
	long arrive;        // arrival time for customer
	int processtime;	// processing time for customer
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
// class scope definitions
	// Node is a nested structure definition local to this class
	enum { Q_SIZE = 10 };
	struct Node { Item item; struct Node * next; };
	// private class members
	Queue(const Queue & q) : qsize(0) { }    // preemptive definition
	Queue & operator=(const Queue & q) { return *this; }
	Node * front;        // pointer to front of Queue
	Node * rear;         // pointer to rear of Queue
	int items;           // current number of items in Queue
	const int qsize;     // maximum number of items in Queue
	
public:
	Queue(int qs = Q_SIZE); // create queue with a qs limit
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item); // add item to end
	bool dequeue(Item &item);       // remove item from front
};