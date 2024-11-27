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
	sharedBuffer*							buffer;								//BUFFER Object
	makeFolderClass*						makeFolderObject;					//makeFolderClass Object
	int										bufSize{};							//Buffer Size
	std::string								sourceFolderPath{};					//Source Folder Path
	const std::vector<std::string>*			bufferPointer;						//Const Buffer Pointer
	const std::vector<std::string>*			newFolderPathPointer;				//Const Buffer "newFolderPath" Pointer

	struct fullPath {															//Stores full paths of files for a specific extension.
		std::vector<std::string>			pathStore{};						//Store Path
	};

public:
	boost::thread copyFileThread;												//Thread Object
	std::vector<struct fullPath> pathVar{};										//Vector of fullPath structs
	void filePathIterator();													//File Path Iterator
	void finalyCopy();															//Copy File

	//Constructor
	copyFiles(sharedBuffer* sharedObject, const std::string_view sourcePath, makeFolderClass* makeFolderClassObject);

	//Destructor
	~copyFiles();
};

#endif // __COPYFILES__
