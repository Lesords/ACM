#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���ر������Խ����i�ֵ���Ʒ�����ɶ�����Ci����Ʒ
//Ȼ��ת����01����������

const int MAXN = 1010;
int v[MAXN],w[MAXN],s[MAXN],f[MAXN];
int main() {
    int n,m;
    cin>>n>>m;//û�и��������Բ���Ҫ��ʼ��Ϊ��Сֵ
    for(int i = 1;i <= n;i++) cin>>v[i]>>w[i]>>s[i];
    for(int i = 1;i <= n;i++) {
        for(int k = 1;k <= s[i];k++) {
            for(int j = m;j >= v[i];j--) {
                f[j] = max(f[j], f[j-v[i]]+ w[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= m;i++) {//ͳ�����ֵ
        ans = max(ans, f[i]);
    }
    cout<<ans;
    return 0;
}
