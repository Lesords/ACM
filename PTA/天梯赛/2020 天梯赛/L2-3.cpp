#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺��������������������
//�κ�һ��������ʽ������ȷ��һ������������������
//Ҳ����˵��ֱ�Ӻ������һ�����������������a�����ж�Ӧ��λ�ü�Ϊ�ڵ�ֵ

const int MAXN = 1e4+5;
int n,a[MAXN],tree[MAXN],cnt;//cntΪ��ǰ������λ��
void solve(int dot) {
    if(dot>n) return;//���ܴ�СΪn
    solve(dot<<1);
    solve(dot<<1|1);
    tree[dot] = a[++cnt];//��¼ֵ����
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    solve(1);
    for(int i = 1;i <= n;i++) {
        if(i!=1) cout<<" ";
        cout<<tree[i];
    }
    return 0;
}
