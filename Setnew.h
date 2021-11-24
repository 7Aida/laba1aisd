#pragma once
#include <iostream>
class Set
{
private:
	int _size;
    int _maxsize;
	int* _data;
public:
	Set() :_size(0), _maxsize(0), _data(new int[_maxsize]) {};
	Set(int* _data, int _size, int _maxsize);
	Set(const Set& rhs);
	int get_size() const;
	int get_maxsize() const;
	~Set()
	{
		delete[] _data;
	}
	int& operator()(int size);
	Set operator-(const Set&);
	Set operator*(const Set&);
	Set operator+(const Set&);
	void operator+=(int);
	void operator-=(int);
	Set& operator=(const Set&);
	friend std::ostream& operator<<(std::ostream& s, const Set& o);
};
