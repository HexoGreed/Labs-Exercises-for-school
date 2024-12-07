/*
 * CSC155_Final_Lab_Starter.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: Ivan
 */
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <cmath>
using namespace std;
const int ROWS = 4;
const int COLS = 4;
const int NUMBERS = 100;






int main() {
    /*
    int board[ROWS][COLS] = {{4, 6, 7, 23},
                             {7, 6, 3, 2},
                             {45, 6, 12, 4},
                             {12, 3, 2, 7}};
    */
    //OR


    /**/
    int board[ROWS][COLS];


    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % NUMBERS + 1;
            printf("%3d ", board[i][j]);
        }
        cout << endl;
    }



    cout << "CORNERS" << endl;   //The corners are compound conditional/if statements for the min/max.
    //Top-left Max


    if (board[0][0] > board[0][1] and board[0][0] > board[1][1] and board[0][0] > board[1][0]) {
        cout << "Peak max: " << board[0][0] << "," << " found at: " << "(0, 0)" << endl;
    }




    //Top-right Max
    if (board[0][COLS - 1] > board[0][COLS - 2] &&
        board[0][COLS - 1] > board[1][COLS - 2] &&
        board[0][COLS - 1] > board[1][COLS - 1]) {
        cout << "Top-Right Peak max: " << board[0][COLS - 1] << "," << " found at: " << "(0, " << COLS - 1 << ")" << endl;
    }
    //this entire thing ^^ essentially dumbed down is
    //it gets the top right corner [0,cols-1] and compares it to its neighbors, [0,cols-2], [1,cols-2], [1,cols-1]




    //Bottom-left Max
    if (board[ROWS - 1][0] > board[ROWS - 2][0] &&
        board[ROWS - 1][0] > board[ROWS - 2][1] &&
        board[ROWS - 1][0] > board[ROWS - 1][1]) {
        cout << "Bottom-left Peak max: " << board[ROWS - 1][0] << "," << " found at: " << "(" << ROWS - 1 << ", 0)" << endl;
    }
    //same premise as above


    //Rottom-right Max
    if (board[ROWS - 1][COLS - 1] > board[ROWS - 1][COLS - 2] &&
        board[ROWS - 1][COLS - 1] > board[ROWS - 2][COLS - 2] &&
        board[ROWS - 1][COLS - 1] > board[ROWS - 2][COLS - 1]) {
        cout << "Botom-Right Peak max: " << board[ROWS - 1][COLS - 1] << "," << " found at: " << "(" << ROWS - 1 << ", " << COLS - 1 << ")" << endl;
    }
    //same thing as above



    //-----



    //Top-left Min
    if (board[0][0] < board[0][1] &&
        board[0][0] < board[1][0] &&
        board[0][0] < board[1][1]) {
        cout << "Top-Left Peak min: " << board[0][0] << "," << " found at: " << "(0, 0)" << endl;
    }
    //does the opposite of what the max does. Checks if the corner is less than its neighbor
    //Its just a giant condtion check




    //Top-right Min

    if (board[0][COLS - 1] < board[0][COLS - 2] &&
        board[0][COLS - 1] < board[1][COLS - 1] &&
        board[0][COLS - 1] < board[1][COLS - 2]) {
        cout << "Top-right Peak min: " << board[0][COLS - 1] << "," << " found at: " << "(0, " << COLS - 1 << ")" << endl;
    }


    //Bottom-left Min
    if (board[ROWS - 1][0] < board[ROWS - 2][0] &&
        board[ROWS - 1][0] < board[ROWS - 2][1] &&
        board[ROWS - 1][0] < board[ROWS - 1][1]) {
        cout << "Bottom-left Peak min: " << board[ROWS - 1][0] << "," << " found at: " << "(" << ROWS - 1 << ", 0)" << endl;
    }

    //Rottom-right Min

    if (board[ROWS - 1][COLS - 1] < board[ROWS - 1][COLS - 2] &&
        board[ROWS - 1][COLS - 1] < board[ROWS - 2][COLS - 2] &&
        board[ROWS - 1][COLS - 1] < board[ROWS - 2][COLS - 1]) {
        cout << "Rottom-right Peak min: " << board[ROWS - 1][COLS - 1] << "," << " found at: " << "(" << ROWS - 1 << ", " << COLS - 1 << ")" << endl;
    }






    //---------



    cout << "\nNON-CORNER EDGE" << endl;  //The non-corner edges are for loops using compound conditional statements for the min/max.
    //Left edge: max, min: j = 0
    for (int i = 1; i < ROWS - 1; i++) {
        if (board[i][0] > board[i - 1][0] and board[i][0] > board[i - 1][1] and board[i][0] > board[i][1]
            and board[i][0] > board[i + 1][0] and board[i][0] > board[i + 1][1]) {
            cout << "Left NON-CORNER Peak max: " << board[i][0] << "," << " found at: " << "(" << i << ", 0)" << endl;
        }
    }


    //left edge min
    for (int i = 1; i < ROWS - 1; i++) {
        if (board[i][0] < board[i - 1][0] && board[i][0] < board[i - 1][1] &&
            board[i][0] < board[i][1] && board[i][0] < board[i + 1][0] &&
            board[i][0] < board[i + 1][1]) {
            cout << "Left NON-CORNER Edge min: " << board[i][0] << " found at: (" << i << ", 0)" << endl;
        }
    }







    //Right edge
    for (int i = 1; i < ROWS - 1; i++) {
        if (board[i][COLS - 1] > board[i - 1][COLS - 1] && board[i][COLS - 1] > board[i - 1][COLS - 2] &&
            board[i][COLS - 1] > board[i][COLS - 2] && board[i][COLS - 1] > board[i + 1][COLS - 1] &&
            board[i][COLS - 1] > board[i + 1][COLS - 2]) {
            cout << "Right NON-CORNER Edge max: " << board[i][COLS - 1] << " found at: (" << i << ", " << COLS - 1 << ")" << endl;
        }
    }
    //just copied what you did, after getting confused for a lil,  i got used to it. 



    //right edge min:
    for (int i = 1; i < ROWS - 1; i++) {
        if (board[i][COLS - 1] < board[i - 1][COLS - 1] && board[i][COLS - 1] < board[i - 1][COLS - 2] &&
            board[i][COLS - 1] < board[i][COLS - 2] && board[i][COLS - 1] < board[i + 1][COLS - 1] &&
            board[i][COLS - 1] < board[i + 1][COLS - 2]) {
            cout << "Right NON-CORNER Edge min: " << board[i][COLS - 1] << " found at: (" << i << ", " << COLS - 1 << ")" << endl;
        }
    }








    //Top edge
    for (int j = 1; j < COLS - 1; j++) {
        if (board[0][j] > board[0][j - 1] && board[0][j] > board[0][j + 1] &&
            board[0][j] > board[1][j - 1] && board[0][j] > board[1][j] &&
            board[0][j] > board[1][j + 1]) {
            cout << "Top NON-CORNER Edge max: " << board[0][j] << " found at: (0, " << j << ")" << endl;
        }
    }


    //top edge min

    for (int j = 1; j < COLS - 1; j++) {
        if (board[0][j] < board[0][j - 1] && board[0][j] < board[0][j + 1] &&
            board[0][j] < board[1][j - 1] && board[0][j] < board[1][j] &&
            board[0][j] < board[1][j + 1]) {
            cout << "Top NON-CORNER Edge min: " << board[0][j] << " found at: (0, " << j << ")" << endl;
        }
    }








    
    //Bottom edge
    for (int j = 1; j < COLS - 1; j++) {
        if (board[ROWS - 1][j] > board[ROWS - 1][j - 1] && board[ROWS - 1][j] > board[ROWS - 1][j + 1] &&
            board[ROWS - 1][j] > board[ROWS - 2][j - 1] && board[ROWS - 1][j] > board[ROWS - 2][j] &&
            board[ROWS - 1][j] > board[ROWS - 2][j + 1]) {
            cout << "Bottom NON-CORNER Edge max: " << board[ROWS - 1][j] << " found at: (" << ROWS - 1 << ", " << j << ")" << endl;
        }
    }


    //Bottom Edge Min:

    for (int j = 1; j < COLS - 1; j++) {
        if (board[ROWS - 1][j] < board[ROWS - 1][j - 1] && board[ROWS - 1][j] < board[ROWS - 1][j + 1] &&
            board[ROWS - 1][j] < board[ROWS - 2][j - 1] && board[ROWS - 1][j] < board[ROWS - 2][j] &&
            board[ROWS - 1][j] < board[ROWS - 2][j + 1]) {
            cout << "Bottom NON-CORNER Edge min: " << board[ROWS - 1][j] << " found at: (" << ROWS - 1 << ", " << j << ")" << endl;
        }
    }
    






    //-------------------------------------------


    cout << "INSIDE (NON-EDGE/NON-CORNER)" << endl;   //The inside is a double-for loop using compound conditional statements for the min/max.
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            if (board[i][j] > board[i - 1][j - 1] and board[i][j] > board[i - 1][j] and board[i][j] > board[i - 1][j + 1]
                and board[i][j] > board[i][j - 1] and board[i][j] > board[i][j + 1] and board[i][j] > board[i + 1][j - 1]
                and board[i][j] > board[i + 1][j] and board[i][j] > board[i + 1][j + 1]) {
                cout << "Peak max: " << board[i][0] << "," << " found at: " << "(" << i << ", " << j << ")" << endl;
            }

        }
    }
    return 0;
}

