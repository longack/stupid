#include <stdio.h>
#include <string>

#include "src/Common/SharedPointer.h"

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

	printf("hello, world\n");
	return 0;
}
