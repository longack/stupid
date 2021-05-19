#include <string>
#include <deque>
#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "src/Common/SharedPointer.h"

template <typename T>
void test_swap(T& lhs, T& rhs)
{
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}

int main(int argc, char* argv[])
{
	using namespace stupid;

	SharedPointer<int> test1 = MakeShared<int>(1);
	SharedPointer<int> test2 = MakeShared<int>(2);

	int value1 = *test1;
	int value2 = *test2;
	printf("test1: %d, test2: %d\n", value1, value2);

	int temp = *test1;
	*test1 = *test2;
	*test2 = temp;

	value1 = *test1;
	value2 = *test2;
	printf("test1: %d, test2: %d\n", value1, value2);

	SharedPointer<std::string> test3 = MakeShared<std::string>("test string1");
	SharedPointer<std::string> test4 = MakeShared<std::string>("test string2");
	printf("test3: %s, test4: %s\n", test3->c_str(), test4->c_str());
	test_swap(test3, test4);
	printf("test3: %s, test4: %s\n", test3->c_str(), test4->c_str());

	SharedPointer<std::string> test5 = test3 = test4;
	printf("test3: %s, test4: %s, test5: %s\n", test3->c_str(), test4->c_str(), (*test5).c_str());
	*test5 = "codea-ppp";
	printf("test3: %s, test4: %s, test5: %s\n", test3->c_str(), test4->c_str(), (*test5).c_str());

	test4 = MakeShared<std::string>("test ppp");
	printf("test4: %s\n", test4->c_str());

	while (true)
	{
		{
			SharedPointer<std::deque<std::string>> leak_test = MakeShared<std::deque<std::string>>();
			leak_test->push_back(*test3);
			leak_test->push_back(*test3);
			leak_test->push_back(*test4);
			leak_test->push_back(*test4);
			leak_test->push_back(*test4);
			leak_test->push_back(*test4);
			leak_test->push_back(*test4);
			leak_test->push_back(*test4);
			leak_test->push_back(*test5);

			
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
			
		}
	}

	return 0;
}
