/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"
#include "error.h"

#include "token.h"
#include "scanner.h"
#include "display.h"
#include "errorHandling.h"
#include "stack.h"
#include "computing.h"


int main(void) {
	initITSboard();    // Initialisierung des ITS Boards
	
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch

	initDisplay();

	char stackResetMsg[] = "Stack resetted!\n";

	while(1) {
		T_token token = nextToken();
		clearStdout();

		switch(token.tok) {
			case NUMBER:
				handleError(stack_push(token.val));
				break;
			case PLUS:
				handleError(addition());
				break;
			case MINUS:
				handleError(substraction());
				break;
			case MULT:
				handleError(multiply()); 
				break;
			case DIV:
				handleError(divide());
				break;
			case PRT:
				handleError(computing_print());
				break;
			case SWAP:
				handleError(swap());
				break;
			case PRT_ALL:
				handleError(computing_printAll());
				break;
			case CLEAR:
				handleError(stack_reset());
				printStdout(stackResetMsg);
				break;
			case DOUBLE:
				handleError(duplicate());
				break;
			case UNEXPECTED:
				handleError(UNEXPECTED_INPUT);
				break;
			case OVERFLOW:
				handleError(INTEGER_OVERFLOW);
				break;
			default:
			 	handleError(UNEXPECTED_INPUT);
				break;
		}

		HAL_Delay(100);
	}
}

// EOF
