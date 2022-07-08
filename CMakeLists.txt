cmake_minimum_required(VERSION 3.22)
project(self_checkout)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        self_checkout
        main.cpp
        Product.cpp
        Product.h
        GroceryStore.cpp
        GroceryStore.h
        Ledger.cpp
        Ledger.h
        SelfCheckout.cpp
        SelfCheckout.h
)
