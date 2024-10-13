#include <iostream>
#include <vector>
#include <thread>
#include <filesystem>
#include "copyFiles.h"

//File Path Iterator
void copyFiles::filePathIterator()
{
	//Lock The Mutex
	buffer->bufferLockMutex();

	//Iterating Over all files & Copying All the Files Path
	for (const auto& filePath : std::filesystem::recursive_directory_iterator(sourceFolderPath.c_str()))
	{
		//Checking if file is an regular file and also checking if it has an extension
		if (std::filesystem::is_regular_file(filePath) && ((std::filesystem::path)(filePath)).has_extension())
		{
			for (int i = 0; i < bufSize; i++)
			{
				if (((std::filesystem::path)(filePath)).extension().string() == (*bufferPointer)[i])
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
			std::filesystem::copy(pathVar[i].pathStore[j].c_str(), (((*newFolderPathPointer)[i]).c_str()) , std::filesystem::copy_options::overwrite_existing);
		}
	}
}

//Constructor
copyFiles::copyFiles(sharedBuffer* sharedObject, const std::string_view sourcePath, makeFolderClass* makeFolderClassObject) :
	buffer{ sharedObject } ,
	sourceFolderPath { sourcePath } ,
	makeFolderObject{ makeFolderClassObject }
{
	//Total Elements in Buffer
	bufSize = buffer->buffSize();

	//Resize Vector
	pathVar.resize(bufSize);

	//Const Buffer Pointer
	bufferPointer = buffer->constbufferPointer();

	//Getting Pointer to "newFolderPath" variable
	newFolderPathPointer = makeFolderObject->constnewFolderPathPointer();

	//Starting Thread Execution
	copyFileThread = std::thread(&copyFiles::filePathIterator, this);
}

//Destructor
copyFiles::~copyFiles() { }