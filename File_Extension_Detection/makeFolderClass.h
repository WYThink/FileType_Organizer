#pragma once

#ifndef __MAKEFOLDERCLASS__
#define __MAKEFOLDERCLASS__

#include <iostream>
#include <filesystem>
#include <thread>
#include <mutex>
#include "sharedBuffer.h"

class makeFolderClass
{
private:
	//sharedBuffer Class Object
	sharedBuffer* buffer;

	//Buffer Pointer
	const std::vector<std::string>* extenBufferPointer;

	//Buffer Size
	int buffSize{};

	//Destination Folder Path
	std::string destination_FolderPath{};

	//Storing The Path Of Newly Created Folder
	std::vector<std::string> newFolderPath{};

public:
	//Thread Object
	std::thread makeFolderThread;

	//Constructor
	makeFolderClass(const std::string_view path , sharedBuffer* sharedObject);

	//Create Folder
	void createFolderInDest();

	//Return Const Pointer To "newFolderPath"
	const std::vector<std::string>* constnewFolderPathPointer() const;

	//Destructor
	~makeFolderClass();
};

#endif // __MAKEFOLDERCLASS__