#include <pico/stdlib.h>
#include <stdio.h>



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
}