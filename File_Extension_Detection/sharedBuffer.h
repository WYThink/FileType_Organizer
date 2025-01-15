#pragma once

#ifndef _SHARED_BUFFER_CLASS
#define _SHARED_BUFFER_CLASS

#include "boost/thread.hpp"
#include <iostream>
#include <vector>

// Shared Buffer Class
class sharedBuffer
{
private:
	boost::mutex mtx;                                  // Mutex Obejct
	boost::condition_variable cv;                      // Conditional Variable
	bool ready{ false };                                 // "Ready" variable
	std::vector<std::string> extension_Buffer{};       // Buffer

public:
	void bufferLockMutex();                            // Manual Mutex Lock
	void bufferInput(const std::string& extensionVar); // Setter
	void bufferUnlockMutex();                          // Manual Mutex Unlock

	std::vector<std::string>* constbufferPointer();   // Return Const Pointer To Buffer
	std::vector<std::string>* buffer_Reference();      // Return Reference to Buffer
	int buffSize();                                    // Buffer Size
	sharedBuffer* returnPointer();					 // Return Class Pointer
};

#endif // !_SHARED_BUFFER_CLASS
