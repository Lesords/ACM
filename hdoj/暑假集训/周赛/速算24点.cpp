#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[5],flag,book[5];
int get_num(char *ch) {//输入处理
	if(ch[0]=='A') return 1;
	else if(ch[0]=='J') return 11;
	else if(ch[0]=='Q') return 12;
	else if(ch[0]=='K') return 13;
	else if(ch[0]=='1') return 10;//10是两个字符
	return ch[0] - '0';
}
void dfs(int now,int next,int pos) {
	if(flag) return;//满足条件
	if(pos==4) {//第四张牌
		if(now+next==24||now-next==24||now*next==24) flag=1;
		if(next!=0&&now%next==0&&now/next==24) flag=1;
		return;
	}
	dfs(now+next,a[pos+1],pos+1);//无括号运算 
	dfs(now-next,a[pos+1],pos+1);
	dfs(now*next,a[pos+1],pos+1);
	if(next!=0&&now%next==0) dfs(now/next,a[pos+1],pos+1);
	//相除时，除数不能为0，且结果不能是小数！！！ 
	dfs(now,next+a[pos+1],pos+1);//括号运算 
	dfs(now,next-a[pos+1],pos+1);
	dfs(now,next*a[pos+1],pos+1);
	if(a[pos+1]!=0&&next%a[pos+1]==0) dfs(now,next/a[pos+1],pos+1);
}
int main() {
	char ch[6];
	while(cin>>ch) {
		a[1] = get_num(ch);//第一张牌输入处理
		for(int i=2;i<=4;i++) {//其余三张牌输入处理
			cin>>ch;
			a[i] = get_num(ch);
		}
		flag = 0;
		sort(a+1,a+5);//全排列之前要先排序
		do {
			dfs(a[1],a[2],2);//第一张牌和第二张牌，当前位置在2
		} while(!flag&&next_permutation(a+1,a+5));
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
