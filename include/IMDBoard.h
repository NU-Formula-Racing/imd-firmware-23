#include <array>
/**
 * @brief  Sound board class.
 */
class IMDBoard
{
public:
    // Constructor
    IMDBoard();

    const uint16_t kCANID{0x600};
    static constexpr int IMD_PIN = 32;

    enum class IMDState;

    IMDBoard::IMDState UpdateState();

private:
};