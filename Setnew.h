#pragma once
#include <iostream>
class Setnew
{
private:
	int* _data;
	int _size;
	int _maxsize;
public:
	Setnew() :_size(0), _maxsize(0), _data(new int[0]) {};
	Setnew(int* _data, int _size, int _maxsize);
	Setnew(const Setnew& rhs);
	int get_size() const;
	int get_maxsize() const;
	~Setnew()
	{
		delete[] _data;
	}
	int& operator()(int size);
	Setnew operator-(Setnew&);
	Setnew operator*(Setnew&);
	Setnew operator+(Setnew&);
	Setnew operator%(int);
	Setnew operator/(int);
	friend std::ostream& operator<<(std::ostream& s, const Setnew& o);
};
