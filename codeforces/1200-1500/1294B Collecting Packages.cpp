#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺��x��y�Ĺ������򣬴�ͷ��ʼ�ߣ����y����ָ������޽�
//x��y���Ӧ���뼴ΪR��U���ֵĴ���

const int MAXN = 1e3+5;
struct node{
    int x,y;
    friend bool operator < (node a,node b) {
        //��x��y��˳������
        if(a.x!=b.x) return a.x < b.x;
        return a.y < b.y;
    }
}a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,flag = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i].x>>a[i].y;
        }
        sort(a+1,a+1+n);
        string ans = "";
        for(int i = 1;i <= n;i++) {
            int dis_x = a[i].x - a[i-1].x;
            int dis_y = a[i].y - a[i-1].y;
            if(dis_y<0) {//y���ܳ��ָ����������ߣ��������޽�
                flag = 1;break;
            }
            for(int j = 1;j <= dis_x;j++) ans += 'R';//dis_x��R
            for(int j = 1;j <= dis_y;j++) ans += 'U';//dis_y��U
        }
        if(flag) {//�޽�
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n"<<ans<<"\n";
    }
    return 0;
}
