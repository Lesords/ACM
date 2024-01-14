#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
char a[1005];
int main() {
	while(gets(a)&&a[0]!='#') {
		int ans = 0;
		map<string,int> map;
		string s="";//初始化 
		for(int i=0;i<strlen(a);i++) {
			if(a[i]==' '&&s=="") continue;//处理多余的空格 
			if(a[i]==' ') {//单词间的空格 
				if(!map[s]) map[s]=++ans;//单词不存在，++ans
				s = "";
				continue;
			}
			s+=a[i];//叠加字符 
			if(i==strlen(a)-1) {//末尾单词，要包括最后一个字符 
				if(!map[s]) map[s]=++ans;//单词不存在，++ans
				s = "";
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
