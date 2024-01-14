#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char a[20];
int num[15]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int get(string a) {
	int len = a.size();//长度
	int k = 1,ans = 0;
	for(int i=1;i<len;i++) k*=10;
	for(int i=0;i<len;i++) {
		ans += k*(a[i]-'0');
		k/=10;
	}
	return ans;
}
bool is_leap(int y) {//判断闰年
	if(!(y%4)&&(y%100)) return true;
	else if(!(y%400)) return true;
	else return false;
}
int cal_month(int year,int month) {
	int ans = 0;
	if(month==1) return 0;//一月份
	num[2] = is_leap(year)?29:28;//闰年二月为29
	for(int i=1;i<month;i++) ans += num[i];
	return ans;
}
int main() {
	while(cin>>a) {
		int year,month,day;
		int cnt = 1;
		string y,m,d;
		for(int i=0;i<strlen(a);i++) {
			if(a[i]=='/') {
				cnt++;
				continue;
			}
			if(cnt==1) y+=a[i];//年
			if(cnt==2) m+=a[i];//月
			if(cnt==3) d+=a[i];//日
		}
		year = get(y);//转为整型 
		month = get(m);
		day = get(d);
		cout<<cal_month(year,month)+day<<endl;
	}
	return 0;
}
