#include <iostream>
#include <iomanip>
#include "clock_time.h"

using namespace::std;

ClockTime::
ClockTime ()
: hour_(0),
  minute_(0),
  second_(0),
  secondsPerTick_(0),
  deltaTime_(0)
{
  recordStartTime();
}

ClockTime::
ClockTime (int hour, int minute, int second, int secondsPerTick)
: hour_(hour),
  minute_(minute),
  second_(second),
  secondsPerTick_(secondsPerTick),
  deltaTime_(0)
{
  recordStartTime();
}

void ClockTime::
reset ()
// The purpose of this method is to reset the time to the recorded
// start time.
{
  unsigned int temp = startTime_;

  hour_  = temp / (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
  temp  -= hour_ * (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

  minute_  = temp / SECONDS_PER_MINUTE;
  temp    -= minute_* SECONDS_PER_MINUTE;

  second_ = temp;
}

void ClockTime::
increment ()
// The purpose of this method is to increment the clock time by the number
// of seconds by which the time is to advance per tick.
{
  deltaTime_ += secondsPerTick_;

  // Compute the new time in terms of seconds.
  int seconds = hour_   * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
                minute_ * SECONDS_PER_MINUTE                    +
                second_                                         + 
                secondsPerTick_;

  // If the new time is greater than the number of seconds in a day, adjust
  // the new time to reflect the number of seconds past midnight.
  if (seconds > (HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE))
    seconds -= (HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

  hour_ = seconds  / (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
  seconds -= hour_ * (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

  minute_ = seconds / SECONDS_PER_MINUTE;
  seconds -= minute_ * SECONDS_PER_MINUTE;

  second_ = seconds;
}

void ClockTime::
display () const
// The purpose of this method is to display the values stored in
// an instance of simulation time.
{
  cout << right << setw(2) << setfill('0') << hour_   << ":"
       << right << setw(2) << setfill('0') << minute_ << ":" 
       << right << setw(2) << setfill('0') << second_;
}

void ClockTime::       // Private method
recordStartTime ()
// The purpose of this method is to compute and record the start time.
{
  startTime_ = hour_   * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
               minute_ * SECONDS_PER_MINUTE                    +
               second_;
}

Clock::Clock(int hour, int minute, int second, double driftPerSecond) :
    m_clockTime(hour, minute, second, 1), m_driftPerSecond(driftPerSecond), m_totalDrift(0)
{
    // Do Nothing
}

void Clock::reset() {
    m_clockTime.reset();
}

void Clock::tick() {
    m_clockTime.increment();
    m_totalDrift += m_driftPerSecond;
}

SundialClock::SundialClock(int hour, int minute, int second) :
    NaturalClock(hour, minute, second, 0.0)
{
    // Do Nothing
}

void SundialClock::displayTime() const {
    std::cout << "SundialClock "
              << m_clockTime.hour() << ':'
              << m_clockTime.minute() << ':'
              << m_clockTime.second()
              << ", total drift: " << m_totalDrift
              << std::endl;
}

CuckooClock::CuckooClock(int hour, int minute, int second) :
    MechanicalClock(hour, minute, second, 0.0)
{
    // Do Nothing
}

void CuckooClock::displayTime() const {
    std::cout << "CuckooClock "
              << m_clockTime.hour() << ':'
              << m_clockTime.minute() << ':'
              << m_clockTime.second()
              << ", total drift: " << m_totalDrift
              << std::endl;
}

GrandFatherClock::GrandFatherClock(int hour, int minute, int second) :
    MechanicalClock(hour, minute, second, 0.000694444)
{
    // Do Nothing
}

void GrandFatherClock::displayTime() const {
    std::cout << "GrandFatherClock "
              << m_clockTime.hour() << ':'
              << m_clockTime.minute() << ':'
              << m_clockTime.second()
              << ", total drift: " << m_totalDrift
              << std::endl;
}

WristClock::WristClock(int hour, int minute, int second) :
    DigitalClock(hour, minute, second, 0.000347222)
{
    // Do Nothing
}

void WristClock::displayTime() const {
    std::cout << "WristClock "
              << m_clockTime.hour() << ':'
              << m_clockTime.minute() << ':'
              << m_clockTime.second()
              << ", total drift: " << m_totalDrift
              << std::endl;
}

AtomicClock::AtomicClock(int hour, int minute, int second) :
    QuantumClock(hour, minute, second, 0.000034722)
{
    // Do Nothing
}

void AtomicClock::displayTime() const {
    std::cout << "AtomicClock "
              << m_clockTime.hour() << ':'
              << m_clockTime.minute() << ':'
              << m_clockTime.second()
              << ", total drift: " << m_totalDrift
              << std::endl;
}
