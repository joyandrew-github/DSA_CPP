#pragma once

#include <string>

class Book{
private:
    int id;
    std::string bookTitle;
    std::string bookAuthor;
    bool available;
public:
    Book(int id,const std::string& bookTitle,const std::string& bookAuthor);

    int getId()const;
    std::string getAuthor()const;
    std::string getTitle()const;

    bool isAvailable()const;

    bool borrowBook();
    bool returnBook();
};