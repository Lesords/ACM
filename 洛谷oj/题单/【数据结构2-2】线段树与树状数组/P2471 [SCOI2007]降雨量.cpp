#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺�߶���+��������
//���Խ���Ŀת����������ʽ��
//����a��b���ж� (a,b) �ڵ�ֵ�Ƿ�С��b��ֵ������a���ڵ���b
//�����±꽨�߶��������ڲ�ѯ��Ӧ��������ֵ
//Ȼ����Ҫ�жϸ��������������Ƿ����
//1. ���b������
//�ж�a���ڲ����ڣ���a���ڣ���a��Ҫ���� (a,b) �����ֵ������Ϊfalse
//���a�����ڣ���ôΪmaybe
//2. ���a������
//����b�������Ѿ��ų��ˣ����Դ�ʱb�Ǵ��ڵģ�����
//��ô���a��b���Ϊ1������a��b�м�û��������¼����ݣ���Ϊmaybe
//��� (a,b) �����ֵ���ڵ���b����Ϊfalse
//����Ϊmaybe
//3. ��ʱa��b��Ϊ����
//ֱ���ж� (a,b) �����ڵ�ֵ�Ƿ�С��b������a��ֵҪ���ڵ���b
//ֻ����һ�������㣬��Ϊfalse
//Ȼ�����Ҫ�ж� a��b ֮���Ƿ������δ��¼������У���Ϊmaybe
//����Ϊtrue

const int MAXN = 5e4+5;
struct node{
    int l, r, maxx;//maxx��¼��Ӧ��������ֵ
}tree[MAXN<<2];
int year[MAXN],rain[MAXN];//yearΪ��ݣ�rainΪ������
//��ǰ�ڵ�Ϊrt��[l,r]Ϊ��������
void build(int rt, int l,int r) {
    tree[rt] = {l, r, -INF};
    if(l==r) {
        tree[rt].maxx = rain[l];
        return ;
    }
    int mid = (l+r)/2;
    build(rt*2, l, mid);
    build(rt*2+1, mid+1, r);
    tree[rt].maxx = max(tree[rt*2].maxx, tree[rt*2+1].maxx);
}
//rtΪ��ǰ�ڵ㣬[l,r]Ϊ��ѯ����
int query(int rt,int l,int r) {
    int L = tree[rt].l;//��ǰ�ڵ�����
    int R = tree[rt].r;
    //����������ֱ�ӷ����������ֵ
    if(l<=L&&R<=r) return tree[rt].maxx;
    int mid = (L+R)/2;
    int ans = -INF;//��ʼ��Ϊ-INF
    //�ֱ��������������ֵ
    if(l<=mid) ans = max(ans, query(rt*2, l, r));
    if(r>mid) ans = max(ans, query(rt*2+1, l, r));
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>year[i]>>rain[i];
    build(1, 1, n);
    cin>>m;
    while(m--) {
        int a,b;
        cin>>a>>b;//��a�꿪ʼ��bֵ���
        if(a>b) {
            cout<<"false\n";continue;
        }
        int pos_a = lower_bound(year+1, year+1+n, a)-year;
        int pos_b = lower_bound(year+1, year+1+n, b)-year;
        int is_a = a==year[pos_a]&&(pos_a<=n);//�ж�a�Ƿ����
        int is_b = b==year[pos_b]&&(pos_b<=n);//�ж�b�Ƿ����
        //���b������
        if(!is_b) {
            //aλ�ò���С��bλ�ã�����
            if(is_a) {
                int maxx = query(1, pos_a+1, pos_b-1);
                //�м䲿�ֿ϶�ҪС��bλ�ã�����aλ�ò���С�ڵ����м�λ�ã�����
                if(rain[pos_a]<=maxx) {
                    cout<<"false\n";continue;
                }
            }
            cout<<"maybe\n";continue;
        }
        //���a�����ڣ���ʱb����
        if(!is_a) {
            if(a+1==b||pos_a==pos_b) {
                cout<<"maybe\n";continue;
            }
            int maxx = query(1, pos_a, pos_b-1);
            if(maxx>=rain[pos_b]) {//�м�ֵ����b��ֵ��Ϊfalse
                cout<<"false\n";continue;
            }
            cout<<"maybe\n";continue;
        }
        //��ʱa��b������
        int maxx = query(1, pos_a+1, pos_b-1);//�����м��ֵ
        //�м�ֵ���ܴ��ڵ���b��ֵ��a��ֵ����С��b��ֵ
        if(maxx>=rain[pos_b]||rain[pos_a]<rain[pos_b]) {
            cout<<"false\n";continue;
        }
        //������ݶ���¼����Ϊtrue
        if(b-a==pos_b-pos_a) cout<<"true\n";
        else cout<<"maybe\n";
    }
    return 0;
}
