#include <iostream>
#include "fileExtension.h"
#include "threadClass.h"
#include "makeFolderClass.h"

int main()
{
	//sharedBuffer Class Object Creation
	sharedBuffer* bufferObject = new sharedBuffer();

	//extension Class Object Creation
	extension* extensionObject = new extension(bufferObject);

	//threadCreation Class Object Creation
	threadCreation* threadObject = new threadCreation(bufferObject);
	
	//Joining Thread of ThreadObject
	if(threadObject->waitThreadCreation.joinable()) threadObject->waitThreadCreation.join();
	
	//makeFolderClass Class Object Creation
	makeFolderClass* makeFolderObject = new makeFolderClass(extensionObject->destin_FolderPathReturn() , bufferObject);

	//Joining Thread of makeFolderThread Object
	if(makeFolderObject->makeFolderThread.joinable()) makeFolderObject->makeFolderThread.join();

	//copyFiles Class Object Creation
	copyFiles* copyFilesObject = new copyFiles(bufferObject, extensionObject->source_FolderPathReturn(), makeFolderObject);


	//Joining Thread
	if (copyFilesObject->copyFileThread.joinable()) copyFilesObject->copyFileThread.join();

	//Destroying Object
	delete extensionObject;
	delete threadObject;
	delete bufferObject;
	delete makeFolderObject;
	delete copyFilesObject;

	return 0;
}