#include<iostream>//ac
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺�������ݷ�Χֻ��100�����Ա����ж�ÿ�����Ӷ�Ա�Ƿ񱻻�ɱ
//��û�б���ɱ������ʣ��ĳ��Ӷ�Ա���ж�б����ͬ��һͬ��ɱ

const int MAXN = 1e3+5;
struct node{
    int x,y;
};
vector<node> v;
int vis[MAXN];//��¼�Ƿ񱻻�ɱ
int main() {
    int n,x,y,ans = 0;
    cin>>n>>x>>y;
    for(int i = 1;i <= n;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});//��¼���г��Ӷ�Ա��λ��
    }
    for(int i = 0;i < n;i++) {
        if(vis[i]) continue;//�����ѻ�ɱ��
        ans += vis[i] = 1;//����״̬�ͽ��
        int disx = v[i].x-x;
        int disy = v[i].y-y;//�����ֵ
        for(int j = i+1;j < n;j++) {
            int tmpx = v[j].x-x;
            int tmpy = v[j].y-y;//�����ֵ
            if(disx*tmpy==disy*tmpx) vis[j] = 1;//б����ͬ��һͬ��ɱ
            //�ж�б�ʿɽ�����ת��Ϊ�ˣ�Ȼ�����ж�
        }
    }
    cout<<ans;
    return 0;
}
