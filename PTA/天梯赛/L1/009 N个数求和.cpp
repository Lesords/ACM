#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
    ll x,y;
}a[105];
ll gcd(ll a,ll b) {//�������
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b) {//��С������
    return a*b/gcd(a,b);
}
int main() {
    int n,flag = 0;
    ll down = 1,up = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        scanf("%lld/%lld", &a[i].x,&a[i].y);
        down = lcm(a[i].y,down);//�������з�ĸ����С������
    }
    for(int i = 1;i <= n;i++) {//Ȼ���ټ���ķ��ӵĴ�С
        up += down/a[i].y*a[i].x;
    }
    ll com = gcd(up,down);//���ӷ�ĸԼ��
    up /= com;
    down /= com;
    if(up/down) cout<<up/down,flag = 1;//��Ϊ0���������Ӧ����
    if(up%down) {
        if(flag) cout<<" ";
        cout<<up%down<<"/"<<down<<endl;
    }
    else if(!flag) cout<<"0";//���һ�������Ľ��Ϊ0����Ҫ���У�����
    return 0;
}
/*
2 -2/3 2/3
*/
