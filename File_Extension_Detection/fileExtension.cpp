#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <cmath>
#include <vector>
#include "fileExtension.h"

//Source folder_Path_Input Function
void extension::source_folder_Path_Input()
{
	//Source Folder Path Input
	std::cout << "Enter Source directory path (e.g., C:\\Users\\Documents) : ";
	std::getline(std::cin >> std::ws, source_Folder_Path);

	//Calling prerequiste_Check() 
	prerequiste_Check(source_Folder_Path.c_str() , 1);
}

//Destination folder_Path_Input Function
void extension::destination_folder_Path_Input()
{
	//Destination Folder Path Input
	std::cout << "Enter Destination directory path (e.g., C:\\Users\\Documents) : ";
	std::getline(std::cin >> std::ws, destination_Folder_Path);

	//Calling prerequiste_Check() 
	prerequiste_Check(destination_Folder_Path.c_str() , 0);
}

//Compare Folder Size
void extension::sizeCalc(const std::string_view sourceFolder)
{
	//Temporary Size Calculate
	std::uintmax_t tmp{};

	//Iterate over all the items inside folder
	for (const auto& path : std::filesystem::recursive_directory_iterator(sourceFolder))
	{
		//Checking if its a file and also checking if it has a extension and calculating total files and file size 
		if (std::filesystem::is_regular_file(path) && ((std::filesystem::path(path)).has_extension()))
		{
			//Calculating Size
			tmp += std::filesystem::file_size(path);

			//Total Files
			totalFiles += 1;
		}
	}

	//Save Size
	sourceSize = tmp;
}

//Get All Extension To Shared Buffer
void extension::allExtension(const std::string_view sourceFolder)
{
	//Lock The Mutex
	buffer->bufferLockMutex();

	//Iterate over all the items inside folder
	for (const auto& path : std::filesystem::recursive_directory_iterator(sourceFolder))
	{
		if (std::filesystem::is_regular_file(path) && ((std::filesystem::path(path)).has_extension()))
		{
			//Pushing File Extension to extenSion variable
			buffer->bufferInput(((std::filesystem::path(path)).extension()).string());
		}
	}

	//Unlock The Mutex
	buffer->bufferUnlockMutex();
}

//Return Source Folder Path
const std::string_view extension::source_FolderPathReturn()
{
	return source_Folder_Path.c_str();
}

//Return Destination Folder Path
const std::string_view extension::destin_FolderPathReturn()
{
	return destination_Folder_Path.c_str();
}

//Constructor Definition
extension::extension(sharedBuffer* bufferObject) : buffer(bufferObject)
{
	//Warning Message
	std::cout << "Warning: Files with the same name will be overwritten." << '\n';

	//Call source_folder_Path_Input() Function
	source_folder_Path_Input();

	//Call destination_folder_Path_Input() Function
	destination_folder_Path_Input();

	//Source Folder Size
	sizeCalc(this->source_FolderPathReturn());

	//Calling allExtension()
	allExtension(this->source_FolderPathReturn());
}

//Destructor
extension::~extension() { std::cout << "Total Files : " << totalFiles << '\n'; }