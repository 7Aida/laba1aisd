#include "Setnew.h"
#include <iostream>
using namespace std;
void tester1()
{
	int maxsize = 50;
	int size = 10;
	int* data;
	data = new int[size];
	//Setnew m3;
	data[0] = 1;
	data[1] = 2;
	data[2] = 2;
	data[3] = 3;
	data[4] = 0;
	data[5] = 4;
	data[6] = 5;
	data[7] = 5;
	data[8] = 6;
	data[9] = 6;
	Setnew m1(data, size, maxsize);
	data[0] = 3;
	data[1] = 4;
	data[2] = 5;
	data[3] = 6;
	data[4] = 7;
	data[5] = 5;
	data[6] = 8;
	data[7] = 8;
	data[8] = 8;
	data[9] = 8;
	Setnew m2(data, size,maxsize);
	
	cout << "1:" << m1 << endl;
	cout << "2:" << m2 << endl;
	cout << "1(2):" << m1(2) << endl;
	cout<<"m1/3:" << m1/6 << endl;
	cout <<"1 + 2:"<<m1 + m2 << endl;
	cout <<"1 - 2:"<< m1 - m2 << endl;
	cout <<"1 * 2:"<< m1 * m2 << endl;
	cout << "m1%3:" << m1 % 1 << endl;
    Setnew m3(0,0,0);
	cout << "1:" << m1 << endl;
	cout << "3:" << m3 << endl;
	cout << "1 + 3:" << m1 + m3 << endl;
	cout << "3 - 1:" << m3 - m1 << endl;
	cout << "1 - 3:" << m1 - m3 << endl;
	cout << "1 * 3:" << m1 * m3 << endl;
}
int main()
{
	tester1();
	
	return 0;
}
