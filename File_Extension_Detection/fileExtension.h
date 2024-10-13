#pragma once

#ifndef __FILEEXTENSION__
#define __FILEEXTENSION__

#include <iostream>
#include <vector>
#include "sharedBuffer.h"
#include "threadClass.h"
#include "copyFiles.h"

//Extesion Class inherting properties from "sharedBuffer" Class and "threadCreation" Class
class extension : public sharedBuffer 
{
private:
	//Source Folder Path
	std::string source_Folder_Path{};

	//Destination Folder Path
	std::string destination_Folder_Path{};

	//Source Folder Size
	std::uintmax_t sourceSize{};

	//Calculate Total Files
	std::uintmax_t totalFiles{};

	//sharedBuffer Object
	sharedBuffer* buffer;

	//threadCreation Object
	threadCreation* thread;

public:
	//Constructor 
	extension(sharedBuffer* bufferObject);
	
	//Return Source Folder Path
	const std::string_view source_FolderPathReturn();

	//Return Destination Folder Path
	const std::string_view destin_FolderPathReturn();

	//Prerequiste Checking 
	void prerequiste_Check(const std::string_view folder_Path , int flag);

	//Path Input (Ask For Folder Path)
	void source_folder_Path_Input();

	//Path Input (Ask For Folder Path)
	void destination_folder_Path_Input();

	//Folder Size Check
	void sizeCalc(const std::string_view sourceFolder);

	//Get All Extension
	void allExtension(const std::string_view sourceFolder);

	//Destructor
	~extension();

};

#endif