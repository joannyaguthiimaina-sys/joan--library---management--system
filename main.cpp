#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Book class
class Book {
public:
    int id;
    string title;
    string author;
    bool available;
    int borrowedBy;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        available = true;
        borrowedBy = -1;
    }

    void display() {
        cout << "ID: " << id
             << ", Title: " << title
             << ", Author: " << author
             << ", Status: ";

        if (available)
            cout << "Available";
        else
            cout << "Borrowed by User " << borrowedBy;

        cout << endl;
    }
};

// User class
class User {
public:
    int userId;
    string name;

    User(int id, string n) {
        userId = id;
        name = n;
    }

    void display() {
        cout << "User ID: " << userId
             << ", Name: " << name << endl;
    }
};

// Library class
class Library {
public:
    vector<Book> books;
    vector<User> users;

    void addBook(Book b) {
        books.push_back(b);
        cout << "Book added." << endl;
    }

    void addUser(User u) {
        users.push_back(u);
        cout << "User added." << endl;
    }

    void displayBooks() {
        if (books.size() == 0) {
            cout << "No books in library." << endl;
            return;
        }

        for (int i = 0; i < books.size(); i++) {
            books[i].display();
        }
    }

    void displayUsers() {
        if (users.size() == 0) {
            cout << "No users found." << endl;
            return;
        }

        for (int i = 0; i < users.size(); i++) {
            users[i].display();
        }
    }

    void removeBook(int bookId) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == bookId) {
                books.erase(books.begin() + i);
                cout << "Book removed." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void searchByTitle(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                books[i].display();
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void borrowBook(int bookId, int userId) {

        bool userFound = false;

        for (int i = 0; i < users.size(); i++) {
            if (users[i].userId == userId) {
                userFound = true;
                break;
            }
        }

        if (!userFound) {
            cout << "User not found." << endl;
            return;
        }

        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == bookId) {

                if (books[i].available) {
                    books[i].available = false;
                    books[i].borrowedBy = userId;
                    cout << "Book borrowed." << endl;
                } else {
                    cout << "Book already borrowed." << endl;
                }
                return;
            }
        }

        cout << "Book not found." << endl;
    }

    void returnBook(int bookId, int userId) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == bookId) {

                if (!books[i].available && books[i].borrowedBy == userId) {
                    books[i].available = true;
                    books[i].borrowedBy = -1;
                    cout << "Book returned." << endl;
                } else {
                    cout << "Return failed." << endl;
                }
                return;
            }
        }

        cout << "Book not found." << endl;
    }
};

int main() {

    Library lib;

    User u1(1, "Alice");
    User u2(2, "Bob");

    lib.addUser(u1);
    lib.addUser(u2);

    Book b1(101, "Clean Code", "Robert Martin");
    Book b2(102, "Atomic Habits", "James Clear");

    lib.addBook(b1);
    lib.addBook(b2);

    cout << "\nAll Books:\n";
    lib.displayBooks();

    cout << "\nBorrowing Book:\n";
    lib.borrowBook(101, 1);

    cout << "\nBooks After Borrow:\n";
    lib.displayBooks();

    cout << "\nReturning Book:\n";
    lib.returnBook(101, 1);

    cout << "\nRemoving Book:\n";
    lib.removeBook(102);

    cout << "\nFinal List:\n";
    lib.displayBooks();

    return 0;
}





