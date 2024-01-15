#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���� a/b/c ��˵��aһ���Ƿ��ӣ�bһ���Ƿ�ĸ
//��Ϊ (a/b)/c = a/(b*c), a/(b/c) = (a*c)/b
//���Զ���ԭ����˵��Ҫʹ���Ϊ����������ʹ��ĸ�����٣����Ӿ�����
//Ҳ����˵���ڵڶ�λ���������˵��������Ϊ����
//��ô�� a1/a2/a3/a4/a5 = a1/(a2/a3/a4/a5) = a1/(a2/(a3*a4*a5))
// = a1*((a3*a4*a5)/a2)) = (a1*a3*a4*a5)/a2
//Ҳ����a2Ϊ��ĸ����������Ϊ����
//��ô��a2��������Լ�֣����Ϊ1��Ϊ������������

const int MAXN = 1e4+5;
int a[MAXN];
int gcd(int a,int b) {//���Լ��
    return b==0?a:gcd(b,a%b);
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        a[2] = a[2]/gcd(a[2],a[1]);//a2��a1Լ��
        if(a[2]==1) {//Ϊ����
            cout<<"Yes\n";
            continue;
        }
        for(int i = 3;i <= n;i++) {//ʣ�������������Լ��
            a[2] /= gcd(a[2],a[i]);
            if(a[2]==1) break;//Ϊ1ֱ�ӽ���
        }
        if(a[2]==1) cout<<"Yes\n";//Ϊ1˵��Ϊ����������flag���
        else cout<<"No\n";
    }
    return 0;
}
