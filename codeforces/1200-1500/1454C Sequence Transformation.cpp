#include<iostream>//ac
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺��������ȥ�أ�Ȼ��ͳ��ȥ�غ���������ֵĴ���
//ö����������Ҫɾ���Ĳ�������ȡ��Сֵ
//ÿ�����Ĳ�����Ϊ��num[i]+1 ��������֮��ļ��������β��
//����ǰ��������β��λ�ã�����Ҫ--

const int MAXN = 2e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        vector<int> b,num(n+1);//bΪȥ�غ�����飬numΪ��Ӧֵ���ֵĴ���
        for(int i = 1;i <= n;i++) {
            if(i==1) {//�׸���ֵ
                b.push_back(a[i]);
                num[a[i]]++;
            }
            else {
                if(a[i]!=a[i-1]) {//������ǰһ���Ž����飨ȥ�أ�
                    b.push_back(a[i]);
                    num[a[i]]++;
                }
            }
        }
        int ans = INF;//��ʼ��ΪINF��ȡ��Сֵ
        for(int i = 1;i <= n;i++) {
            if(num[i]==0) continue;//���������ֵ���ֵ
            int tmp = num[i]+1;//���м��
            if(b[0]==i) tmp--;//��������λ��
            if(b.back()==i) tmp--;//������βλ��
            ans = min(ans, tmp);//���´�
        }
        cout<<ans<<"\n";
    }
    return 0;
}
