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
			stupid_queue_node<T>* temp_node = new stupid_queue_node<T>(data);

			if (std::atomic_compare_exchange_weak(&size, 0, 1))
			{
				tail = head = temp_node;
				return 0;
			}

			size.fetch_add(1, std::memory_order_relaxed);
			return 0;
		}

		int dequeue(T& data)
		{
			return 0;
		}

		stupid_lockfree_queue() 
		{
			tail = head = nullptr;
			size = 0;
		}

	private:
		stupid_queue_node<T>* tail;
		stupid_queue_node<T>* head;



		std::atomic_int size;
	};
}

#endif 
