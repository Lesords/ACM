#include<iostream>//ac
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

//��⣺��set�洢���еļ���
//ÿ�β�ѯ��ʱ�򣬱�����һ�����ϣ������ж��ٸ��ڵڶ�������Ҳ����
//�����ֵļ�ΪNc���������϶��еĲ���������ĸ�����
//�������ϵ�������-Nc = Nt����������һ���еĲ���������ĸ�����

set<int> st[55];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int m;cin>>m;
        for(int j = 1;j <= m;j++) {
            int tmp;cin>>tmp;
            st[i].insert(tmp);
        }
    }
    int k;cin>>k;
    for(int i = 1;i <= k;i++) {
        int a,b,num = 0;
        cin>>a>>b;
        //������һ������
        for(set<int>::iterator it = st[a].begin();it!=st[a].end();it++) {
            if(st[b].find(*it)!=st[b].end()) num++;//�ж��Ƿ��ڵڶ���������Ҳ����
        }
        double aa = num;//aaΪ��ͬ���ֵĲ���������ĸ���
        double bb = st[a].size()+st[b].size()-num;
        printf("%.2f%%\n",aa/bb*100);
    }
    return 0;
}
