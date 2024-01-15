#include<iostream>//ac
#include<string>
using namespace std;
char tree[1<<11];//n���Ϊ10
int n;
void build_tree(string a,int root) {//��������
	int B = 0, I = 0;
	for(int i = 0;i < a.size();i++) {
		if(a[i]=='0') B = 1;
		else if(a[i]=='1') I = 1;
		if(B&&I) break;
	}
	if(B&I) tree[root] = 'F';//01����ΪF 
	else tree[root] = (B?'B':'I');
	if(a.size()==1) return;//���ɷ�ʱ�����еݹ�
	int mid = a.size()/2;
	//a.substr(0,mid) �� ��0��ʼ��ȡmid���ַ�
	build_tree(a.substr(0,mid),root<<1);//��ݹ� 
	build_tree(a.substr(mid,mid),root<<1|1);//�ҵݹ�
}
void postorder(int root) {//�������
	if(root>=(1<<(n+1))) return;//Խ��
	postorder(root<<1);//����
	postorder(root<<1|1);//����
	cout<<tree[root];//�������ֵ
}
int main() {
	string a;
	cin>>n>>a;
	//2^n ������ ��n+1����������ΧΪ 1 ~ ( (1<<(n+1)) - 1 )
	build_tree(a,1);
	postorder(1);
	return 0;
} 
