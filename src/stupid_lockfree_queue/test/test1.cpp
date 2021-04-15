#include "stdio.h"
#include "stupid_lockfree_queue.h"

int main(int argc, char* argv[]) 
{
	int get = -1;
	stupid::stupid_lockfree_queue<int> test_queue;

	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);

	test_queue.enqueue(3);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.enqueue(8);
	test_queue.enqueue(9);
	test_queue.enqueue(3);
	test_queue.enqueue(59);
	test_queue.enqueue(2333);
	test_queue.enqueue(7);
	test_queue.enqueue(3);
	test_queue.enqueue(43434);
	test_queue.enqueue(3434);

	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);
	test_queue.dequeue(get); printf("get from queue: %d\n", get);

	test_queue.enqueue(39);
	test_queue.enqueue(44);
	test_queue.enqueue(78);

	return 0;
}
