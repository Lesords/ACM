#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺��С������Ǿ������֣��������������Ϊ1��ʣ������һ��
//Ȼ���������ѧ��⣺n*(n-1)/2 Ϊ���Ѷ���

ll getmin(ll a,ll b) {//��Сֵ
    ll num = a/b;
    ll rest = a%b;
    if(rest==0) {//û��ʣ���ʱ�򣬼�Ϊb������num���˵Ķ���
        return b*(num*(num-1))/2;
    }
    else {//Ϊrest��num+1�Ķ�������(b-rest����num�Ķ�����������
        num++;
        return (rest)*(num*(num-1))/2+(b-rest)*(num-1)*(num-2)/2;
    }
}
int main() {
    ll n,m;
    cin>>n>>m;//���������ʣ��һ�ӵ�����Ϊ n-m+1���۳�m-1����
    cout<<getmin(n,m)<<" "<<(n-m)*(n-m+1)/2<<"\n";
    return 0;
}
