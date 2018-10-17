#ifndef REPLY_ADMIN_H
#define REPLY_ADMIN_H

#define NUM_OF_CHAT 200

#include <string>

class ReplyAdmin {
public:
    ReplyAdmin();
    ~ReplyAdmin();

    void log() const;
    int getChatCount() const;

    bool addChat(const std::string& chat);
    bool removeChat(int index);
    bool removeChat(int start, int end);

private:
    size_t m_size;
    std::string* m_chats;
};

#endif
