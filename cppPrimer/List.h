#pragma once
namespace LIST {
	typedef int ListData;
	class List
	{
		static const int LEN = 10;
		int arr[LEN];
		int count;
	public:
		List() { count = 0; }
		bool add(ListData x);
		bool isEmpty() const;
		bool isFull() const;
		void visit(void(*pf)(ListData &));
		~List();
	};
}

