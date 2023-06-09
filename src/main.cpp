#include <Arduino.h>
#include "virtualTimer.h"
#include "IMDBoard.h"

#ifdef ARDUINO_ARCH_ESP32
#include "esp_can.h"
// The tx and rx pins are constructor arguments to ESPCan, which default to TX = 5, RX = 4
ESPCAN can_bus{};
#endif

// Initialize timer to call functions at
// specified frequencies.
VirtualTimerGroup timer_group;

// Initialize board.
IMDBoard imd_board;

CANSignal<IMDBoard::IMDState, 0, 8, CANTemplateConvertFloat(1), CANTemplateConvertFloat(0), false> imd_status_signal{};
CANTXMessage<1> imd_tx_message{can_bus, imd_board.kCANID, 1, 100, timer_group, imd_status_signal};

void UpdateIMDStatus()
{
  imd_status_signal = imd_board.UpdateState();
}

void setup()
{

#ifdef SERIAL_DEBUG
  // Initialize serial output
  Serial.begin(9600);
#endif

  // Initialize CAN bus.
  can_bus.Initialize(ICAN::BaudRate::kBaud1M);

  // Initialize our timer(s)
  timer_group.AddTimer(100, UpdateIMDStatus);
}

void loop()
{
  can_bus.Tick();
  timer_group.Tick(millis());
}