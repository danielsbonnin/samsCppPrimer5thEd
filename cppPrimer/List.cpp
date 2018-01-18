#include "stdafx.h"
#include "List.h"
#include <iostream>

namespace LIST {
	bool List::add(ListData d)
	{
		if (!isFull())
		{
			arr[count] = d;
			count++;
			return true;
		}
		return false;
	}

	bool List::isEmpty() const
	{
		return (count == 0);
	}

	bool List::isFull() const
	{
		return (count == LEN);
	}

	void List::visit(void(*pf) (ListData &))
	{
		int n = LEN > count ? count : LEN;
		for (int i = 0; i < n; ++i)
			pf(arr[i]);
	}

	List::~List()
	{
	}
}