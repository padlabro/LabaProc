#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "gtest/gtest.h"
#include "Test.h"

using namespace std;

int main(int argc, char* argv[]) {

	if (argc != 3) {
		cout << "incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start" << endl;

	container c;
	Init(c);

	In(c, ifst);
	ofst << "Filled container. " << endl;
	Sort(c);
	Out(c, ofst);
	cout << "Stop" << endl;
	
	ifst.close();
	ofst.close();
	return 0;
	/*::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}