#include<iostream>//ac
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

//���⣺������ż����ת��Ϊ������������ ��������ͬ�� ��2
//��⣺����set�������в���������ż����,set�Ĵ�С��Ϊ���

//����ֵ�����������map�����У�unordered_mapЧ�ʻ�ߵ㣩!!!

int main() {
	int t,n;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		int tmp,maxx = 0,ans = 0;
		set<int> s;
		while(n--) {
			cin>>tmp;
			while(tmp%2 == 0) {//ż��
				if(s.count(tmp))  break;//�Ѵ��ڴ���������
				s.insert(tmp);//�������в�������(����2)
				tmp /= 2;
			}
		}
		cout<<s.size()<<endl;
	}
	return 0;
}
