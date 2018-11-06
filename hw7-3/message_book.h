#ifndef MESSAGE_BOOK_H
#define MESSAGE_BOOK_H

#include <map>
#include <vector>

class MessageBook {
public:
    MessageBook();
    ~MessageBook();

    void AddMessage(int number, const std::string& message);
    void DeleteMessage(int number);

    std::vector<int> GetNumbers() const;
    const std::string& GetMessage(int number) const;

private:
    std::map<int, std::string> m_message;

    static const std::string empty_string;
};

#endif
