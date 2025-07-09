# Quantum Book Store

A C++ console application simulating an extensible online bookstore with admin and customer features.

## Features
- Inventory management for PaperBook, EBook, and DemoBook
- Add, remove, and view books (admin)
- Customer sign up, login, add to cart, remove from cart, checkout
- File-based persistence for books and customers
- Easily extensible for new book types

## Project Structure
```
QuantumBookStore/
├── Admin/
│   ├── admin.cpp
│   └── admin.h
├── Books/
│   ├── book.cpp, book.h
│   ├── PaperBook.cpp, PaperBook.h
│   ├── ebook.cpp, ebook.h
│   ├── demobook.cpp, demobook.h
├── Cart/
│   ├── cart.cpp, cart.h
│   ├── cartitem.cpp, cartitem.h
├── Customer/
│   ├── Customer.cpp, Customer.h
│   ├── CustomerSession.cpp, CustomerSession.h
├── Data/
│   ├── book.txt         # Inventory file
│   ├── customers.txt    # Customer data
│   └── orders.txt       # (future use)
├── InputValidator/
│   ├── InputValidator.cpp, InputValidator.h
├── Services/
│   ├── shippingservice.cpp, shippingservice.h
│   ├── emailservice.cpp, emailservice.h
├── Test/
│   └── BookInventoryTest.cpp
├── main.cpp
├── CMakeLists.txt
├── .gitignore
└── LICENSE
```

## Build & Run
1. **Requirements:** CMake 3.14+, C++14 compiler
2. **Build:**
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
3. **Run:**
   ```sh
   ./QuantumBookStore
   ```

## Example Usage
```
===== Quantum Book Store =====
1. Admin Login
2. Customer Login
3. Customer Sign Up
0. Exit
Choose an option: 1

=== Admin Menu ===
1. View Inventory
2. Add Book
3. Remove Book
4. Save and Exit
...
```

## Test Cases

### 1. Admin: View Inventory
```
===== Quantum Book Store =====
1. Admin Login
2. Customer Login
3. Customer Sign Up
0. Exit
Choose an option: 1

=== Admin Menu ===
1. View Inventory
2. Add Book
3. Remove Book
4. Save and Exit
Enter choice: 1

===== Book Inventory =====
[1] [Paper Book] The Cairo Code | Year: 2020 | Price: 150 | ISBN: 9789771451234 | Stock: 10
[2] [E-Book] Digital Nile Adventures | Year: 2021 | Price: 100 | ISBN: 9789776543219
[3] [Demo Book] Introduction to Ancient Egypt | Year: 1998 | Price: 0 | ISBN: 9789779876543 | Not For Sale
[4] [Paper Book] el fajr  | Year: 2020 | Price: 900 | ISBN: 4354365464 | Stock: 50
```

### 2. Admin: Add Book
```
=== Admin Menu ===
1. View Inventory
2. Add Book
3. Remove Book
4. Save and Exit
Enter choice: 2
Select book type:
1. PaperBook
2. EBook
3. DemoBook
Choice: 1
Enter title: elfajr
Enter year: 2020
Enter price: 500
Enter ISBN: 43534543543
Enter stock: 50
Book added successfully.
```

### 3. Admin: Remove Book
```
=== Admin Menu ===
1. View Inventory
2. Add Book
3. Remove Book
4. Save and Exit
Enter choice: 3

===== Book Inventory =====
[1] [Paper Book] The Cairo Code | Year: 2020 | Price: 150 | ISBN: 9789771451234 | Stock: 10
[2] [E-Book] Digital Nile Adventures | Year: 2021 | Price: 100 | ISBN: 9789776543219
[3] [Demo Book] Introduction to Ancient Egypt | Year: 1998 | Price: 0 | ISBN: 9789779876543 | Not For Sale
[4] [Paper Book] el fajr  | Year: 2020 | Price: 900 | ISBN: 4354365464 | Stock: 50
[5] [Paper Book] elfajr | Year: 2020 | Price: 500 | ISBN: 43534543543 | Stock: 50
Enter number of book to remove: 2
Book removed.
```

### 4. Customer: Login and View Books
```
===== Quantum Book Store =====
1. Admin Login
2. Customer Login
3. Customer Sign Up
0. Exit
Choose an option: 2
Enter username: ahmed123
Login successful.

1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 1

===== Book Inventory =====
[1] [Paper Book] The Cairo Code | Year: 2020 | Price: 150 | ISBN: 9789771451234 | Stock: 10
[2] [Demo Book] Introduction to Ancient Egypt | Year: 1998 | Price: 0 | ISBN: 9789779876543 | Not For Sale
[3] [Paper Book] el fajr  | Year: 2020 | Price: 900 | ISBN: 4354365464 | Stock: 50
[4] [Paper Book] elfajr | Year: 2020 | Price: 500 | ISBN: 43534543543 | Stock: 50
```

### 5. Customer: Add to Cart and View Cart
```
1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 2

===== Book Inventory =====
[1] [Paper Book] The Cairo Code | Year: 2020 | Price: 150 | ISBN: 9789771451234 | Stock: 10
[2] [Demo Book] Introduction to Ancient Egypt | Year: 1998 | Price: 0 | ISBN: 9789779876543 | Not For Sale
[3] [Paper Book] el fajr  | Year: 2020 | Price: 900 | ISBN: 4354365464 | Stock: 50
[4] [Paper Book] elfajr | Year: 2020 | Price: 500 | ISBN: 43534543543 | Stock: 50
Enter book number to add: 1
Enter quantity: 2
Book added to cart.

1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 3

----- Your Cart -----
[1] The Cairo Code (Physical Copy) | Quantity: 2 | Subtotal: 300
```

### 6. Customer: Attempt to Add DemoBook to Cart (Should Fail)
```
1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 2

===== Book Inventory =====
[1] [Paper Book] The Cairo Code | Year: 2020 | Price: 150 | ISBN: 9789771451234 | Stock: 10
[2] [Demo Book] Introduction to Ancient Egypt | Year: 1998 | Price: 0 | ISBN: 9789779876543 | Not For Sale
[3] [Paper Book] el fajr  | Year: 2020 | Price: 900 | ISBN: 4354365464 | Stock: 50
[4] [Paper Book] elfajr | Year: 2020 | Price: 500 | ISBN: 43534543543 | Stock: 50
Enter book number to add: 2
This book is not available for purchase.
```

### 7. Customer: Remove from Cart
```
1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 4

----- Your Cart -----
[1] The Cairo Code (Physical Copy) | Quantity: 2 | Subtotal: 300
[2] elfajr (Physical Copy) | Quantity: 1 | Subtotal: 500
Enter item number to remove: 1
Item removed from cart.

1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 3

----- Your Cart -----
[1] elfajr (Physical Copy) | Quantity: 1 | Subtotal: 500
```

### 8. Customer: Checkout
```
1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 5
Enter your shipping address: mokhtar street

[ShippingService] Shipping the following books to: mokhtar street
- elfajr
Checkout complete. Paid: $500

1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 0
Logged out.
```

### 9. Customer: Add EBook to Cart (Quantity defaults to 1)
```
1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 2

===== Book Inventory =====
[1] [Paper Book] The Cairo Code | Year: 2020 | Price: 150 | ISBN: 9789771451234 | Stock: 10
[2] [E-Book] Digital Nile Adventures | Year: 2021 | Price: 100 | ISBN: 9789776543219
[3] [Demo Book] Introduction to Ancient Egypt | Year: 1998 | Price: 0 | ISBN: 9789779876543 | Not For Sale
[4] [Paper Book] el fajr  | Year: 2020 | Price: 900 | ISBN: 4354365464 | Stock: 50
Enter book number to add: 2
Book added to cart.

1. View Books
2. Add to Cart
3. View Cart
4. Remove from Cart
5. Checkout
0. Logout
Choice: 3

----- Your Cart -----
[1] Digital Nile Adventures (E-Book) | Quantity: 1 | Subtotal: 100
```

## License
MIT License (see LICENSE file) 