#include<iostream>//ac
#include<set>
using namespace std;

//��⣺��֪���ݷ�Χ���Ϊ30λ������Լ�¼ÿ�����Ķ�����λֵ
//ֻҪ����һ�����λ����1��0��������Դ�Ϊ������ͨ��
//�𰸼�Ϊ��ȥ�غ������-1��*����λ��Ӧ��ֵ��

//˼·����������ľ���Ϊ���ֵ����Խ��λ����1��0�����ֵԽ��

bool vis[31][2];
set<int> s;//������ͬ��Ȩֵ����Ϊ0������ȥ�أ�����
int main() {
	int n,tmp,ans;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		if(s.count(tmp)) continue;//�Ѵ���
		s.insert(tmp);
		for(int i = 0;i <= 30;i++) {//��������λ��
			if(tmp&1) vis[i][1] = 1;//��¼����Ӧ�Ķ�����ֵ
			else vis[i][0] = 1;
			tmp >>= 1;//ÿ������һλ
		}
	}
	for(int i = 0;i <= 30;i++) {
		if(vis[i][0]&&vis[i][1]) {//����1����0
			ans = i;//�������������λ
			break;
		}
	}//set�Ĵ�С��Ϊȥ�غ������
	cout<<(s.size()-1)*(1<<ans)<<endl;
	return 0;
}
