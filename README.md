# CIS17B-S25-33477-Assignment4
# User Instructions

## How to Compile

1. Open a terminal or command prompt.  
2. Navigate to the directory containing `storage_manager.cpp`.  
3. Compile the code using:

   ```bash
   g++ -std=c++11 -o storage_manager storage_manager.cpp
How to Run
• On Linux or macOS:

./storage_manager

• On Windows:

storage_manager.exe

How to use
Launch the program.

A menu will show up with options:

Add an item

Find an item by ID

Remove an item by ID

List items by description

Exit the program

You type the number of the option you want and hit enter. The program checks for errors like:

Trying to add an item with a duplicate ID

Finding or removing an item that doesn’t exist

Listing when no items have been added
