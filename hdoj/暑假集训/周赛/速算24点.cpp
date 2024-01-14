#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[5],flag,book[5];
int get_num(char *ch) {//���봦��
	if(ch[0]=='A') return 1;
	else if(ch[0]=='J') return 11;
	else if(ch[0]=='Q') return 12;
	else if(ch[0]=='K') return 13;
	else if(ch[0]=='1') return 10;//10�������ַ�
	return ch[0] - '0';
}
void dfs(int now,int next,int pos) {
	if(flag) return;//��������
	if(pos==4) {//��������
		if(now+next==24||now-next==24||now*next==24) flag=1;
		if(next!=0&&now%next==0&&now/next==24) flag=1;
		return;
	}
	dfs(now+next,a[pos+1],pos+1);//���������� 
	dfs(now-next,a[pos+1],pos+1);
	dfs(now*next,a[pos+1],pos+1);
	if(next!=0&&now%next==0) dfs(now/next,a[pos+1],pos+1);
	//���ʱ����������Ϊ0���ҽ��������С�������� 
	dfs(now,next+a[pos+1],pos+1);//�������� 
	dfs(now,next-a[pos+1],pos+1);
	dfs(now,next*a[pos+1],pos+1);
	if(a[pos+1]!=0&&next%a[pos+1]==0) dfs(now,next/a[pos+1],pos+1);
}
int main() {
	char ch[6];
	while(cin>>ch) {
		a[1] = get_num(ch);//��һ�������봦��
		for(int i=2;i<=4;i++) {//�������������봦��
			cin>>ch;
			a[i] = get_num(ch);
		}
		flag = 0;
		sort(a+1,a+5);//ȫ����֮ǰҪ������
		do {
			dfs(a[1],a[2],2);//��һ���ƺ͵ڶ����ƣ���ǰλ����2
		} while(!flag&&next_permutation(a+1,a+5));
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
