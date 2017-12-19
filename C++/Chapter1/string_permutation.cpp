//To check whether a given string is permutation of another string or not
//Assuming the string to be an ASCII string
#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class StringPermutation
{
public:
	int start();
	bool sort_m(string& str,string& str2);
	bool hash_m(const string& str,const string& str2);
	string result(bool value);
};

bool StringPermutation::sort_m(string& str,string& str2)
{
	if(str.length()!=str2.length())
		return false;
	sort(str.begin(),str.end());
	sort(str2.begin(),str2.end());

	if(str!=str2)
		return false;
	else
		return true;

}

bool StringPermutation::hash_m(const string& str,const string& str2)
{
	if(str.length()!=str2.length())
		return false;
	int count[128]={0};
	for(int i=0;i<str.length();i++)
		count[str[i]-'0']++;
	for(int i=0;i<str2.length();i++)
	{
		count[str2[i]-'0']--;
		if(count[str[i]]<0)return false;
	}
	return true;
}


string StringPermutation::result(bool value)
{
	if(value)
		return "True";
	else
		return "False";
}

int StringPermutation::start()
{
	string input[]={"adil","dila"};
	
	cout<<result(sort_m(input[0],input[1]))<<endl;
	cout<<result(hash_m(input[0],input[1]))<<endl;

	return 0;
}

int main()
{
	StringPermutation ob1;
	ob1.start();
}

