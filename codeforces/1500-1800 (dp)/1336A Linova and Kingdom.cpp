#include<iostream>//ac
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����Ҫʹ���Ŀ���ֵ�����ô��Ŀ��Ҫѡ��k����ҵ����
//���ǹ�ҵ����û�й���ֵ�����Կ���ת��Ϊ��Ҫ n-k �����γ���
//��ô����ÿ�����γ����������ӹ�ҵ����ת��Ϊ���γ��еĹ���ֵ�仯Ϊ
// siz[now]-1 - (dep[now]-1)   =>   siz[now]-dep[now]
//ע��sizΪ�����������������Լ�����depΪ��ȣ���1��ʼ�㣩
//Ȼ������nth_element����ǰn-k���ֵ����
//n-k���Ҷ��Ǳ�n-k��ģ��ʸ��Ӷȱ������

const int MAXN = 2e5+5;
int a[MAXN],dep[MAXN],siz[MAXN],val[MAXN];
vector<int> g[MAXN];
bool cmp(int a,int b) {
    return a > b;
}
void dfs(int now, int fa) {
    dep[now] = dep[fa]+1;//���Ϊ����+1
    siz[now] = 1;//��ǰ��������Ϊ1������
    for(int dot:g[now]) {
        if(dot==fa) continue;//��������
        dfs(dot, now);//�ȱ����������
        siz[now] += siz[dot];//��������
    }
    val[now] = siz[now]-dep[now];//����now�Ĺ���ֵ
}
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i < n;i++) {//ֻ��n-1�����ݣ�����
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);//��1��ʼ���������ڵ�
    nth_element(val+1,val+n-k, val+n+1,cmp);//ѡ��ǰn-k�������
    ll ans = 0;//���ݱ�int
    for(int i = 1;i <= n-k;i++) {
        ans += val[i];
    }
    cout<<ans<<"\n";
    return 0;
}
