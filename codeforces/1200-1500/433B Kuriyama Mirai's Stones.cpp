#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺ԭ����ǰ׺��+��������ǰ׺��

const int MAXN = 1e5+5;
ll a[MAXN],b[MAXN],sumA[MAXN],sumB[MAXN];
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],b[i] = a[i];
    sort(b+1,b+1+n);//����
    for(int i = 1;i <= n;i++) {//ǰ׺��
        sumA[i] = sumA[i-1] + a[i];
        sumB[i] = sumB[i-1] + b[i];
    }
    cin>>m;
    for(int i = 1;i <= m;i++) {
        int op,l,r;
        cin>>op>>l>>r;
        //op�ж����ĸ�����������
        if(op==1) cout<<sumA[r]-sumA[l-1]<<"\n";
        else cout<<sumB[r]-sumB[l-1]<<"\n";
    }
    return 0;
}
