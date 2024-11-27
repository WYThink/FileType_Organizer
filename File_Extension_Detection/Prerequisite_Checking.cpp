#include <filesystem>
#include "fileExtension.h"
#include "boost/filesystem.hpp"

//folderPathCheck() Function 
void extension::prerequiste_Check(const std::string_view folder_Path, int flag)
{
	if (!boost::filesystem::is_directory(folder_Path))
	{
		std::cout << "Invalid Path : \"" << folder_Path << "\"" << '\n';

		//Flag == 1 , then Source Folder Path Input
		if (flag == 1) source_folder_Path_Input();

		//Else Destination Folder Path Input	
		else destination_folder_Path_Input();
	}

	if(flag == 1) 
	{
		//Source Folder Empty or Not && Copy Permission
		if (true == boost::filesystem::is_empty(folder_Path))
		{
			std::cout << "Source Folder : \'" << folder_Path << "\' is Empty" << '\n';
			source_folder_Path_Input();
		}
		else { std::cout << "Source Folder ✅✅" << '\n'; }

		//Copy Permission (Aka Read Permission)-----------------/
		boost::filesystem::perms permission = boost::filesystem::status(folder_Path).permissions();

		if ((permission & boost::filesystem::perms::owner_read) == boost::filesystem::perms::no_perms)
		{
			std::cout << "Source Folder : \'" << folder_Path << "\' Does Not Have Read Permissions" << '\n';
			source_folder_Path_Input();
		}
		else { std::cout << "Read Permission ✅✅" << '\n'; }
	}
	
	else //Chech Destiantion Folder is Empty or Not
	{
		if (false == boost::filesystem::is_empty(folder_Path))
		{
			std::cout << "Destination Folder : \'" << folder_Path << "\' is Not Empty" << '\n';
			destination_folder_Path_Input();
		}
		else { std::cout << "Destination Folder  ✅✅" << '\n'; }

		//Paste Permission (Aka Write Permission)---------------/
		boost::filesystem::perms permission = boost::filesystem::status(folder_Path).permissions();

		if ((permission & boost::filesystem::perms::owner_write) == boost::filesystem::perms::no_perms)
		{
			std::cout << "Destination Folder : \'" << folder_Path << "\' Does Not Have Write Permissions" << '\n';
			destination_folder_Path_Input();
		}
		else { std::cout << "Write Permission ✅✅" << '\n'; }
	}
}
