#include<iostream>//ac
#include<queue>
using namespace std;
int book[1005];//�ڴ��д�����Ϊ 1
int main() {
	int m, n, ans = 0,tmp;
	cin>>m>>n;
	queue<int> q;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		if(book[tmp]) continue;//�����ѯ���ڴ����У�
		if(q.size()+1<=m) q.push(tmp);//�ڴ�δ��
		else {
			book[q.front()] = 0;//ɾ����������
			q.pop();//������������
			q.push(tmp);//�������
		}
		book[tmp] = 1, ans++;//��ѯ����������
	}
	cout<<ans<<endl;
	return 0;
}
