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

//��⣺������㽻���ɣ����Կ��������ǰ׺��
//Ȼ��������յ���������Էֳ����֣��������ֺ���������
//�����������ֿ���ֱ���������������ͣ���Ϊ0������У�a^a = 0��
//������������ֱ��ö�������߽磬Ȼ���������ǰ׺�����������������Ƿ���ͬ

const int MAXN = 2e3+5;
const int MOD = 1e9+7;
int pre[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,sum = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            if(i==1) sum = tmp;
            else sum ^= tmp;
            pre[i] = pre[i-1]^tmp;
        }
        int ans = sum==0;//sum==0���ж��Ƿ���Էֳ���������
        for(int i = 1;i <= n;i++) {//ö�������߽�
            for(int j = i+1;j <= n;j++) {
                //ֻҪ��һ������������ɣ�����|������
                ans |= (pre[i]==(pre[j]^pre[i])) && (pre[i]==(pre[n]^pre[j]));
            }
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
/*
1
6
2 3 1 3 2 0

2
4
2 3 1 10
3
1 1 10

2
5
1 1 1 1 2
5
1 2 2 1 1
*/
