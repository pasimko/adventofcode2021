#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

// I think this problem calls for binary trees, but I'll stick with my current implementation. 
// I'll be curious to see what my solutions look like next year, after having taken
// some actual CS :)

using namespace std;

// Sum the bits in the nth position of a list of sequences.
int countBits(vector<int> sequences, int place) {
    int bitCounts = 0;

    for (int i = 0; i < sequences.size(); i ++) {
        // The remainder of a bitshifted int tells us whether that place is a 1 or 0
        bitCounts += (sequences[i] >> place) & 1;
    }
    return bitCounts;
}

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    if (!input) {
        cerr << "Could not open file" << endl;
        return 1;
    }
    string sequence;
    vector<int> sequences; // Will hold the input file line by line

    int oxygenBitCount;
    int co2BitCount;
    vector<int> oxygenSequences;
    vector<int> co2Sequences;

    int bits;
    int mostRecent;

    // Read in da file, convert binary string sequence to int
    while (input >> sequence) {
        sequences.push_back(stoi(sequence, 0, 2));
    }
    // Couldn't find a succinct solution in <5 min to finding the leftmost changed bit
    // of a number. So we're just gonna use the string length :)
    bits = sequence.length(); 

    oxygenSequences = sequences;
    co2Sequences = sequences;


    /* We now have a copy of the input to use for both oxygen and CO2. We also have
     * recorded the amount of bits in the input sequences.
     * Now we must iterate through the vectors containing the input, pruning it as we go.
     */


    /* I could mash these loops together by replacing mostRecent with ~mostRecent for co2.
     * They might not require the same iterations, so it would be a bit awkward. I think
     * this way is fine.
    */

    for (int i = 0; oxygenSequences.size() > 1; i ++) {     // Iterate through sequences until only one matches criteria
        vector<int> tempOxygenSequences;
        oxygenBitCount = countBits(oxygenSequences, bits-i-1); // Extra -1 because our places start at 0

        mostRecent = oxygenBitCount >= oxygenSequences.size()*0.5 ? 1 : 0; // Set to most common bit. Default to 1.

        for (int j = 0; j < oxygenSequences.size(); j ++) { // Prune the sequences
            if ((oxygenSequences[j] >> (bits-i-1) & 1) == mostRecent) {
                tempOxygenSequences.push_back(oxygenSequences[j]);
            }
        }
        oxygenSequences = tempOxygenSequences;
    }
    for (int i = 0; co2Sequences.size() > 1; i ++) {     // Iterate through sequences until only one matches criteria
        vector<int> tempCo2Sequences;
        co2BitCount = countBits(co2Sequences, bits-i-1); // Extra -1 because our places start at 0

        mostRecent = co2BitCount < co2Sequences.size()*0.5 ? 1 : 0; // We want the opposite of oxygen for co2
        for (int j = 0; j < co2Sequences.size(); j ++) { // Prune the sequences
            if ((co2Sequences[j] >> (bits-i-1) & 1) == mostRecent) {
                tempCo2Sequences.push_back(co2Sequences[j]);
            }
        }
        co2Sequences = tempCo2Sequences;
    }

    cout << (oxygenSequences[0]*co2Sequences[0]) << endl;

    return 0;
}
