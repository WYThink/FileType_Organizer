#pragma once

#ifndef __FILEEXTENSION__
#define __FILEEXTENSION__

#include "copyFiles.h"
#include "sharedBuffer.h"
#include "threadClass.h"
#include <iostream>
#include <vector>

// Extesion Class inherting properties from "sharedBuffer" Class and
// "threadCreation" Class
class extension : public sharedBuffer {
private:
  std::string source_Folder_Path{};							// Source Folder Path
  std::string destination_Folder_Path{};					// Destination Folder Path
  std::uintmax_t sourceSize{};								// Source Folder Size
  std::uintmax_t totalFiles{};								// Calculate Total Files
  sharedBuffer *buffer;										// sharedBuffer Object Pointer
  threadCreation *thread;									// threadCreation Object Pointer

public:
  const std::string_view source_FolderPathReturn(); // Return Source Folder Path
  const std::string_view
  destin_FolderPathReturn(); // Return Destination Folder Path

  void source_folder_Path_Input();      // Path Input (Ask For Folder Path)
  void destination_folder_Path_Input(); // Path Input (Ask For Folder Path)
  void sizeCalc(const std::string_view sourceFolder);     // Folder Size Check
  void allExtension(const std::string_view sourceFolder); // Get All Extension

  // Prerequiste Checking
  void prerequiste_Check(const std::string_view folder_Path, int flag);

  // Constructor
  extension(sharedBuffer *bufferObject);

  // Destructor
  ~extension();
};

#endif