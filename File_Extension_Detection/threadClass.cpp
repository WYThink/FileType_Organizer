#include "threadClass.h"
#include <algorithm>
#include <iostream>
#include <vector>

// Thread In "Wait" State
void threadCreation::threadWAIT() {

  buffer->bufferLockMutex();                                       // Lock Mutex
  removeDuplicates();                                              // Calling removeDuplicates()
  buffer->bufferUnlockMutex();                                     // Unlock Mutex
}

void threadCreation::removeDuplicates()                            // Remove Duplicates
{
  std::sort((*bufferReference).begin(),
            (*bufferReference).end());                             // Sort The Vector

  auto last = std::unique(
      (*bufferReference).begin(),
      (*bufferReference).end());                                   // Remove Duplicates using std::remove

  (*bufferReference)
      .erase(last, (*bufferReference).end());                      // Erase the duplicate elements
}

// Constructor
threadCreation::threadCreation(sharedBuffer *sharedObject) : buffer{sharedObject}, waitThreadCreation{&threadCreation::threadWAIT, this} {

  bufferReference = buffer->buffer_Reference(); // Buffer Reference
}

// Destructor
threadCreation::~threadCreation() {}