#include<iostream>//ac  ��ʽ�Ƶ�+��ʽɸ+Ψһ�ֽⶨ��
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺��Ŀ�ɻ�Ϊ��a*b�����������ظ���
//Ȼ����ɸ�����������������Ψһ�ֽⶨ���������Ӹ���
//��(x,y)����������ʵ������x��y�ĸ�������������һ���Ƴ�����һ����
//ax+by=xy  =>  ax+(b-x)y = 0   =>  y = ax/(x-b)
//=>    y = (a(x-b)+ab)/(x-b)   =>  y = a + ab/(x-b)  => ����ab������������

const int MAXN = 1e6+5;
vector<int> prime;//�������ݷ�Χ�ڵ���������
int vis[MAXN];
int main() {
    for(int i = 2;i < MAXN;i++) {
        if(vis[i]) continue;
        prime.push_back(i);//��¼����
        for(int j = i+i;j < MAXN;j+=i) vis[j] = 1;
    }//��ɸ����������
    int t;
    int len = prime.size()-1;
    cin>>t;
    while(t--) {
        ll a,b;
        cin>>a>>b;
        ll num = a*b,ans = 1;
        for(int i = 0;i <= len;i++) {
            int tmp = 0;
            while(num%prime[i]==0) {
                num /= prime[i];
                tmp++;//����ָ��
            }
            if(tmp) ans *= tmp+1;//����Ϊ�����������ӵ� ָ��+1 �ĳ˻�
            if(num==1) break;//�������������
        }
        cout<<ans<<"\n";
    }
    return 0;
}
