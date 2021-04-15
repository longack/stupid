#ifndef STUPID_QUEUE_NODE_H_
#define STUPID_QUEUE_NODE_H_

namespace stupid
{
	template <typename T> 
	class stupid_queue_node 
	{
	public:
		stupid_queue_node<T>(const T& element)
		{
			data = element;
			next = nullptr;
		}

		stupid_queue_node<T>(const T&& element)
		{
			data = std::move(element);
			next = nullptr;
		}

		stupid_queue_node<T>() { next = nullptr; }

	public:
		stupid_queue_node<T>* next;
		T data;
	};
}

#endif 
