#define _CRT_SECURE_NO_WARNINGS
#include"../Slack/Stack.cpp"
#include"../Queue/Queue.cpp"

#include<iostream>
#include<cstring>
using namespace std;

void convertLower(char *&str)
{
	int length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	}
}

void nhapChuoi(char *&str)
{
	str = nullptr;
	char buff[256];
	cin.getline(buff, 256);
	str = new char[strlen(buff)];
	strcpy(str, buff);
}

void loaiBoDau(char *&str)
{
	int length = strlen(str);
	for (int i = 0; i < length; )
	{
		switch (str[i])
		{
		case '\'':case '"': case '.':case ',':case'!':case':':
			strcpy(str + i, str + i + 1);
			length--;
			break;
		default:i++;
		}
	}
}

bool isPalindrome(char *str)
{
	char *tmp = new char[strlen(str)];
	strcpy(tmp, str);
	loaiBoDau(tmp);
	convertLower(tmp);
	loaiBoDau(tmp);
	int tmpLength = strlen(tmp);

	STACK<char> s;
	QUEUE<char> q;
	for (int i = 0; i < tmpLength; i++)
	{
		if (str[i] != ' ')
		{
			s.push(tmp[i]);
			q.enqueue(tmp[i]);
		}
	}

	char front, rear;
	while (s.pop(rear) && q.dequeue(front))
	{
		if (front != rear)
		{	
			delete []tmp;
			return false;
		}
	}
	
	return true;
}

int main()
{
	char *str;
	nhapChuoi(str);
	cout << str << endl;
	loaiBoDau(str);
	cout << str << endl;
	cout << boolalpha << isPalindrome(str) << endl;
	//delete []str;
	str;
	system("pause");
}
