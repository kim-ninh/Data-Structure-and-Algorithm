#include "BMP_Encoding.h"
#include "Queue.cpp"
void BMP_Encode_a_File(char *inputFileName,char *outputFileName)
{
	fstream fInput(inputFileName, ios::in | ios::binary);
	fstream fOutput(outputFileName, ios::out | ios::binary);

	unsigned char rep = 0;
	unsigned char cLast, c;
	fInput.read((char*)&c, 1);

	while (!fInput.eof())
	{
		rep = 1;
		fInput.read((char*)&cLast, 1);
		if (fInput.eof())
		{
			fOutput.put(0);
			fOutput.put(rep);
			fOutput.put(c);
			break;
		}
		
		if (c == cLast)
		{
			do
			{
				rep++;
				fInput.read((char*)&cLast, 1);	
			} while (!fInput.eof() && c == cLast);

			fOutput.put(rep);	
			fOutput.put(c);		
			c = cLast;
		}
		else
		{
			QUEUE<unsigned char> q;
			q.enqueue(c);
			do
			{
				q.enqueue(cLast);
				c = cLast;
				++rep;
				fInput.read((char*)&cLast, 1);
			} while (!fInput.eof() && c != cLast);

			if (!fInput.eof()) --rep;
			fOutput.put(0);
			fOutput.put(rep);		
			
			while (rep--)
			{
				q.dequeue(c);
				fOutput.put(c);		
			}
			c = cLast;
			if (!fInput.eof())
				fInput.seekg(-1, ios::cur);
		}
		
	}

	/*int last;
	for (int i = 0; i < nLen - 1; i = last)
	{
		last = i + 1;
		if (aString[i] == aString[last])
		{
			do
			{
				++last;
			} while (aString[i] == aString[last] 
					&& last - i < MAX_RUNLENGTH);

			fEncode.put((unsigned char)(last - i));
			fEncode.put(aString[i]);
		}
		else
		{
			while (aString[i] != aString[last]
				&& aString[last] != aString[last + 1]
				&& last - i <= MAX_RUNLENGTH)
				++last;

			fEncode.put('\0');
			fEncode.put((unsigned char)(last - i));
			for (int j = i; j < last; j++)
				fEncode.put(aString[j]);
		}
	}*/
}

void BMP_Decode_a_File(char *inputFileName, char *outputFileName)
{
	fstream fEncode, fDecode;
	fEncode.open(inputFileName, ios::in | ios::binary);
	fDecode.open(outputFileName, ios::out | ios::binary);

	unsigned char n, c;
	fEncode.read((char*)&n, 1);
	while (!fEncode.eof())
	{
		if (n != 0)
		{
			fEncode.read((char*)&c, 1);
			for (int j = 0; j < n; j++)
				fDecode.put(c);
		}
		else
		{
			fEncode.read((char*)&n, 1);
			while (n--)
			{
				fEncode.read((char*)&c, 1);
				fDecode.put(c);
			}
		}
		fEncode.read((char*)&n, 1);

		//n = fEncode.get();
		//if (n != 0)
		//{
		//	c = (unsigned char)fEncode.get();
		//	
		//	for (int j = 0; j < n; j++)
		//		fDecode.put(c);
		//}
		//else
		//{
		//	n = (unsigned char)fEncode.get();
		//	while (n--)
		//	{
		//		//c = (unsigned char)fEncode.get();
		//		//fDecode.put(c);
		//		fEncode.read((char*)c, 1);
		//		fDecode.write((char*)c, 1);
		//	}
		//}
	}
	fEncode.close();
	fDecode.close();
}
