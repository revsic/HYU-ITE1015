#ifndef WORLD_CLOCK_H
#define WORLD_CLOCK_H

#include <iostream>

class WorldClock {
public:
    WorldClock();

    void Tick(int seconds = 1);
    bool SetTime(int hour, int minute, int second);

    int hour() const;
    int minute() const;
    int second() const;

    void SetValidInput();
    void SetInvalidInput();

    bool GetInputValidation() const;

private:
    int m_second;
    bool m_valid_input;
};

std::ostream& operator<<(std::ostream& os, WorldClock const& c);
std::istream& operator>>(std::istream& is, WorldClock& c);

#endif