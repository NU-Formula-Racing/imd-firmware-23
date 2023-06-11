#include <Arduino.h>
#include <IMDBoard.h>

enum class IMDBoard::IMDState
{
    kActive = 0,
    kFault = 1
};

IMDBoard::IMDBoard()
{
    pinMode(IMD_PIN, INPUT);
};

IMDBoard::IMDState IMDBoard::UpdateState()
{
    if (digitalRead(IMD_PIN) == LOW)
    {
        return IMDState::kActive;
    }
    else
    {
        return IMDState::kFault;
    }
}