#include "sharedBuffer.h"
#include "boost/thread.hpp"
#include <iostream>
#include <vector>

// Lock The Mutex
void sharedBuffer::bufferLockMutex() 
{
  boost::unique_lock<boost::mutex> lock(mtx);                            // Lock Mutex
  cv.wait(lock, [this] { return !ready; });                              // Waiting
  ready = true;                                                          // Ready
}

// Fill the Buffer
void sharedBuffer::bufferInput(const std::string &extensionVar) 
{
  extension_Buffer.push_back(extensionVar);                              // Push Back
}

std::vector<std::string> *sharedBuffer::buffer_Reference() 
{
  return &extension_Buffer;                                              // Return Pointer of Buffer
}

// Return Const Pointer To Buffer ,so buffer is not modified
std::vector<std::string> *sharedBuffer::constbufferPointer() 
{
  return &extension_Buffer;
}

// Buffer Size
int sharedBuffer::buffSize() { return extension_Buffer.size(); }

// Unlock The Mutex
void sharedBuffer::bufferUnlockMutex() 
{
  boost::unique_lock<boost::mutex> lock(mtx);                            // Locking the mutex
  ready = false;                                                         // Unlock the Object
  cv.notify_one();                                                       // Notifying
}
