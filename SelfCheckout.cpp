#include "SelfCheckout.h"

void SelfCheckout::scan(const std::vector<Product>& products) {
    std::cout << std::endl;
    std::cout << "Scanned Items: " << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    int count{1};
    for (const auto& product: products) {
        ledger.add(product);
        std::cout << count << "," << product << std::endl;
        count++;
    }
    std::cout << std::string(80, '=') << std::endl;
    std::cout << "Subtotal: $" << ledger.getSubtotal() << std::endl;
    std::cout << "Tax: $" << ledger.getTax() << std::endl;
    std::cout << "Total: $" << ledger.getTotal() << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    std::cout << std::endl;
}

void SelfCheckout::purchase() {
    std::cout << "Please select a payment method:" << std::endl;
    std::cout << "1. Cash" << std::endl;
    std::cout << "2. Card" << std::endl;
    std::cout << "> ";
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            cashTransaction();
            break;
        case 2:
            cardTransaction();
            break;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
    if (getPaymentResult()) {
        printReceipt();
    }
    resetLedger();
}

void SelfCheckout::cashTransaction() {
    std::cout << std::endl;
    std::cout << "Please enter the amount of cash you are paying with:" << std::endl;
    std::cout << "> ";
    double payment;
    std::cin >> payment;
    ledger.setPayment(payment);
    ledger.setChange(payment - ledger.getTotal());
    changeRepository -= ledger.getChange();
    if (ledger.getChange() < 0) {
        std::cout << std::endl;
        std::cout << "Insufficient funds." << std::endl;
        paymentResult = false;
        std::cout << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Payment successful." << std::endl;
        paymentResult = true;
        std::cout << std::endl;
    }
}

void SelfCheckout::cardTransaction() {
    std::cout << std::endl;
    ledger.setPayment(ledger.getTotal());
    paymentResult = true;
    std::cout << "Payment successful!" << std::endl;
    std::cout << std::endl;
}

void SelfCheckout::printReceipt() {
    std::cout << "Receipt:" << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    int count{1};
    for (const auto& product: ledger.getItems()) {
        std::cout << count << "," << product << std::endl;
        count++;
    }
    std::cout << std::string(80, '=') << std::endl;
    std::cout << "Subtotal: $" << ledger.getSubtotal() << std::endl;
    std::cout << "Tax: $" << ledger.getTax() << std::endl;
    std::cout << "Total: $" << ledger.getTotal() << std::endl;
    std::cout << "Payment: $" << ledger.getPayment() << std::endl;
    std::cout << "Change: $" << ledger.getChange() << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    std::cout << std::endl;
}

void SelfCheckout::resetLedger() {
    ledger.reset();
}

double SelfCheckout::getChangeRepository() const {
    return changeRepository;
}

void SelfCheckout::setChangeRepository(double changeRepo) {
    SelfCheckout::changeRepository = changeRepo;
}

bool SelfCheckout::getPaymentResult() const {
    return paymentResult;
}
