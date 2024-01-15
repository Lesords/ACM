#include<iostream>//ac
#include<algorithm>
using namespace std;
struct student{
	int num,chi,mat,eng,sum;
	friend bool operator < (student a,student b) {
		if(a.sum!=b.sum) return a.sum > b.sum;//先排总分 
		else if(a.chi!=b.chi) return a.chi > b.chi;//然后语文
		else return a.num < b.num;//最后编号
	}
}p[305];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>p[i].chi>>p[i].mat>>p[i].eng;
		p[i].num = i;//编号
		p[i].sum = p[i].chi + p[i].mat + p[i].eng;//总分
	}
	sort(p+1, p+1+n);
	for(int i = 1;i <= 5;i++) {//只取五位
		cout<<p[i].num<<' '<<p[i].sum<<endl;
	}
	return 0;
}
