#include <iostream>
#include "model/Library.hpp"

int main()
{
    Library library;

    // Create  Books
    Book book1(1, "TestBook", "Joy");
    Book book2(2, "Atomic Habits", "James Clear");
    Book book3(3, "The Alchemist", "Paulo Coelho");

    // Add Books
    std::cout << "Adding Books\n";
    std::cout << "Book 1: " << (library.addBook(book1) ? "Added" : "Already Exists") << "\n\n";
    std::cout << "Book 2: "
              << (library.addBook(book2) ? "Added" : "Already exists")
              << '\n';

    std::cout << "Book 3: "
              << (library.addBook(book3) ? "Added" : "Already exists")
              << "\n\n";

    // Try adding a duplicate ID
    Book duplicateBook(1, "Another Book", "Unknown Author");
    std::cout << "Adding duplicate ID: "
              << (library.addBook(duplicateBook) ? "Added" : "Failed")
              << "\n\n";

    // Display books
    std::cout << "All Books :" << '\n';
    library.displayBooks();

    // Borrow Books
    std::cout << "Borrow books2 :" << (library.borrowBook(2) ? "Success" : "Failed") << "\n\n";

    // Return the book
    std::cout << "Return book 2: "
              << (library.returnBook(2) ? "Success" : "Failed")
              << "\n\n";

    // Find an Book
    Book *findBook = library.findBook(2);
    if (findBook != nullptr)
    {
        std::cout << "Found book: "
                  << findBook->getTitle() << '\n';
    }
    else
    {
        std::cout << "Book not found\n";
    }

    // Find a nonexistent book
    if (library.findBook(99) == nullptr)
    {
        std::cout << "Book ID 99 does not exist\n";
    }

    // Remove an book
    std::cout << "Remove book 3 :" << (library.removeBook(3) ? "Sucessfully Removed" : "Failed") 
    << "\n\n";

    std::cout << "Final Library: " << '\n';
    library.displayBooks();

    return 0;
}