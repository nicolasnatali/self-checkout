#ifndef SELF_CHECKOUT_GROCERYSTORE_H
#define SELF_CHECKOUT_GROCERYSTORE_H

#include "Product.h"
#include "SelfCheckout.h"

#include <iostream>
#include <iomanip>
#include <vector>

class GroceryStore {
public:
    void run();

private:
    double cashRepository{std::numeric_limits<double>::infinity()};
    std::vector<Product> inventory{
            Product("Meat01", "T-Bone Steak", 7.99),
            Product("Meat02", "Tyson Fresh Chicken Wings", 10.00),
            Product("Icecream01", "Chocolate Ice Cream", 2.50),
            Product("Icecream02", "Vanilla Ice Cream", 2.50),
            Product("Corn01", "Fresh Sweet Corn", 2.00),
            Product("Casewater01", "24 Bottles 16-Oz of Deer Park Water", 4.99),
            Product("Potatochips01", "Plain Potato Chips", 2.00),
            Product("Potatochips02", "Green Onion Potato Chips", 2.00),
            Product("Donuts01", "Glazed Donuts One-Dozen", 4.99),
            Product("Sausage01", "8-Sausage Pack", 4.99),
            Product("Eggs01", "Dozen Eggs", 3.00),
            Product("Milk01", "Gallon Milk", 4.00)
    };
    SelfCheckout selfCheckout{};
    std::vector<Product> shoppingCart{};

    void viewInventory();

    void viewShoppingCart();

    void selectItems();
};

#endif //SELF_CHECKOUT_GROCERYSTORE_H
