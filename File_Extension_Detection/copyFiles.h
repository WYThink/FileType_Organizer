#pragma once

#ifndef __COPYFILES__
#define __COPYFILES__

#include <iostream>
#include <vector>
#include "sharedBuffer.h"
#include "makeFolderClass.h"
#include "boost/thread.hpp"

//Class for Copying Files 
class copyFiles
{
private:
	//Buffer Object
	sharedBuffer* buffer;

	//makeFolderClass Object
	makeFolderClass* makeFolderObject;
	
	//Buffer Size
	int bufSize{};

	// Stores full paths of files for a specific extension.
	struct fullPath
	{
		//Store Path
		std::vector<std::string> pathStore{};
	};

	//Source Folder Path
	std::string sourceFolderPath{};

	//Const Buffer Pointer
	const std::vector<std::string>* bufferPointer;

	//Const Buffer "newFolderPath" Pointer
	const std::vector<std::string>* newFolderPathPointer;

public:
	//Thread Object
	boost::thread copyFileThread;
	
	//Vector of fullPath structs
	std::vector<struct fullPath> pathVar{};

	//Constructor
	copyFiles(sharedBuffer* sharedObject, const std::string_view sourcePath , makeFolderClass * makeFolderClassObject);

	//File Path Iterator
	void filePathIterator();

	//Copy File
	void finalyCopy();

	//Destructor
	~copyFiles();
};

#endif // __COPYFILES__