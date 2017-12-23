#include<iostream>
#include<fstream>
using namespace std;

int PCXEncode_a_Run(unsigned char c, int nRunCount, fstream &fEncode);

int PCXEncode_a_String(char *aString, int nLen, fstream &fEncode);

void PCXDecode_a_File(fstream &fEncode, fstream &fDecode);