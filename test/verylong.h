#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int SZ = 1000; 

class verylong
{
private:
	char vlstr[SZ]; 
	int vlen;          
	bool sign;         
	verylong natural_addition(const verylong) const;    
	verylong natural_subtraction(const verylong) const;
	int cmp(const verylong) const;
	verylong natural_multiplication(const verylong) const;
	verylong natural_division(const verylong, bool) const;
	verylong multdigit(const int) const;                
	verylong mult10(const verylong) const;              
public:
	verylong() : vlen(0), sign(true) 
	{
		vlstr[0] = L'\0';
	}
	verylong(const char s[SZ])    
	{
		strcpy(vlstr, s); vlen = strlen(s); sign = true;
	}
	verylong(const long n)           
	{
		if (n < 0)                   
			sign = false;
		else
			sign = true;
		ltoa(abs(n), vlstr, 10);    
		strrev(vlstr);              
									 
		vlen = strlen(vlstr);        
	}

	verylong operator+ (const verylong); 
	verylong operator- (const verylong); 
	verylong operator* (const verylong); 
	verylong operator/ (const verylong); 
	verylong operator% (const verylong); 
	bool operator == (verylong v);
	bool operator != (verylong v);
	bool operator <= (verylong& v);
	bool operator > (verylong v);
};
