#include <iostream>
#include <ctime> // For generating random numbers
#include <chrono> // For pause between iterations
#include <thread> // For pause function
#include <iomanip> // For list of bets
#include <vector> // For storing bridges

using namespace std::chrono;
using namespace std;

class Racer {
public:
    string name;
    char symbol;
    int position;
    int speedMin;
    int speedMax;
    int wins;

    Racer(string name, char symbol, int speedMin, int speedMax) 
        : name(name), symbol(symbol), position(0), speedMin(speedMin), speedMax(speedMax), wins(0) {}

    void reset_position() {
        position = 0;
    }

    void move() {
        int steps = rand() % (speedMax - speedMin + 1) + speedMin;
        position += steps;
        cout << name << " moved " << steps << " steps" << endl;
    }
};

class Race {
private:
    vector<Racer> racers;
    const int width = 45;
    const int height = 17;
    const int PAUSE_DURATION_MS = 1000; // Pause duration in milliseconds (1 second)
    int race_rounds;

public:
    Race(int race_rounds) : race_rounds(race_rounds) {}

    void add_racer(const Racer& racer) {
        racers.push_back(racer);
    }

    void display_track() {
        char track[height][width];
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

        // Assign racer symbols
        int base_column = 1; // Define the base starting column
        for (int i = 0; i < racers.size(); ++i) {
            int pos = racers[i].position;
            char symbol = racers[i].symbol;
            int start_col = base_column + i; // Adjust starting column based on racer index

            // Adjust position to avoid overlap for each racer
            switch (pos) {
                case 0: track[height - 2][start_col] = symbol; break;
                case 1: track[height - 4][start_col] = symbol; break;
                case 2: track[height - 6][start_col] = symbol; break;
                case 3: track[height - 6][start_col + 4] = symbol; break;
                case 4: track[height - 6][start_col + 8] = symbol; break;
                case 5: track[height - 6][start_col + 12] = symbol; break;
                case 6: track[height - 6][start_col + 16] = symbol; break;
                case 7: track[height - 6][start_col + 20] = symbol; break;
                case 8: track[height - 8][start_col + 20] = symbol; break;
                case 9: track[height - 10][start_col + 20] = symbol; break;
                case 10: track[height - 12][start_col + 20] = symbol; break;
                case 11: track[height - 12][start_col + 16] = symbol; break;
                case 12: track[height - 12][start_col + 12] = symbol; break;
                case 13: track[height - 10][start_col + 12] = symbol; break;
                case 14: track[height - 10][start_col + 8] = symbol; break;
                case 15: track[height - 10][start_col + 4] = symbol; break;
                case 16: track[height - 12][start_col + 4] = symbol; break;
                case 17: track[height - 14][start_col + 4] = symbol; break;
                case 18: track[1][start_col + 4] = symbol; break;
                case 19: track[1][start_col + 8] = symbol; break;
                case 20: track[1][start_col + 12] = symbol; break;
                case 21: track[1][start_col + 16] = symbol; break;
                case 22: track[1][start_col + 20] = symbol; break;
                case 23: track[1][start_col + 24] = symbol; break;
                case 24: track[1][start_col + 28] = symbol; break;
                case 25: track[1][start_col + 32] = symbol; break;
                case 26: track[1][start_col + 36] = symbol; break;
                case 27: track[1][start_col + 40] = symbol; break;
                case 28: track[height - 14][start_col + 40] = symbol; break;
                case 29: track[height - 12][start_col + 40] = symbol; break;
                case 30: track[height - 12][start_col + 36] = symbol; break;
                case 31: track[height - 12][start_col + 32] = symbol; break;
                case 32: track[height - 12][start_col + 28] = symbol; break;
                case 33: track[height - 10][start_col + 28] = symbol; break;
                case 34: track[height - 8][start_col + 28] = symbol; break;
                case 35: track[height - 8][start_col + 32] = symbol; break;
                case 36: track[height - 8][start_col + 36] = symbol; break;
                case 37: track[height - 6][start_col + 36] = symbol; break;
                case 38: track[height - 4][start_col + 36] = symbol; break;
                case 39: track[height - 2][start_col + 36] = symbol; break;
                case 40: track[height - 2][start_col + 32] = symbol; break;
                case 41: track[height - 2][start_col + 28] = symbol; break;
                case 42: track[height - 2][start_col + 24] = symbol; break;
                case 43: track[height - 2][start_col + 20] = symbol; break;
                case 44: track[height - 2][start_col + 16] = symbol; break;
                case 45: track[height - 2][start_col + 12] = symbol; break;
                case 46: track[height - 2][start_col + 8] = symbol; break;
                case 47: track[height - 2][start_col + 4] = symbol; break;
                case 48: track[height - 2][start_col] = symbol; break;
                default: track[height - 2][start_col] = symbol; break;
            }
        }
        
        // Display the track
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++)
                cout << track[i][j];
            cout << endl;
        }
        cout << endl;
    }

    void start() {
        for (int round = 1; round <= race_rounds; ++round) {
            // Reset positions for each new round
            for (auto& racer : racers) {
                racer.reset_position();
            }

            // Display initial track for each round
            cout << "\nRound " << round << endl;

            display_track();

            int turn_of_race = 1;

            while (true) {
                // Increment turn of the race
                turn_of_race++;

                // Move each racer forward randomly
                for (auto& racer : racers) {
                    racer.move();
                }

                display_track();

                // Check if any racer has reached the end of the track
                bool any_winner = false;
                for (auto& racer : racers) {
                    if (racer.position >= 49) {
                        cout << racer.name << " wins the race for this round!\n" << endl;
                        racer.wins++;
                        any_winner = true;
                    }
                }

                if (any_winner) break;

                // Pause before next iteration
                this_thread::sleep_for(milliseconds(PAUSE_DURATION_MS));
            }
        }

        cout << "Game Over" << endl;
        cout << "\nThe score is:" << endl;
        for (const auto& racer : racers) {
            cout << racer.name << ": " << racer.wins << " wins" << endl;
        }
    }
};

int main() {
    srand(time(0)); // Seed for random number generation

    int race_rounds;
    cout << "Enter number of rounds for the race: ";
    cin >> race_rounds;

    Race race(race_rounds);

    race.add_racer(Racer("X Wing", 'X', 2, 4));
    race.add_racer(Racer("Tie Fighter", 'T', 1, 5));
    race.add_racer(Racer("Soulless One", 'S', 3, 6));

    race.start();

    return 0;
}
