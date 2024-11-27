#include <iostream>
#include <vector>
#include "copyFiles.h"
#include "boost/thread.hpp"
#include "boost/filesystem.hpp"

//File Path Iterator
void copyFiles::filePathIterator()
{
	//Lock The Mutex
	buffer->bufferLockMutex();

	//Iterating Over all files & Copying All the Files Path
	for (const auto& filePath : boost::filesystem::recursive_directory_iterator(sourceFolderPath.c_str()))
	{
		//Checking if file is an regular file and also checking if it has an extension
		if (boost::filesystem::is_regular_file(filePath) && ((boost::filesystem::path)(filePath)).has_extension())
		{
			for (int i = 0; i < bufSize; i++)
			{
				if (((boost::filesystem::path)(filePath)).extension().string() == (*bufferPointer)[i])
				{
					//Pushing the Whole Path of file as String
					pathVar[i].pathStore.push_back(filePath.path().string().c_str());
				}
			}
		}
	}
	//Calling finalyCopy()
	finalyCopy();

	//UnLock The Mutex
	buffer->bufferUnlockMutex();
}

//Copy Files
void copyFiles::finalyCopy()
{
	for (int i = 0; i < bufSize; i++)
	{
		for (int j = 0; j < pathVar[i].pathStore.size(); j++)
		{
			//Calling copy() of filesystem Library also using "overwrite_existing" flag
			boost::filesystem::copy(pathVar[i].pathStore[j].c_str(), (((*newFolderPathPointer)[i]).c_str()) , boost::filesystem::copy_options::overwrite_existing);
		}
	}
}

//Constructor
copyFiles::copyFiles(sharedBuffer* sharedObject, const std::string_view sourcePath, makeFolderClass* makeFolderClassObject) :
	buffer{ sharedObject } ,
	sourceFolderPath { sourcePath } ,
	makeFolderObject{ makeFolderClassObject }
{
	bufSize = buffer->buffSize();                                            //Total Elements in Buffer
	pathVar.resize(bufSize);                                                 //Resize Vector
	
	bufferPointer = buffer->constbufferPointer();                            //Const Buffer Pointer
	
	newFolderPathPointer = makeFolderObject->constnewFolderPathPointer();    //Getting Pointer to "newFolderPath" variable
	copyFileThread = boost::thread(&copyFiles::filePathIterator, this);      //Starting Thread Execution
}

//Destructor
copyFiles::~copyFiles() { }