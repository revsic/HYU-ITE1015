#include "simple_account.h"

#include <sstream>

Account::Account(std::string&& id) : m_id(std::move(id)), m_balance(0)
{
    // Do Nothing
}

Account::Account(const std::string& id) : m_id(id), m_balance(0)
{
    // Do Nothing
}

std::string Account::Log() const {
    std::stringstream stream;
    stream << "Balance of user " << m_id << ": " << m_balance;
    return stream.str();
}

int Account::Deposit(int money) {
    if (m_balance + money > 1000000) {
        return 1;
    }

    m_balance += money;
    return 0;
}

int Account::Withdraw(int money) {
    if (m_balance - money < 0) {
        return 1;
    }

    m_balance -= money;
    return 0;
}

Manager::Manager() : m_size(0)
{
    // Do Nothing
}

int Manager::GetSize() const {
    return m_size;
}

const Account& Manager::operator[](size_t size) const {
    return m_accounts[size];
}

int Manager::NewAccount() {
    if (m_size >= 10) {
        return 1;
    }

    m_accounts.emplace_back(std::to_string(m_size));
    m_size += 1;
    return 0;
}

int Manager::Deposit(int id, int money) {
    if (id >= m_size) {
        return 1;
    }

    Account& account = m_accounts[id];
    return account.Deposit(money);
}

int Manager::Withdraw(int id, int money) {
    if (id >= m_size) {
        return 1;
    }

    Account& account = m_accounts[id];
    return account.Withdraw(money);
}

int Manager::Transfer(int src, int dst, int money) {
    if (src >= m_size || dst >= m_size) {
        return 1;
    }

    Account& src_account = m_accounts[src];
    Account& dst_account = m_accounts[dst];

    if (src_account.Withdraw(money)) {
        return 1;
    }

    if (dst_account.Deposit(money)) {
        src_account.Deposit(money);
        return 1;
    }

    return 0;
}