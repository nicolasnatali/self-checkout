#ifndef SELF_CHECKOUT_PRODUCT_H
#define SELF_CHECKOUT_PRODUCT_H

#include <ostream>
#include <string>

class Product {
public:
    Product(std::string id, std::string desc, double price);

    [[nodiscard]] const std::string &getId() const;

    [[nodiscard]] const std::string &getDesc() const;

    [[nodiscard]] double getPrice() const;

    friend std::ostream &operator<<(std::ostream &os, const Product &product);

private:
    std::string id;
    std::string desc;
    double price;
};

#endif //SELF_CHECKOUT_PRODUCT_H
