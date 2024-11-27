#pragma once

#ifndef __MAKEFOLDERCLASS__
#define __MAKEFOLDERCLASS__

#include "boost/thread.hpp"
#include "sharedBuffer.h"
#include <filesystem>
#include <iostream>

class makeFolderClass 
{
	private:
	  sharedBuffer *buffer;                                               // sharedBuffer Class Object
	  const std::vector<std::string> *extenBufferPointer;                 // Buffer Pointer
	  int buffSize{};                                                     // Buffer Size
	  std::string destination_FolderPath{};                               // Destination Folder Path
	  std::vector<std::string> newFolderPath{};                           // Storing The Path Of Newly Created Folder

	public:
	  boost::thread makeFolderThread;                                     // Thread Object
	  void createFolderInDest();                                          // Create Folder
	  const std::vector<std::string> * constnewFolderPathPointer() const; // Return Const Pointer To "newFolderPath"

	  // Constructor
	  makeFolderClass(const std::string_view path, sharedBuffer *sharedObject);

	  // Destructor
	  ~makeFolderClass();
};

#endif // __MAKEFOLDERCLASS__