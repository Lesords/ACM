#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int num,time;//numΪ��ţ�timeΪ����
	friend bool operator < (node a,node b) {
		return a.time > b.time;//�Ӵ�С����
	}
}col[1005],row[1005];
int ans_c[1005],ans_r[1005];//����������
int main() {
	int m,n,k,l,d;
	memset(col,0,sizeof(col));//��ʼ��
	memset(row,0,sizeof(row));
	cin>>m>>n>>k>>l>>d;
	int x1,y1,x2,y2;
	for(int i = 1;i <= d;i++) {
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2) {//����ͬ��ȡ�У�
			int minn = min(y1,y2);
			col[minn].num = minn;//�����Сֵ
			col[minn].time++;//����++
		}
		else {
			int minn = min(x1,x2);
			row[minn].num = minn;
			row[minn].time++;
		}
	}
	sort(col+1,col+1005);//�ṹ������
	sort(row+1,row+1005);
	for(int i = 1;i <= k;i++) {//������
		ans_r[i] = row[i].num;//�н��
	}
	for(int i = 1;i <= l;i++) {
		ans_c[i] = col[i].num;//�н��
	}
	//��������Ϊ�ֵ��򣡣���
	sort(ans_r+1,ans_r+k+1);//�ֵ��򣨴�С����
	sort(ans_c+1,ans_c+l+1);
	for(int i = 1;i <= k;i++) {//������
		if(i!=1) cout<<' ';
		cout<<ans_r[i];
	}
	cout<<endl;
	for(int i = 1;i <= l;i++) {
		if(i!=1) cout<<' ';
		cout<<ans_c[i];
	}
	cout<<endl;
	return 0;
}
