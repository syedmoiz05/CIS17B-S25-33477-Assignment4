#  - User Instructions

## How to Compile

1. Open a terminal or command prompt.
2. Navigate to the directory containing the source file 
3. Compile the code using:

   g++ -std=c++11 -o LibrarySystem LibrarySystem.cpp

  

## How to Run

- On Linux or macOS:
  ./LibrarySystem

- On Windows:
  LibrarySystem.exe

## How to Use
1. Launch the program.
2. A menu will show up with options:
3. Add an item
4. Find an item by ID
5. Remove an item by ID
6. List items by description
7. Exit the program
   
You type the number of the option you want and hit enter. The program checks for errors like:

Trying to add an item with a duplicate ID

Finding or removing an item that doesn’t exist

Listing when no items have been added
