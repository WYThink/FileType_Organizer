#include <iostream>
#include "makeFolderClass.h"
#include "sharedBuffer.h"
#include "boost/thread.hpp"
#include "boost/filesystem.hpp"

//Create Folder (Using Thread)
void makeFolderClass::createFolderInDest()
{
	//Lock The Mutex
	buffer->bufferLockMutex();

	for (int i = 0 ; i < buffSize ; i++)
	{
		//Temporary Path
		std::string tempPath = destination_FolderPath + "\\" + ((*extenBufferPointer)[i]);

		//Create Folder
		boost::filesystem::create_directory(tempPath.c_str());

		//Pushing New Folder Path in "newFolderPath" Variable
		newFolderPath.push_back(tempPath.c_str());
	}

	// Unlock Mutex
	buffer->bufferUnlockMutex();
}

//Return Const Pointer To "newFolderPath"
const std::vector<std::string>* makeFolderClass::constnewFolderPathPointer() const
{
	return &newFolderPath;
}

//Constructor
makeFolderClass::makeFolderClass(const std::string_view path, sharedBuffer* sharedObject) : 

	destination_FolderPath{ path }, 
	buffer{ sharedObject } ,
	makeFolderThread(&makeFolderClass::createFolderInDest , this)

{
	//Buffer Address
	extenBufferPointer = buffer->constbufferPointer();

	//Buffer Size
	buffSize = buffer->buffSize();
}

//Destructor
makeFolderClass::~makeFolderClass() { }