#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
int main()
{
	char c;
	std::string a;
	while(scanf("%c",&c)!=EOF) {
		if(c=='A'||c=='a'||c=='O'||c=='o'
		 ||c=='Y'||c=='y'||c=='E'||c=='e'
		 ||c=='U'||c=='u'||c=='I'||c=='i')
		  continue;
		if(c>=65&&c<=90)
		  c+=32;
		if(c>=97&&c<=122)
		  a+='.';
		a+=c;
	}
	std::cout<<a;
	return 0;
}
