#include<iostream>//ac
#include<set>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺���ڹ�ϵ(a,b)��˵���������Ϊ�� (a+1,b-1)��Χ��ĸ߶�-1
//��ֲ�����d[a+1]--,d[b]++
//��ô����λ��p���ԣ����ֵ�϶�Ϊ0
//��Ҫע�⣬ÿ�ֹ�ϵ�Ĵ�С���Լ��������ظ��Ĺ�ϵ����

const int MAXN = 1e4+5;
int d[MAXN];
set<pii> st;//���ڳ��ع�ϵ
int main() {
    int n,m,p,h;
    cin>>n>>p>>h>>m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);//������С������
        if(st.count({a,b})) continue;//�ظ��ˣ�������
        else st.insert({a,b});//�����¼��ǰ��ϵ
        d[a+1]--;// (a+1,b-1)������--
        d[b]++;
    }
    int sum = 0;//���ڼ���ǰ׺�ͣ�����ǰλ�õĸ߶�
    for(int i = 1;i <= n;i++) {
        sum += d[i];//�ۼ�
        cout<<sum+h<<"\n";//��h�ĺͼ�Ϊ���߶�
    }
    return 0;
}
