#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺���ڸ�������q��˵��ֻ��������������q[i] == q[i-1] ���� q[i] > q[i-1]
//��Ϊq����Ϊǰ׺���ֵ�����Բ����� q[i] < q[i-1]
//��ô��Ӧ��� q[i] > q[i-1] ��˵�����ǿ���֪����ǰλ�� a[i] �ض�Ϊ q[i]
//��Ϊǰ��Ŀ϶���Ϊ <= q[i-1]����ôҪ�� q[i] > q[i-1]��ֻ����iλ�÷��� ��ֵ ������
//��ô���� q[i] == q[i-1] �������
//��С�ֵ���Ϊ ѡ����С�Ļ�δѡ��� ����
//����ֵ���Ϊ ѡ����С��ǰһ���̶�ֵ ������
// ��Ϊ������ȵ�������˵����������ֶ�������� ǰһ��ȷ����q[i] ����һ��q[i]��

const int MAXN = 2e5+5;
int a[MAXN];//��¼ԭ����
void solve(vector<int> &q,bool minn) {
    //q�����ã�ֱ���޸����ݣ����践��,minn�жϵ�ǰ�Ƿ�Ϊ��С�ֵ�������
    set<int> hav;//hav��¼��δѡ�������
    for(int i = 1;i <= (int)q.size();i++) {//�����е������ȷ���hav������
        hav.insert(i);
    }
    for(int v: q) {//�Ѿ�ȷ���ļ�Ϊ�Ѿ�ѡ��ģ���hav������ɾ��
        if(v!=-1) hav.erase(v);
    }
    int lastVal = -1;//��¼��һ����ǰȷ����ֵ
    for(int &i : q) {//�������ã�����ֱ���޸������е�ֵ
        if(i==-1) {
            set<int>::const_iterator it;//ֻ�鿴�����޸ģ����ƶ�ָ�룩
            if(minn) {//����Сֵ����ȡhav�����׼���
                it = hav.begin();
            }
            else {//��������lower_boundѰ�� ��С�� lastVal ������
                it = --hav.lower_bound(lastVal);
            }
            i = *it;//�޸ĵ�ǰ����ֵ
            hav.erase(i);//ɾ��i���֣���ȷ��
        }
        else lastVal = i;//������ǰȷ����ֵ
    }
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        vector<int> res1(n,-1),res2(n,-1);//��ʼ��
        for(int i = 1;i <= n;i++) {//����ԭ����
            if(a[i]>a[i-1]) {//����ǰλ�ô���ǰһ��λ�ã���ȷ����ǰλ�õ�ֵ
                res1[i-1] = res2[i-1] = a[i];//�±���-1��res1��res2��0��ʼ����
            }
        }
        solve(res1, true);//����С�ֵ��������
        solve(res2, false);//������ֵ��������
        for(int v: res1) {//�����Ӧ�Ľ��
            cout<<v<<" ";
        }
        cout<<"\n";
        for(int v: res2) {
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
