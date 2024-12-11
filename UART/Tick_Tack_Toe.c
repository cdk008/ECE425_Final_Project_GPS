/*
 * @file Tick_Tack_Toe.c
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
 
 #include "UART0.h"
 #include "string.h"
 #include "SysTick_Delay.h"

// indexies is used to fill the board and keep track of the moves played.
char indexies[10] = "012345678";

// selected_cell is used to display the cell that the player has selected.
char selected_cell = '0';

// line is used in the print board function to print the rows with information.
char line[12] = " X | Y | Z ";

// current player is used to display the player whos turn it is and the seventh index is used for 
// reference or to fill a space when the player selects to do so.
char current_player[10] = "Player O";

// win_message is displayed when a win in detected by the current player. The seventh index is
// replaced by the symbol of the winning player.
char win_message[45] = "Player O Wins!\n\n Starting new game...\n\n";

// draw_message is displayed when all of the spaces have been filled and no player has one.
char draw_message[45] = "It's a draw!\n\n Starting new game...\n\n";


 
void Change_Line (char x1, char x2, char x3)
{
	// Indexies for line are overwritten with the symbols to be printed in
	// the next line in the Print_Board function
	line[1] = x1;
	line[5] = x2;
	line[9] = x3;
	
}
 
void Print_Board(void)
{
	UART0_Output_String("   |   |   ");
	UART0_Output_Newline();
	Change_Line(indexies[0], indexies[1], indexies[2]);
	UART0_Output_String(line);
	UART0_Output_Newline();
	UART0_Output_String("___|___|___");
	UART0_Output_Newline();
	UART0_Output_String("   |   |   ");
	UART0_Output_Newline();
	Change_Line(indexies[3], indexies[4], indexies[5]);
	UART0_Output_String(line);
	UART0_Output_Newline();
	UART0_Output_String("___|___|___");
	UART0_Output_Newline();
	UART0_Output_String("   |   |   ");
	UART0_Output_Newline();
	Change_Line(indexies[6], indexies[7], indexies[8]);
	UART0_Output_String(line);
	UART0_Output_Newline();
	UART0_Output_String("   |   |   ");
	UART0_Output_Newline();
	UART0_Output_Newline();
	
}

void Change_Player(void)
{
	// Alternates the player.
	if (current_player[7] == 'O')
	{
		current_player[7] = 'X';
	}
	else
	{
		current_player[7] = 'O';
	}
}

void Print_Player_Instructions(void)
{
	UART0_Output_String(current_player);
	UART0_Output_Newline();
	
	UART0_Output_String("Current selected cell: ");
	UART0_Output_Character(selected_cell);
	UART0_Output_Newline();
	UART0_Output_Newline();
	
	UART0_Output_String("Press \"1\" to traverse the cells and select the desired cell.");
	UART0_Output_Newline();
	
	UART0_Output_String("Press \"2\" confirm the choice of the selected cell.");
	UART0_Output_Newline();
	
	UART0_Output_String("Press \"3\" to reset the game.");
	UART0_Output_Newline();
	UART0_Output_Newline();
	UART0_Output_Newline();
}

int Check_Space(char pos)
{
	// Compares the current position to the default value
	if (pos == indexies[pos - '0'])
	{
		// Replaces the default value of the array with the current player's symbol.
		// Return of 1 verifies move was made.
		indexies[pos - '0'] = current_player[7];
		return 1;
	}
	else
	{
		// Displays message for filled space. Returns 0 meaning move was not made.
		UART0_Output_String("Invalid Move! Please choose a space that has not been taken.");
		return 0;
	}
}

void Reset_Board(void)
{	
	// String indexies is reset to its default value.
	strcpy(indexies, "012345678");
	
	// The current player and selected cell are reset to default values of O and 0 respectively/
	current_player[7] = 'O';
	selected_cell = '0';
}

void Check_Win(void)
{
	// Variable win tracks if a win has been found. No win or 0 is default. A 1 means a win was detected.
	int win = 0;
	
	// Check for win including index 0 going down diagonal and across.
	if (current_player[7] == indexies[0])
	{
		// Check for a win down the left side.
		if (current_player[7] == indexies[3] && current_player[7] == indexies[6])
		{
			win = 1;
		}
		// Check for a win on diagonal from top left to bottom right.
		else if (current_player[7] == indexies[4] && current_player[7] == indexies[8])
		{
			win = 1;
		}
		// Check for a win on top row.
		else if (current_player[7] == indexies[1] && current_player[7] == indexies[2])
		{
			win = 1;
		}
	}
	
	// Check for win including index 1 going down center.
	if (current_player[7] == indexies[1] && current_player[7] == indexies[4] && current_player[7] == indexies[7])
	{
		win = 1;
	}
	
	// Check for win including index 2 going down and diagonal.
	if (current_player[7] == indexies[2])
	{
		// Check for a win going down right side.
		if (current_player[7] == indexies[5] && current_player[7] == indexies[8])
		{
			win = 1;
		}
		// Check for a win going diagonally from top right to bottom left.
		else if (current_player[7] == indexies[4] && current_player[7] == indexies[6])
		{
			win = 1;
		}
	}
	
	// Check for win including index 3 going across the center.
	if (current_player[7] == indexies[3] && current_player[7] == indexies[4] && current_player[7] == indexies[5])
	{
		win = 1;
	}
	
	// Check for win including index 6 going across the bottom.
	if (current_player[7] == indexies[6] && current_player[7] == indexies[7] && current_player[7] == indexies[8])
	{
		win = 1;
	}
	
	if (win)
	{
		// If a win was detected, set the win message with the current player's symbol and display the message.
		// Then reset the board for a new game.
		win_message[7] = current_player[7];
		UART0_Output_String(win_message);
		UART0_Output_Newline();
		UART0_Output_Newline();
		SysTick_Delay1ms(2000);
		Reset_Board();
		Change_Player();
	}
}

void Check_Draw (void)
{
	// The variable draw checks if a draw has been detected. A 1 verifies a draw while a 0 is no draw.
	int draw = 1;
	
	for (unsigned int i = 0; i < strlen(indexies); i++)
	{
		// Iterates throught the indexies array looking for an index that has its default value. If true for 
		// any index, draw is set to 0 and no draw is detected.
		if (i == indexies[i] - '0')
		{
			draw = 0;
		}
	}
	
	if (draw)
	{
		// If a draw was detected, the draw_message is displayed and the board is reset.
		UART0_Output_String(draw_message);
		UART0_Output_Newline();
		UART0_Output_Newline();
		SysTick_Delay1ms(2000);
		Reset_Board();
		Change_Player();
	}
}

void Player_Navigation(void)
{
	//
	int i = 0;
	char pos[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
	int nav = 1;
	
	while (nav == 1)
	{
		// Input from user used in switch statement to determine move.
		char choice = UART0_Input_Character();
		
		switch (choice)
		{
			case '1': // Iterates position on board by 1 or from 8 to 0.
			{
				if (i < 8)
				{
					i++;
				}
				else
				{
					i = 0;
				}
				selected_cell = pos[i];
				Print_Board();
				Print_Player_Instructions();
				break;
			}
		
			case '2': // Checks if chosen space was full. Checks win, draw and changes player is move is successful.
			{
				// Check space function
				int check = Check_Space(selected_cell);
				if (check == 0)
				{
					break;
				}
				
				// Switch Player
				else
				{
					Check_Win();
					Check_Draw();
					Change_Player();
					nav = 0;
					selected_cell = '0';
					Print_Board();
					Print_Player_Instructions();
					break;
				}
			}
			case '3': // Resets Board.
			{
				Reset_Board();
				nav = 0;
				UART0_Output_Newline();
				UART0_Output_Newline();
				UART0_Output_String("Resetting Game...");
				UART0_Output_Newline();
				UART0_Output_Newline();
				SysTick_Delay1ms(2000);
				Print_Board();
				Print_Player_Instructions();
				break;
			}
			default: // Tells player to use numbers on keyboard if invalid input is detected.
			{
				UART0_Output_Newline();
				UART0_Output_String("Invalid Control: Please enter a 1, 2, or 3 from the keyboard.");
				UART0_Output_Newline();
				UART0_Output_Newline();
				SysTick_Delay1ms(2000);
				Print_Board();
				Print_Player_Instructions();
			}
		}
	}
}