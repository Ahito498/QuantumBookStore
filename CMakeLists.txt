cmake_minimum_required(VERSION 3.29)
project(QuantumBookStore)

set(CMAKE_CXX_STANDARD 14)

add_executable(QuantumBookStore
    main.cpp
        Books/book.h
        Books/book.cpp
        Books/paperbook.h
        Books/paperbook.cpp
        Books/ebook.h
        Books/ebook.cpp
        Books/demobook.h
        Books/demobook.cpp
        Services/shippingservice.h
        Services/shippingservice.cpp
        Services/emailservice.h
        Services/emailservice.cpp
        Cart/cartitem.h
        Cart/cartitem.cpp
        Cart/cart.h
        Cart/cart.cpp
        Admin/admin.h
        Admin/admin.cpp
        InputValidator/InputValidator.h
        InputValidator/InputValidator.cpp
        Customer/Customer.h
        Customer/Customer.cpp
        Customer/CustomerSession.h
        Customer/CustomerSession.cpp
        Test/BookInventoryTest.cpp)
