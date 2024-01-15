#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
struct node{
	string name;
	int year,month,day,num;
	friend bool operator < (node a,node b) {
		if(a.year!=b.year) return a.year < b.year;
		else if(a.month!=b.month) return a.month < b.month;
		else if(a.day!=b.day) return a.day < b.day;
		else return a.num > b.num;
	}
}a[105];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i].name>>a[i].year>>a[i].month>>a[i].day;
		a[i].num = i;
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++) cout<<a[i].name<<endl;
	return 0;
}
