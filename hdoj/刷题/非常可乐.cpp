#include<iostream>//ac
#include<cstring>
#include<queue>
using namespace std;
struct cup {
	int c[4],step;
}now;
int a[4],t,book[105][105];//��һάΪ���ֱ����ڶ�άΪ�ϴ���
void poor(int i,int j) {//i -> j
	int sum = now.c[i]+now.c[j];//����
	now.c[j] = (sum>=a[j])?a[j]:sum;//�ж��Ƿ��װ��
	now.c[i] = sum - now.c[j];
}
void bfs() {
	queue<cup> q;
	cup tmp;
	memset(book,0,sizeof(book));//��ʼ��
	q.push(cup{0,a[1],0,0,0});//��ʼ����c[0]!!!
	book[a[1]][0] = 1;//��ǳ�ʼ״̬
	while(!q.empty()) {
		tmp = q.front();q.pop();
		if(tmp.c[1]==tmp.c[2]&&tmp.c[3]==0) {//����������ͬ
			cout<<tmp.step<<endl;            //��һ��Ϊ0
			return;
		}
		for(int i = 1;i <= 3;i++) {//i->j 
			for(int j = 1;j <= 3;j++) {
				if(i==j||tmp.c[i]==0) continue;//iΪ�ձ�
				now = tmp;
				poor(i,j);
				if(book[now.c[1]][now.c[2]]) continue;//�ظ�
				now.step++;
				q.push(now);
				book[now.c[1]][now.c[2]] = 1;//��ǵ�ǰ���
			}
		}
	}
	cout<<"NO"<<endl;//�޷�ƽ��
}
int main() {
	while(cin>>a[1]>>a[2]>>a[3]&&a[1]+a[2]+a[3]) {
		if(a[1]%2) {//�����޷�ƽ��
			cout<<"NO"<<endl;continue;
		}//��a[2]Ϊ�ϴ���������
		if(a[2]<a[3]) t = a[2],a[2] = a[3], a[3] = t;
		bfs();
	}
	return 0;
}
