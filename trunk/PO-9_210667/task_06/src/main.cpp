#include <QCoreApplication>
#include <QString>
#include <QDebug>

// Базовый класс для управления балансом счета
class Account {
public:
    explicit Account(QString holder, double initialBalance = 0.0)
        : accountHolder(holder), balance(initialBalance) {}

    virtual ~Account() {}

    // Внести средства на счет
    virtual void deposit(double amount) {
        balance += amount;
        qDebug() << accountHolder << "внесено: $" << amount;
    }

    // Снять средства со счета
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            qDebug() << accountHolder << "снято: $" << amount;
        } else {
            qDebug() << "Недостаточно средств на счете для снятия.";
        }
    }

    // Получить баланс счета
    double getBalance() const {
        return balance;
    }

protected:
    QString accountHolder;
    double balance;
};

// Класс для представления банковских транзакций
class Transaction {
public:
    Transaction(Account& account, double amount)
        : account(account), amount(amount) {}

    // Выполнить транзакцию
    virtual void execute() = 0;

protected:
    Account& account;
    double amount;
};

// Класс для представления операции пополнения счета
class DepositTransaction : public Transaction {
public:
    DepositTransaction(Account& account, double amount)
        : Transaction(account, amount) {}

    void execute() override {
        account.deposit(amount);
    }
};

// Класс для представления операции снятия со счета
class WithdrawTransaction : public Transaction {
public:
    WithdrawTransaction(Account& account, double amount)
        : Transaction(account, amount) {}

    void execute() override {
        account.withdraw(amount);
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Пример использования классов
    Account savingsAccount("Иванов Иван", 1000.0);

    qDebug() << "Баланс счета до транзакций: $" << savingsAccount.getBalance();

    DepositTransaction deposit(savingsAccount, 500.0);
    deposit.execute();

    WithdrawTransaction withdraw(savingsAccount, 200.0);
    withdraw.execute();

    qDebug() << "Баланс счета после транзакций: $" << savingsAccount.getBalance();

    return a.exec();
}
