#include<iostream>//ac
#include<cmath>
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e4+5;
struct node{
    string name;//����
    int val;//�µ���
    friend bool operator < (node a,node b) {
        return a.val < b.val;//��С��������
    }
}a[MAXN];
int main() {
    int n;
    double sum = 0;//��������
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].name>>a[i].val;
        sum += a[i].val;//�ۼ�
    }
    sum /= n*2;//��n���ٳ�2
    int ans = INF,index = 0;
    for(int i = 1;i <= n;i++) {
        if(abs(a[i].val-sum)<ans) {//�Ҳ�ֵ��С��λ��
            ans = abs(a[i].val-sum);
            index = i;//��¼λ��
        }
    }
    cout<<int(sum)<<" "<<a[index].name;
    return 0;
}
