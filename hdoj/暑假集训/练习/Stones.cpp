#include<iostream>
#include<queue>
using namespace std;
struct node{
	int pos;//ʯ�鵱ǰλ�� 
	int dis;//ʯ������ӳ�ȥ�ľ��� 
	friend bool operator < (node a,node b) {//��������� 
		if(a.pos==b.pos) return a.dis>b.dis;//������С�ģ�Ȼ���Ӵ�� 
		return a.pos>b.pos;
	}
};
int main() {
	int t;
	cin>>t;
	while(t--) {
		priority_queue<node> q;
		int n,num=1;//ʯ�ӵĴ��� 
		node temp;
		cin>>n;//ʯ������ 
		for(int i=1;i<=n;i++) {
			int a,b;
			cin>>a>>b;
			temp.pos=a;//ʯ�鵱ǰ��λ�� 
			temp.dis=b;//ʯ������ӳ�ȥ�ľ��� 
			q.push(temp);
		}
		while(!q.empty()) {//�ж��Ƿ���ʯ�� 
			temp=q.top();
			q.pop();
			if(num%2) {//�ж��������λ���ż���� 
				temp.pos+=temp.dis;//�޸�ʯ��λ�� 
				q.push(temp);
			}
			num++;//ʯ�ӵĴ���++ 
		}
		cout<<temp.pos<<endl;//temp����ľ������һ���ӵ�ʯͷ 
	}
	return 0;
} 
