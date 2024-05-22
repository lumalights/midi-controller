#include <hardware/gpio.h>
#include <pico/time.h>
#include <stdio.h>


int main () {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    };
    return 0;
};

class MFader {
    private:
    int index;

    public:
    int value;
    
    void moveUp() {
        // pin x high, pin y low
    };

    void moveDown() {
        // pin x low, pin y high
    };

    void moveStop() {
        // pin x low, pin y low
    };
};



int UpdateFaderPosition(MFader fader, int value) {
    int faderPos;   // read fader position from mcp3008
    bool touched;   // read fader touch from mtch105 through mcp23s17

    while (faderPos < value and not touched) {
        fader.moveUp();
    };
    fader.moveStop();
    while (faderPos > value and not touched) {
        fader.moveDown();
    };
    fader.moveStop();
    
    return faderPos;
}