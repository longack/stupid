#include <termios.h>

#include "src/Peer/Attributes/CharacterSizeMask.h"

namespace stupid 
{

inline typeof(CS5) GetCSM(CharacterSizeMask _csm)
{
	static typeof(CS5) csm_tbl[] = { CS5, CS6, CS7, CS8, };
	return csm_tbl[_csm];
}


int CSMAttribute::Set(ComArgsPack* fd /* is and only is this */)
{
	auto csm = GetCSM(_csm);
	fd->_tc_attr->c_cflag |= csm;
	
	return 0;
}

}

