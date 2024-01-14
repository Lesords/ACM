#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
struct node {
	char name[17];
	int data;
	int cnt;//�Ⱥ�˳�� 
	friend bool operator < (node a, node b) {
		if(a.data!=b.data) return a.data>b.data;//���Ƽ�����ֵС�� 
		else return a.cnt>b.cnt;//Ȼ���Ⱥ�˳���Ƽ� 
	}
};
int main() {
	int t;
	cin>>t; 
	for(int k=1;k<=t;k++) {
		int n,cnt=1;//cntΪ˳�򣬳�ʼ��Ϊ1 
		cin>>n;//������ 
		cout<<"Case #"<<k<<":"<<endl;
		priority_queue<node> q;//ÿ�ζ�����Գ�ʼ�����ȶ��� 
		for(int i=1;i<=n;i++) {
			string op;
			cin>>op;
			if(op=="Add") {//�ӵĲ��� 
				node tmp;
				cin>>tmp.name>>tmp.data;
				tmp.cnt=cnt++;//˳��++ 
				q.push(tmp);
				cout<<q.size()<<endl;//�����Ա�� 
			}
			else {
				int num, cc=1, flag=0;
				node tmp[1000];//�����洢��ʱ���ݵĽṹ������ 
				memset(tmp,0,sizeof(tmp));
				cin>>num;
				if(q.empty()) {//�˲ſ�Ϊ�յ���� 
					cout<<"WAIT..."<<endl;
					continue;
				}
				while(!q.empty()) {
					tmp[cc]=q.top();
					q.pop();
					if(tmp[cc].data>=num) {//�������� 
						flag=1;
						for(int i=cc-1;i>=1;i--) {
							q.push(tmp[i]);
						}//����ķ�������� 
						break;
					}
					else cc++;//��ʱ���ݵı��++ 
				}
				if(flag) cout<<tmp[cc].name<<endl;
				else {//�������ݶ�Ҫ��������� 
					for(int i=cc-1;i>=1;i--) q.push(tmp[i]);
					cout<<"WAIT..."<<endl;
				}
			}
		}
	}
}
