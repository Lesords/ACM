#include<iostream>//ac
#include<algorithm>
using namespace std;
struct student{
	int num,money;
	char name[30];//����������
	friend bool operator < (student a,student b) {
		if(a.money!=b.money) return a.money > b.money;//����Ǯ
		return a.num < b.num;//���ű��
	}
}p[105];
int main() {
	int n,sum = 0,score1,score2,paper;
	cin>>n;
	char lead,west;
	for(int i = 1;i <= n;i++) {
		cin>>p[i].name;
		p[i].num = i;
		int tmp = 0;//��ʼ����ʱ��ѧ��Ϊ0
		cin>>score1>>score2>>lead>>west>>paper;
		if(score1>80&&paper>=1) tmp += 8000;//��˳���д���ཱѧ��
		if(score1>85&&score2>80) tmp += 4000;
		if(score1>90) tmp += 2000;
		if(score1>85&&west == 'Y') tmp += 1000;
		if(score2>80&&lead == 'Y') tmp += 850;
		sum += tmp;//��ѧ������
		p[i].money = tmp;//��ǰѧ���Ľ�ѧ��
	}
	sort(p+1,p+1+n);//����
	cout<<p[1].name<<endl<<p[1].money<<endl<<sum<<endl;
	return 0;
}
