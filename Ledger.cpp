#include "Ledger.h"

void Ledger::add(const Product &product) {
    items.push_back(product);
    subtotal += product.getPrice();
    tax += 0.05 * product.getPrice();
    total = subtotal + tax;
}

void Ledger::reset() {
    items.clear();
    subtotal = 0.00;
    tax = 0.00;
    total = 0.00;
    payment = 0.00;
    change = 0.00;
}

const std::vector<Product> &Ledger::getItems() const {
    return items;
}

double Ledger::getSubtotal() const {
    return subtotal;
}

double Ledger::getTax() const {
    return tax;
}

double Ledger::getTotal() const {
    return total;
}

double Ledger::getPayment() const {
    return payment;
}

void Ledger::setPayment(double amount) {
    Ledger::payment = amount;
}

double Ledger::getChange() const {
    return change;
}

void Ledger::setChange(double amount) {
    Ledger::change = amount;
}
