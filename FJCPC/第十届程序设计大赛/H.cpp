#include<bits/stdc++.h>
using namespace std;
char str[100005];
int main()
{
	int flag=0;
	while(gets(str)!=NULL)
	{
		int len=strlen(str);
		for(int i=0;i<len;i++)
		{
			if(!flag&&str[i]=='/'&&i+1<len&&str[i+1]=='/')
				break;
			if(!flag&&str[i]=='/'&&i+1<len&&str[i+1]=='*')
			{
				i+=2;
				flag=1;
			}
			if(!flag)
			{
				printf("%c",str[i]);
			}
			if(flag&&str[i]=='*'&&i+1<len&&str[i+1]=='/')
			{
				i++;
				flag=0;
			}
		}
		puts("");
	}
}
