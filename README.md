# FileType-Organizer

**FileType Organizer** is a C++ CLI based application designed to efficiently organize files based on their extensions. It scans a specified source directory, identifies different file types, and sorts them into separate folders in a destination directory. This tool is ideal for users looking to streamline and categorize files, making it easier to manage and access them.

## Features
- Organizes files based on their extensions.
- Multithreading for improved performance.
- Mutex-based synchronization to ensure thread safety.
- Robust file handling using the C++ standard filesystem library.

## Technologies
- C++
- C++ Standard Filesystem Library
- C++ Standard Threading
- Object-Oriented Programming (OOP) with Classes

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
