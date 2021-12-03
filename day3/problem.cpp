#include <iostream>
#include <fstream>
#include <cmath>

#define SIZE 12

using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    if (!input) {
        cerr << "Could not open file" << endl;
    }
    string sequence;

    int count = 0;
    int bitCounts[SIZE] {0};

    int gamma = 0;
    int epsilon = 0;

    while (input >> sequence) {
        for (int i = 0; i < SIZE; i ++) {
            bitCounts[i] += sequence[i] - 48; // Convert char to int
        }
        count ++;
    }
    for (int i = 0; i < SIZE; i ++) {
        if (bitCounts[i] > count/2) {
            gamma += pow(2, SIZE-i-1);
        }
        else {
            epsilon += pow(2, SIZE-i-1);
        }
    }

    cout << gamma*epsilon << endl;

    return 0;
}
