#include <iostream>
#include <fstream>
#include <sstream>

constexpr size_t MAX_SIZE = 10;

class Slice {
public:
    Slice(std::string* ptr, size_t size) : m_ptr(ptr), m_size(size) {
        // Do Nothing
    }

    ~Slice() {
        delete[] m_ptr;
    }

    std::string& operator[](size_t idx) {
        return m_ptr[idx];
    }

    size_t size() const {
        return m_size;
    }

private:
    std::string* m_ptr;
    size_t m_size;
};

Slice split(const std::string& inp, const std::string& delim) {
    std::string* storage = new std::string[MAX_SIZE];

    size_t idx = 0;
    size_t start = 0;

    while (true) {
        size_t found = inp.find(delim, start);
        if (found == std::string::npos) {
            storage[idx] = inp.substr(start);
            break;
        }

        storage[idx] = inp.substr(start, found - start);
        
        idx += 1;
        start = found + 1;
    }

    return Slice(storage, idx + 1);
}

class Item {
public:
    Item() : m_age(0), m_numSubjects(0), m_next(nullptr) {
        // Do Nothing
    }

    Item(const std::string& inp) : m_next(nullptr) {
        Slice result = split(inp, ":");
        Slice subjects = split(result[3], ",");
        
        m_name = result[0];
        m_id = result[2];
        m_age = std::atoi(result[1].c_str());
        m_numSubjects = subjects.size();

        for (size_t i = 0; i < m_numSubjects; ++i) {
            m_subjects[i] = subjects[i];
        }
    }

    ~Item() {
        if (m_next != nullptr) {
            delete m_next;
        }
    }

    void InsertItem(Item* item) {
        Item* next = m_next;
        m_next = item;
        item->m_next = next;
    }

    void PrintSubjects() {
        bool flag = false;
        for (size_t i = 0; i < m_numSubjects; ++i) {
            if (flag) {
                std::cout << " & ";
            }
            flag = true;

            std::cout << m_subjects[i];
        }
    }

    const std::string& GetName() const {
        return m_name;
    }

    const std::string& GetID() const {
        return m_id;
    }

    Item* GetNextNode() const {
        return m_next;
    }

private:
    std::string m_name;
    std::string m_id;
    int m_age;

    size_t m_numSubjects;
    std::string m_subjects[10];

    Item* m_next;
};

int main() {
    Item head_;
    Item* last = &head_;

    std::fstream stream("./input.txt");

    std::string temp;
    while (!stream.eof()) {
        stream >> temp;
        Item* item = new Item(temp);

        last->InsertItem(item);
        last = item;
    }

    Item* head = head_.GetNextNode();
    while (head != nullptr) {
        const std::string& id = head->GetID();
        if (id.substr(0, 4) == "2013") {
            std::cout << head->GetName() << '(' << id << ") : ";
            head->PrintSubjects();
            std::cout << std::endl;
        }

        head = head->GetNextNode();
    }

    return 0;
}
