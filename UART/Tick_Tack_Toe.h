/*
 * @file Tick_Tack_Toe.h
 *
 * @brief Main source code for the UART program.
 *
 * This file contains the main entry point and function definitions for the UART program.
 *
 * @note For more information regarding the UART module, refer to the
 * Universal Asynchronous Receivers / Transmitters (UARTs) section
 * of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @author Cody Krueger
 */
 
 /**
 * @brief The Change_Line function changes the information in a string that contains a row of information.
 *
 * @param x1, x2, x3 are the symbols that are passed into the board. Either a number indicating the space of an open 
 *	square or the symbol that a player previously placed. Used for printing the board.
 *
 * @return None
 */
void Change_Line(char x1, char x2, char x3);
 
 /**
 * @brief The Print_Board function transmits the current tick tack toe board to the terminal.
 *
 * @param None
 *
 * @return None
 */
void Print_Board(void);

 /**
 * @brief The Change_Player function changes the player turn. This is used to tell which player turn it
 * is in the Print_Player_Instructions function. The seventh index is also pulled when the player symbol
 * is needed for placement or reference.
 *
 * @param None
 *
 * @return None
 */
void Change_Player(void);

 /**
 * @brief The Print_Player_Instructions function prints the information of the player whos turn it
 * is and how to play.
 * 
 * @param None
 *
 * @return None
 */
void Print_Player_Instructions(void);

 /**
 * @brief The Check_Space checks to see if a space has been played and returns a message to 
 * try again if it has.
 *
 * @param char pos is the position currently selected
 *
 * @return int is a check that returns whether the space was used or not. 0 = used, 1 = unused.
 */
int Check_Space(char pos);

 /**
 * @brief The Reset_Board function resets the array indexies that is used to feed the board 
 * information and sets the current player to O in preparation for a new game.
 *
 * @param None.
 *
 * @return None.
 */
void Reset_Board(void);

 /**
 * @brief The Check_Win function checks to see if there is a winning condition on the board for the 
 * current player. It is called after either player makes a successful move. If a win is detected, 
 * a message is displayed declaring the winner and a new game is started.
 *
 * @param None.
 *
 * @return None.
 */
void Check_Win(void);

 /**
 * @brief The Check_Draw function checks to see if all positions on the board have been played
 * It is called after either player makes a successful move. If a draw is detected, 
 * a message is displayed declaring a draw and a new game is started.
 *
 * @param None.
 *
 * @return None.
 */
void Check_Draw(void);

/**
 * @brief The Player_Navigation function keeps track of the position of a player during their turn, 
 * and determines what to do when the input buttons are pressed. A 1 iterates through the board, a 
 * 2 attempts to select the selected cell, and a 3 resets the game. If an invalid control is entered,
 * a message is displayed directing the player to use the keyboard controls.
 *
 * @param None.
 *
 * @return None.
 */
void Player_Navigation(void);
