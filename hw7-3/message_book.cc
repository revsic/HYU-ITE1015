#include "message_book.h"

const std::string MessageBook::empty_string;

MessageBook::MessageBook() {
    // Do Nothing
}

MessageBook::~MessageBook() {
    // Do Nothing
}

void MessageBook::AddMessage(int number, const std::string& message) {
    m_message[number] = message;
}

void MessageBook::DeleteMessage(int number) {
    auto iter = m_message.find(number);
    if (iter != m_message.end()) {
        m_message.erase(iter);
    }
}

std::vector<int> MessageBook::GetNumbers() const {
    std::vector<int> keys;
    keys.reserve(m_message.size());

    for (auto const& map_pair : m_message) {
        keys.emplace_back(map_pair.first);
    }
    return keys;
}

const std::string& MessageBook::GetMessage(int number) const {
    auto iter = m_message.find(number);
    if (iter != m_message.end()) {
        return (*iter).second;
    }
    return empty_string;
}
