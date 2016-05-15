#include "HugeInt.h"

HugeInt :: ~HugeInt(){
	//for (int i = 0 ; i < 256 ; i++)
	//	cout<<theNum[i];
	
//	cout<<endl;
//	cout<<endl;
}

HugeInt :: HugeInt(){
	for(int i = 0 ; i < 256 ; ++i)
		theNum[i] = 0;
}

HugeInt :: HugeInt (int inInt){
	for(int i = 0 ; i < 256 ; ++i)
		theNum[i] = 0;
	for (int i = 0 ; inInt != 0 ; i ++){
		theNum[i] = inInt % 10 ;
		inInt = inInt / 10;
	}
}

HugeInt ::HugeInt (const char* inChar){
	for(int i = 0 ; i < 256 ; ++i)
		theNum[i] = 0;
	
	int len = strlen(inChar);
	for (int i = len - 1 ; i >=0 ; i--){
		theNum[len - 1 - i] = inChar[i] -'0';
	}
	//for (int j = 0 ; j < len ; j++)
	//	cout<<theNum[j];
	//	cout<<endl;
}

istream & operator >>(istream & in,HugeInt &a){
	int buffer[256] = {0};
	int ctr = 0 ;
	char inChar;
	in.get(inChar);
	while (inChar != '\n'){
		buffer [ctr] = inChar - '0';
		ctr ++ ;
		in.get(inChar);
	}
	ctr -=1; //finfish but ctr +1
	int len = ctr ;
	while (ctr >= 0 ){
		a.theNum[ctr] = buffer [0+ len - ctr];
		ctr -- ;
	}
	return in ;
}

ostream & operator <<(ostream & out,HugeInt &a){
	int i = 255 ;
	while(a.theNum[i] == 0 )
		i--;
	if (i >= 0){
		while(i >= 0){
			out<<a.theNum[i];
			i--;
		}
	}
	else
		out << 0 ;
	return out ;
}

HugeInt HugeInt::operator + (const HugeInt & a ){
	int carry = 0 ;
	HugeInt result ;
	for(int i = 0 ; i < 256 ; ++i){
		result.theNum[i] = a.theNum[i] + theNum[i] + carry ;		
		carry = result.theNum[i] / 10 ;
		result.theNum[i] = result.theNum[i] %10;
	}
	return result;
}

HugeInt HugeInt::operator - (const HugeInt & a ){
	int borrow = 0 ;
	HugeInt result ;
	for(int i = 0 ; i < 256 ; ++i){
		result.theNum[i] =  theNum[i] - a.theNum[i] - borrow ;
		if(result.theNum[i] < 0){
			borrow = 1 ; 
			result.theNum[i] += 10 ;
		}
		else borrow = 0 ;
	}
	return result;
}

HugeInt& HugeInt::operator = (const HugeInt & a ){
	for (int i = 0 ; i < 256 ; i++)
		theNum[i] = a.theNum[i];
	return *this;
}