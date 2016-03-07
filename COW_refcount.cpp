#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class String
{
public:

	String()
	{
		_length = 0;
		_string = NULL;
		_refcount = 1;
	}

	String(const char* str)
	{
		_length = strlen(str);
		_string = new char[_length];
		_refcount = 1;

		strcpy_s(_string, strlen(str) + 1, str);
	}

	String(const String& str)
	{
		_length = str._length;
		_string = new char[_length];
		_refcount += 1;

		strcpy_s(_string, strlen(str._string) + 1, str._string);
	}

	char charAt(int index) const
	{
		return _string[index];
	}

	int length() const
	{
		return _length;
	}

	void print(char* str)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			cout << str[i];
		}
		cout << endl;
	}

	void print()
	{
		for (int i = 0; i < _length; i++){
			cout << _string[i];
		}
		cout << endl;
	}

	void reserve(int charLength)
	{
		char* temp = new char[_length];
		strcpy_s(temp, strlen(_string) + 1, _string);

		_string = new char[_length + charLength];
		strcpy_s(_string, strlen(temp) + 1, temp);
		_length += charLength;
	}

	void append(char c)
	{
		reserve(1);
		_string[_length - 1] = c;
		_string[_length] = '\0';
	}

	~String()
	{
		_refcount -= 1;
		if (_refcount == 0)
		{
			if (_string != NULL)
			{
				delete[] _string;
				_string = NULL;
			}
		}
	}

private:

	int _length;
	static int _refcount;
	char* _string;
};

int String::_refcount = 0;

int main(int argc, char *argv[])
{
	String string("Testing..........");
	cout << endl;
	string.append('a');
	cout << endl;
	string.append('b');
	cout << endl;
	string.append('c');
	cout << endl;
	string.print();

	return 0;
}