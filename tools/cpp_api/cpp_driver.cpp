// cpp_driver.cpp
// 

#include <stdexcept>
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
	try {
		cout << "[orchidea, ver. " << ORCHIDEA_VERSION_MAJOR << "." << 
		ORCHIDEA_VERSION_MINOR << "]" << endl << endl;
		cout << "C++ API test driver" << endl;
		cout << "(c) 2018, www.carminecella.com" << endl << endl;	

	}
	catch (exception& e) {
		cout << "Error: " << e.what () << endl;
	}
	catch (...) {
		cout << "Fatal error: unknown exception" << endl;
	}
	return 0;
}

// EOF

