#include <system_error>
#include <cstdlib>
#include <stdio.h>

#include <unistd.h>
#include <sys/fcntl.h>

#include "src/Common/ErrorCode.h"
#include "src/Peer/Attributes/ComArgsPack.h"

namespace stupid
{

ComArgsPack::ComArgsPack(std::string name)
{
	_fd = open(name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
	if (_fd < 0)
	{
		std::system_error e(std::error_code(ERR_FD_OPEN_FAILED, std::system_category()), 
							std::string("cannot open device " + name));
		throw e;
	}

	if (tcgetattr(_fd, _tc_attr))
	{
		std::system_error e(std::error_code(ERR_TCATTR_CANNOT_REACH, std::system_category()), 
							std::string("cannot open device " + name));

		throw e;
	}
}

}
