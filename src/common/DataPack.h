#ifndef DATA_PACK_H_
#define DATA_PACK_H_

#include <unistd.h>
#include <memory>
#include <string>

class Worker;

class DataPack
{
public:
	void SetData(std::unique_ptr<void> buffer, size_t size);
	void SetData(void* raw, size_t buffer_size);
	void SetData(const std::string& buffer);

private:
	friend class Peer;
	std::unique_ptr<void> _buffer;
	size_t _buffer_size;
};

#endif // DATA_PACK_H_ 
