#include <Arduino.h>
#include <IMDBoard.h>


IMDBoard::IMDBoard()
{
    pinMode(IMD_PIN, INPUT);
};

void IMDBoard::UpdateState()
{
    if (digitalRead(IMD_PIN) == LOW)
    {
        state = IMDState::kFault;
    }
}