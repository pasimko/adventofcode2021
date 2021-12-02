#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) 
{
    ifstream input(argv[1]);

    if (!input) {
        cerr << "Couldn't open file" << endl;
    }

    string direction; // Should be forward, up, or down
    int steps;

    int depth = 0;
    int horizontalPos = 0;
    int aim = 0;

    while (input >> direction >> steps) { // Read da file
        if (direction == "forward") {
            horizontalPos += steps;
            depth += aim*steps;
        }
        if (direction == "down") {
            aim += steps;
        }
        if (direction == "up") {
            aim -= steps;
        }
    }

    cout << depth*horizontalPos << endl;

    return 0;
}
