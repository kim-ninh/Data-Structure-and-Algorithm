#include"PCX_Encoding.h"
#include"BMP_Encoding.h"
#include<iostream>
#include<fstream>

using namespace std;
#include<string.h>

//int main()
//{
//	fstream originalFile, encodeFile, decodeFile;
//
//	/*originalFile.open("original.txt", ios::out);
//	for (int i = 0; i < 300; i++)
//		originalFile << 'a';
//	originalFile << "xyzt";
//	for (int i = 0; i < 5; i++)
//		originalFile << 'n';
//	originalFile.close();*/
//
//	encodeFile.open("original-BMP-encode.txt", ios::out | ios::binary);
//	originalFile.open("original.txt", ios::in | ios::binary);
//	char buff[1024];
//	originalFile.getline(buff, 1024);
//	BMP_Encode_a_str(buff, strlen(buff), encodeFile);
//	originalFile.close();
//	encodeFile.close();
//
//	decodeFile.open("original-BMP-decode.txt", ios::out | ios::binary);
//	encodeFile.open("original-BMP-encode.txt", ios::in | ios::binary);
//	BMP_Decode_a_File(encodeFile, decodeFile);
//	decodeFile.close();
//	encodeFile.close();
//
//	encodeFile.open("original-PCX-encode.txt", ios::out | ios::binary);
//	originalFile.open("original.txt", ios::in | ios::binary);
//	PCXEncode_a_String(buff, strlen(buff), encodeFile);
//	originalFile.close();
//	encodeFile.close();
//
//	decodeFile.open("original-PCX-decode.txt", ios::out | ios::binary);
//	encodeFile.open("original-PCX-encode.txt", ios::in | ios::binary);
//	PCXDecode_a_File(encodeFile, decodeFile);
//	decodeFile.close();
//	encodeFile.close();
//
//	/*cout <<(short) 'ÿ' << endl;
//	cout << (short) '-' << endl;
//	system("pause");*/
//	return 0;
//}

int main(/*int argc, char *argv[]*/)
{
	/*if (strcmp(argv[1], "-e") == 0)
	{
		BMP_Encode_a_File(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "-d") == 0)
	{
		BMP_Decode_a_File(argv[2], argv[3]);
	}

	return 0;*/
	int *arr;
	arr = new int[8];
	for (int i = 0; i < 8; i++)
		arr[i] = 1;
	
	cout << sizeof(arr) << endl;
	cout << sizeof(arr) / sizeof(int) << endl;
	//delete[]arr;
	system("pause");
}