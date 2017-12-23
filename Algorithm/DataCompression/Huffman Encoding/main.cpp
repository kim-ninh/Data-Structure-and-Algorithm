//#include <string>
//#include <iostream>
#include <Windows.h>

//#include<experimental\filesystem>
//#include"Static Huffman.h"
//using namespace std::experimental::filesystem::v1;
//using namespace std;
#include<iostream>
using namespace std;

bool ListDirectoryContents(const char *sDir)
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	char sPath[2048];
	
	//Specify a file mask. *.* = We want everything!
	sprintf(sPath, "%s\\*.*", sDir);
	
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		printf("Path not found: [%s]\n", sDir);
		return false;
	}

	do
	{
		//Find first file will always return "."
		//    and ".." as the first two directories.
		if (strcmp(fdFile.cFileName, ".") != 0
			&& strcmp(fdFile.cFileName, "..") != 0)
		{
			//Build up our file path using the passed in
			//  [sDir] and the file/foldername we just found:
			sprintf(sPath, "%s\\%s", sDir, fdFile.cFileName);
			
			//Is the entity a File or Folder?
			if (fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
			{
				printf("Directory: %s\n", sPath);
				ListDirectoryContents(sPath); //Recursion, I love it!
			}
			else {
				printf("File: %s\n", sPath);
			}
		}
	} while (FindNextFile(hFind, &fdFile)); //Find the next file.

	FindClose(hFind); //Always, Always, clean things up!

	return true;
}

//ListDirectoryContents("C:\\Windows\\");

int main(int argc, char *argv[])
{
	//ListDirectoryContents("D:\\Tai xuong\\Photo");
	//cout << getTotalFile("C:\\Users\\Kim Ninh\\Desktop\\test") << endl;
	
	//HuffmanEncoding HFE;
	//HFE.Encode_a_Folder("C:\\Users\\Kim Ninh\\Desktop\\test", "C:\\Users\\Kim Ninh\\Desktop\\test\\simple.hfm");
	//HFE.ListFiles("C:\\Users\\Kim Ninh\\Desktop\\test\\simple.hfm");
	//HFE.Decode_a_File("C:\\Users\\Kim Ninh\\Desktop\\test\\simple.hfm", "C:\\Users\\Kim Ninh\\Desktop\\test\\Giai Nen");
	system("pause");
	return 0;
}

