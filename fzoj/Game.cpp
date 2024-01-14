#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e5+5;
char a[maxn],b[maxn];
int nextt[maxn],len_a,len_b;
void get_next() {//��next���� 
	int i = 0,j = -1;
	nextt[i] = j;
	while(i<len_b) {
		if(b[i]==b[j]||j==-1) nextt[++i] = ++j;
		else j = nextt[j];
	}
}
bool kmp() {//kmp�㷨 
	int i = 0,j = 0;
	get_next();
	while(i<len_a&&j<len_b) {
		if(a[i]==b[j]||j==-1) i++,j++;
		else j = nextt[j];
	}
	if(j==len_b) return true;//ƥ��ɹ� 
	return false;
}
int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		len_a = strlen(a);
		len_b = strlen(b);
		if(b[0]=='0') {//bΪ0�����
			cout<<"Alice"<<endl;
			continue;
		}
		if(len_a<len_b) cout<<"Bob"<<endl;
		//a���ַ�����bС�Ļ���b����һֱ��ת������Ϸ��һֱ����
		else {//ֻ���ж�b�ǲ���a���Ӵ�����
			if(kmp()) cout<<"Alice"<<endl;
			else {
				reverse(a,a+len_a);//��ת֮�� 
				if(kmp()) cout<<"Alice"<<endl;
				else cout<<"Bob"<<endl;
			}
		}
	}
	return 0;
} 
