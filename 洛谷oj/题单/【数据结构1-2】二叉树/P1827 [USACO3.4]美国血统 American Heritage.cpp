#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
char a[MAXN],b[MAXN],val[MAXN];//a������������飬bǰ��������飬val�浱ǰ�ڵ���ַ�
int len,cnt,Left[MAXN],Right[MAXN];//cntΪ�ڵ��ţ�LeftΪ����ӣ�RightΪ�Ҷ���
int idx(char ch) {//�ַ�ת����
    return ch-'A';
}
//idΪ��ǰ�ڵ��ţ�l��rΪǰ��������䣬L��RΪ�����������
void solve(int id,int l,int r,int L,int R) {
    if(l>r) return;
    char rt = b[l];//�����ַ�
    val[id] = rt;//�洢��ǰ�ڵ���ַ�
    int pos = 0;//�洢����������������λ��
    for(int i = L;i <= R;i++) {//Ѱ�Ҹ���������������λ��
        if(a[i]==rt) {
            pos = i;break;
        }
    }
    int lnum = pos-L;//������������
    int rnum = R-pos;//������������
    if(lnum) {//�������������
        ++cnt;
        Left[id] = cnt;//��¼��ǰ�ڵ�������
        //��lΪ�߽�+lnum
        solve(cnt,l+1,l+lnum,L,pos-1);
    }
    if(rnum) {//�������������
        ++cnt;
        Right[id] = cnt;//��¼��ǰ�ڵ���Ҷ���
        //��rΪ�߽�-rnum+1
        solve(cnt,r-rnum+1,r,pos+1,R);
    }
}
void postorder(int rt) {//�������
    if(Left[rt]) {
        postorder(Left[rt]);
    }
    if(Right[rt]) {
        postorder(Right[rt]);
    }
    cout<<val[rt];
}
int main() {
    cin>>a+1>>b+1;
    len = strlen(a+1);
    cnt = 1;//��ʼ��Ϊ1������
    solve(1,1,len,1,len);
    postorder(1);
    return 0;
}
