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
		string s="";//��ʼ�� 
		for(int i=0;i<strlen(a);i++) {
			if(a[i]==' '&&s=="") continue;//�������Ŀո� 
			if(a[i]==' ') {//���ʼ�Ŀո� 
				if(!map[s]) map[s]=++ans;//���ʲ����ڣ�++ans
				s = "";
				continue;
			}
			s+=a[i];//�����ַ� 
			if(i==strlen(a)-1) {//ĩβ���ʣ�Ҫ�������һ���ַ� 
				if(!map[s]) map[s]=++ans;//���ʲ����ڣ�++ans
				s = "";
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
