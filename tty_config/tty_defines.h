#ifndef TTY_DEFINES_H_
#define TTY_DEFINES_H_

enum BaudRate
{ 
	BaudRate_0, 
	BaudRate_50, 
	BaudRate_75, 
	BaudRate_110, 
	BaudRate_134, 
	BaudRate_150, 
	BaudRate_200, 
	BaudRate_300, 
	BaudRate_600, 
	BaudRate_1200, 
	BaudRate_1800, 
	BaudRate_2400, 
	BaudRate_4800, 
	BaudRate_9600, 
	BaudRate_19200, 
	BaudRate_38400, 
	BaudRate_57600, 
	BaudRate_115200, 
	BaudRate_230400,
};

enum CharacterSizeMask
{
	CharacterSizeMask_5bit, 
	CharacterSizeMask_6bit, 
	CharacterSizeMask_7bit, 
	CharacterSizeMask_8bit,
};

enum StopBit
{
	Stop_1bit,
	Stop_2bit,
};


#endif // TTY_DEFINES_H_ 
