cmake_minimum_required(VERSION 3.5.0)
project( OrderBook VERSION 0.1.0 LANGUAGES C CXX)

add_library(OrderBookLib STATIC
    src/order.cpp
    src/order_book.cpp
    src/trade.cpp
    src/thread_pool.cpp
)


add_executable( OrderBook 
    src/main.cpp
)

target_link_libraries(OrderBook OrderBookLib)

include(CTest)
enable_testing()

add_subdirectory(third_party/googletest)
add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
