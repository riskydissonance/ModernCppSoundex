#include "Soundex.h"
#include <iostream>
using namespace std;

int main(const int argc, char** argv) {
	const Soundex soundex;
	if(argc == 1)
	{
		cout << "No args passed" << endl;
		return 1;
	}
	const auto soundexed = soundex.encode((argv[1]));
	cout << soundexed << endl;
	return 0;
}