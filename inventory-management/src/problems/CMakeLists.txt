add_executable(inventory-management
    main.cpp
)

target_include_directories(inventory-management PRIVATE ${CMAKE_SOURCE_DIR}/include)