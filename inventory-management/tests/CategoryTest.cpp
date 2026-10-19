#include <gtest/gtest.h>
#include <stdexcept>
#include "model/Category.hpp"

TEST(CategoryTest,CreateCategoryWithIdAndName)
{
    Category category("1","Electronics");

    EXPECT_EQ(category.getId(),"1");
    EXPECT_EQ(category.getName(),"Electronics");
}

TEST(CategoryTest,ThrowExceptionWhenIdIsEmpty)
{
    EXPECT_THROW(
        Category category("","Electronics"),
        std::invalid_argument
    );

    EXPECT_THROW(
        Category category("1",""),
        std::invalid_argument
        );

}



TEST(CategoryTest, PreservesSpacesInCategoryName) {
    Category category("C101", "Home Appliances");

    EXPECT_EQ(category.getId(), "C101");
    EXPECT_EQ(category.getName(), "Home Appliances");
}
