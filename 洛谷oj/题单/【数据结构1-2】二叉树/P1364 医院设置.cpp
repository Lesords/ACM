#include<iostream>//ac
#include<cstring>
#include<set>
#include<map>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺floyd�������··�����Ӷ�O(n^3)
//Ȼ����ö��ÿ����ΪҽԺ����Ҫ�ľ���ͣ�ȡ��Сֵ

const int MAXN = 105;
int a[MAXN][MAXN],num[MAXN];//a��ͼ��num��¼ÿ�����еľ�������
int main() {
    int n,cnt = 0;
    cin>>n;
    memset(a,0x3f,sizeof(a));//��ʼ��Ϊ���ֵ
    for(int i = 1;i <= n;i++) {
        a[i][i] = 0;//�Լ������Լ���ֵΪ0
        int w,u,v;
        cin>>w>>u>>v;
        num[i] = w;//��¼��ǰ���е�����
        if(u) {//��u���ڣ�����
            a[i][u] = a[u][i] = 1;
        }
        if(v) {//��v���ڣ�����
            a[i][v] = a[v][i] = 1;
        }
    }
    for(int k = 1;k <= n;k++) {//floyd�������·
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                a[i][j] = a[j][i] = min(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }
    int ans = INF;
    for(int i = 1;i <= n;i++) {
        int tmp = 0;//������iΪҽԺ�����·��֮��
        for(int j = 1;j <= n;j++) {
            tmp += a[i][j]*num[j];//j���о����ߵ�iҽԺ������Ϊnum[j]������
        }
        ans = min(ans, tmp);
    }
    cout<<ans;
    return 0;
}

