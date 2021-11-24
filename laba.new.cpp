#include "Setnew.h"
#include <iostream>
#include <stdexcept>
using namespace std;


template<class T>
void EXPECT_EQ(const T& a, const T& b, const char*msg)
{
	if (a != b)
		throw exception(msg);
}

void tester1()
{
	Set m1;
	cout << " m1:" << m1  << endl;
	m1 += 4;
	m1 += 3;
	m1 += 3;
	cout << " m1:" << m1 << "\n" << endl;
	EXPECT_EQ(m1.get_size(),2,"expect set size = 2");
	EXPECT_EQ(m1(0), 4, "expect first set elem = 4");
	EXPECT_EQ(m1(0), 4, "expect second set elem = 4");

}

void tester2()
{
	int *a= new int [3];
	a[0] = 1; 
	a[1] = 2; 
    Set m1(a,2,5);
	a[0] = 2;
	a[1] = 3;
	Set m2(a, 2, 5);
	Set m3 = m1 + m2;
	cout << " m1:" << m1 << endl;
	cout << " m2:" << m2 << endl;
	cout << " m3=m1+m2:" << m3 << "\n" << endl;
	EXPECT_EQ(m3.get_size(), 3, "expect set size = 3");
	EXPECT_EQ(m3(0), 1, "expect first set elem = 1");
	EXPECT_EQ(m3(1), 2, "expect second set elem = 2");
	EXPECT_EQ(m3(2), 3, "expect3 set elem = 3");

}

void tester3()
{
	int* a = new int[3];
	a[0] = 1;
	a[1] = 2;
	a[2] = 1;
	Set m1(a, 3, 5);
	Set m2 = m1;
	cout << " m1:" << m1 << endl;
	cout << " m2:" << m2 << "\n" << endl;
	EXPECT_EQ(m2.get_size(), 2, "expect set size = 2");
	EXPECT_EQ(m2(0), 1, "expect first set elem = 1");
	EXPECT_EQ(m2(1), 2, "expect second set elem = 2");
}
void tester4()
{
	int* a = new int[5];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	Set m1(a, 5, 10);
	cout << " m1:" << m1 << endl;
	m1 -= 3;
	cout << " m1:" << m1 << "\n" << endl;
	EXPECT_EQ(m1.get_size(), 4, "expect set size = 4");
}

void tester5()
{
	int* a = new int[3];
	a[0] = 1;
	a[1] = 2;
	Set m1(a, 2, 5);
	a[0] = 2;
	a[1] = 3;
	Set m2(a, 2, 5);
	Set m3 = m1 - m2;
	cout << " m1:" << m1 << endl;
	cout << " m2:" << m2 << endl;
	cout << " m3=m1-m2:" << m3 << "\n" << endl;
	EXPECT_EQ(m3.get_size(), 1, "expect set size = 1");
	EXPECT_EQ(m3(0), 1, "expect first set elem 1");
}

void tester6()
{
	int* a = new int[3];
	a[0] = 1;
	a[1] = 2;
	Set m1(a, 2, 5);
	a[0] = 2;
	a[1] = 3;
	Set m2(a, 2, 5);
	Set m3 = m1 * m2;
	cout << " m1:" << m1 << endl;
	cout << " m2:" << m2 << endl;
	cout << " m3=m1*m2:" << m3 << "\n" << endl;
	EXPECT_EQ(m3.get_size(), 1, "expect set size = 1");
	EXPECT_EQ(m3(0), 2, "expect first set elem 2");
}

int main()
{
	try 
	{
		tester1();
		cout << "ok" << "\n__________\n" << endl;
		tester2();
		cout << "ok" << "\n__________\n" << endl;
		tester3();
		cout << "ok" << "\n__________\n" << endl;
		tester4();
		cout << "ok" << "\n__________\n" << endl;
		tester5();
		cout << "ok" << "\n__________\n" << endl;
		tester6();
		cout << "ok" << "\n__________\n" << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	};
	return 0;
}
