# OrderBook Project

## Overview

This project implements a basic order book for managing limit orders in a financial exchange. The code handles both buy and sell orders, processes trades when orders match, and stores the trade details such as price, quantity, and timestamp. The order book is thread-safe and scalable, ensuring that orders are processed in the correct sequence.

## Features
- **Order Book Management**: Insert, manage, and match limit orders.
- **Trade Recording**: Log executed trades with detailed information.
- **Concurrency**: A thread pool is used to handle the processing of orders in a multithreaded environment, ensuring high performance.
- **Fine-Grained Locking**: We use fine-grained mutexes for locking parts of the order book to avoid bottlenecks, ensuring optimal performance in a multithreaded setup.
  
## Assumptions
1. **Asset Specific Order Books**: Each asset has its own order book for both buy and sell orders.
2. **First-In-First-Out (FIFO)**: Orders with the same price are processed in the order they were received (Timestamp of created order).
3. **Trade Price Assumption**: When a buy order is placed, the trade will occur at the best available (lowest) sell price, similarly when a sell order is placed, the trade will occur at the best available (highest) buy price.
   <br>Example1: If a buy order is placed for 130 and the matching sell order is at 90, the trade will be executed at 90 (the lowest offered price).
   <br>Example2: If a sell order is placed for 90 and the maximum available buy order is for 130, the trade will be executed at 130 (the highest offered price).

## Dependencies
- **CMake (version >= 3.5)**: Build System
- **GCC **: I have used gcc (Rev6, Built by MSYS2 project) 13.2.0, but any clang or gcc compiler should work ideally.
- **Google Test (GTest)**: Used for unit testing.

### Required Libraries
1. **Google Test** (for unit testing)
3. **C++ Standard Library (C++17)**

### How to Build
- Clone the repository
- Configure with Cmake (If using VS Code, run the "Cmake: Configure" command from Command Palette.
- Compile the project Run command ("cmake --build .") in the root folder(Order_book).
- Run the exe file generated in the exe folder.
- To run tests run the exe file generated in build/tests directory.
- **NOTE**: Google test library is included in this repo, need not to be installed seperately.

