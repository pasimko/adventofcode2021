/**
 * Input:   File with integer values separated by newlines
 * Output:  Number of three-measurement sliding window sums that are greater than the 
 *          previous window.
*/


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    // Read input file
    ifstream input(argv[1]);
    if (!input) {
        cerr << "Cannot open file" << endl;
    }

    int num;
    vector<int> nums;
    
    int total = 0;

    for (int i = 0; input >> num; i ++) {
        nums.push_back(num);
        // The first window has nothing to compare to, so skip it
        if (i >= 3) {
            // The difference of two windows is equal to the lastmost and firstmost indices
            if (nums[i] > nums[i-3]) {
                total ++;
            }
        }
    }
    cout << total << endl;
}
