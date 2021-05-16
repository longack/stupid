#ifndef UNIQUEPOINTER_H_
#define UNIQUEPOINTER_H_

#include <sys/types.h>

#include "src/Common//SharedPointer.h"

namespace stupid
{

template <typename T>
class UniquePointer
{
private:
	template <typename>
	class TProxy
	{
	public:
		TProxy(T);
		~TProxy();

		void operator=(T const&);
		void operator=(T const);

		operator T const();

	private:
	};
 
public:
	UniquePointer();
	~UniquePointer();

	UniquePointer<T> const operator==(UniquePointer<T> const&);
	TProxy<T> operator*();

private:
	UniquePointer(UniquePointer<T> const&) 	= delete;
	UniquePointer(UniquePointer<T> const&&) = delete;
	UniquePointer<T> const operator=(UniquePointer<T> const&) 	= delete;
	UniquePointer<T> const operator=(UniquePointer<T> const&&) 	= delete;

private:
	size_t _use;
	T* _raw;
};

template <typename T, typename ...Args>
UniquePointer<T> MakeUnique(Args...);

}

#endif 	// UNIQUEPOINTER_H_
