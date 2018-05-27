// anarkid.cpp
//

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// 1. compute MFCC of target
// 2. read text file for data in memory filename + coefficients
// 3. chromosome is sequence of random numbers from 1 to n files
// 4. mutation is +-r integer
// 5. evaluation is = some of corresponding envelopes and distance with target
// -- N instruments in solution if given, no choice for other params

int main (int argc, char* argv[]) {
    try {


    } catch (exception& e) {
        cout << "Error: " << e.what () << endl;
    } catch (...) {
        cout << "Fatal error: unknown exception" << endl;
    }
    return 0;
}

// EOF

