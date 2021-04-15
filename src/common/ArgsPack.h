#ifndef ARGS_PACK_H_
#define ARGS_PACK_H_

class Peer;

class ArgsPack
{
public:
	virtual int SetArgs(...);

private:
	virtual int Config(Peer) = 0;
};

#endif // ARGS_PACK_H_
