#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//���⣺����������n�����������r�����ж����в�ͬ���͵���Ϳ������������
//��⣺��������r<������n����ôÿ���������еĲ�ͬ����Ϊ������r(1,2,3,������,r)
//��������>=����������ô�ܹ�ֻ��һ���������ƽ�Ƶõ�֮�����������

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,r;
        cin>>n>>r;
        if(r==1) cout<<"1\n";//������Ϊ1������
        else {
            ll res = 0;//����ģ�����������������ʱ��
            if(r>=n) r = n-1,res = 1;//�޸�r
            cout<<(1+r)*r/2+res<<endl;//�Ȳ����
        }
    }
	return 0;
}
