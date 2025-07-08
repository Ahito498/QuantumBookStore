#include "../Admin/admin.h"
#include "../Books/PaperBook.h"
#include "../Books/EBook.h"
#include "../Books/DemoBook.h"
#include <iostream>
#include <memory>

using namespace std;

class BookInventoryTest {
public:
    static void runAllTests() {
        cout << "\n--- Book Inventory Test ---\n";
        testAddBooks();
        testRemoveBook();
        testBuyBook();
    }

    static void testAddBooks() {
        cout << "\n[TEST] Adding books...\n";
        AdminSession::loadInventory();
        AdminSession::getInventory().push_back(make_unique<PaperBook>("Test Paper", 2022, 50.0, "ISBNPAPER", 5));
        AdminSession::getInventory().push_back(make_unique<EBook>("Test EBook", 2021, 30.0, "ISBNEBOOK"));
        AdminSession::getInventory().push_back(make_unique<demobook>("Test Demo", 2000, 0.0, "ISBNDEMO"));
        AdminSession::saveInventory();
        AdminSession::viewInventory();
    }

    static void testRemoveBook() {
        cout << "\n[TEST] Removing the first book...\n";
        AdminSession::loadInventory();
        if (!AdminSession::getInventory().empty()) {
            AdminSession::getInventory().erase(AdminSession::getInventory().begin());
            AdminSession::saveInventory();
        }
        AdminSession::viewInventory();
    }

    static void testBuyBook() {
        cout << "\n[TEST] Simulate buying a book (manual simulation, as CustomerSession is interactive)...\n";
        AdminSession::loadInventory();
        if (!AdminSession::getInventory().empty()) {
            auto& bookPtr = AdminSession::getInventory().front();
            if (bookPtr->isPurchasable()) {
                cout << "Buying 1 copy of: ";
                bookPtr->printDetails();
                bookPtr->decreaseStock(1);
                AdminSession::saveInventory();
                cout << "[TEST] Book bought. Updated inventory:\n";
                AdminSession::viewInventory();
            } else {
                cout << "[TEST] First book is not purchasable.\n";
            }
        } else {
            cout << "[TEST] No books to buy.\n";
        }
    }
};

/*int main() {
    BookInventoryTest::runAllTests();
    return 0;
} */