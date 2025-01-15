#include <iostream>
#include "fileExtension.h"
#include "threadClass.h"
#include "makeFolderClass.h"

int main()
{
	//extension Class Object Creation
	extension* extensionObject = new extension();

	// "sharedBuffer" Class Pointer
	sharedBuffer* bufferObject = extensionObject->buffer;

	//threadCreation Class Object Creation
	threadCreation* threadObject = new threadCreation(bufferObject);

	//Joining Thread of ThreadObject
	if (threadObject->waitThreadCreation.joinable()) threadObject->waitThreadCreation.join();

	//makeFolderClass Class Object Creation
	makeFolderClass* makeFolderObject = new makeFolderClass(extensionObject->destin_FolderPathReturn(), bufferObject);

	//Joining Thread of makeFolderThread Object
	if (makeFolderObject->makeFolderThread.joinable()) makeFolderObject->makeFolderThread.join();

	//copyFiles Class Object Creation
	copyFiles* copyFilesObject = new copyFiles(bufferObject, extensionObject->source_FolderPathReturn(), makeFolderObject);


	//Joining Thread
	if (copyFilesObject->copyFileThread.joinable()) copyFilesObject->copyFileThread.join();

	//Destroying Object
	delete extensionObject;
	delete threadObject;
	delete makeFolderObject;
	delete copyFilesObject;

	return 0;
}