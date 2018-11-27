#include "clock_time.h"
#include <iostream>
#include <vector>

using ull = unsigned long long;

class Clock {
public:
    Clock(int hour, int minute, int second, double driftPerSecond) :
        m_clockTime(hour, minute, second, 1), m_driftPerSecond(driftPerSecond), m_totalDrift(0)
    {
        // Do Nothing
    }
    
    virtual ~Clock() = default;
    virtual void displayTime() const = 0;

    void reset() {
        m_clockTime.reset();
    }

    void tick() {
        m_clockTime.increment();
        m_totalDrift += m_driftPerSecond;
    }

protected:
    ClockTime m_clockTime;
    double m_driftPerSecond;
    double m_totalDrift;
};

class NaturalClock : public Clock {
public:
    NaturalClock(int hour, int minute, int second, double driftPerSecond) :
        Clock(hour, minute, second, driftPerSecond)
    {
        // Do Nothing
    }
};

class SundialClock : public NaturalClock {
public:
    SundialClock(int hour, int minute, int second) :
        NaturalClock(hour, minute, second, 0.0)
    {
        // Do Nothing
    }

    void displayTime() const override {
        std::cout << "SundialClock "
                  << m_clockTime.hour() << ':'
                  << m_clockTime.minute() << ':'
                  << m_clockTime.second()
                  << ", total drift: " << m_totalDrift
                  << std::endl;
    }
};

class MechanicalClock : public Clock {
public:
    MechanicalClock(int hour, int minute, int second, double driftPerSecond) :
        Clock(hour, minute, second, driftPerSecond)
    {
        // Do Nothing
    }
};

class CuckooClock : public MechanicalClock {
public:
    CuckooClock(int hour, int minute, int second) :
        MechanicalClock(hour, minute, second, 0.0)
    {
        // Do Nothing
    }

    void displayTime() const override {
        std::cout << "CuckooClock "
                  << m_clockTime.hour() << ':'
                  << m_clockTime.minute() << ':'
                  << m_clockTime.second()
                  << ", total drift: " << m_totalDrift
                  << std::endl;
    }
};

class GrandFatherClock : public MechanicalClock {
public:
    GrandFatherClock(int hour, int minute, int second) :
        MechanicalClock(hour, minute, second, 0.000694444)
    {
        // Do Nothing
    }

    void displayTime() const override {
        std::cout << "GrandFatherClock "
                  << m_clockTime.hour() << ':'
                  << m_clockTime.minute() << ':'
                  << m_clockTime.second()
                  << ", total drift: " << m_totalDrift
                  << std::endl;
    }
};

class DigitalClock : public Clock {
public:
    DigitalClock(int hour, int minute, int second, double driftPerSecond) :
        Clock(hour, minute, second, driftPerSecond)
    {
        // Do Nothing
    }
};

class WristClock : public DigitalClock {
public:
    WristClock(int hour, int minute, int second) :
        DigitalClock(hour, minute, second, 0.000347222)
    {
        // Do Nothing
    }

    void displayTime() const override {
        std::cout << "WristClock "
                  << m_clockTime.hour() << ':'
                  << m_clockTime.minute() << ':'
                  << m_clockTime.second()
                  << ", total drift: " << m_totalDrift
                  << std::endl;
    }
};

class QuantumClock : public Clock {
public:
    QuantumClock(int hour, int minute, int second, double driftPerSecond) :
        Clock(hour, minute, second, driftPerSecond)
    {
        // Do Nothing
    }
};

class AtomicClock : public QuantumClock {
public:
    AtomicClock(int hour, int minute, int second) :
        QuantumClock(hour, minute, second, 0.000034722)
    {
        // Do Nothing
    }

    void displayTime() const override {
        std::cout << "AtomicClock "
                  << m_clockTime.hour() << ':'
                  << m_clockTime.minute() << ':'
                  << m_clockTime.second()
                  << ", total drift: " << m_totalDrift
                  << std::endl;
    }
};

int main() {
    std::vector<Clock*> vec = {
        new SundialClock(0, 0, 0),
        new CuckooClock(0, 0, 0),
        new GrandFatherClock(0, 0, 0),
        new WristClock(0, 0, 0),
        new AtomicClock(0, 0, 0)
    };

    ull seconds;
    std::cin >> seconds;

    std::cout << "Reported clock times after resetting:" << std::endl;
    for (auto elem : vec) {
        elem->reset();
        elem->displayTime();
    }

    std::cout << "\nRunning the clocks..." << std::endl;
    for (size_t i = 0; i < seconds; ++i) {
        for (auto elem : vec) {
            elem->tick();
        }
    }

    std::cout << "\nReported clock times after running:" << std::endl;
    for (auto elem : vec) {
        elem->displayTime();
        delete elem;
    }

    return 0;
}
