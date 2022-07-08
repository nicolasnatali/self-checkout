#ifndef SELF_CHECKOUT_SELFCHECKOUT_H
#define SELF_CHECKOUT_SELFCHECKOUT_H

#include "Ledger.h"

#include <iostream>
#include <vector>

class SelfCheckout {
public:
    void scan(const std::vector<Product>& products);

    void purchase();

    [[nodiscard]] double getChangeRepository() const;

    void setChangeRepository(double changeRepo);

    [[nodiscard]] bool getPaymentResult() const;

private:
    double changeRepository{200.00};
    Ledger ledger;
    bool paymentResult{true};

    void cashTransaction();

    void cardTransaction();

    void printReceipt();

    void resetLedger();
};

#endif //SELF_CHECKOUT_SELFCHECKOUT_H
