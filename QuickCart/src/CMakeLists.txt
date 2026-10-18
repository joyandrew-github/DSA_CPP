add_executable(QuickCart
    main.cpp
    Application.cpp
)

target_link_libraries(QuickCart PRIVATE QuickCartCommon)