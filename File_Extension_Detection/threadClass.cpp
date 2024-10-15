#include <iostream>
#include <vector>
#include <algorithm>
#include "threadClass.h"

//Thread In "Wait" State
void threadCreation::threadWAIT()
{
	// Lock Mutex
	buffer->bufferLockMutex();

	// Calling removeDuplicates()
	removeDuplicates();

	// Unlock Mutex
	buffer->bufferUnlockMutex();
}

//Remove Duplicates
void threadCreation::removeDuplicates()
{
	//Sort The Vector
	std::sort((*bufferReference).begin(), (*bufferReference).end());

	//Remove Duplicates using std::remove
	auto last = std::unique((*bufferReference).begin(), (*bufferReference).end());

	//Erase the duplicate elements
	(*bufferReference).erase(last, (*bufferReference).end());
}

//Constructor
threadCreation::threadCreation(sharedBuffer* sharedObject) : buffer{ sharedObject } , waitThreadCreation{&threadCreation::threadWAIT , this}
{
	//Buffer Reference
	bufferReference = buffer->buffer_Reference();
}

//Destructor
threadCreation::~threadCreation() {}