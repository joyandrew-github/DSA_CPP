#include "model/Book.hpp"

Book::Book(int id, const std::string &bookTitle, const std::string &bookAuthor)
    : id(id),
      bookTitle(bookTitle),
      bookAuthor(bookAuthor),
      available(true) {}

int Book::getId() const
{
    return id;
}

std::string Book::getTitle() const
{
    return bookTitle;
}

std::string Book::getAuthor() const
{
    return bookAuthor;
}

bool Book::isAvailable() const
{
    return available;
}

bool Book::borrowBook()
{
    if (!available)
    {
        return false;
    }
    available = false;
    return true;
}

bool Book::returnBook()
{
    if (available)
    {
        return false;
    }
    available = true;
    return true;
}