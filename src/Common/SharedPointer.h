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
	#define PRINT_CONSTRUCTION 	\
		printf("[%s:%d] construction\n", __FILE__, __LINE__);

	#define PRINT_DESTRUCTION 	\
		printf("[%s:%d] desconstruction\n", __FILE__, __LINE__);

	#define PRINT_POINTER_DEL 	\
		printf("[%s:%d] delete raw pointer\n", __FILE__, __LINE__);

	#define PRINT_USE			\
		printf("[%s:%d] use: %d\n", __FILE__, __LINE__, _use);

	#define PRINT_ANOTHER_USE	\
		printf("[%s:%d]: another._use: %d\n", __FILE__, __LINE__, another._use);
#else 
	#define PRINT_CONSTRUCTION 
	#define PRINT_DESTRUCTION
	#define PRINT_POINTER_DEL
	#define PRINT_USE
	#define PRINT_ANOTHER_USE
#endif 

namespace stupid
{

template <typename T>
class SharedPointer
{
public:
	SharedPointer(T const&);
	SharedPointer();
	~SharedPointer();

	SharedPointer(SharedPointer<T> const&);
	SharedPointer(SharedPointer<T> const&&);
	SharedPointer<T> const operator=(SharedPointer<T> const&);
	SharedPointer<T> const operator=(SharedPointer<T> const&&);

	T& operator*();
	T* operator->();
	
private:

	mutable int _use;
	T* _raw;
};

template <typename T, typename ...Args>
SharedPointer<T> MakeShared(Args ...args) 
{ 
	return SharedPointer<T>(T(args...)); 
}

template <typename T>
SharedPointer<T>::SharedPointer(T const& instance) 
	: _use(1)
	, _raw(new T(instance)) 
{ 
	PRINT_CONSTRUCTION;
}

template <typename T>
SharedPointer<T>::SharedPointer() 
	: _use(1)
	, _raw(0) 
{
	PRINT_CONSTRUCTION;
}

template <typename T>
SharedPointer<T>::~SharedPointer() 
{ 
	PRINT_DESTRUCTION;

	PRINT_USE;
	if (!--_use && _raw) 
	{
		PRINT_POINTER_DEL
		delete _raw; 
	}
}

template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T> const& another)
{
	PRINT_CONSTRUCTION;
		
	PRINT_ANOTHER_USE;

	++another._use;
	_raw = another._raw;
	_use = another._use;
}

template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T> const&& another)
{
	PRINT_CONSTRUCTION;

	PRINT_ANOTHER_USE;

	++another._use;
	_raw = another._raw;
	_use = another._use;
}

template <typename T>
SharedPointer<T> const SharedPointer<T>::operator=(SharedPointer<T> const& another)
{
	// add another first can avoid self-assgin check
	PRINT_ANOTHER_USE;
	++another._use; 

	PRINT_USE
	if (!--_use && _raw) 
	{
		PRINT_POINTER_DEL
		delete _raw;
	}

	_raw = another._raw;
	_use = another._use;

	return *this;
}

template <typename T>
SharedPointer<T> const SharedPointer<T>::operator=(SharedPointer<T> const&& another)
{
	// add another first can avoid self-assgin check
	PRINT_ANOTHER_USE;
	++another._use; 

	PRINT_USE;
	if (!--_use && _raw) 
	{
		PRINT_POINTER_DEL;
		delete _raw;
	}

	_raw = another._raw;
	_use = another._use;

	return *this;
}

template <typename T>
T& SharedPointer<T>::operator*() 
{ 
	return *_raw;
}

template <typename T>
T* SharedPointer<T>::operator->()
{
	return _raw;
}

}

#undef PRINT_CONSTRUCTION 
#undef PRINT_DESTRUCTION
#undef PRINT_POINTER_DEL
#undef PRINT_USE
#undef PRINT_ANOTHER_USE

#endif 	// SHAREDPOINTER_H_
