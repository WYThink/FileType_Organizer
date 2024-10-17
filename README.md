# FileType-Organizer

**FileType Organizer** is a C++ CLI based application designed to efficiently organize files based on their extensions. It scans a specified source directory, identifies different file types, and sorts them into separate folders in a destination directory. This tool is ideal for users looking to streamline and categorize files, making it easier to manage and access them.

## Features
- Organizes files based on their extensions.
- Multithreading for improved performance.
- Mutex-based synchronization to ensure thread safety.
- Robust file handling using the C++ standard filesystem library.

## Technologies

- **C++ (Version 1.85.0) **: Core programming language used for developing the application.
- **Boost C++ Libraries**: 
  - **Boost Filesystem**: For handling file and directory operations.
  - **Boost Thread**: For implementing multithreading to improve performance.
- **Multithreading and Concurrency**: Efficient use of threads to handle file scanning and copying tasks concurrently.
- **Object-Oriented Programming (OOP)**: Designed using classes and objects for better structure and maintainability.

## How It Works
1. The application prompts the user to enter a source folder and a destination folder.
2. It scans the source folder recursively for files.
3. The program identifies each file's extension and organizes them into corresponding folders in the destination path.
4. Multithreading is used to enhance performance during the file scanning and copying process.
5. Mutex locks are employed to manage thread synchronization effectively.

## Usage
- Enter the source folder path when prompted.
- Specify the destination folder where organized files will be stored.
- The application will notify if a file with the same name already exists.

## Installation

1. **Download the Project Files**  
   - Obtain the source code for the FileType Organizer application.

2. **Download Boost C++ Pre-built Libraries**  
   - Ensure you download the appropriate version of the Boost C++ Libraries.

3. **Set Up Project Configuration in Visual Studio 2022**  
   - Open your project in Visual Studio 2022 and configure it for either Debug or Release mode.

4. **Configure Additional Include Directories**  
   - Navigate to **Project > Properties > C/C++ > General > Additional Include Directories**.  
   - Add the path to the **include** folder of the Boost C++ Library.

5. **Configure Additional Library Directories**  
   - Navigate to **Project > Properties > Linker > General > Additional Library Directories**.  
   - Add the path to the **lib64-msvc-14.3** folder of the Boost C++ Library.

6. **Specify Additional Dependencies**  
   - Navigate to **Project > Properties > Linker > Input > Additional Dependencies**.  
   - Add the names of the required libraries:
   - **Release**
     - For Filesystem, include `boost_filesystem-vc143-mt-x64-1_85.lib`.
     - For Threading, include `boost_thread-vc143-mt-x64-1_85.lib`.
   - **Debug**
     - For Filesystem, include `boost_filesystem-vc143-mt-gd-x64-1_85.lib`.
     - For Threading, include `boost_thread-vc143-mt-gd-x64-1_85.lib`.   

7. **Debug/Release Library Usage**  
   - Use libraries that include "gd" in their names for Debug builds.
   - Use libraries without "gd" for Release builds.

8. **Setting Up Environment Variables**  
   - If your project compiles successfully but encounters missing `.dll` files during runtime, add the **lib64-msvc-14.3** path (where `.lib` and `.dll` files are located) to your system's environment variables.

 
## Demo

https://github.com/user-attachments/assets/e83af568-d1b1-4d60-aa33-a1d01f5618dd

