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

//��⣺����D1�ķ����ж��Ƿ�ΪYES
//���ΪYES�������Ӧ����
//1. ���ж����Ƿ�Ϊ��������Ϊ�����������һ�к����̹���
//����cnt���жϵ�ǰ�̵ı�ţ����ݱ����ż������¼���Ƶ��ַ�
//�ǵ��޸��еĴ�С��ע����ǰ��ֵԭ���ı���С
//2. �ж����Ƿ�Ϊ��������Ϊ�����������һ�������̹���
//����cnt����¼��ǰ�̵ı�ţ����ݱ����ż������¼���Ƶ��ַ�
//�ǵ��޸��еĴ�С
//3. ��ʣ������λ��ȫ�����������������̹���
//4. Ȼ��������̹�����������棬������������ʣ��ĺ������
//��Ϊ�ظ��̵Ļ���ʣ���λ�ö���������ˣ�����Ҫ���У�����

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
char ans[105][105];//��¼���Ľ��
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        int min_h = n%2?m/2:0;
        int max_h = n*m/2 - (m%2?n/2:0);
        if(min_h<=k&&k<=max_h&&(k-min_h)%2==0) {//��ΪYES
            cout<<"YES\n";
            int len_n = n,len_m = m;//�ȼ�¼ԭ����С
            if(n%2) {//���ж���û�ж����һ����Ҫ�����̹���
                int cnt = 1;
                for(int i = 1;i < m;i += 2) {//ÿ��������
                    ans[n][i] = ans[n][i+1] = cnt%2?'a':'b';//������ż����ѡ����Ƶ��ַ�
                    k--,cnt++;
                }
                n--;//��ȥһ��
            }
            if(m%2) {//�ж��Ƿ��ж����һ����Ҫ����ڷŹ���
                int cnt = 1;
                for(int i = 1;i < n;i += 2) {//ÿ��������
                    ans[i][m] = ans[i+1][m] = cnt%2?'c':'d';//������ż����ѡ����Ƶ��ַ�
                    cnt++;
                }
                m--;//��ȥһ��
            }
            //��ʣ������λ��ȫ������ڷ�
            int cnt = 1;
            for(int i = 1;i <= n;i += 2) {
                for(int j = 1;j <= m;j += 2) {
                    //���������ڷ�
                    ans[i][j] = ans[i+1][j] = cnt%2?'m':'n';//�ַ�����ѡ��
                    ans[i][j+1] = ans[i+1][j+1] = cnt%2?'o':'p';
                }
                cnt++;//���� �� ����ż����ѡ���ַ�������
            }
            //Ȼ����ˮƽ�ڷ�ʣ��k���Ĺ���
            for(int i = 1;i <= n;i += 2) {
                for(int j = 1;j <= m;j += 2) {
                    if(k==0) break;//Ϊ0������
                    ans[i][j] = ans[i][j+1] = cnt%2?'e':'f';
                    ans[i+1][j] = ans[i+1][j+1] = cnt%2?'g':'h';
                    k -= 2,cnt++;//������ż��ѡ����Ƶ��ַ�
                }
                if(k==0) break;//Ϊ0������
            }
            for(int i = 1;i <= len_n;i++) {//������Ľ��
                for(int j = 1;j <= len_m;j++) cout<<ans[i][j];
                cout<<"\n";
            }
        }
        else cout<<"NO\n";
    }
    return 0;
}
