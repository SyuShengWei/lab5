
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class HugeInt {
	friend istream & operator >>(istream & in,HugeInt &a);
	friend ostream & operator <<(ostream & out,HugeInt &a);

public:
	HugeInt();
	HugeInt(int inInt);
	HugeInt(const char* inChar);
	~HugeInt();
	HugeInt operator - (const HugeInt & a );
	HugeInt operator + (const HugeInt & a );
	HugeInt &operator = (const HugeInt& a);
	

	int theNum[256];
	//theNum store the number from small to big digit
	
};
