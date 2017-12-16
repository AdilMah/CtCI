#include<iostream>
#include<string>
using namespace std;

class UniqueString
{
public:
	int start();
	bool isUnique(const string& str);
	bool isUnique2(const string& str);
	string result(bool value);
};

bool UniqueString::isUnique(const string& str)
{
	if(str.length()>256)
		return false;
	unsigned int checker=0;

	for(int i=0;i<str.length();i++)
	{
		int value=str[i]-'a';
		if((checker&(1<<value))!=0)
			return false;
		checker=checker|(1<<value);
	}
	return true;
}

bool UniqueString::isUnique2(const string& str)
{
	if(str.length()>256)
		return false;
	
	bool set[256]={0};
	for(int i=0;i<str.length();i++)
	{
		int value=str[i];
		if(set[value]==1)
			return false;

		set[value]=1;
	}
	return true;
}

string UniqueString::result(bool value)
{
	if(value)
		return "True";
	else
		return "False";
}

int UniqueString::start()
{
	string input[]={"adil","aadil"};
	for(int i=0;i<2;i++)
	{
		cout<<input[i]<<"::"<<result(isUnique(input[i]))<<endl;
		cout<<input[i]<<"::"<<result(isUnique2(input[i]))<<endl;
	}
	return 0;
}

int main()
{
	UniqueString ob1;
	ob1.start();
}

