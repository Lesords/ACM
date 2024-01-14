#include<cstdio>//ac
#include<algorithm>
using namespace std;

//��⣺��Ȩֵ�߶�������¼ÿ��ֵ���ֵ�λ�ã�ά������������λ��
// (1,pos) ��pos��ԭ����ֵ��λ���޸ĳ�n+1����ԭ������ɾ����
// (1,r,k) ����ֵ��[k,n]��ȡλ�ô���r����Сֵ

const int MAXN = 1e5+5;
struct node {
    int l,r,index;//index��¼ֵ��λ�ã������������λ��
}tree[MAXN<<2];
int a[MAXN],val[MAXN],n,m;//val��¼ֵ��a��¼��Ӧֵ��λ��
void build(int dot,int l,int r) {//��ʼ���߶���
    tree[dot].l = l,tree[dot].r = r;//�ýڵ����������
    if(l==r) {//Ҷ�ӽ��
        tree[dot].index = a[l];//����l���ֵ�λ��
        return;
    }
    int mid = (l+r)/2;
    build(dot<<1,l,mid);//������
    build(dot<<1|1,mid+1,r);//������
    //���½ϴ����λ��
    tree[dot].index = max(tree[dot<<1].index,tree[dot<<1|1].index);
}
void change(int dot,int val) {//�޸Ľڵ������dot�ǽڵ��±꣬val���޸ĵ�ֵ��
    int l = tree[dot].l,r = tree[dot].r;//��������
    if(l==r&&l==val) {//Ҷ�ӽڵ���ֵΪval
        tree[dot].index = n+1;//�޸�λ��
        return ;
    }
    int mid = (l+r)/2;
    if(val<=mid) change(dot<<1,val);//�ݹ��޸İ���val������
    else change(dot<<1|1,val);
    //�������λ��
    tree[dot].index = max(tree[dot<<1].index,tree[dot<<1|1].index);
}
int query(int dot,int l,int r,int index) {//��ѯ[l,r]������λ�ô���index����Сֵ
    if(l <= tree[dot].l && tree[dot].r <= r) {//��ѯ������ڽڵ�����
        if(tree[dot].l==tree[dot].r) {//Ҷ�ӽڵ�
            if(tree[dot].index>index) return tree[dot].l;
            else return n+1;
        }
        //�ж������ӽڵ��ĸ���λ�ô���index�������ж���ӦΪֵС��
        if(tree[dot<<1].index>index) return query(dot<<1,l,r,index);
        if(tree[dot<<1|1].index>index) return query(dot<<1|1,l,r,index);
        return n+1;
    }
    int mid = (tree[dot].l+tree[dot].r)/2;
    int ans = n+1;//��ʼ��Ϊn+1
    //ֻ�жϵ��࣬δ�ж���һ�࣬������Ҫд��ѯ���䣨l��r��Ϊͬһ��ʱ��ȡmid�����ԭֵ��������
    if(mid>=l) ans = query(dot<<1,l,r,index);//�������а�������ѯ���䲻�䣡������
    if(mid<r) ans = min(ans,query(dot<<1|1,l,r,index));//�������а�����ȡС��
    return ans;//���ؽ��
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) {
            scanf("%d",&val[i]);a[val[i]] = i;
            //�������ݣ�����¼��Ӧֵ��λ�ã�λ��Ϊ�±꣩
        }
        build(1,1,n);//��ʼ��Ȩֵ�߶���
        int op,x,y,last = 0;
        for(int i = 1;i <= m;i++) {
            scanf("%d%d",&op,&x);
            if(op==1) {
                x ^= last;//xΪ�����޸�ֵ���±�
                change(1,val[x]);
            }
            else {
                scanf("%d",&y);
                x ^= last;//r��ֵ
                y ^= last;//k��ֵ
                last = query(1,y,n,x);//����last
                printf("%d\n",last);
            }
        }
    }
    return 0;
}
