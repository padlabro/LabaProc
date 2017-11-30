#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "gtest/gtest.h"
#include "Test.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start" << endl;

	container c;
	Init(c);

	In(c, ifst);
	
	int k1 = 10;
	int k = 10;
	while (k != 0) {

		cout << "Input number:" << endl;
		cout << "1 - Out container" << endl;
		cout << "2 - Sort and out container" << endl;
		cout << "3 - Out only fish" << endl;
		cout << "4 - Out only birf" << endl;
		cout << "5 - Out only beast" << endl;
		cout << "6 - Multimethod" << endl;
		cout << "7 - Clear and out container" << endl;
		cout << "0 - exit" << endl;
		cin >> k;
		if (cout.fail())
		{
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (k < 0 || k > 7) {
			cout << "Incorrect choice! Try again!" << endl;
			continue;
		}
		else {
			switch (k)
			{
			case 1:
				Out(c, ofst);
				break;
			case 2:
				cout << "Input number:" << endl;
				cout << "0 - from small to big" << endl;
				cout << "1 - from big to small" << endl;
				while (k1 != 0 || k1 != 1)
				{
					cin >> k1;
					if (cout.fail())
					{
						cout << "Wrong input!" << endl;
						exit(1);
					}
					if (k1 != 0 || k1 != 1)
					{
						cout << "Incorrect choice! Try again!" << endl;
						continue;
					}
				}
				switch (k1)
				{
				case 0:
					Sort(c, 0);
					break;
				case 1:
					Sort(c, 1);
					break;
				default:
					break;
				}
				Out(c, ofst);
				break;
			case 3:
				OutFish(c, ofst);
				break;
			case 4:
				OutBird(c, ofst);
				break;
			case 5:
				OutBeast(c, ofst);
				break;
			case 6:
				Multimethod(c, ofst);
				break;
			case 7:
				Clear(c);
				Out(c, ofst);
				break;
			default:
				break;
			}
		}
	}

	cout << "Stop" << endl;

	ifst.close();
	ofst.close();
	return 0;
	/*::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}