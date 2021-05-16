#ifndef CHARACTERSIZEMASK_H_
#define CHARACTERSIZEMASK_H_

#include "src/Peer/Attributes/Attribute.h"
#include "src/Peer/Attributes/ComArgsPack.h"

namespace stupid
{

enum CharacterSizeMask
{
	CharacterSizeMask_5bit, 
	CharacterSizeMask_6bit, 
	CharacterSizeMask_7bit, 
	CharacterSizeMask_8bit,
};

class CSMAttribute : public Attribute
{
public:
	int Set(ComArgsPack* fd);

private:
	CharacterSizeMask _csm;
};

}

#endif 	// CHARACTERSIZEMASK_H_
