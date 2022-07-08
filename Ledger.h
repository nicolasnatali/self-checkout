#ifndef SELF_CHECKOUT_LEDGER_H
#define SELF_CHECKOUT_LEDGER_H

#include "Product.h"

#include <vector>

class Ledger {
public:
    void add(const Product &product);

    void reset();

    [[nodiscard]] const std::vector<Product> &getItems() const;

    [[nodiscard]] double getSubtotal() const;

    [[nodiscard]] double getTax() const;

    [[nodiscard]] double getTotal() const;

    [[nodiscard]] double getPayment() const;

    void setPayment(double amount);

    [[nodiscard]] double getChange() const;

    void setChange(double amount);

private:
    std::vector<Product> items;
    double subtotal{0.00};
    double tax{0.00};
    double total{0.00};
    double payment{0.00};
    double change{0.00};
};

#endif //SELF_CHECKOUT_LEDGER_H
