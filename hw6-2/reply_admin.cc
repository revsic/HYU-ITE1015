#include "reply_admin.h"

#include <iostream>

ReplyAdmin::ReplyAdmin() : 
    m_size(0), m_chats(new std::string[NUM_OF_CHAT]) 
{
    // Do Nothing
}

ReplyAdmin::~ReplyAdmin() {
    if (m_chats != nullptr) {
        delete[] m_chats;
    }
}

void ReplyAdmin::log() const {
    for (size_t i = 0; i < m_size; ++i) {
        std::cout << i << ' ' << m_chats[i] << std::endl;
    }
}

int ReplyAdmin::getChatCount() const {
    return m_size;
}

bool ReplyAdmin::addChat(const std::string& chat) {
    if (m_size >= NUM_OF_CHAT) {
        return false;
    }

    m_chats[m_size] = chat;
    m_size += 1;
    return true;
}

bool ReplyAdmin::removeChat(int index) {
    if (index >= m_size) {
        return false;
    }

    for (int i = index; i < m_size - 1; ++i) {
        m_chats[i] = std::move(m_chats[i + 1]);
    }
    m_size -= 1;
    return true;
}

bool ReplyAdmin::removeChat(int start, int end) {
    if (start < 0 || end >= m_size) {
        return false;
    }

    int dist = end - start + 1;
    for (int i = start; i < m_size - dist; ++i) {
        m_chats[i] = std::move(m_chats[i + dist]);
    }

    m_size -= dist;
    return true;
}
