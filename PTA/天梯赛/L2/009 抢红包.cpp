#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+6;
struct node{
    int id,num;
    double money;
    friend bool operator < (node a,node b) {
        //��Ǯ����������Ȼ����
        if(a.money!=b.money) return a.money > b.money;
        else if(a.num!=b.num) return a.num > b.num;
        return a.id < b.id;
    }
}a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) a[i].id = i;//id��ʾ���
    for(int i = 1;i <= n;i++) {
        int k;cin>>k;
        for(int j = 1;j <= k;j++) {
            int id;double money;
            cin>>id>>money;
            a[i].money -= money;//��ǰ�������i��Ǯ����
            a[id].num++;//�������id�����ĺ������++
            a[id].money += money;//Ǯ������++
        }
    }
    sort(a+1,a+n+1);//��������
    for(int i = 1;i <= n;i++) {
        printf("%d %.2f\n",a[i].id,a[i].money/100);//Ԫ���� /100
    }
    return 0;
}
