#ifndef DISPLAY_H
#define DISPLAY_H

// start the main display output
void startDisplay();

// update the display buffer 
void update_displayBuffer(double angle ,double velocity);

// print one character from the display buffer 
void update_display();

#endif
// EOF