#include "SoundexEncoder.h"
#include <iostream>
using namespace std;

int main(const int argc, char** argv) {
	const soundex::SoundexEncoder soundexEncoder;
	if(argc == 1)
	{
		cout << "No args passed" << endl;
		return 1;
	}
	const auto encoded = soundexEncoder.encode((argv[1]));
	cout << encoded << endl;
	return 0;
}