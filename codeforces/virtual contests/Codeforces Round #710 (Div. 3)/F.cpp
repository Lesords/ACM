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

//��⣺���� r+c Ϊż��ֻ�������ߣ�Ϊ����ֻ��������
//����Ŀ�б�֤�϶��н⣬���Կ϶�ʱ����������
//���Կ����ȸ���r����С�������򣨼ǵ�������(1,1)
//Ȼ��������ۣ�
//����ż��ֻ�������ߣ���������֮��Ŀ������ֵ��Ϊ����������
//�����������������ߣ�����������Ŀ������ֵҲΪ����������
//���Զ���ͬһ���ż����˵����Ҫ���Ķ�Ӧ�Ĳ�ֵ���ܵ���Ŀ�ĵ�
//
//��ͼ���Եõ������Ը��� r-c ��ֵ�����ࣨr�϶�>=c��
//
//1. �����ǰ�����һ����Ĳ�ֵ��ͬ��
//      ������Ĳ�ֵΪż����ֻ�����Ķ�Ӧ�ĳ������޸�·��
//      ������Ĳ�ֵΪ��������ô����ֱ�Ӳ��������ߣ�������
//2. �����ǰ�����һ����Ĳ�ֵ����ͬ��
//      ���ݲ�ֵ�����࣬������ϣ����������յ�ķ����ֵ����
//      ������Ĳ�ֵΪ����������ȡ��
//      ������Ĳ�ֵΪż��������ȡ��

//ע�⣺��ͼ���԰�����⣬�໭ͼ���ҹ��ɣ�����

const int MAXN = 2e5+5;
struct node{
    int r,c;
    friend bool operator < (node a,node b) {
        if(a.r!=b.r) return a.r < b.r;//�ȸ���r��С��������
        return a.c < b.c;//Ȼ���ڸ���c����
    }
}a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i].r;
        for(int i = 1;i <= n;i++) cin>>a[i].c;
        sort(a+1,a+1+n);//����
        ll ans = 0;
        a[0] = {1,1};//���Ϊ (1,1) ������
        for(int i = 1;i <= n;i++) {//���е㶼��Ҫ���ǣ���Ϊ1λ�ò�һ����Ϊ��㣡����
            int lastd = abs(a[i-1].r-a[i-1].c);//��һ��Ĳ�ֵ
            int nowd = abs(a[i].r-a[i].c);//��ǰ��Ĳ�ֵ
            if(lastd==nowd) {
                //���Ϊż����ֻ���޸�·��������
                if(lastd%2==0) ans += (a[i].r-a[i-1].r);
            }
            else {
                if(lastd%2) {//���ݲ���࣡����
                    ans += (nowd-lastd+1)/2;//����ȡ��������������һ�Σ�������
                }
                else {
                    ans += (nowd-lastd)/2;//����ȡ��
                }
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
