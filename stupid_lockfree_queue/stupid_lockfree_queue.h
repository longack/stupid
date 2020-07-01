#ifndef STUPID_LOCKFREE_QUEUE_H_
#define STUPID_LOCKFREE_QUEUE_H_

#include <atomic>
#include <type_traits>
#include "stupid_queue_node.h"

namespace stupid
{
	template <typename T> 
	class stupid_lockfree_queue
	{
	public:
		int enqueue(const T& data)
		{
			stupid_queue_node<T>* temp = new stupid_queue_node<T>(data);

			tail->next = temp;
			tail = tail->next;

			++size;
			return 0;
		}

		int dequeue(T& data)
		{
			if (!size) return -1;

			stupid_queue_node<T>* temp = dummy.next;

			data = temp->data;
			dummy.next = temp->next;

			if (1 == size) tail = &dummy;

			delete temp;
			--size;
			return 0;
		}

		stupid_lockfree_queue() 
		{ 
			tail = &dummy; 
			size = 0;
		}

	private:
		stupid_queue_node<T>* tail;
		stupid_queue_node<T> dummy;

		unsigned int size;
	};
}

#endif 
