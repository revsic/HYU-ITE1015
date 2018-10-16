#ifndef SIMPLE_ACCOUNT_H
#define SIMPLE_ACCOUNT_H

#include <string>
#include <vector>

class Account {
public:
    Account(std::string&& id);
    Account(const std::string& id);

    std::string Log() const;
    int Deposit(int money);
    int Withdraw(int money);

private:
    std::string m_id;
    int m_balance;
};

class Manager {
public:
    Manager();
    
    int GetSize() const;
    std::string Log(int id) const;

    int NewAccount();
    int Deposit(int id, int money);
    int Withdraw(int id, int money);
    int Transfer(int src, int dst, int money);

private:
    int m_size;
    std::vector<Account> m_accounts;
};

#endif