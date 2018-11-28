#include "world_clock.h"

WorldClock::WorldClock() : m_second(0), m_valid_input(true) {
    // Do Nothing
}

void WorldClock::Tick(int seconds) {
    const int SEC_PER_DAY = 86400;

    m_second += seconds;
    if (m_second > SEC_PER_DAY) {
        m_second -= SEC_PER_DAY;
    }
    else if (m_second < 0) {
        m_second += SEC_PER_DAY;
    }
}

bool WorldClock::SetTime(int hour, int minute, int second) {
    const int HOUR = 60 * 60;
    const int MINUTE = 60;
    auto valid = [](int n, int limit) { return n >= 0 && n < limit; };

    if (valid(hour, 24) && valid(minute, 60) && valid(second, 60)) {
        m_second = hour * HOUR + minute * MINUTE + second;

        SetValidInput();
        return true;
    }
    SetInvalidInput();
    std::cout << "Invalid time: " << hour << ':' << minute << ':' << second << std::endl;

    return false;
}

int WorldClock::hour() const {
    const int HOUR = 60 * 60;
    return m_second / HOUR;
}

int WorldClock::minute() const {
    const int HOUR = 60 * 60;
    return (m_second - hour() * HOUR) / 60;
}

int WorldClock::second() const {
    const int HOUR = 60 * 60;
    const int MINUTE = 60;
    return m_second - hour() * HOUR - minute() * MINUTE;
}

void WorldClock::SetValidInput() {
    m_valid_input = true;
}

void WorldClock::SetInvalidInput() {
    m_valid_input = false;
}

bool WorldClock::GetInputValidation() const {
    return m_valid_input;
}

std::ostream& operator<<(std::ostream& os, WorldClock const& clock) {
    os << clock.hour() << ':' << clock.minute() << ':' << clock.second();
    return os;
}

std::istream& operator>>(std::istream& is, WorldClock& clock) {
    char sep;
    int hour, minute, second;
    is >> hour >> sep >> minute >> sep >> second;

    clock.SetTime(hour, minute, second);
    return is;
}
