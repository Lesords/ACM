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

//��⣺����ÿ���������ֻ��Ϳk����ɫ
//��ô�������������򣬰�˳��Ϳɫ����¼��Ӧ����Ϳ�Ĵ���
//Ϳ��k�εģ�������
//�����������˳��Ϳ
//ע�⣺���Ϳ�Ŀ��ܲ�����k����������Ҫ����ɾ��һ�飬ɾ������k

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int val,pos;//valΪֵ��posΪλ��
    friend bool operator < (node a,node b) {
        if(a.val==b.val) return a.pos < b.pos;//������ͬ������λ������
        return a.val < b.val;//���������ֵ����
    }
}a[MAXN];
int b[MAXN],num[MAXN];//b��¼ÿ��λ��Ϳ����ɫ��num��¼��ǰ��ɫͿ�Ĵ���
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) num[i]=0;//��ʼ��Ϊ0�����ڼ�¼ÿ�����ֻ滭�Ĵ���
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            a[i] = {tmp,i};
        }
        sort(a+1,a+1+n);//����
        int id = 1;//��ʼֵΪ1
        for(int i = 1;i <= n;i++) {
            int now = a[i].val;//��ǰֵ
            int pos = a[i].pos;//��ǰλ��
            if(num[now]>=k) {//�Ѿ�Ϳ��k���ˣ����ܼ���Ϳ��
                b[pos] = 0;
            }
            else {
                b[pos] = id++;//Ϳid��������id��ֵ
                num[now]++;//��Ӧ����Ϳ�Ĵ���++
                if(id==k+1) id = 1;//��id���ˣ�����Ϊ1
            }
        }
        int p = n;//�Ӻ���һ����ʼ��
        while(1) {
            int now = a[p].pos;//��ǰ����λ��
            //����ǰͿ��Ϊkɫ�������
            if(b[now]==k) break;//wa�ˣ������ж�0������
            b[now] = 0;//����Ϳ������
            p--;
        }
        for(int i = 1;i <= n;i++) cout<<b[i]<<" ";
        cout<<'\n';
    }
    return 0;
}
/*
3
6 3
1 2 5 5 5 6
7 3
1 2 5 5 5 5 6

1
7 3
1 2 5 5 5 6 6

1
10 3
1 2 5 5 5 5 6 6 6 6
*/
