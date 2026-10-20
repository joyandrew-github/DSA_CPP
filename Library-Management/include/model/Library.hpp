#pragma once

#include<unordered_map>
#include "model/Book.hpp"

class Library{
private:
    std::unordered_map<int,Book>books;

public:
    Library ();
    // add a book to the library
    bool addBook(const Book& book);

    //find a book by its id
    Book* findBook(int id);
 
    // find a book by its id (const version)
    //why const version? Because it allows you to call this method on const Library objects, ensuring that the method does not modify the state of the Library instance. This is useful for read-only operations where you want to retrieve information without altering the underlying data.
    const Book* findBook(int id) const;

    bool borrowBook(int id);
    bool returnBook(int id);

    bool removeBook(int id);

    void displayBooks() const;

};