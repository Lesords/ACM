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

//��⣺��̬�滮������ÿ��λ�ã�ҪôѡҪô��ѡ
//����ѡ�Ͳ�ѡ���������������һ��״̬�ڵ�ǰ�л�������һ�У���Ӧ��cnt������һ����
//ע�⣺cntѡ����������ܳ���ÿ�е�һ�룡����
//��ǰ�����ƣ���ôdp[n][1][0][0]��Ϊ��
//dp[i][j][cnt][rem]����i��jλ��֮ǰ����ǰ���Ѿ�ѡ����cnt����������Ϊrem������ܺ�

const int MAXN = 75;
int a[MAXN][MAXN],dp[MAXN][MAXN][MAXN][MAXN];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>a[i][j];
    }
    memset(dp,-1,sizeof(dp));//��ʼ��Ϊ-1����ʾ״̬���ɴ�
    dp[1][1][0][0] = 0;//��ʼ�����Ϊ0
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            int tx = (j==m)?i+1:i;//�������ĩ����Ҫ�Ƶ���һ������
            int ty = (j==m)?1:j+1;
            for(int cnt = 0;cnt <= m/2;cnt++) {
                for(int rem = 0;rem < k;rem++) {
                    if(dp[i][j][cnt][rem]==-1) continue;//����״̬�����ڵ����
                    //��ѡ��ǰλ��
                    if(i!=tx) {//��ͬ�У�cnt��Ϊ0
                        dp[tx][ty][0][rem] = max(dp[tx][ty][0][rem], dp[i][j][cnt][rem]);
                    }
                    else {//ͬ��
                        dp[tx][ty][cnt][rem] = max(dp[tx][ty][cnt][rem], dp[i][j][cnt][rem]);
                    }
                    //ѡ��ǰλ��
                    if(cnt+1 <= m/2) {//��ǰѡ��֮��Ҫ����m/2������
                        int re = (rem+a[i][j])%k;//��������
                        if(i!=tx) {//��ͬ�У�cnt��Ϊ0
                            dp[tx][ty][0][re] = max(dp[tx][ty][0][re], dp[i][j][cnt][rem]+a[i][j]);
                        }
                        else {//ͬ��
                            dp[tx][ty][cnt+1][re] = max(dp[tx][ty][cnt+1][re],dp[i][j][cnt][rem]+a[i][j]);
                        }
                    }
                }
            }
        }
    }
    cout<<dp[n+1][1][0][0];
	return 0;
}
