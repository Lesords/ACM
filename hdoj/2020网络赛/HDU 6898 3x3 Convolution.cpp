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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

//��⣺Cx,y���㹫ʽ��ʵ�Ǵ� (x,y) ��ʼ���������3��λ��
//Ȼ�����������Ӧλ����ˣ�ȡ�ͼ�Ϊ���

//���ڼ�������ӽ����޴󣬲������Ľ����֤Ϊ����
//��ô����֪������ÿ��λ�� (x,y) ���ԣ����k����Ϊ����
//��ôһֱ��֮��ÿ��λ�ö���������0���������Ϊ0
//��Ϊ ����*���� �����Ľ����Խ��ԽС

//������k����Ľ���ܺ�Ϊ1
//��ôҪ�뵱ǰλ���й��ף���ô k1,1 ����Ϊ1
//��Ϊÿ��λ�� ���� ���Ǻ� k1,1 ��˵�
//���ԣ�ֻҪ k1,1 Ϊ1����ô�������Ϊԭ���ľ���

const int MAXN = 1e3+5;
int a[MAXN][MAXN],k[5][5];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                cin>>a[i][j];
            }
        }
        int cnt = 0;
        for(int i = 1;i <= 3;i++) {
            for(int j = 1;j <= 3;j++) {
                cin>>k[i][j];
                if(k[i][j]) cnt++;
            }
        }
        //���ֻ��һ��λ����ֵ��������λ��(1,1)����ô˵��k1,1ֵΪ1
        int flag = cnt==1&&k[1][1];
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(j!=1) cout<<" ";
                cout<<(flag?a[i][j]:0);//ֵΪ1��Ϊԭ�����飬����Ϊ0
            }
            cout<<"\n";
        }
    }
	return 0;
}
