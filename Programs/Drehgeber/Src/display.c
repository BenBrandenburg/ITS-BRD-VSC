#include "fsm.h"
#include "computing.h"
#include "additionalFonts.h"
#include "lcd.h"
#include "fontsFLASH.h"

#define START_X  3
#define X   2
#define Y   5


static char angle_ [7];
static int angleLength_ ;
static int angleIndex_ = 0;
static bool angleNextChar_ = true;

static char velocity_ [7];
static int velocityLength_ ;
static int velocityIndex_ = 0;
static bool velocityNextChar_ = true;

static bool isPrinting_ = false;


/* 
lässt auf dem display standart Text erscheinen
*/
void startDisplay ()
{
    lcdGotoXY(X,Y);
    lcdPrintlnS("Drehwinkel in Grad:\n");
    lcdGotoXY( X,(Y *2) );
    lcdPrintlnS("Drehgeschwindigkeit:\n");
}

/*
@param angle angle ist der Winkelgrad der angezeigt werden soll
@param velocity velocity ist die Geschwindigkeit die angezeigt werden soll*/
void update_display(double angle , double velocity ){
    if (!isPrinting_)
    {
        convertAngle(angle);
        convertVelocity(velocity);
        isPrinting_ = true;
    }
    
    if (angleNextChar_){

        lcdGotoXY(START_X + angleIndex_, Y); 
        lcdPrintC(angle_[angleIndex_]);
        angleIndex_++;
        if(angleIndex_ == angleLength_){
            angleNextChar_ = false;
        }

    }

    if (velocityNextChar_){

        lcdGotoXY(START_X + velocityIndex_, (Y *2)); 
        lcdPrintC(velocity_[velocityIndex_]);
        velocityIndex_++;
        if(velocityIndex_ == velocityLength_){
            velocityNextChar_ = false;
        }

    }
    if ( !velocityNextChar_ && !angleNextChar_)
    {
        isPrinting_ = false;
    }
       

}
/*

param angle angle ist die zahl welche in ein char[] umgewandelt wird
*/
void convertAngleIntoCharArray (double angle){
    sprintf(angle_ "%.3f" angle);
    angleLength_ = strlen(angle_);
    angleIndex_ = 0;
    angleNextChar_ = true
    
}

/*
param angle angle ist die zahl welche in ein char[] umgewandelt wird
*/

void convertVelocity (double velocity ){
    sprintf(velocity_ "%.3f" velocity);
    velocityLength_ = strlen(velocity_);
    velocityIndex_ = 0;
    velocityNextChar_ = true;
}


