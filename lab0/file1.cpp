//Nick Krisulevicz
//file1.cpp
//demo file for cosc220 lab 1
//02/03/2022

#include <iostream>
#include "file2.h"
using namespace std;

int main(){
	int i = 3;
	int sq;
	sq = squareIt(i);
	cout << "Square of " << i << " is " << sq << endl;
	return 0;
}
