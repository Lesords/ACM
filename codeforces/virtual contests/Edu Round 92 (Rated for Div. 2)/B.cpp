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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺�ƶ�k�Σ�������������ң��������z�Σ���õ�ǰλ��ֵ��Ӧ�ķ����������÷�
//��⣺ֻ�����ƶ�k�κ󴦵�λ��Ϊ1+k���������ƶ�һ�Σ����Ӧ��ĩβλ��-2
//����1->2->3->4����Ϊ��1->2->3->2�� 1->2->1->2
//���ڲ������������ƶ�������ÿ�������ƶ��������Ϊȡ�������������ܺͣ����ظ���
//��ô���������ƶ���ֵ����ȡǰ׺�ͣ������ƶ���λ�ÿ���Ϊ �������������

const int MAXN = 1e5+5;
int a[MAXN],pre[MAXN],maxx[MAXN];//pre[i]Ϊ1-i�ĺͣ�maxxΪ1-iΪĩβλ���������������ֵ
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,k,z;
        cin>>n>>k>>z;
        for(int i = 1;i <= n;i++) cin>>a[i],pre[i] = pre[i-1]+a[i];//����+ǰ׺��
        for(int i = 1;i < n;i++) {//iΪĩβ�������������ֵ
            maxx[i] = max(maxx[i-1],a[i]+a[i+1]);
        }
        int ans = 0;
        for(int i = 0;i <= z;i++) {
            if(k-2*i<1) break;//���ĩβλ��С��1������Ĵ������ܻ�ࣩ
            ans = max(ans,pre[k+1-2*i]+maxx[k+1-2*i]*i);//maxxȡֵλ�ÿ���Ϊĩβλ�ã���������
            //i�����󣬶�Ӧĩβλ��Ϊ k+1-2*i
        }
        cout<<ans<<endl;
    }
	return 0;
}
/*
������
1
18 11 4
11 19 18 19 19 5 14 15 17 4 10 9 8 17 9 2 15 10
219
*/
