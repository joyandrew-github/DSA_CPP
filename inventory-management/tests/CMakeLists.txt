add_executable(InventoryTests
    ProductTest.cpp
    InventoryTest.cpp
    CategoryTest.cpp
)

target_include_directories(InventoryTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(InventoryTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(InventoryTests)