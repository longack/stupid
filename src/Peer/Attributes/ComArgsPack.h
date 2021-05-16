#ifndef COMARGSPACK_H_
#define COMARGSPACK_H_

#include <string>

#include <termios.h>

#include "src/Peer/Attributes/ArgsPack.h"

namespace stupid
{

class ComArgsPack : public ArgsPack
{
	friend class CSMAttribute;

public:
	ComArgsPack(std::string name);
	~ComArgsPack();

private:
	ComArgsPack(ComArgsPack const&) 	= delete;
	ComArgsPack(ComArgsPack const&&) 	= delete;
	ComArgsPack const operator=(ComArgsPack const&) 	= delete;
	ComArgsPack const operator=(ComArgsPack const&&) 	= delete;
 
private:
	termios* _tc_attr;
	int _fd;
};

}

#endif 	// COMARGSPACK_H_
