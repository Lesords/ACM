#include<iostream>//ac
#include<algorithm>
using namespace std;
struct student{
	int num,chi,mat,eng,sum;
	friend bool operator < (student a,student b) {
		if(a.sum!=b.sum) return a.sum > b.sum;//�����ܷ� 
		else if(a.chi!=b.chi) return a.chi > b.chi;//Ȼ������
		else return a.num < b.num;//�����
	}
}p[305];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>p[i].chi>>p[i].mat>>p[i].eng;
		p[i].num = i;//���
		p[i].sum = p[i].chi + p[i].mat + p[i].eng;//�ܷ�
	}
	sort(p+1, p+1+n);
	for(int i = 1;i <= 5;i++) {//ֻȡ��λ
		cout<<p[i].num<<' '<<p[i].sum<<endl;
	}
	return 0;
}
