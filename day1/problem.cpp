#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    if (!input) {
        cerr << "Cannot open file" << endl;
    }

    int num;
    vector<int> nums;
    
    int total = 0;

    for (int i = 0; input >> num; i ++) {
        nums.push_back(num);
        if (i >= 3) {
            if (nums[i] > nums[i-3]) {
                total ++;
            }
        }
    }
    cout << total << endl;
}
