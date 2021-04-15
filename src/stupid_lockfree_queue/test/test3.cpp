#include <string>
#include <stdio.h>
#include <iostream>
#include "stupid_lockfree_queue.h"

class kv
{
public:
	kv() = default;
	kv(const std::string k, const std::string v)
	{
		key = k;
		value = v;
	}

	void print() { std::cout << "key: " << key << " value: " << value << std::endl; }

private:
	std::string key;
	std::string value;
};

int main(int argc, char* argv[])
{
	stupid::stupid_lockfree_queue<kv> test_queue;

	kv get;

	while (true)
	{
		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();

		test_queue.enqueue(kv("ddd", "twq"));
		test_queue.enqueue(kv("jasdklfakl", "twq"));
		test_queue.enqueue(kv("ddd", "twq"));
		test_queue.enqueue(kv("023948jds", "twq"));

		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();

		test_queue.enqueue(kv("ddd", "twq"));
		test_queue.enqueue(kv("jaklsdjasdfkl", "twq"));
		test_queue.enqueue(kv("cujikddd", "twq"));
		test_queue.enqueue(kv("ddddafd", "twq"));

		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();
		test_queue.dequeue(get); get.print();
	};

	return 0;
}
