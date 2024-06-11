#include <iostream>
#include <ctime> //for generate random number
#include <chrono> //for pause between iteration
#include <thread> //for pause function
#include <iomanip> //for list of bets
#include <vector> // For storing bridges
#include <limits>

using namespace std;
using namespace std::chrono;

struct Bridge 
{
    int start;
    int end;
};

// Function to generate random steps within a range for each racer
int generateRandomSteps(int minSteps, int maxSteps) {
    return rand() % (maxSteps - minSteps + 1) + minSteps;
}

// Function to display track and update racer's position
void display_track1(int position1, int position2, int position3)
{
    const int width = 45;
    const int height = 17;

    char track[height][width];
    
    char xwing_char = 'x';
    char tiefighter_char = 'y';
    char soullessone_char = 'z';

    //Initialize all to spaces
    for (int i = 0; i < height; i++) // Loop through each row of the track
        for (int j = 0; j < width; j++) // Loop through each column in the current row
            track[i][j] = ' ';

    //Top track
    for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
    {
        for (int j = 4; j < width - 1; j = j + 4) // Loop through each 3 column in the current row
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 4; j < width; j = j + 4) // Loop through each 3 column in the current row
        track[1][j] = '|';

    //Left and right tracks - vertical lines top part
    for (int i = 3; i < height - 8; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][4] = '|';
        track[i][8] = '|';
        track[i][width - 5] = '|';
        track[i][width - 1] = '|';
        //track design
        track[5][width - 17] = '|';
        track[5][width - 13] = '|';
        track[5][width - 9] = '|';
        track[7][width - 17] = '|';
        track[7][width - 13] = '|';
        track[7][width - 5] = ' ';
        track[7][width - 1] = ' ';
        track[5][8] = '|';
        track[5][12] = '|';
        track[5][16] = '|';
        track[5][20] = '|';
        track[5][24] = '|';
        track[7][12] = '|';
        track[7][16] = '|';
        track[7][20] = '|';
        track[7][24] = '|';
    }
    //Left and right tracks - vertical lines bottom part
    for (int i = 9; i < height - 3; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][0] = '|';
        track[i][4] = '|';
        track[i][width - 5] = '|';
        track[i][width - 9] = '|';
        //track design
        track[9][0] = ' ';
        track[9][4] = ' ';
        track[9][20] = '|';
        track[9][24] = '|';
        track[9][28] = '|';
        track[9][32] = '|';
        track[11][8] = '|';
        track[11][12] = '|';
        track[11][16] = '|';
        track[11][20] = '|';
        track[11][24] = '|';
    }
    //Left track - horizontal lines top part
    for (int i = 4; i < height - 8; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][4] = '+';
        track[i][5] = '-';
        track[i][6] = '-';
        track[i][7] = '-';
        track[i][8] = '+';
        //track design
        track[i][9] = '-';
        track[i][10] = '-';
        track[i][11] = '-';
        track[i][12] = '+';
        track[i][13] = '-';
        track[i][14] = '-';
        track[i][15] = '-';
        track[i][16] = '+';
        track[i][17] = '-';
        track[i][18] = '-';
        track[i][19] = '-';
        track[i][20] = '+';
        track[i][21] = '-';
        track[i][22] = '-';
        track[i][23] = '-';
        track[i][24] = '+';
        track[i][25] = '-';
        track[i][26] = '-';
        track[i][27] = '-';
        track[i][28] = '+';
        track[i][29] = '-';
        track[i][30] = '-';
        track[i][31] = '-';
        track[i][32] = '+';
        track[i][33] = '-';
        track[i][34] = '-';
        track[i][35] = '-';
        track[i][36] = '+';
        track[i][37] = '-';
        track[i][38] = '-';
        track[i][39] = '-';
        track[4][9] = ' ';
        track[4][10] = ' ';
        track[4][11] = ' ';
        track[4][25] = ' ';
        track[4][26] = ' ';
        track[4][27] = ' ';
        track[6][25] = ' ';
        track[6][26] = ' ';
        track[6][27] = ' ';
        track[8][25] = ' ';
        track[8][26] = ' ';
        track[8][27] = ' ';
        track[8][17] = ' ';
        track[8][18] = ' ';
        track[8][19] = ' ';
    }
    //Left track - horizontal lines bottom part
    for (int i = 10; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '-';
        track[i][4] = '+';
        //track design
        track[i][5] = '-';
        track[i][6] = '-';
        track[i][7] = '-';
        track[i][8] = '+';
        track[i][9] = '-';
        track[i][10] = '-';
        track[i][11] = '-';
        track[i][12] = '+';
        track[i][13] = '-';
        track[i][14] = '-';
        track[i][15] = '-';
        track[i][16] = '+';
        track[i][17] = '-';
        track[i][18] = '-';
        track[i][19] = '-';
        track[i][20] = '+';
        track[i][21] = '-';
        track[i][22] = '-';
        track[i][23] = '-';
        track[i][24] = '+';
        track[10][28] = '+';
        track[10][29] = '-';
        track[10][30] = '-';
        track[10][31] = '-';
        track[10][32] = '+';
        track[10][33] = '-';
        track[10][34] = '-';
        track[10][35] = '-';
    }
    //Right track - horizontal lines top part
    for (int i = 4; i < height - 10; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][width - 5] = '+';
        track[i][width - 4] = '-';
        track[i][width - 3] = '-';
        track[i][width - 2] = '-';
        track[i][width - 1] = '+';
    }
    //Right track - horizontal lines bottom part
    for (int i = 8; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][width - 9] = '+';
        track[i][width - 8] = '-';
        track[i][width - 7] = '-';
        track[i][width - 6] = '-';
        track[i][width - 5] = '+';
    }

    //Bottom track
    for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 0; j < width - 5; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 5] = '+';
    }

    for (int j = 0; j < width - 4; j = j + 4) // Loop through each 3 column of the track
        track[height - 2][j] = '|';

    //Assign racer 1 symbol
    switch (position1)
    {
    //Go up
    case 0:
        track[height - 2][1] = xwing_char;
        break;
    case 1:
        track[height - 4][1] = xwing_char;
        break;
    case 2:
        track[height - 6][1] = xwing_char;
        break;
    //Go right
    case 3:
        track[height - 6][5] = xwing_char;
        break;
    case 4:
        track[height - 6][9] = xwing_char;
        break;
    case 5:
        track[height - 6][13] = xwing_char;
        break;
    case 6:
        track[height - 6][17] = xwing_char;
        break;
    case 7:
        track[height - 6][21] = xwing_char;
        break;
    //Go up
    case 8:
        track[height - 8][21] = xwing_char;
        break;
    case 9:
        track[height - 10][21] = xwing_char;
        break;
    case 10:
        track[height - 12][21] = xwing_char;
        break;
    //Go left
    case 11:
        track[height - 12][17] = xwing_char;
        break;
    case 12:
        track[height - 12][width - 32] = xwing_char;
        break;
    //Go down
    case 13:
        track[height - 10][width - 32] = xwing_char;
        break;
    //Go left
    case 14:
        track[height - 10][width - 36] = xwing_char;
        break;
    case 15:
        track[height - 10][width - 40] = xwing_char;
        break;
    //Go up
    case 16:
        track[height - 12][width - 40] = xwing_char;
        break;
    case 17:
        track[height - 14][width - 40] = xwing_char;
        break;
    case 18:
        track[1][width - 40] = xwing_char;
        break;
    //Go right
    case 19:
        track[1][width - 36] = xwing_char;
        break;
    case 20:
        track[1][width - 32] = xwing_char;
        break;
    case 21:
        track[1][width - 28] = xwing_char;
        break;
    case 22:
        track[1][width - 24] = xwing_char;
        break;
    case 23:
        track[1][width - 20] = xwing_char;
        break;
    case 24:
        track[1][width - 16] = xwing_char;
        break;
    case 25:
        track[1][width - 12] = xwing_char;
        break;
    case 26:
        track[1][width - 8] = xwing_char;
        break;
    case 27:
        track[1][width - 4] = xwing_char;
        break;
    //Go down
    case 28:
        track[height - 14][width - 4] = xwing_char;
        break;
    case 29:
        track[height - 12][width - 4] = xwing_char;
        break;
    //Go left
    case 30:
        track[height - 12][width - 8] = xwing_char;
        break;
    case 31:
        track[height - 12][width - 12] = xwing_char;
        break;
    case 32:
        track[height - 12][width - 16] = xwing_char;
        break;
    //Go down
    case 33:
        track[height - 10][width - 16] = xwing_char;
        break;
    case 34:
        track[height - 8][width - 16] = xwing_char;
        break;
    //Go right
    case 35:
        track[height - 8][width - 12] = xwing_char;
        break;
    case 36:
        track[height - 8][width - 8] = xwing_char;
        break;
    //Go down
    case 37:
        track[height - 6][width - 8] = xwing_char;
        break;
    case 38:
        track[height - 4][width - 8] = xwing_char;
        break;
    case 39:
        track[height - 2][width - 8] = xwing_char;
        break;
    //Go left
    case 40:
        track[height - 2][width - 12] = xwing_char;
        break;
    case 41:
        track[height - 2][width - 16] = xwing_char;
        break;
    case 42:
        track[height - 2][width - 20] = xwing_char;
        break;
    case 43:
        track[height - 2][width - 24] = xwing_char;
        break;
    case 44:
        track[height - 2][width - 28] = xwing_char;
        break;
    case 45:
        track[height - 2][width - 32] = xwing_char;
        break;
    case 46:
        track[height - 2][width - 36] = xwing_char;
        break;
    case 47:
        track[height - 2][width - 40] = xwing_char;
        break;
    case 48:
        track[height - 2][width - 44] = xwing_char;
        break;
    //From 49, prevent output display error
    case 49:
        track[height - 2][width - 44] = xwing_char;
        break;
    case 50:
        track[height - 2][width - 44] = xwing_char;
        break;
    case 51:
        track[height - 2][width - 44] = xwing_char;
        break;
    case 52:
        track[height - 2][width - 44] = xwing_char;
        break;
    }

    //Assign racer 2 symbol
    switch (position2)
    {
    //Go up
    case 0:
        track[height - 2][2] = tiefighter_char;
        break;
    case 1:
        track[height - 4][2] = tiefighter_char;
        break;
    case 2:
        track[height - 6][2] = tiefighter_char;
        break;
    //Go right
    case 3:
        track[height - 6][6] = tiefighter_char;
        break;
    case 4:
        track[height - 6][10] = tiefighter_char;
        break;
    case 5:
        track[height - 6][14] = tiefighter_char;
        break;
    case 6:
        track[height - 6][18] = tiefighter_char;
        break;
    case 7:
        track[height - 6][22] = tiefighter_char;
        break;
    //Go up
    case 8:
        track[height - 8][22] = tiefighter_char;
        break;
    case 9:
        track[height - 10][22] = tiefighter_char;
        break;
    case 10:
        track[height - 12][22] = tiefighter_char;
        break;
    //Go left
    case 11:
        track[height - 12][18] = tiefighter_char;
        break;
    case 12:
        track[height - 12][width - 31] = tiefighter_char;
        break;
    //Go down
    case 13:
        track[height - 10][width - 31] = tiefighter_char;
        break;
    //Go left
    case 14:
        track[height - 10][width - 35] = tiefighter_char;
        break;
    case 15:
        track[height - 10][width - 39] = tiefighter_char;
        break;
    //Go up
    case 16:
        track[height - 12][width - 39] = tiefighter_char;
        break;
    case 17:
        track[height - 14][width - 39] = tiefighter_char;
        break;
    case 18:
        track[1][width - 39] = tiefighter_char;
        break;
    //Go right
    case 19:
        track[1][width - 35] = tiefighter_char;
        break;
    case 20:
        track[1][width - 31] = tiefighter_char;
        break;
    case 21:
        track[1][width - 27] = tiefighter_char;
        break;
    case 22:
        track[1][width - 23] = tiefighter_char;
        break;
    case 23:
        track[1][width - 19] = tiefighter_char;
        break;
    case 24:
        track[1][width - 15] = tiefighter_char;
        break;
    case 25:
        track[1][width - 11] = tiefighter_char;
        break;
    case 26:
        track[1][width - 7] = tiefighter_char;
        break;
    case 27:
        track[1][width - 3] = tiefighter_char;
        break;
    //Go down
    case 28:
        track[height - 14][width - 3] = tiefighter_char;
        break;
    case 29:
        track[height - 12][width - 3] = tiefighter_char;
        break;
    //Go left
    case 30:
        track[height - 12][width - 7] = tiefighter_char;
        break;
    case 31:
        track[height - 12][width - 11] = tiefighter_char;
        break;
    case 32:
        track[height - 12][width - 15] = tiefighter_char;
        break;
    //Go down
    case 33:
        track[height - 10][width - 15] = tiefighter_char;
        break;
    case 34:
        track[height - 8][width - 15] = tiefighter_char;
        break;
    //Go right
    case 35:
        track[height - 8][width - 11] = tiefighter_char;
        break;
    case 36:
        track[height - 8][width - 7] = tiefighter_char;
        break;
    //Go down
    case 37:
        track[height - 6][width - 7] = tiefighter_char;
        break;
    case 38:
        track[height - 4][width - 7] = tiefighter_char;
        break;
    case 39:
        track[height - 2][width - 7] = tiefighter_char;
        break;
    //Go left
    case 40:
        track[height - 2][width - 11] = tiefighter_char;
        break;
    case 41:
        track[height - 2][width - 15] = tiefighter_char;
        break;
    case 42:
        track[height - 2][width - 19] = tiefighter_char;
        break;
    case 43:
        track[height - 2][width - 23] = tiefighter_char;
        break;
    case 44:
        track[height - 2][width - 27] = tiefighter_char;
        break;
    case 45:
        track[height - 2][width - 31] = tiefighter_char;
        break;
    case 46:
        track[height - 2][width - 35] = tiefighter_char;
        break;
    case 47:
        track[height - 2][width - 39] = tiefighter_char;
        break;
    case 48:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    //From 49, prevent output display error
    case 49:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    case 50:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    case 51:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    case 52:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    }

    //Assign racer 3 symbol
    switch (position3)
    {
    //Go up
    case 0:
        track[height - 2][3] = soullessone_char;
        break;
    case 1:
        track[height - 4][3] = soullessone_char;
        break;
    case 2:
        track[height - 6][3] = soullessone_char;
        break;
    //Go right
    case 3:
        track[height - 6][7] = soullessone_char;
        break;
    case 4:
        track[height - 6][11] = soullessone_char;
        break;
    case 5:
        track[height - 6][15] = soullessone_char;
        break;
    case 6:
        track[height - 6][19] = soullessone_char;
        break;
    case 7:
        track[height - 6][23] = soullessone_char;
        break;
    //Go up
    case 8:
        track[height - 8][23] = soullessone_char;
        break;
    case 9:
        track[height - 10][23] = soullessone_char;
        break;
    case 10:
        track[height - 12][23] = soullessone_char;
        break;
    //Go left
    case 11:
        track[height - 12][19] = soullessone_char;
        break;
    case 12:
        track[height - 12][width - 30] = soullessone_char;
        break;
    //Go down
    case 13:
        track[height - 10][width - 30] = soullessone_char;
        break;
    //Go left
    case 14:
        track[height - 10][width - 34] = soullessone_char;
        break;
    case 15:
        track[height - 10][width - 38] = soullessone_char;
        break;
    //Go up
    case 16:
        track[height - 12][width - 38] = soullessone_char;
        break;
    case 17:
        track[height - 14][width - 38] = soullessone_char;
        break;
    case 18:
        track[1][width - 38] = soullessone_char;
        break;
    //Go right
    case 19:
        track[1][width - 34] = soullessone_char;
        break;
    case 20:
        track[1][width - 30] = soullessone_char;
        break;
    case 21:
        track[1][width - 26] = soullessone_char;
        break;
    case 22:
        track[1][width - 22] = soullessone_char;
        break;
    case 23:
        track[1][width - 18] = soullessone_char;
        break;
    case 24:
        track[1][width - 14] = soullessone_char;
        break;
    case 25:
        track[1][width - 10] = soullessone_char;
        break;
    case 26:
        track[1][width - 6] = soullessone_char;
        break;
    case 27:
        track[1][width - 2] = soullessone_char;
        break;
    //Go down
    case 28:
        track[height - 14][width - 2] = soullessone_char;
        break;
    case 29:
        track[height - 12][width - 2] = soullessone_char;
        break;
    //Go left
    case 30:
        track[height - 12][width - 6] = soullessone_char;
        break;
    case 31:
        track[height - 12][width - 10] = soullessone_char;
        break;
    case 32:
        track[height - 12][width - 14] = soullessone_char;
        break;
    //Go down
    case 33:
        track[height - 10][width - 14] = soullessone_char;
        break;
    case 34:
        track[height - 8][width - 14] = soullessone_char;
        break;
    //Go right
    case 35:
        track[height - 8][width - 10] = soullessone_char;
        break;
    case 36:
        track[height - 8][width - 6] = soullessone_char;
        break;
    //Go down
    case 37:
        track[height - 6][width - 6] = soullessone_char;
        break;
    case 38:
        track[height - 4][width - 6] = soullessone_char;
        break;
    case 39:
        track[height - 2][width - 6] = soullessone_char;
        break;
    //Go left
    case 40:
        track[height - 2][width - 10] = soullessone_char;
        break;
    case 41:
        track[height - 2][width - 14] = soullessone_char;
        break;
    case 42:
        track[height - 2][width - 18] = soullessone_char;
        break;
    case 43:
        track[height - 2][width - 22] = soullessone_char;
        break;
    case 44:
        track[height - 2][width - 26] = soullessone_char;
        break;
    case 45:
        track[height - 2][width - 30] = soullessone_char;
        break;
    case 46:
        track[height - 2][width - 34] = soullessone_char;
        break;
    case 47:
        track[height - 2][width - 38] = soullessone_char;
        break;
    case 48:
        track[height - 2][width - 42] = soullessone_char;
        break;
    //From 49, prevent output display error
    case 49:
        track[height - 2][width - 42] = soullessone_char;
        break;
    case 50:
        track[height - 2][width - 42] = soullessone_char;
        break;
    case 51:
        track[height - 2][width - 42] = soullessone_char;
        break;
    case 52:
        track[height - 2][width - 42] = soullessone_char;
        break;
    }

    //Display the track
    for (int i = 0; i < height; i++) // Loop through each row of the track
    {
        for (int j = 0; j < width; j++) // Loop through each column of the track
            cout << track[i][j];
        cout << endl;
    }
    cout << endl;
}

// Function to display track and update racer's position
void display_track2(int position1, int position2, int position3)
{
    const int width = 33;
    const int height = 25;

    char track[height][width];
    
    char xwing_char = 'x';
    char tiefighter_char = 'y';
    char soullessone_char = 'z';

    //Initialize all to spaces
    for (int i = 0; i < height; i++) // Loop through each row of the track
        for (int j = 0; j < width; j++) // Loop through each column in the current row
            track[i][j] = ' ';

    //Top track
    for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
    {
        for (int j = 0; j < width - 1; j = j + 4) // Loop through each 3 column in the current row
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 0; j < width; j = j + 4) // Loop through each 3 column in the current row
        track[1][j] = '|';

    //Left and right tracks - vertical lines top part
    for (int i = 3; i < height - 17; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][0] = '|';
        track[i][4] = '|';
        track[i][width - 5] = '|';
        track[i][width - 1] = '|';
        //track design
        track[7][width - 25] = '|';
        track[7][width - 21] = '|';
        track[7][width - 17] = '|';
        track[7][width - 13] = '|';
    }

    //Left and right tracks - vertical lines middle part
    for (int i = 11; i < height - 8; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][4] = '|';
        track[i][8] = '|';
        track[i][width - 5] = '|';
        track[i][width - 1] = '|';
        //track design
        track[9][width - 17] = '|';
        track[9][width - 13] = '|';
        track[9][width - 5] = '|';
        track[9][width - 1] = '|';
        track[11][width - 21] = '|';
        track[11][width - 17] = '|';
        track[11][width - 13] = '|';
    }

    //Left and right tracks - vertical lines bottom part
    for (int i = 15; i < height; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][12] = '|';
        track[i][16] = '|';
        track[i][width - 5] = '|';
        track[i][width - 1] = '|';
    }

    //Left track - horizontal lines top part
    for (int i = 4; i < height - 15; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '-';
        track[i][4] = '+';
    }
    
    //Left track - horizontal lines middle part
    for (int i = 6; i < height - 8; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][4] = '+';
        track[i][5] = '-';
        track[i][6] = '-';
        track[i][7] = '-';
        track[i][8] = '+';
        track[i][9] = '-';
        track[i][10] = '-';
        track[i][11] = '-';
        track[i][12] = '+';
        track[i][13] = '-';
        track[i][14] = '-';
        track[i][15] = '-';
        track[i][16] = '+';
        track[i][17] = '-';
        track[i][18] = '-';
        track[i][19] = '-';
        track[i][20] = '+';
        track[14][17] = ' ';
        track[14][18] = ' ';
        track[14][19] = ' ';
        track[14][20] = ' ';
        track[16][17] = ' ';
        track[16][18] = ' ';
        track[16][19] = ' ';
        track[16][20] = ' ';
    }
    
    //Left track - horizontal lines bottom part
    for (int i = 14; i < height - 4; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][12] = '+';
        track[i][13] = '-';
        track[i][14] = '-';
        track[i][15] = '-';
        track[i][16] = '+';
    }
    //Right track - horizontal lines
    for (int i = 4; i < height - 4; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][width - 5] = '+';
        track[i][width - 4] = '-';
        track[i][width - 3] = '-';
        track[i][width - 2] = '-';
        track[i][width - 1] = '+';
    }

    //Bottom track
    for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 12; j < width - 1; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int j = 12; j < width; j = j + 4) // Loop through each 3 column of the track
        track[height - 2][j] = '|';

    //Assign racer 1 symbol
    switch (position1)
    {
    //Go up
    case 0:
        track[height - 2][width - 20] = xwing_char;
        break;
    case 1:
        track[height - 4][width - 20] = xwing_char;
        break;
    case 2:
        track[height - 6][width - 20] = xwing_char;
        break;
    case 3:
        track[height - 8][width - 20] = xwing_char;
        break;
    case 4:
        track[height - 10][width - 20] = xwing_char;
        break;
    //Go left
    case 5:
        track[height - 10][width - 24] = xwing_char;
        break;
    case 6:
        track[height - 10][width - 28] = xwing_char;
        break;
    //Go up
    case 7:
        track[height - 12][width - 28] = xwing_char;
        break;
    case 8:
        track[height - 14][width - 28] = xwing_char;
        break;
    //Go right
    case 9:
        track[height - 14][width - 24] = xwing_char;
        break;
    case 10:
        track[height - 14][width - 20] = xwing_char;
        break;
    case 11:
        track[height - 14][width - 16] = xwing_char;
        break;
    //Go up
    case 12:
        track[height - 16][width - 16] = xwing_char;
        break;
    case 13:
        track[height - 18][width - 16] = xwing_char;
        break;
    //Go left
    case 14:
        track[height - 18][width - 20] = xwing_char;
        break;
    case 15:
        track[height - 18][width - 24] = xwing_char;
        break;
    case 16:
        track[height - 18][width - 28] = xwing_char;
        break;
    case 17:
        track[height - 18][width - 32] = xwing_char;
        break;
    //Go up
    case 18:
        track[height - 20][width - 32] = xwing_char;
        break;
    case 19:
        track[height - 22][width - 32] = xwing_char;
        break;
    case 20:
        track[height - 24][width - 32] = xwing_char;
        break;
    //Go right
    case 21:
        track[height - 24][width - 28] = xwing_char;
        break;
    case 22:
        track[height - 24][width - 24] = xwing_char;
        break;
    case 23:
        track[height - 24][width - 20] = xwing_char;
        break;
    case 24:
        track[height - 24][width - 16] = xwing_char;
        break;
    case 25:
        track[height - 24][width - 12] = xwing_char;
        break;
    case 26:
        track[height - 24][width - 8] = xwing_char;
        break;
    case 27:
        track[height - 24][width - 4] = xwing_char;
        break;
    //Go down
    case 28:
        track[height - 22][width - 4] = xwing_char;
        break;
    case 29:
        track[height - 20][width - 4] = xwing_char;
        break;
    case 30:
        track[height - 18][width - 4] = xwing_char;
        break;
    case 31:
        track[height - 16][width - 4] = xwing_char;
        break;
    case 32:
        track[height - 14][width - 4] = xwing_char;
        break;
    case 33:
        track[height - 12][width - 4] = xwing_char;
        break;
    case 34:
        track[height - 10][width - 4] = xwing_char;
        break;
    case 35:
        track[height - 8][width - 4] = xwing_char;
        break;
    case 36:
        track[height - 6][width - 4] = xwing_char;
        break;
    case 37:
        track[height - 4][width - 4] = xwing_char;
        break;
    case 38:
        track[height - 2][width - 4] = xwing_char;
        break;
    //Go left
    case 39:
        track[height - 2][width - 8] = xwing_char;
        break;
    case 40:
        track[height - 2][width - 12] = xwing_char;
        break;
    case 41:
        track[height - 2][width - 16] = xwing_char;
        break;
    case 42:
        track[height - 2][width - 20] = xwing_char;
        break;
    //From 42, prevent output display error
    case 43:
        track[height - 2][width - 20] = xwing_char;
        break;
    case 44:
        track[height - 2][width - 20] = xwing_char;
        break;
    case 45:
        track[height - 2][width - 20] = xwing_char;
        break;
    }

    //Assign racer 2 symbol
    switch (position2)
    {
    //Go up
    case 0:
        track[height - 2][width - 19] = tiefighter_char;
        break;
    case 1:
        track[height - 4][width - 19] = tiefighter_char;
        break;
    case 2:
        track[height - 6][width - 19] = tiefighter_char;
        break;
    case 3:
        track[height - 8][width - 19] = tiefighter_char;
        break;
    case 4:
        track[height - 10][width - 19] = tiefighter_char;
        break;
    //Go left
    case 5:
        track[height - 10][width - 23] = tiefighter_char;
        break;
    case 6:
        track[height - 10][width - 27] = tiefighter_char;
        break;
    //Go up
    case 7:
        track[height - 12][width - 27] = tiefighter_char;
        break;
    case 8:
        track[height - 14][width - 27] = tiefighter_char;
        break;
    //Go right
    case 9:
        track[height - 14][width - 23] = tiefighter_char;
        break;
    case 10:
        track[height - 14][width - 19] = tiefighter_char;
        break;
    case 11:
        track[height - 14][width - 15] = tiefighter_char;
        break;
    //Go up
    case 12:
        track[height - 16][width - 15] = tiefighter_char;
        break;
    case 13:
        track[height - 18][width - 15] = tiefighter_char;
        break;
    //Go left
    case 14:
        track[height - 18][width - 19] = tiefighter_char;
        break;
    case 15:
        track[height - 18][width - 23] = tiefighter_char;
        break;
    case 16:
        track[height - 18][width - 27] = tiefighter_char;
        break;
    case 17:
        track[height - 18][width - 31] = tiefighter_char;
        break;
    //Go up
    case 18:
        track[height - 20][width - 31] = tiefighter_char;
        break;
    case 19:
        track[height - 22][width - 31] = tiefighter_char;
        break;
    case 20:
        track[height - 24][width - 31] = tiefighter_char;
        break;
    //Go right
    case 21:
        track[height - 24][width - 27] = tiefighter_char;
        break;
    case 22:
        track[height - 24][width - 23] = tiefighter_char;
        break;
    case 23:
        track[height - 24][width - 19] = tiefighter_char;
        break;
    case 24:
        track[height - 24][width - 15] = tiefighter_char;
        break;
    case 25:
        track[height - 24][width - 11] = tiefighter_char;
        break;
    case 26:
        track[height - 24][width - 7] = tiefighter_char;
        break;
    case 27:
        track[height - 24][width - 3] = tiefighter_char;
        break;
    //Go down
    case 28:
        track[height - 22][width - 3] = tiefighter_char;
        break;
    case 29:
        track[height - 20][width - 3] = tiefighter_char;
        break;
    case 30:
        track[height - 18][width - 3] = tiefighter_char;
        break;
    case 31:
        track[height - 16][width - 3] = tiefighter_char;
        break;
    case 32:
        track[height - 14][width - 3] = tiefighter_char;
        break;
    case 33:
        track[height - 12][width - 3] = tiefighter_char;
        break;
    case 34:
        track[height - 10][width - 3] = tiefighter_char;
        break;
    case 35:
        track[height - 8][width - 3] = tiefighter_char;
        break;
    case 36:
        track[height - 6][width - 3] = tiefighter_char;
        break;
    case 37:
        track[height - 4][width - 3] = tiefighter_char;
        break;
    case 38:
        track[height - 2][width - 3] = tiefighter_char;
        break;
    //Go left
    case 39:
        track[height - 2][width - 7] = tiefighter_char;
        break;
    case 40:
        track[height - 2][width - 11] = tiefighter_char;
        break;
    case 41:
        track[height - 2][width - 15] = tiefighter_char;
        break;
    case 42:
        track[height - 2][width - 19] = tiefighter_char;
        break;
    //From 42, prevent output display error
    case 43:
        track[height - 2][width - 19] = tiefighter_char;
        break;
    case 44:
        track[height - 2][width - 19] = tiefighter_char;
        break;
    case 45:
        track[height - 2][width - 19] = tiefighter_char;
        break;
    }

    //Assign racer 3 symbol
    switch (position3)
    {
    //Go up
    case 0:
        track[height - 2][width - 18] = soullessone_char;
        break;
    case 1:
        track[height - 4][width - 18] = soullessone_char;
        break;
    case 2:
        track[height - 6][width - 18] = soullessone_char;
        break;
    case 3:
        track[height - 8][width - 18] = soullessone_char;
        break;
    case 4:
        track[height - 10][width - 18] = soullessone_char;
        break;
    //Go left
    case 5:
        track[height - 10][width - 22] = soullessone_char;
        break;
    case 6:
        track[height - 10][width - 26] = soullessone_char;
        break;
    //Go up
    case 7:
        track[height - 12][width - 26] = soullessone_char;
        break;
    case 8:
        track[height - 14][width - 26] = soullessone_char;
        break;
    //Go right
    case 9:
        track[height - 14][width - 22] = soullessone_char;
        break;
    case 10:
        track[height - 14][width - 18] = soullessone_char;
        break;
    case 11:
        track[height - 14][width - 14] = soullessone_char;
        break;
    //Go up
    case 12:
        track[height - 16][width - 14] = soullessone_char;
        break;
    case 13:
        track[height - 18][width - 14] = soullessone_char;
        break;
    //Go left
    case 14:
        track[height - 18][width - 18] = soullessone_char;
        break;
    case 15:
        track[height - 18][width - 22] = soullessone_char;
        break;
    case 16:
        track[height - 18][width - 26] = soullessone_char;
        break;
    case 17:
        track[height - 18][width - 30] = soullessone_char;
        break;
    //Go up
    case 18:
        track[height - 20][width - 30] = soullessone_char;
        break;
    case 19:
        track[height - 22][width - 30] = soullessone_char;
        break;
    case 20:
        track[height - 24][width - 30] = soullessone_char;
        break;
    //Go right
    case 21:
        track[height - 24][width - 26] = soullessone_char;
        break;
    case 22:
        track[height - 24][width - 22] = soullessone_char;
        break;
    case 23:
        track[height - 24][width - 18] = soullessone_char;
        break;
    case 24:
        track[height - 24][width - 14] = soullessone_char;
        break;
    case 25:
        track[height - 24][width - 10] = soullessone_char;
        break;
    case 26:
        track[height - 24][width - 6] = soullessone_char;
        break;
    case 27:
        track[height - 24][width - 2] = soullessone_char;
        break;
    //Go down
    case 28:
        track[height - 22][width - 2] = soullessone_char;
        break;
    case 29:
        track[height - 20][width - 2] = soullessone_char;
        break;
    case 30:
        track[height - 18][width - 2] = soullessone_char;
        break;
    case 31:
        track[height - 16][width - 2] = soullessone_char;
        break;
    case 32:
        track[height - 14][width - 2] = soullessone_char;
        break;
    case 33:
        track[height - 12][width - 2] = soullessone_char;
        break;
    case 34:
        track[height - 10][width - 2] = soullessone_char;
        break;
    case 35:
        track[height - 8][width - 2] = soullessone_char;
        break;
    case 36:
        track[height - 6][width - 2] = soullessone_char;
        break;
    case 37:
        track[height - 4][width - 2] = soullessone_char;
        break;
    case 38:
        track[height - 2][width - 2] = soullessone_char;
        break;
    //Go left
    case 39:
        track[height - 2][width - 6] = soullessone_char;
        break;
    case 40:
        track[height - 2][width - 10] = soullessone_char;
        break;
    case 41:
        track[height - 2][width - 14] = soullessone_char;
        break;
    case 42:
        track[height - 2][width - 18] = soullessone_char;
        break;
    //From 42, prevent output display error
    case 43:
        track[height - 2][width - 18] = soullessone_char;
        break;
    case 44:
        track[height - 2][width - 18] = soullessone_char;
        break;
    case 45:
        track[height - 2][width - 18] = soullessone_char;
        break;
    }

    //Display the track
    for (int i = 0; i < height; i++) // Loop through each row of the track
    {
        for (int j = 0; j < width; j++) // Loop through each column of the track
            cout << track[i][j];
        cout << endl;
    }
    cout << endl;
}

// Function to display track and update racer's position
void display_track3(int position1, int position2, int position3)
{
    const int width = 77;
    const int height = 19;

    char track[height][width];
    
    char xwing_char = 'x';
    char tiefighter_char = 'y';
    char soullessone_char = 'z';

    //Initialize all to spaces
    for (int i = 0; i < height; i++) // Loop through each row of the track
        for (int j = 0; j < width; j++) // Loop through each column in the current row
            track[i][j] = ' ';

    //Top track
    for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
    {
        for (int j = 0; j < width - 17; j = j + 4) // Loop through each 3 column in the current row
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';

        }
        track[i][width - 17] = '+';
    }

    for (int j = 0; j < width - 16; j = j + 4) // Loop through each 3 column in the current row
        track[1][j] = '|';

    for (int j = 16; j < width - 24; j = j + 4) // Loop through each 3 column in the current row
        track[5][j] = '|';

    for (int j = 24; j < width; j = j + 4) // Loop through each 3 column in the current row
        track[9][j] = '|';

    for (int j = 48; j < width - 4; j = j + 4) // Loop through each 3 column in the current row
        track[15][j] = '|';

    for (int j = 0; j < width - 60; j = j + 4) // Loop through each 3 column in the current row
        track[15][j] = '|';

    for (int j = 12; j < width - 48; j = j + 4) // Loop through each 3 column in the current row
        track[13][j] = '|';

    //Left and right tracks - vertical
    for (int i = 3; i < height - 13; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][0] = '|';
        track[i][4] = '|';
        track[i][width - 21] = '|';
        track[i][width - 17] = '|';
    }

    //Left and right tracks - vertical lines
    for (int i = 7; i < height - 9; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][0] = '|';
        track[i][4] = '|';
        track[i][width - 61] = '|';
        track[i][width - 57] = '|';
    }

    //Left and right tracks - vertical lines
    for (int i = 11; i < height - 4; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
    {
        track[i][0] = '|';
        track[i][4] = '|';
        track[i][width - 5] = '|';
        track[i][width - 1] = '|';
        track[13][width - 9] = '|';
        track[15][width - 53] = '|';
        track[15][width - 49] = '|';
    }

    //Left track - horizontal lines
    for (int i = 4; i < height - 2; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '-';
        track[i][4] = '+';
    }
    
    //Left track - horizontal lines
    for (int i = 4; i < height - 12; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][56] = '+';
        track[i][57] = '-';
        track[i][58] = '-';
        track[i][59] = '-';
        track[i][60] = '+';
    }
    //Right track - horizontal lines
    for (int i = 4; i < height - 8; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
    {
        track[i][width - 61] = '+';
        track[i][width - 60] = '-';
        track[i][width - 59] = '-';
        track[i][width - 58] = '-';
        track[i][width - 57] = '+';
        track[12][width - 9] = '+';
        track[12][width - 8] = '-';
        track[12][width - 7] = '-';
        track[12][width - 6] = '-';
        track[12][width - 5] = '+';
        track[12][width - 4] = '-';
        track[12][width - 3] = '-';
        track[12][width - 2] = '-';
        track[12][width - 1] = '+';
        track[14][width - 4] = '-';
        track[14][width - 3] = '-';
        track[14][width - 2] = '-';
        track[14][width - 1] = '+';
    }

    for (int i = 4; i < height - 12; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 20; j < width - 24; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 21] = '+';
    }

    for (int i = 8; i < height - 8; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 20; j < width - 1; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 1] = '+';
    }

    for (int i = 12; i < height - 4; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 12; j < width - 50; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 49] = '+';
    }

    for (int i = 14; i < height - 2; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 4; j < width - 64; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 61] = '+';
    }

     for (int i = 14; i < height - 2; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 48; j < width - 8; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 5] = '+';
    }

    //Bottom track
    for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
    {
        for (int j = 24; j < width - 28; j = j + 4) // Loop through each 3 column of the track
        {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][width - 25] = '+';
    }

    for (int j = 24; j < width - 24; j = j + 4) // Loop through each 3 column of the track
        track[height - 2][j] = '|';

    //Assign racer 1 symbol
    switch (position1)
    {
    //Go up
    case 0:
        track[height - 4][1] = xwing_char;
        break;
    case 1:
        track[height - 6][1] = xwing_char;
        break;
    case 2:
        track[height - 8][1] = xwing_char;
        break;
    case 3:
        track[height - 10][1] = xwing_char;
        break;
    case 4:
        track[height - 12][1] = xwing_char;
        break;
    case 5:
        track[height - 14][1] = xwing_char;
        break;
    case 6:
        track[height - 16][1] = xwing_char;
        break;
    case 7:
        track[height - 18][1] = xwing_char;
        break;
    //Go right
    case 8:
        track[height - 18][width - 72] = xwing_char;
        break;
    case 9:
        track[height - 18][width - 68] = xwing_char;
        break;
    case 10:
        track[height - 18][width - 64] = xwing_char;
        break;
    case 11:
        track[height - 18][width - 60] = xwing_char;
        break;
    case 12:
        track[height - 18][width - 56] = xwing_char;
        break;
    case 13:
        track[height - 18][width - 52] = xwing_char;
        break;
    case 14:
        track[height - 18][width - 48] = xwing_char;
        break;
    case 15:
        track[height - 18][width - 44] = xwing_char;
        break;
    case 16:
        track[height - 18][width - 40] = xwing_char;
        break;
    case 17:
        track[height - 18][width - 36] = xwing_char;
        break;
    case 18:
        track[height - 18][width - 32] = xwing_char;
        break;
    case 19:
        track[height - 18][width - 28] = xwing_char;
        break;
    case 20:
        track[height - 18][width - 24] = xwing_char;
        break;
    case 21:
        track[height - 18][width - 20] = xwing_char;
        break;
    //Go down
    case 22:
        track[height - 16][width - 20] = xwing_char;
        break;
    case 23:
        track[height - 14][width - 20] = xwing_char;
        break;
    //Go left
    case 24:
        track[height - 14][width - 24] = xwing_char;
        break;
    case 25:
        track[height - 14][width - 28] = xwing_char;
        break;
    case 26:
        track[height - 14][width - 32] = xwing_char;
        break;
    case 27:
        track[height - 14][width - 36] = xwing_char;
        break;
    case 28:
        track[height - 14][width - 40] = xwing_char;
        break;
    case 29:
        track[height - 14][width - 44] = xwing_char;
        break;
    case 30:
        track[height - 14][width - 48] = xwing_char;
        break;
    case 31:
        track[height - 14][width - 52] = xwing_char;
        break;
    case 32:
        track[height - 14][width - 56] = xwing_char;
        break;
    case 33:
        track[height - 14][width - 60] = xwing_char;
        break;
    //Go down
    case 34:
        track[height - 12][width - 60] = xwing_char;
        break;
    case 35:
        track[height - 10][width - 60] = xwing_char;
        break;
    //Go right
    case 36:
        track[height - 10][width - 56] = xwing_char;
        break;
    case 37:
        track[height - 10][width - 52] = xwing_char;
        break;
    case 38:
        track[height - 10][width - 48] = xwing_char;
        break;
    case 39:
        track[height - 10][width - 44] = xwing_char;
        break;
    case 40:
        track[height - 10][width - 40] = xwing_char;
        break;
    case 41:
        track[height - 10][width - 36] = xwing_char;
        break;
    case 42:
        track[height - 10][width - 32] = xwing_char;
        break;
    case 43:
        track[height - 10][width - 28] = xwing_char;
        break;
    case 44:
        track[height - 10][width - 24] = xwing_char;
        break;
    case 45:
        track[height - 10][width - 20] = xwing_char;
        break;
    case 46:
        track[height - 10][width - 16] = xwing_char;
        break;
    case 47:
        track[height - 10][width - 12] = xwing_char;
        break;
    case 48:
        track[height - 10][width - 8] = xwing_char;
        break;
    case 49:
        track[height - 10][width - 4] = xwing_char;
        break;
    //Go down
    case 50:
        track[height - 8][width - 4] = xwing_char;
        break;
    case 51:
        track[height - 6][width - 4] = xwing_char;
        break;
    //Go left
    case 52:
        track[height - 6][width - 8] = xwing_char;
        break;
    //Go down
    case 53:
        track[height - 4][width - 8] = xwing_char;
        break;
    //Go left
    case 54:
        track[height - 4][width - 12] = xwing_char;
        break;
    case 55:
        track[height - 4][width - 16] = xwing_char;
        break;
    case 56:
        track[height - 4][width - 20] = xwing_char;
        break;
    case 57:
        track[height - 4][width - 24] = xwing_char;
        break;
    case 58:
        track[height - 4][width - 28] = xwing_char;
        break;
    //Go down
    case 59:
        track[height - 2][width - 28] = xwing_char;
        break;
    //Go left
    case 60:
        track[height - 2][width - 32] = xwing_char;
        break;
    case 61:
        track[height - 2][width - 36] = xwing_char;
        break;
    case 62:
        track[height - 2][width - 40] = xwing_char;
        break;
    case 63:
        track[height - 2][width - 44] = xwing_char;
        break;
    case 64:
        track[height - 2][width - 48] = xwing_char;
        break;
    case 65:
        track[height - 2][width - 52] = xwing_char;
        break;
    //Go up
    case 66:
        track[height - 4][width - 52] = xwing_char;
        break;
    case 67:
        track[height - 6][width - 52] = xwing_char;
        break;
    //Go left
    case 68:
        track[height - 6][width - 56] = xwing_char;
        break;
    case 69:
        track[height - 6][width - 60] = xwing_char;
        break;
    case 70:
        track[height - 6][width - 64] = xwing_char;
        break;
    //Go down
    case 71:
        track[height - 4][width - 64] = xwing_char;
        break;
    //Go left
    case 72:
        track[height - 4][width - 68] = xwing_char;
        break;
    case 73:
        track[height - 4][width - 72] = xwing_char;
        break;
    case 74:
        track[height - 4][width - 76] = xwing_char;
        break;
    //From 74, prevent output display error
    case 75:
        track[height - 4][width - 76] = xwing_char;
        break;
    case 76:
        track[height - 4][width - 76] = xwing_char;
        break;
    case 77:
        track[height - 4][width - 76] = xwing_char;
        break;
    }

    //Assign racer 2 symbol
    switch (position2)
    {
    //Go up
    case 0:
        track[height - 4][2] = tiefighter_char;
        break;
    case 1:
        track[height - 6][2] = tiefighter_char;
        break;
    case 2:
        track[height - 8][2] = tiefighter_char;
        break;
    case 3:
        track[height - 10][2] = tiefighter_char;
        break;
    case 4:
        track[height - 12][2] = tiefighter_char;
        break;
    case 5:
        track[height - 14][2] = tiefighter_char;
        break;
    case 6:
        track[height - 16][2] = tiefighter_char;
        break;
    case 7:
        track[height - 18][2] = tiefighter_char;
        break;
    //Go right
    case 8:
        track[height - 18][width - 71] = tiefighter_char;
        break;
    case 9:
        track[height - 18][width - 67] = tiefighter_char;
        break;
    case 10:
        track[height - 18][width - 63] = tiefighter_char;
        break;
    case 11:
        track[height - 18][width - 59] = tiefighter_char;
        break;
    case 12:
        track[height - 18][width - 55] = tiefighter_char;
        break;
    case 13:
        track[height - 18][width - 51] = tiefighter_char;
        break;
    case 14:
        track[height - 18][width - 47] = tiefighter_char;
        break;
    case 15:
        track[height - 18][width - 43] = tiefighter_char;
        break;
    case 16:
        track[height - 18][width - 39] = tiefighter_char;
        break;
    case 17:
        track[height - 18][width - 35] = tiefighter_char;
        break;
    case 18:
        track[height - 18][width - 31] = tiefighter_char;
        break;
    case 19:
        track[height - 18][width - 27] = tiefighter_char;
        break;
    case 20:
        track[height - 18][width - 23] = tiefighter_char;
        break;
    case 21:
        track[height - 18][width - 19] = tiefighter_char;
        break;
    //Go down
    case 22:
        track[height - 16][width - 19] = tiefighter_char;
        break;
    case 23:
        track[height - 14][width - 19] = tiefighter_char;
        break;
    //Go left
    case 24:
        track[height - 14][width - 23] = tiefighter_char;
        break;
    case 25:
        track[height - 14][width - 27] = tiefighter_char;
        break;
    case 26:
        track[height - 14][width - 31] = tiefighter_char;
        break;
    case 27:
        track[height - 14][width - 35] = tiefighter_char;
        break;
    case 28:
        track[height - 14][width - 39] = tiefighter_char;
        break;
    case 29:
        track[height - 14][width - 43] = tiefighter_char;
        break;
    case 30:
        track[height - 14][width - 47] = tiefighter_char;
        break;
    case 31:
        track[height - 14][width - 51] = tiefighter_char;
        break;
    case 32:
        track[height - 14][width - 55] = tiefighter_char;
        break;
    case 33:
        track[height - 14][width - 59] = tiefighter_char;
        break;
    //Go down
    case 34:
        track[height - 12][width - 59] = tiefighter_char;
        break;
    case 35:
        track[height - 10][width - 59] = tiefighter_char;
        break;
    //Go right
    case 36:
        track[height - 10][width - 55] = tiefighter_char;
        break;
    case 37:
        track[height - 10][width - 51] = tiefighter_char;
        break;
    case 38:
        track[height - 10][width - 47] = tiefighter_char;
        break;
    case 39:
        track[height - 10][width - 43] = tiefighter_char;
        break;
    case 40:
        track[height - 10][width - 39] = tiefighter_char;
        break;
    case 41:
        track[height - 10][width - 35] = tiefighter_char;
        break;
    case 42:
        track[height - 10][width - 31] = tiefighter_char;
        break;
    case 43:
        track[height - 10][width - 27] = tiefighter_char;
        break;
    case 44:
        track[height - 10][width - 23] = tiefighter_char;
        break;
    case 45:
        track[height - 10][width - 19] = tiefighter_char;
        break;
    case 46:
        track[height - 10][width - 15] = tiefighter_char;
        break;
    case 47:
        track[height - 10][width - 11] = tiefighter_char;
        break;
    case 48:
        track[height - 10][width - 7] = tiefighter_char;
        break;
    case 49:
        track[height - 10][width - 3] = tiefighter_char;
        break;
    //Go down
    case 50:
        track[height - 8][width - 3] = tiefighter_char;
        break;
    case 51:
        track[height - 6][width - 3] = tiefighter_char;
        break;
    //Go left
    case 52:
        track[height - 6][width - 7] = tiefighter_char;
        break;
    //Go down
    case 53:
        track[height - 4][width - 7] = tiefighter_char;
        break;
    //Go left
    case 54:
        track[height - 4][width - 11] = tiefighter_char;
        break;
    case 55:
        track[height - 4][width - 15] = tiefighter_char;
        break;
    case 56:
        track[height - 4][width - 19] = tiefighter_char;
        break;
    case 57:
        track[height - 4][width - 23] = tiefighter_char;
        break;
    case 58:
        track[height - 4][width - 27] = tiefighter_char;
        break;
    //Go down
    case 59:
        track[height - 2][width - 27] = tiefighter_char;
        break;
    //Go left
    case 60:
        track[height - 2][width - 31] = tiefighter_char;
        break;
    case 61:
        track[height - 2][width - 35] = tiefighter_char;
        break;
    case 62:
        track[height - 2][width - 39] = tiefighter_char;
        break;
    case 63:
        track[height - 2][width - 43] = tiefighter_char;
        break;
    case 64:
        track[height - 2][width - 47] = tiefighter_char;
        break;
    case 65:
        track[height - 2][width - 51] = tiefighter_char;
        break;
    //Go up
    case 66:
        track[height - 4][width - 51] = tiefighter_char;
        break;
    case 67:
        track[height - 6][width - 51] = tiefighter_char;
        break;
    //Go left
    case 68:
        track[height - 6][width - 55] = tiefighter_char;
        break;
    case 69:
        track[height - 6][width - 59] = tiefighter_char;
        break;
    case 70:
        track[height - 6][width - 63] = tiefighter_char;
        break;
    //Go down
    case 71:
        track[height - 4][width - 63] = tiefighter_char;
        break;
    //Go left
    case 72:
        track[height - 4][width - 67] = tiefighter_char;
        break;
    case 73:
        track[height - 4][width - 71] = tiefighter_char;
        break;
    case 74:
        track[height - 4][width - 75] = tiefighter_char;
        break;
    //From 74, prevent output display error
    case 75:
        track[height - 4][width - 75] = tiefighter_char;
        break;
    case 76:
        track[height - 4][width - 75] = tiefighter_char;
        break;
    case 77:
        track[height - 4][width - 75] = tiefighter_char;
        break;
    }

    //Assign racer 3 symbol
    switch (position3)
    {
    //Go up
    case 0:
        track[height - 4][3] = soullessone_char;
        break;
    case 1:
        track[height - 6][3] = soullessone_char;
        break;
    case 2:
        track[height - 8][3] = soullessone_char;
        break;
    case 3:
        track[height - 10][3] = soullessone_char;
        break;
    case 4:
        track[height - 12][3] = soullessone_char;
        break;
    case 5:
        track[height - 14][3] = soullessone_char;
        break;
    case 6:
        track[height - 16][3] = soullessone_char;
        break;
    case 7:
        track[height - 18][3] = soullessone_char;
        break;
    //Go right
    case 8:
        track[height - 18][width - 70] = soullessone_char;
        break;
    case 9:
        track[height - 18][width - 66] = soullessone_char;
        break;
    case 10:
        track[height - 18][width - 62] = soullessone_char;
        break;
    case 11:
        track[height - 18][width - 58] = soullessone_char;
        break;
    case 12:
        track[height - 18][width - 54] = soullessone_char;
        break;
    case 13:
        track[height - 18][width - 50] = soullessone_char;
        break;
    case 14:
        track[height - 18][width - 46] = soullessone_char;
        break;
    case 15:
        track[height - 18][width - 42] = soullessone_char;
        break;
    case 16:
        track[height - 18][width - 38] = soullessone_char;
        break;
    case 17:
        track[height - 18][width - 34] = soullessone_char;
        break;
    case 18:
        track[height - 18][width - 30] = soullessone_char;
        break;
    case 19:
        track[height - 18][width - 26] = soullessone_char;
        break;
    case 20:
        track[height - 18][width - 22] = soullessone_char;
        break;
    case 21:
        track[height - 18][width - 18] = soullessone_char;
        break;
    //Go down
    case 22:
        track[height - 16][width - 18] = soullessone_char;
        break;
    case 23:
        track[height - 14][width - 18] = soullessone_char;
        break;
    //Go left
    case 24:
        track[height - 14][width - 22] = soullessone_char;
        break;
    case 25:
        track[height - 14][width - 26] = soullessone_char;
        break;
    case 26:
        track[height - 14][width - 30] = soullessone_char;
        break;
    case 27:
        track[height - 14][width - 34] = soullessone_char;
        break;
    case 28:
        track[height - 14][width - 38] = soullessone_char;
        break;
    case 29:
        track[height - 14][width - 42] = soullessone_char;
        break;
    case 30:
        track[height - 14][width - 46] = soullessone_char;
        break;
    case 31:
        track[height - 14][width - 50] = soullessone_char;
        break;
    case 32:
        track[height - 14][width - 54] = soullessone_char;
        break;
    case 33:
        track[height - 14][width - 58] = soullessone_char;
        break;
    //Go down
    case 34:
        track[height - 12][width - 58] = soullessone_char;
        break;
    case 35:
        track[height - 10][width - 58] = soullessone_char;
        break;
    //Go right
    case 36:
        track[height - 10][width - 54] = soullessone_char;
        break;
    case 37:
        track[height - 10][width - 50] = soullessone_char;
        break;
    case 38:
        track[height - 10][width - 46] = soullessone_char;
        break;
    case 39:
        track[height - 10][width - 42] = soullessone_char;
        break;
    case 40:
        track[height - 10][width - 38] = soullessone_char;
        break;
    case 41:
        track[height - 10][width - 34] = soullessone_char;
        break;
    case 42:
        track[height - 10][width - 30] = soullessone_char;
        break;
    case 43:
        track[height - 10][width - 26] = soullessone_char;
        break;
    case 44:
        track[height - 10][width - 22] = soullessone_char;
        break;
    case 45:
        track[height - 10][width - 18] = soullessone_char;
        break;
    case 46:
        track[height - 10][width - 14] = soullessone_char;
        break;
    case 47:
        track[height - 10][width - 10] = soullessone_char;
        break;
    case 48:
        track[height - 10][width - 6] = soullessone_char;
        break;
    case 49:
        track[height - 10][width - 2] = soullessone_char;
        break;
    //Go down
    case 50:
        track[height - 8][width - 2] = soullessone_char;
        break;
    case 51:
        track[height - 6][width - 2] = soullessone_char;
        break;
    //Go left
    case 52:
        track[height - 6][width - 6] = soullessone_char;
        break;
    //Go down
    case 53:
        track[height - 4][width - 6] = soullessone_char;
        break;
    //Go left
    case 54:
        track[height - 4][width - 10] = soullessone_char;
        break;
    case 55:
        track[height - 4][width - 14] = soullessone_char;
        break;
    case 56:
        track[height - 4][width - 18] = soullessone_char;
        break;
    case 57:
        track[height - 4][width - 22] = soullessone_char;
        break;
    case 58:
        track[height - 4][width - 26] = soullessone_char;
        break;
    //Go down
    case 59:
        track[height - 2][width - 26] = soullessone_char;
        break;
    //Go left
    case 60:
        track[height - 2][width - 30] = soullessone_char;
        break;
    case 61:
        track[height - 2][width - 34] = soullessone_char;
        break;
    case 62:
        track[height - 2][width - 38] = soullessone_char;
        break;
    case 63:
        track[height - 2][width - 42] = soullessone_char;
        break;
    case 64:
        track[height - 2][width - 46] = soullessone_char;
        break;
    case 65:
        track[height - 2][width - 50] = soullessone_char;
        break;
    //Go up
    case 66:
        track[height - 4][width - 50] = soullessone_char;
        break;
    case 67:
        track[height - 6][width - 50] = soullessone_char;
        break;
    //Go left
    case 68:
        track[height - 6][width - 54] = soullessone_char;
        break;
    case 69:
        track[height - 6][width - 58] = soullessone_char;
        break;
    case 70:
        track[height - 6][width - 62] = soullessone_char;
        break;
    //Go down
    case 71:
        track[height - 4][width - 62] = soullessone_char;
        break;
    //Go left
    case 72:
        track[height - 4][width - 66] = soullessone_char;
        break;
    case 73:
        track[height - 4][width - 70] = soullessone_char;
        break;
    case 74:
        track[height - 4][width - 74] = soullessone_char;
        break;
    //From 74, prevent output display error
    case 75:
        track[height - 4][width - 74] = soullessone_char;
        break;
    case 76:
        track[height - 4][width - 74] = soullessone_char;
        break;
    case 77:
        track[height - 4][width - 74] = soullessone_char;
        break;
    }

    //Display the track
    for (int i = 0; i < height; i++) // Loop through each row of the track
    {
        for (int j = 0; j < width; j++) // Loop through each column of the track
            cout << track[i][j];
        cout << endl;
    }
    cout << endl;
}

bool apply_bridge(int &position, const vector<Bridge> &bridges) {
    for (const auto &bridge : bridges) {
        if (position == bridge.start) {
            position = bridge.end;
            return true;
        }
    }
    return false; // Ensure the function returns false if no bridge was used
}

int main()
{
    srand(time(0)); // Seed for random number generation
    int xwing_position = 0;
    int xwing_SpeedMin = 2;
    int xwing_SpeedMax = 4;
    int tiefighter_position = 0;
    int tiefighter_SpeedMin = 1;
    int tiefighter_SpeedMax = 5;
    int soullessone_position = 0;
    int soullessone_SpeedMin = 3;
    int soullessone_SpeedMax = 6;
    const int PAUSE_DURATION_MS = 1000; // Pause duration in milliseconds (1 second)
    int xw = 0, tw = 0, sw = 0;
    int race_rounds = 0;
    int turn_of_race = 1;
    int tracksec;
    int endpoint;
    float bet = 0;
    int option = 0; 
    string racer1, racer2;
    vector<Bridge> bridges;
    int num_bridges;

    cout << "Select track" << endl;
    cout << "1. Track 1" << endl;
    display_track1(xwing_position, tiefighter_position, soullessone_position);
    cout << "2. Track 2" << endl;
    display_track2(xwing_position, tiefighter_position, soullessone_position);
    cout << "3. Track 3" << endl;
    display_track3(xwing_position, tiefighter_position, soullessone_position);
    cout << "4. (Random)" << endl;

    while (true) {
        cin >> tracksec;
        if (tracksec >= 1 && tracksec <= 4) {
            break;
        } else {
            cout << "Invalid input. Please select a track (1, 2, 3, or 4):" << endl;
        }
    }

    if (tracksec == 4) {
        tracksec = rand() % 3 + 1; // Generate a random track number between 1 and 3
    }

    cout << "Enter number of rounds for the race: ";
    cin >> race_rounds;

    // Get number of bridges from user
    while (true) {
        cout << "Enter the number of bridges (3-5): ";
        cin >> num_bridges;
        if (cin.fail() || num_bridges < 3 || num_bridges > 5) {
            cin.clear(); // Clear the error flag set by invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input. Please enter a number between 3 and 5." << endl;
        } else {
            break; // Valid input, exit the loop
        }
    }

    // Get start and end positions for each bridge
    for (int i = 0; i < num_bridges; ++i) {
        Bridge bridge;
        cout << "Enter start location for bridge " << i + 1 << ": ";
        cin >> bridge.start;
        cout << "Enter end location for bridge " << i + 1 << ": ";
        cin >> bridge.end;
        bridges.push_back(bridge);
    }

    cout << "Place your bet: " << setw(25) << "rewards\n";
    cout << "1) Two racers of your choice win" << setw(10) << "x1.5\n";
    cout << "2) One racer of your choice wins" << setw(10) << "x2\n";
    cin >> option;
    cout << "Amount you want to bet (RM): ";
    cin >> bet;
    
    if (option == 1) {
        cout << "Which two racers do you want (X, T, S): ";
        cin >> racer1 >> racer2;
    } else if (option == 2) {
        cout << "Which racer do you want (X, T, S): ";
        cin >> racer1;
    }



    for (int round = 1; round <= race_rounds; ++round)
    {
        // Reset positions for each new round
        xwing_position = 0;
        tiefighter_position = 0;
        soullessone_position = 0;
        turn_of_race = 1;

        // Display initial track for each round
        cout << "\nRound " << round << endl;

        // Set track length based on the selected track
        switch (tracksec) {
            case 1:
                endpoint = 49;
                break;
            case 2:
                endpoint = 42;
                break;
            case 3:
                endpoint = 74;
                break;
        }

        // Display initial track based on selected or random track
        switch (tracksec) {
            case 1:
                display_track1(xwing_position, tiefighter_position, soullessone_position);
                break;
            case 2:
                display_track2(xwing_position, tiefighter_position, soullessone_position);
                break;
            case 3:
                display_track3(xwing_position, tiefighter_position, soullessone_position);
                break;
        }

        while (true)
        {
            // Increment turn of the race
            turn_of_race++;

            // Generate random steps for the racers in each iteration
            int xwing_Steps = generateRandomSteps(xwing_SpeedMin, xwing_SpeedMax);
            int tiefighter_Steps = generateRandomSteps(tiefighter_SpeedMin, tiefighter_SpeedMax);
            int soullessone_Steps = generateRandomSteps(soullessone_SpeedMin, soullessone_SpeedMax);

            // Move each racer forward randomly
            xwing_position += xwing_Steps;
            tiefighter_position += tiefighter_Steps;
            soullessone_position += soullessone_Steps;

            // Display turn of the race
            cout << "Turn " << turn_of_race << endl << endl;

            // Mention number of steps each racer moved
            cout << "X Wing moved " << xwing_Steps << " steps" << endl;
            cout << "Tie Fighter moved " << tiefighter_Steps << " steps" << endl;
            cout << "Soulless One moved " << soullessone_Steps << " steps" << endl;

            // Apply bridges
            bool bridge_used1 = apply_bridge(xwing_position, bridges);
            bool bridge_used2 = apply_bridge(tiefighter_position, bridges);
            bool bridge_used3 = apply_bridge(soullessone_position, bridges);

            if (bridge_used1) {
                cout << "Racer x used a bridge!" << endl;
            }
            if (bridge_used2) {
                cout << "Racer y used a bridge!" << endl;
            }
            if (bridge_used3) {
                cout << "Racer z used a bridge!" << endl;
            }

            // Display updated track based on the current track for the round
            switch (tracksec) {
                case 1:
                    display_track1(xwing_position, tiefighter_position, soullessone_position);
                    break;
                case 2:
                    display_track2(xwing_position, tiefighter_position, soullessone_position);
                    break;
                case 3:
                    display_track3(xwing_position, tiefighter_position, soullessone_position);
                    break;
            }

            // Check if any racer has reached the end of the track
            if (xwing_position >= endpoint && tiefighter_position >= endpoint && soullessone_position >= endpoint)
            {
                cout << "It's a tie for this round!\n" << endl;
                break; // Exit the loop for this round
            }
            else if (xwing_position >= endpoint)
            {
                cout << "X Wing wins the race for this round!\n" << endl;
                xw++;
                break; // Exit the loop for this round
            }
            else if (tiefighter_position >= endpoint)
            {
                cout << "Tie Fighter wins the race for this round!\n" << endl;
                tw++;
                break; // Exit the loop for this round
            }
            else if (soullessone_position >= endpoint)
            {
                cout << "Soulless One wins the race for this round!\n" << endl;
                sw++;
                break; // Exit the loop for this round
            }

            // Pause before next iteration
            this_thread::sleep_for(milliseconds(PAUSE_DURATION_MS));
        }
    }

    cout << "Game Over" << endl;
    cout << "\nThe score is:";
    cout << "\nxwing:" << xw << "\ntiefigther:" << tw << "\nsoullessone:" << sw;

    // Calculate and display the result of the bet
    bool bet_won = false;

    auto is_winner = [](const std::string& racer, int wins) {
        return wins > 0; // Simplified condition to check if the racer has won
    };

    if (option == 1) {
        if ((racer1 == "X" && (xw > tw) && (xw > sw)) || ((racer1 == "T" && (tw > xw) && (tw > sw)) || (racer1 == "S" && (sw > tw) && (sw > xw)))) {
            bet_won = true;
            cout << "\nYou won the bet Your reward is: RM" << bet * 1.5 << endl;
        } else if ((racer2 == "X" && (xw > tw) && (xw > sw)) || ((racer2 == "T" && (tw > xw) && (tw > sw)) || (racer2 == "S" && (sw > tw) && (sw > xw)))) {
            bet_won = true;
            cout << "\nYou won the bet Your reward is: RM" << bet * 1.5 << endl;
        } else {
            cout << "\nYou lost the bet!" << endl;
        }
    } else if (option == 2) {
        if ((racer1 == "X" && (xw > tw) && (xw > sw)) || ((racer1 == "T" && (tw > xw) && (tw > sw)) || (racer1 == "S" && (sw > tw) && (sw > xw)))) {
            bet_won = true;
            cout << "\nYou won the bet Your reward is: RM" << bet * 2 << endl;
        } else {
            cout << "\nYou lost the bet!" << endl;
        }
    }

    // Display the list of bridges
    cout << "Bridges:" << endl;
    for (int i = 0; i < bridges.size(); ++i) {
        cout << "Bridge " << i + 1 << ": Start = " << bridges[i].start << ", End = " << bridges[i].end << endl;
    }
    
    return 0;
}
