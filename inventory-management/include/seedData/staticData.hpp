#ifndef STATIC_DATA_HPP
#define STATIC_DATA_HPP

#include "../model/Category.hpp"
#include <vector>

inline std::vector<Category> getStaticCategories() {
    return {
        Category("C001", "Electronics"),
        Category("C002", "Clothing"),
        Category("C003", "Home Appliances"),
        Category("C004", "Books"),
        Category("C005", "Toys"),
        Category("C006", "Sports Equipment"),
        Category("C007", "Beauty Products"),
        Category("C008", "Automotive Parts"),
        Category("C009", "Garden Supplies"),
        Category("C010", "Office Supplies")
    };
}

#endif