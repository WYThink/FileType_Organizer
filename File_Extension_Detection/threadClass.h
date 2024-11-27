#pragma once

#ifndef __THREADCLASS__
#define __THREADCLASS__

#include "boost/thread.hpp"
#include "sharedBuffer.h"
#include <iostream>
#include <vector>

// Thread Class
class threadCreation 
{
	private:
	  sharedBuffer *buffer;                         // sharedBuffer Class Object
	  std::vector<std::string> *bufferReference;    // Buffer Reference

	public:
	  boost::thread waitThreadCreation;             // Thread Creation
	  threadCreation(sharedBuffer *sharedObject);   // Constructor
	  void threadWAIT();                            // Thread in "Wait" State
	  void removeDuplicates();                      // Remove Duplicates

	  // Destructor
	  ~threadCreation();
};

#endif // !__THREADCLASS__
