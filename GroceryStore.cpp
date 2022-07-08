#include "GroceryStore.h"

void GroceryStore::run() {
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "Welcome to the Grocery Store!" << std::endl;
    while (true) {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Select Items" << std::endl;
        std::cout << "2. View Shopping Cart" << std::endl;
        std::cout << "3. Checkout" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "> ";
        int option;
        std::cin >> option;
        switch (option) {
            case 1:
                viewInventory();
                selectItems();
                break;
            case 2:
                viewShoppingCart();
                break;
            case 3:
                if (selfCheckout.getChangeRepository() < 50.00) {
                    cashRepository -= (200.00 - selfCheckout.getChangeRepository());
                    selfCheckout.setChangeRepository(200.00);
                }
                selfCheckout.scan(shoppingCart);
                selfCheckout.purchase();
                shoppingCart.clear();
                break;
            case 4:
                cashRepository = 0.0;
                return;
            default:
                std::cout << "Invalid option." << std::endl;
                break;
        }
    }
}

void GroceryStore::viewInventory() {
    std::cout << std::endl;
    std::cout << "Inventory:" << std::endl;
    for (const auto &product: inventory) {
        std::cout << product.getId() << "," << product.getDesc() << "," << product.getPrice() << std::endl;
    }
    std::cout << std::endl;
}

void GroceryStore::selectItems() {
    std::cout << "Please select items to add to your cart. Type 'done' when finished." << std::endl;
    while (true) {
        std::cout << "> ";
        std::string id;
        std::cin >> id;
        if (id == "done") {
            break;
        }
        auto product = std::find_if(inventory.begin(), inventory.end(), [&id](const Product &product) {
            return product.getId() == id;
        });
        if (product == inventory.end()) {
            std::cout << "Invalid product." << std::endl;
            continue;
        }
        shoppingCart.push_back(*product);
    }
    std::cout << std::endl;
}

void GroceryStore::viewShoppingCart() {
    std::cout << std::endl;
    std::cout << "Shopping Cart:" << std::endl;
    for (const auto &product: shoppingCart) {
        std::cout << product.getId() << "," << product.getDesc() << "," << product.getPrice() << std::endl;
    }
    std::cout << std::endl;
}
