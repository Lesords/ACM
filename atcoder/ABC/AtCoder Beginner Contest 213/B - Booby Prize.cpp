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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺����ֵԽС������Խ��
//������С�ģ���Ӧֵ��Խ��
//����������Ϊ ֵ�ڶ����
//ֱ�ӽṹ�����򼴿�

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int val,pos;//valΪֵ��posΪ��Ӧλ��
    friend bool operator < (node a, node b) {
        //��С��������
        if(a.val==b.val) return a.pos < b.pos;
        return a.val < b.val;
    }
}a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].val;
        a[i].pos = i;//��¼��Ӧֵ
    }
    sort(a+1,a+1+n);
    cout<<a[n-1].pos<<"\n";//����ڶ���ֵ��λ�ü���
	return 0;
}
