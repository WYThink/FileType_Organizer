#pragma once

#ifndef _SHARED_BUFFER_CLASS
#define _SHARED_BUFFER_CLASS

#include <iostream>
#include <vector>
#include "boost/thread.hpp"

//Shared Buffer Class
class sharedBuffer
{
private:
	//Mutex Obejct
	boost::mutex mtx;

	//Conditional Variable
	boost::condition_variable cv;

	//"Ready" variable
	bool ready{ false };

	//Buffer
	std::vector<std::string> extension_Buffer{};

public:
	//Manual Mutex Lock
	void bufferLockMutex();
	
	//Setter
	void bufferInput(const std::string& extensionVar);

	//Manual Mutex Unlock
	void bufferUnlockMutex();

	//Return Const Pointer To Buffer
	std::vector<std::string>* constbufferPointer();

	//Return Reference to Buffer
	std::vector<std::string>* buffer_Reference();

	//Buffer Size
	int buffSize();
};

#endif // !_SHARED_BUFFER_CLASS
