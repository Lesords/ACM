#include<iostream>//ac 
#include<cstdio>
#include<cstring>
#include<algorithm>
//#define hhh
using namespace std;
struct person{
	char name[15];
	int pro,time;
	friend bool operator < (person a,person b) {
		if(a.pro==b.pro&&a.time==b.time)//字典序！！！ 
			return strcmp(a.name,b.name) < 0;
		else if(a.pro==b.pro) return a.time<b.time;
		return a.pro>b.pro;
	}
}a[1005];//数据开大点！！！ 
int n,m;
void f(char tmp[],int num) {//利用地址传递字符数组
	if(tmp[0] == '0'|| tmp[0] == '-') return;//没过题
	a[num].pro++;//题数++
	int flag = 0,pos = 1,ans = 0;//pos为位置，ans为时间
	int len = strlen(tmp) - 1;
	for(int i = len;i >= 0;i--) {//从右到左
		if(tmp[i] == ')') { flag = 1;continue; }
		if(flag) {//括号内的罚时
			if(tmp[i]=='(') { 
				pos = 1;
				a[num].time += ans * m;//ans为错误次数
				ans = flag = 0;
				continue; 
			}
			int t_num = tmp[i] - '0';
			ans += t_num * pos;
			pos *= 10;
		}
		else {
			int t_num = tmp[i] - '0';
			ans += t_num * pos;
			pos *= 10;
		}
	}
	a[num].time += ans;//通过时间
}
int main() {
	int num = 1;
	char tmp[15];
	#ifdef hhh
	freopen("dat.in","r",stdin);
	freopen("dat.out","w",stdout);
	#endif
	cin>>n>>m;
	while(cin>>a[num].name) {
		for(int i = 1;i <= n;i++) {//n道题
			cin>>tmp;
			f(tmp,num);
		}
		num++;
	}
	sort(a+1,a+num);
	for(int i = 1;i < num;i++) {
		printf("%-10s %2d %4d\n",a[i].name,a[i].pro,a[i].time);
	}
	#ifdef hhh
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}
/*样例
8 20
Smith     -1    -16   8     0   0   120  39     0
John	  116	-2	  11	0	0	82	 55(1)	0
Josephus  72(3)	126	  10	-3	0	47	 21(2)	-2
Bush	  0	    -1	  -8	0	0	0	 0	    0
Alice	  -2	67(2) 13	-1	0	133	 79(1)	-1
Bob	      0	    0	  57(5)	0	0	168	 -7	    0
*/
