#include"PCX_Encoding.h"
#define MAX_RUNLENGTH 63
int PCXEncode_a_Run(unsigned char c, int nRunCount, fstream &fEncode)
{
	if (nRunCount)
	{
		if ((nRunCount == 1) && (c < 192))		//192d == 1100 0000b
		{
			fEncode.put(c);
			return 1;
		}
		else
		{
			fEncode.put(0xC0 | nRunCount);
			fEncode.put(c);
			return 2;
		}
	}
	return 0;
}

int PCXEncode_a_String(char *aString, int nLen, fstream &fEncode)
{
	unsigned char cThis, cLast;
	int nTotal = 0;
	int nRunCount = 1;

	cLast = *(aString);
	for (int i = 0; i < nLen; i++)
	{
		cThis = *(++aString);
		if (cThis == cLast)
		{
			nRunCount++;
			if (nRunCount == MAX_RUNLENGTH)
			{
				nTotal += PCXEncode_a_Run(cLast, nRunCount, fEncode);
				nRunCount = 0;
			}
		}
		else
		{
			if (nRunCount)
				nTotal += PCXEncode_a_Run(cLast, nRunCount, fEncode);
			cLast = cThis;
			nRunCount = 1;
		}
	}

	if (nRunCount)
		nTotal += PCXEncode_a_Run(cLast, nRunCount, fEncode);
	return (nTotal);
}

void PCXDecode_a_File(fstream &fEncode, fstream &fDecode)
{
	unsigned char c, n;
	short tmp;
	while (!fEncode.eof())
	{
		tmp = fEncode.get();
		if (tmp == EOF) break;
		
		c = (unsigned char) tmp;
		if ((c & 0xC0) == 0xC0)
		{
			n = c & 0x3f;
			c = (unsigned char)fEncode.get();
		}
		else
			n = 1;
		for (int i = 0; i < n; i++)
			fDecode.put(c);
	}
}