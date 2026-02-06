# joan--library---management--system
A simple but well defined library system.

**
Library Management System (C++)**
Project Description

This project is a simple Library Management System written in C++.

The system allows the user to:

Add books

Remove books

Search books by title

Add users

Borrow books

Return books

Display all books and users

The project was developed using Object-Oriented Programming (OOP) concepts.

How the System is Designed

The program is divided into three main classes:

1. Book Class

This class represents a single book.

It stores:

Book ID

Title

Author

Availability status

It also keeps track of which user borrowed the book.

2. User Class

This class represents a library user.

It stores:

User ID

Name

3. Library Class

This class manages everything.

It:

Stores all books using a vector

Stores all users using a vector

Handles adding, removing, searching

Handles borrowing and returning books

This makes the system modular because each class has its own responsibility.

Features Implemented

Add new books

Remove books by ID

Search books by title

Add users

Borrow books (only if available and user exists)

Return books (only by the correct user)

Handle errors like:

Book not found

User not found

Book already borrowed

Test Cases
Positive Test Cases:

Adding multiple books → They appear when displayed

Borrowing an available book → Status changes to borrowed

Returning a borrowed book → Status changes to available

Removing an existing book → It disappears from the list

Negative Test Cases:

Borrowing a book that is already borrowed → Shows error

Borrowing with invalid user ID → Shows error

Removing a non-existing book → Shows error

Searching for a non-existing book → Shows error

How to Compile and Run

Open terminal or command prompt.

Compile the program:

g++ main.cpp -o library


Run the program:

On Windows:

library.exe


On Linux/Mac:

./library

Concepts Used

Classes and Objects

Constructors

Vectors

Encapsulation

Basic error handling

Modular design
