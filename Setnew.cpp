#include "Setnew.h"
std::ostream& operator<<(std::ostream& s, const Set& o)
{
	s << "(";
	for (int i = 0; i < o._size; i++)
	{
		s << o._data[i];
		if (i != o._size - 1) s << ';';
	}
	s << ')';
	return s;
}

int Set::get_size() const
{
	return _size;
}

int Set::get_maxsize() const
{
	return _maxsize;
}

Set::Set(int* _data, int _size, int _maxsize)
{
	int a = 0;
	for (int i = 0; i < _size; ++i)
	{
		int k = i + 1;
		for (k; k < _size; ++k)
		{
			if (_data[i] == _data[k])
			{
				_data[k] = NULL;
			}
		}
	}
	for (int i = 0; i < _size; i++)
	{
		for (int e = i + 1; e < _size; e++)
		{
			if (_data[i] == NULL)
			{

				if (_data[e] != NULL)
				{
					_data[i] = _data[e];
					_data[e] = NULL;
				}
			}
		}
	}
	a = 0;
	for (int i = 0; i < _size; i++)
	{
		if (_data[i] == NULL)
		{
			a++;
		}
	}
	this->_maxsize = _maxsize;
	this->_size = _size - a;
	this->_data = new int[_maxsize];

	for (int i = 0; i < _maxsize; i++)
	{
		if (i >= _size)
			this->_data[i] = NULL;
		else
			this->_data[i] = _data[i];

	}
}

Set::Set(const Set& rhs)
{
	this->_size = rhs._size;
	this->_maxsize = rhs._maxsize;
	this->_data = new int[rhs._maxsize];
	for (int i = 0; i < _maxsize; i++)
	{
		this->_data[i] = rhs._data[i];
	}
}

int& Set::operator() (int col)
{
	if (col >= _size || col < 0)
		throw"incorrect size";
	return _data[col];
}

Set Set::operator+(const Set& obj2)
{
	Set obj3;
	for (int i = 0; i < _size; ++i)
	{
	    obj3+= _data[i];
	}
	for (int i = 0; i < obj2._size; ++i)
	{
		obj3 += obj2._data[i];
	}
	return obj3;
}

Set Set::operator-(const Set& obj2)
{
	Set obj4;
	for (int i = 0; i < _size; ++i)
	{
		obj4 += _data[i];
	}
	for (int i = 0; i < obj2._size; ++i)
	{
		obj4 -= obj2._data[i];
	}
	return obj4;
	
}

Set Set::operator*(const Set& obj2)
{
	Set obj5;
	for (int i = 0, c = 0; i < _size; ++i)
	{
		for (int j = 0; j < obj2._size; ++j)
		{
			if (_data[i] == obj2._data[j])
			{
				obj5 += _data[i];
			}
		}
	}
	return obj5;
}

void Set::operator-=(int term)
{
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] == term)
		{
			for (i; i < _size; ++i)
			{
				_data[i] = _data[i + 1];
				if (i == _size - 1)
				{
					_data[i] = NULL;
					_size--;
				}
			}
		}
	}
}

void  Set::operator+=(int elem)
{
	
	bool exists = false;
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] == elem)
		{
			exists = true;
			break;
		}
	}
	if (!exists)
	{
		int* tmp = new int[_size + 1];
		for (int i = 0; i < _size; i++) 
		{ 
			tmp[i] = _data[i];
		}
		tmp[_size] = elem;
		delete[] _data;
		_data = tmp;
		++_size;
		++_maxsize;
	}
}

Set& Set::operator=(const Set& a)
{
	_maxsize = a._maxsize;
	_size = a._size;
	_data = new int[_size];
	for (int i = 0; i < _size; i++)
	{
		_data[i] = a._data[i];
	}
	return *this;
}