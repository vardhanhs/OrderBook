add_executable(OrderBookTests
    test_order.cpp
    test_order_book.cpp
    test_trade.cpp
)

target_link_libraries(OrderBookTests gtest gtest_main)

target_link_libraries(OrderBookTests OrderBookLib)

add_test(NAME OrderBookTests COMMAND OrderBookTests)