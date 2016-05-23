#pragma once

class MyString
{
public:
	MyString(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	MyString(const MyString& s)
		:_str(NULL)
	{
		MyString tmp(s._str);
		swap(tmp._str, _str);
	}
	/*
	MyString(const MyString& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	*/

	MyString& operator =(MyString s)
	{
		if (_str != s._str)
		{
			swap(s._str, _str);
		}
		return *this;
	}
	/*
	MyString& operator=(MyString& s)
	{
		if (_str != s._str)
		{
			char* tmp = new char[strlen(s._str) + 1];
			if (tmp)
			{
				delete[] _str;
				_str = tmp;
				strcpy(_str, s._str);
			}
		}
		return *this;
	}
	*/

	~MyString()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

	friend ostream& operator <<(ostream& os, MyString& s);
protected:
	char* _str;
};

ostream& operator <<(ostream& os, MyString& s)
{
	os << s._str << endl;
	return os;
}