#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) : type(t), amount(a) {}
};

class Account {
public:
    string accountNumber;
    double balance;
    vector<Transaction> transactions;

    Account(string accNumber, double bal) : accountNumber(accNumber), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction("Withdrawal", amount));
            cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }

    void printAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transactions:" << endl;
        for (Transaction t : transactions) {
            cout << t.type << ": " << t.amount << endl;
        }
    }
};

class Customer {
public:
    string name;
    string customerID;
    vector<Account> accounts;

    Customer(string n, string id) : name(n), customerID(id) {}

    void addAccount(Account account) {
        accounts.push_back(account);
    }

    void printCustomerInfo() {
        cout << "Customer Name: " << name << endl;
        cout << "Customer ID: " << customerID << endl;
        for (Account& acc : accounts) {
            acc.printAccountInfo();
        }
    }
};

int main() {
    Customer customer("John Doe", "C123");

    Account acc1("A123", 1000.0);
    customer.addAccount(acc1);

    int choice;
    double amount;

    cout << "\nBanking System Menu:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Check Balance\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            customer.accounts[0].deposit(amount);
            break;
        case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            customer.accounts[0].withdraw(amount);
            break;
        case 3:
            customer.accounts[0].checkBalance();
            break;
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
    }

    return 0;
}
