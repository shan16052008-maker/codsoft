#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;
//==================================BOOK CLASS==================================
class Book {
    public:
        int id;      
        string title;
        string author;
        string isbn;
        bool issued;
        string issuedTo;
        string issuedDate;
        int publicationYear;
        int totalCopies;
        int availableCopies;
        Book() {}    
        Book(int j, string t, string a, string i, int pY, int tC) {
            id = j;
            title = t;
            author = a;
            isbn = i;
            issued = false;
            issuedTo = "None";
            issuedDate = "N/A";
            publicationYear = pY;
            totalCopies = tC;
            availableCopies = tC; // Initially, all copies are available
        }
    };
//==================================LIBRARY CLASS==================================     
class Library {
    private:
        vector<Book> books;
    public:
    void loadBooks() {
        ifstream inFile("books.txt");
        if (!inFile) {
            cerr << "Error opening file!" << endl;
            return;
        }
        Book b;
        while (inFile >> b.id >> b.title >> b.author >> b.isbn >> b.publicationYear >> b.totalCopies) {
            inFile.ignore(); // Ignore the newline character after reading totalCopies
            getline(inFile, b.issuedTo); // Read issuedTo
            getline(inFile, b.issuedDate); // Read issuedDate
            inFile >> b.issued; // Read issued status
            inFile.ignore(); // Ignore the newline character after reading issued status
            getline(inFile, b.issuedTo); // Read issuedTo again (if needed)
            getline(inFile, b.issuedDate); // Read issuedDate again (if needed)
            b.availableCopies = b.totalCopies; // Set available copies to total copies
            books.push_back(b);
        }
        inFile.close();
    }
    void saveBooks() {
        ofstream outFile("books.txt");
        for (const auto& b : books) {
            outFile << b.id << " " << b.title << " " << b.author << " " << b.isbn << " "
                    << b.publicationYear << " " << b.totalCopies << endl;
            outFile << b.issuedTo << endl;
            outFile << b.issuedDate << endl;
            outFile << b.issued << endl;
        }
        outFile.close();
    }
    void addBook() {
        int id, publicationYear, totalCopies;
        string title, author, isbn;
        cout<<"===============================ADD BOOK===============================" << endl;
        cout<< "Enter Book ID: ";
        cin >> id;
        cin.ignore(); 
        for (const auto& b : books) {
            if (b.id == id) {
                cout << "Book with this ID already exists!" << endl;
                return;
            }
        }
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book ISBN: ";
        getline(cin, isbn);
        cout << "Enter publication year: ";
        cin >> publicationYear;
        cout << "Enter total copies: ";
        cin >> totalCopies;
        Book newBook(id, title, author, isbn, publicationYear, totalCopies);
        books.push_back(newBook);
        saveBooks();
        cout << "Book added successfully!" << endl;
    }
    void displayBooks() {
        cout <<"===============================LIBRARY BOOKS===============================" << endl;
        if (books.empty()) {
            cout << "No books available in the library!" << endl;
            return;
        }
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "ISBN"<<setw(20)<<"ISSUED TO" << setw(20) << "ISSUED DATE" << setw(15) << "Issued" << setw(15) << "Publication Year" << setw(15) << "Total Copies" << setw(15) << "Available Copies" << endl;
        cout <<"=====================================================================================================================\n";
        for (const auto& b : books) {
            cout << left << setw(10) << b.id << setw(30) << b.title << setw(20) << b.author << setw(15) << b.isbn << setw(20) <<(b.issued?"issued":"available")<<setw(20)<<b.issuedTo<< setw(20) << b.issuedDate << setw(15) << b.issued << setw(15) << b.publicationYear << setw(15) << b.totalCopies << setw(15) << b.availableCopies << endl;
        }
    }
    void searchBook() {
        int id;
        bool found = false;
        cout <<"===============================SEARCH BOOK===============================" << endl;
        cout << "Enter Book ID: "<<endl;
        cin >> id;
        for (const auto& b : books) {
            if (b.id == id) {
                cout << "Book found!" << endl;
                cout << "ID: " << b.id << endl;
                cout << "Title: " << b.title << endl;
                cout << "Author: " << b.author << endl;
                cout << "ISBN: " << b.isbn << endl;
                cout << "Publication Year: " << b.publicationYear << endl;
                cout << "Total Copies: " << b.totalCopies << endl;
                cout << "Available Copies: " << b.availableCopies << endl;
                cout << "Issued To: " << (b.issued ? b.issuedTo : "Available") << endl;
            if (b.issued) {
                cout << "Issued to: " << b.issuedTo << endl;
                cout << "Issued date: " << b.issuedDate << endl;
            }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found!" << endl;
        }
    }
    string getCurrentDate() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        stringstream ss;
        ss << 1900 + ltm->tm_year << "-" << setw(2) << setfill('0') << 1 + ltm->tm_mon << "-" << setw(2) << setfill('0') << ltm->tm_mday;
        return ss.str();
    }
    void issueBook() {
        int id;
        string studentName;
        bool found = false;
        cout <<"===============================ISSUE BOOK===============================" << endl;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        for (auto& b : books) {
            if (b.id == id) {
                if (b.issued) {
                    cout << "Book is already issued to " << b.issuedTo << " on " << b.issuedDate << endl;
                    return;
                }
                else if (b.availableCopies <= 0) {
                    cout << "No copies available for this book!" << endl;
                    return;
                }
                 else if (!b.issued) {
                cout << "Enter student name: ";
                getline(cin, studentName);
                b.issued = true;
                b.issuedTo = studentName;
                b.issuedDate = getCurrentDate();
                b.availableCopies--;
                saveBooks();
                cout << "Book issued successfully to " << studentName << " on " << b.issuedDate << endl;
                found = true;
                }
                break;
            }
        }
        if (!found) {
            cout << "Book not found!" << endl;
        }
    }
    void returnBook() {
        int id;
        bool found = false;
        cout <<"===============================RETURN BOOK===============================" << endl;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        for (auto& b : books) {
            if (b.id == id) {
                if (!b.issued) {
                    cout << "Book is not issued!" << endl;
                    return;
                }
                b.issued = false;
                b.issuedTo = "None";
                b.issuedDate = "N/A";
                b.availableCopies++;
                saveBooks();
                cout << "Book returned successfully!" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found!" << endl;
        }
    }
    void deleteBook() {
        int id;
        bool found = false;
        cout <<"===============================DELETE BOOK===============================" << endl;
        cout << "Enter Book ID: ";
        cin >> id;
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                if (it->issued) {
                    cout << "Cannot delete book. It is currently issued to " << it->issuedTo << " on " << it->issuedDate << endl;
                    return;
                }
                books.erase(it);
                saveBooks();
                cout << "Book deleted successfully!" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found!" << endl;
        }
    }
};
bool login() {
    string username, password;
    cout <<"===============================LIBRARY LOGIN===============================" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    return (username == "shan" && password == "1903");
if (username == "shan" && password == "1903") {
        return true;
    }
   return false;
}
int main() {
    if (!login()) {
        cout << "Invalid username or password!" << endl;
        return 0;
    }
    Library library;
    library.loadBooks();
    int choice;
    do {
        cout <<"===============================LIBRARY MANAGEMENT SYSTEM===============================" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Delete Book" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.issueBook();
                break;
            case 5:
                library.returnBook();
                break;
            case 6:
                library.deleteBook();
                break;
            case 7:
                cout << "\nsaving data...\n";
                cout << "Thank you for using LMS!\n";
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}