#include<iostream>//ac
#include<set>
using namespace std;
const int MAXN = 1e5 + 5;
int leftt[MAXN],rightt[MAXN];
int main() {
	int n,m,a,b,start = 1;//��ʼ���Ϊ1
	leftt[1] = rightt[1] = 0;//��ʼ��1�����Ҷ�Ϊ0�����գ�
	cin>>n;
	for(int i = 2;i <= n;i++) {
		cin>>a>>b;//0��1��
		if(b) {//�� i ����a���ұ�
			int tmp = rightt[a];//ȡԭ����a��������
			rightt[a] = leftt[tmp] = i;//����ԭ��������״̬
			rightt[i] = tmp;//���²������ֵ���������
			leftt[i] = a;
		}
		else {//�� i ����a�����
			int tmp = leftt[a];//ȡԭ����a��������
			leftt[a] = rightt[tmp] = i;//����ԭ��������״̬ 
			leftt[i] = tmp;//���²������ֵ���������
			rightt[i] = a;
			if(tmp==0) start = i;//��Ϊ�գ��������
		}
	}
	cin>>m;//��ȥѧ������
	set<int> s;
	while(m--) cin>>a,s.insert(a);//�� �Ƴ����� ����set������
	while(start) {
		if(!s.count(start)) {//������set�����������
			cout<<start<<(start?' ':'\n');
		}//�����Ƶ���һλ
		start = rightt[start];
	}
	return 0;
}
