#pragma once

#ifndef __THREADCLASS__
#define __THREADCLASS__

#include <iostream>
#include <vector>
#include "sharedBuffer.h"
#include "boost/thread.hpp"

//Thread Class
class threadCreation
{
private:
	//sharedBuffer Class Object
	sharedBuffer* buffer;

	//Buffer Reference
	std::vector<std::string>* bufferReference;

public:
	//Thread Creation
	boost::thread waitThreadCreation;
	
	//Constructor
	threadCreation(sharedBuffer* sharedObject);

	//Thread in "Wait" State
	void threadWAIT();

	//Remove Duplicates
	void removeDuplicates();

	//Destructor
	~threadCreation();
};

#endif // !__THREADCLASS__
