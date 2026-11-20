#include "idf/launcher_platform.h"
#include "powerSave.h"
#include <interface.h>

#define BTN_ACT LOW
#define UP_BTN  32
#define DW_BTN  33
#define SEL_BTN 12
#define ESC_BTN 21

void _setup_gpio() {
    launcherGpioInputPullup(UP_BTN);
    launcherGpioInputPullup(DW_BTN);
    launcherGpioInputPullup(SEL_BTN);
    launcherGpioInputPullup(ESC_BTN);
}

void _post_setup_gpio() {}

void _setBrightness(uint8_t brightval) {}

void InputHandler(void) {
    if (launcherGpioRead(UP_BTN) == BTN_ACT) {
        PrevPress = true;
        AnyKeyPress = true;
        delay(120);
    }
    if (launcherGpioRead(DW_BTN) == BTN_ACT) {
        NextPress = true;
        AnyKeyPress = true;
        delay(120);
    }
    if (launcherGpioRead(SEL_BTN) == BTN_ACT) {
        SelPress = true;
        AnyKeyPress = true;
        delay(150);
    }
    if (launcherGpioRead(ESC_BTN) == BTN_ACT) {
        EscPress = true;
        AnyKeyPress = true;
        delay(150);
    }
}
