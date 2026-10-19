#ifndef CATEGORY_HPP
#define CATEGORY_HPP
#include <stdexcept>
#include <string>

class Category {
private:
  std::string id;
  std::string name;

public:
  Category(const std::string &id, const std::string &name)
      : id(id), name(name) {
    if (id.empty()) {
      throw std::invalid_argument("Category id cannot be empty");
    }
    if (name.empty()) {
      throw std::invalid_argument("Category name cannot be empty");
    }
  }

  const std::string &getId() const { return id; }
  const std::string &getName() const { return name; }
};

#endif