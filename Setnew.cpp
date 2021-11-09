#include "Setnew.h"
std::ostream& operator<<(std::ostream& s, const Setnew& o)
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
int Setnew::get_size() const
{
	return _size;
}
int Setnew::get_maxsize() const
{
	return _maxsize;
}
//Setnew::Setnew()
//{
//	/*_maxsize = 10;
//	_size = 0;
//	_data ;*/
//	this->_size = 1;
//	this->_maxsize = 10;
//	this->_data = new int[_maxsize];
//	for (int i = 1; i < _maxsize; i++)
//	{
//			this->_data[0] = 1;
//			this->_data[i] = NULL;
//
//	}
//};
Setnew::Setnew(int* _data, int _size, int _maxsize)
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

Setnew::Setnew(const Setnew& rhs)
{
	this->_size = rhs._size;
	this->_maxsize = rhs._maxsize;
	this->_data = new int[rhs._maxsize];
	for (int i = 0; i < _maxsize; i++)
	{
		this->_data[i] = rhs._data[i];
	}
}

int& Setnew::operator() (int col)
{
	if (col >= _size || col < 0)
		throw"incorrect size";
	return _data[col];
}
Setnew Setnew::operator+(Setnew& obj2)
{
	int* m = new int[_size + obj2._size];
	int t = 0;
	for (int i = 0; i < _size; ++i)
	{
		{
			m[t] = _data[i];
			t++;
		}
	}
	for (int i = 0; i < obj2._size; ++i)
	{
		{
			m[t] = obj2._data[i];
			t++;
		}
	}Setnew obj3(m, _size + obj2._size, _maxsize + obj2._maxsize);

	return obj3;
}
Setnew Setnew::operator-(Setnew& obj2)
{
	int* n = new int[_size];
	int c = 0;
	if (obj2._size == 0)
	{
		for (int i = 0; i < _size; i++)
		{
			n[i] = _data[i];
		}

	}
	else 
	{
		for (int i = 0; i < _size; i++)
		{
			int t = 0;
			for (int j = 0; j < obj2._size; j++)
			{
				if (_data[i] != obj2._data[j])
				{
					t++;
					if (t == obj2._size)
					{
						n[c] = _data[i];
						c++;
					}
				}
			}
		}

		for (c; c < _size; c++)
		{
			n[c] = NULL;
		}
	}

	Setnew obj4(n, _size, _maxsize);
	return obj4;
}

Setnew Setnew::operator*(Setnew& obj2)
{
	int* n = new int[_size];
	int t = 0;

	for (int i = 0, c = 0; i < _size; ++i)
	{
		for (int j = 0; j < obj2._size; ++j)
		{
			if (_data[i] == obj2._data[j])
			{
				if (c > _size)
					return *this;
				n[c] = _data[i];
				t++;

				c++;
			}
		}
	}

	for (t; t < _size; t++)
	{
		n[t] = NULL;
	}


	Setnew obj5(n, _size, _maxsize);
	return obj5;
}
Setnew Setnew:: operator/(int term)
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
	return *this;
}
Setnew Setnew:: operator%(int elem)
{
	int a = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] == elem)
		{
			++a;
			break;
		}
	}
	if (a == 0)
	{
		_data[_size] = elem;
		++_size;
	}
	return *this;
}