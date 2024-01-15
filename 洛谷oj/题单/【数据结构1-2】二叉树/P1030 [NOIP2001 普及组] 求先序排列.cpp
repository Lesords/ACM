#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
char a[MAXN],b[MAXN],tree[MAXN];//a������������飬b�Ǻ���������飬tree�洢�ڵ���ַ�
int len,cnt,l[MAXN],r[MAXN];//cntΪ�ڵ�ı�ţ�l������ӵı�ţ�r���Ҷ��ӵı��
//idΪ��ǰ�ڵ��ţ�left��rightΪ����������䣬L��RΪ�����������
void solve(int id,int left,int right,int L,int R) {
    if(left>right) return;
    char rt = b[right];//�洢���ڵ��ַ�
    tree[id] = rt;
    int pos = 0;//��¼��������и��ڵ��ַ���λ��
    for(int i = L;i <= R;i++) {//Ѱ�Ҹ��ڵ��ַ���λ��
        if(a[i]==rt) {
            pos = i;break;
        }
    }
    int lnum = pos-L;//��������������
    int rnum = R-pos;//��������������
    if(lnum) {//�������������
        l[id] = ++cnt;//��¼��ǰ�ڵ�������
        //��leftΪ��߽磬lnumΪ���䳤��
        solve(cnt, left,left+lnum-1,L,pos-1);
    }
    if(rnum) {//�������������
        r[id] = ++cnt;//��¼��ǰ�ڵ���Ҷ���
        //Ϊright-1Ϊ�ұ߽磬rnumΪ���䳤��
        solve(cnt, right-rnum,right-1,pos+1,R);
    }
}
void preorder(int rt) {//�������
    cout<<tree[rt];
    if(l[rt]) {
        preorder(l[rt]);
    }
    if(r[rt]) {
        preorder(r[rt]);
    }
}
int main() {
    cin>>a+1>>b+1;
    len = strlen(a+1);//���������1������
    cnt = 1;
    solve(1,1,len,1,len);
    preorder(1);
    return 0;
}
