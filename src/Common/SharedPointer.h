#ifndef SHAREDPOINTER_H_
#define SHAREDPOINTER_H_

#include <stdio.h>
#include <sys/types.h>
#include <system_error>

#undef PRINT_CONSTRUCTION 
#undef PRINT_DESTRUCTION
#undef PRINT_POINTER_DEL
#undef PRINT_USE
#undef PRINT_ANOTHER_USE

#ifndef NDEBUG
	#define PRINT_POINTER_DEL 	\
		printf("[%s:%d] going to delete pointer\n", __FILE__, __LINE__)

	#define PRINT_DEL_CHECK		\
		printf("[%s:%d] check to delete pointer\n", __FILE__, __LINE__)

	#define PRINT_PTR_INFO 		\
		if (_data)				\
			printf("[%s:%d] object(%p) -> { _use: %d, _raw: %p }\n", __FILE__, __LINE__, this, _data->_use, _data->_raw);

	#define PRINT_ANOTHER_INFO	\
		if (another._data)		\
			printf("[%s:%d] object(%p) -> { _use: %d, _raw: %p }\n", __FILE__, __LINE__, &another, another._data->_use, another._data->_raw);

#else 
	#define PRINT_POINTER_DEL
	#define PRINT_DEL_CHECK
	#define PRINT_PTR_INFO
	#define PRINT_ANOTHER_INFO

#endif 

namespace stupid
{

template <typename T>
class SharedPointer
{
public:
	SharedPointer(T const& value) : _data(new rc)
	{
		_data->_use = 1; 
		_data->_raw = value;

		PRINT_PTR_INFO;
	}

	SharedPointer() : _data(0x00) { }

	~SharedPointer()
	{ 
		PRINT_PTR_INFO;

		PRINT_DEL_CHECK;
		if (_data && !--_data->_use) 
		{
			PRINT_POINTER_DEL;
			delete _data; 
		}
	}

	SharedPointer(SharedPointer<T> const& another)
	{
		PRINT_ANOTHER_INFO;

		_data = another._data;

		if (another._data) 
		{
			++another._data->_use;
		}

		PRINT_ANOTHER_INFO;
		PRINT_PTR_INFO;
	}

	SharedPointer(SharedPointer<T> const&& another)
	{
		PRINT_ANOTHER_INFO;

		_data = another._data;

		if (another._data) 
		{
			++another._data->_use;
		}

		PRINT_ANOTHER_INFO;
		PRINT_PTR_INFO;
	}

	SharedPointer<T> const operator=(SharedPointer<T> const& another)
	{
		PRINT_ANOTHER_INFO;
		PRINT_PTR_INFO;

		// add another first can avoid self-assgin check
		if (another._data)
		{
			++another._data->_use; 
		}

		PRINT_DEL_CHECK;
		if (_data && !--_data->_use) 
		{
			PRINT_POINTER_DEL;
			delete _data;
		}

		_data = another._data;

		PRINT_ANOTHER_INFO;
		PRINT_PTR_INFO;

		return *this;
	}

	SharedPointer<T> const operator=(SharedPointer<T> const&& another)
	{
		PRINT_ANOTHER_INFO;
		PRINT_PTR_INFO;

		// add another first can avoid self-assgin check
		if (another._data)
		{
			++another._data->_use; 
		}

		PRINT_DEL_CHECK;
		if (_data && !--_data->_use) 
		{
			PRINT_POINTER_DEL;
			delete _data;
		}

		_data = another._data;

		PRINT_ANOTHER_INFO;
		PRINT_PTR_INFO;

		return *this;
	}

	T& operator*()
	{ 
		PRINT_PTR_INFO;
		return _data->_raw;
	}

	T* operator->()
	{
		PRINT_PTR_INFO;
		return &(_data->_raw);
	}
	
private:
	struct rc { int _use; T _raw; }* _data;
};

template <typename T, typename ...Args>
SharedPointer<T> MakeShared(Args ...args) 
{ 
	return SharedPointer<T>(T(args...)); 
}

}

#undef PRINT_POINTER_DEL
#undef PRINT_DEL_CHECK
#undef PRINT_PTR_INFO
#undef PRINT_ANOTHER_INFO

#endif 	// SHAREDPOINTER_H_
