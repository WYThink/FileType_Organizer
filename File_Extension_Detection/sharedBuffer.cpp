#include <iostream>
#include <vector>
#include "sharedBuffer.h"
#include "boost/thread.hpp"

//Lock The Mutex
void sharedBuffer::bufferLockMutex()
{
	//Lock Mutex
	boost::unique_lock<boost::mutex> lock(mtx);

	//Waiting Thread
	cv.wait(lock, [this] { return !ready; });

	//Ready
	ready = true;
}

//Fill the Buffer
void sharedBuffer::bufferInput(const std::string& extensionVar)
{
	//Push Back
	extension_Buffer.push_back(extensionVar);
}

//Return Referenec to Buffer
std::vector<std::string>* sharedBuffer::buffer_Reference()
{
	return &extension_Buffer;
}

//Return Const Pointer To Buffer ,so buffer is not modified
std::vector<std::string>* sharedBuffer::constbufferPointer()
{
	return &extension_Buffer;
}

//Buffer Size
int sharedBuffer::buffSize()
{
	return extension_Buffer.size();
}

//Unlock The Mutex
void sharedBuffer::bufferUnlockMutex()
{
	//Locking the mutex
	boost::unique_lock<boost::mutex> lock(mtx);

	//Unlock the Object
	ready = false;

	//Notifying
	cv.notify_one();
}