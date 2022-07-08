#include "Product.h"

Product::Product(std::string id, std::string desc, double price)
        : id(std::move(id)), desc(std::move(desc)), price(price) {}

const std::string &Product::getId() const {
    return id;
}

const std::string &Product::getDesc() const {
    return desc;
}

double Product::getPrice() const {
    return price;
}

std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << product.id << "," << product.desc << "," << product.price;
    return os;
}
