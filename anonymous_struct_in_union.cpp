#include <iostream>

union test
{
	struct
	{
		char a;
		char b;
		char c;
		char d;
	};

	struct
	{
		int x;
	};

	float y;
};

int main()
{
	using namespace std;

	test x = {};

	x.x = 10;

	cout << "Values: " << (short)x.a << " " << (short)x.b << " " << (short)x.c << " " << (short)x.d << endl;
	cout << "X: " << x.x << ", Y: " << x.y;

	return 0;
}