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

//��⣺����ֻ�������ַ�
//���Կ��Լ�¼ÿ�����У���Ӧ�ַ����ֵĴ����Ѿ��ܳ���
//Ȼ������ַ����㣬�ж���ÿ���ַ�Ϊ���ַ�����������ַ�������
//�������ַ������ն�Ӧ ���ַ�-�����ַ� �Ĳ�ֵ���Ӵ�С���򣡣���
//��������ѡ������ַ���
//Ȼ��ʵʱ�����Ӧ���ַ������ַ��ĳ���
//����������������´𰸣��������

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int num[5];//��Ӧ����ַ�������
    int sum;//������
}a[MAXN];
int id;//idΪ��ǰ��������ַ�
bool cmp(node x,node y) {
    int x_rest = x.sum-x.num[id];//x�е������ַ�����
    int y_rest = y.sum-y.num[id];//y�е������ַ�����
    return x.num[id]-x_rest > y.num[id]-y_rest;//��ֵ�Ӵ�С����
}
int idx(char ch) {//����Ӧ�ַ�תΪ����
    if(ch<='d') return ch-'a';
    return 4;//����eΪ4
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        memset(a, 0, sizeof(a));//��ʼ��Ϊ0
        for(int i = 1;i <= n;i++) {
            string s;
            cin>>s;
            for(int j = 0;j < s.size();j++) {
                int now = idx(s[j]);
                a[i].num[now]++;//��¼��ǰi�ַ�����now����
            }
            a[i].sum = s.size();//��¼i�ַ������ܳ���
        }
        int ans = 0;
        for(int i = 0;i <= 4;i++) {//���������ַ�
            id = i;//�޸��������ַ�
            sort(a+1,a+n+1,cmp);//����
            int sum = 0,now = 0;//sumΪ�����ַ�������nowΪ���ַ�����
            for(int j = 1;j <= n;j++) {//���������ַ���
                sum += a[j].sum;
                now += a[j].num[i];
                if(sum-now<now) {//�������ַ������ַ�С��������������´�
                    ans = max(ans, j);
                }
                else break;//����ֱ�ӽ���
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1
5
cbdca
d
a
d
e

1
3
b
c
ca
*/
