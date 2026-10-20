#include <iostream>

#include "model/Library.hpp"

Library::Library() = default;

bool Library::addBook(const Book &book)
{

    auto res = books.emplace(book.getId(), book);
    return res.second;
}

Book *Library::findBook(int id)
{
    auto it = books.find(id);
    if (it == books.end())
    {
        return nullptr;
    }
    return &it->second;
}

const Book *Library::findBook(int id) const
{
    auto it = books.find(id);
    if (it == books.end())
    {
        return nullptr;
    }
    return &it->second;
}

bool Library::borrowBook(int id)
{
    Book *book = findBook(id);

    if (book == nullptr)
    {
        return false;
    }
    return book->borrowBook();
}

bool Library::returnBook(int id)
{
    Book *book = findBook(id);
    if (book == nullptr)
    {
        return false;
    }
    return book->returnBook();
}

bool Library::removeBook(int id)
{
    auto it = books.find(id);
    if (it == books.end())
    {
        return false;
    }
    if (!it->second.isAvailable())
    {
        return false;
    }
    books.erase(it);
    return true;
}

void Library::displayBooks() const
{
    for (const auto &pair : books)
    {
        const Book &book = pair.second;
        std::cout << "Book Id: " << book.getId() << '\n';
        std::cout << "Title: " << book.getTitle() << '\n';
        std::cout << "Author: " << book.getAuthor() << '\n';
        std::cout << "Available :"
                  << (book.isAvailable() ? "Yes" : "No") << "\n\n";
    }
}