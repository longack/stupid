#ifndef PEER_H_
#define PEER_H_ 

#include <unistd.h>
#include <deque>

class ArgsPack;
class DataPack;
class Worker;

class Peer
{
public:
	virtual int AsyncWrite(const DataPack&, const Worker)	= 0;
	virtual int AsyncRead(DataPack&, const Worker)			= 0;

	virtual ssize_t SyncRead(DataPack&)			= 0;
	virtual ssize_t SyncWrite(const DataPack&)	= 0;

	virtual int SetConfig(ArgsPack)				= 0;

private:
	std::deque<DataPack> _packet_queue;

	int _peer_type;
	int _fd;
};

#endif // PEER_H_ 
