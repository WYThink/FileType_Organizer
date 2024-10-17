#include <filesystem>
#include "fileExtension.h"
#include "boost/filesystem.hpp"

/*
		Flag = 1 = Source Folder Path
		Flag = 0 = Destination Folder Path

		1) Valid Path (Source Folder & Destination Folder)
		2) Is Empty (Source Folder) & Destination Folder)
			.) Source Folder = Not Empty
			.) Destination Folder = Should Empty

		3) Copy Permission (Source Folder)
			-> Read Permission on the source folder: You need "Read" permission to access the file in the source folder to be able to copy it.
				
		4) Write Permission (Destination Folder)
			-> Write Permission on the destination folder: You need "Write" permission on the destination folder to be able to paste the copied file there.
*/

//folderPathCheck() Function 
void extension::prerequiste_Check(const std::string_view folder_Path, int flag)
{

// 1) Valid Path or Not
/*-------------------------------------------------------------*/
	if (!boost::filesystem::is_directory(folder_Path))
	{
		std::cout << "Invalid Path : \"" << folder_Path << "\"" << '\n';

		//Flag == 1 , then Source Folder Path Input
		if (flag == 1) source_folder_Path_Input();

		//Else Destination Folder Path Input	
		else destination_folder_Path_Input();
	}
/*-------------------------------------------------------------*/



// 2) , 3) , 4)
/*-------------------------------------------------------------*/
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
/*-------------------------------------------------------------*/
}
