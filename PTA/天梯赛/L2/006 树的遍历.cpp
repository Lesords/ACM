#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺���ú���������еĸ��ڵ���ȷ������������Ȼ������ݹ�
//��¼ÿ�������ȣ�Ȼ������vector�洢��Ӧ��ȵĽڵ�
//������������ȳ��ֵĽڵ㼴��

const int MAXN= 35;
int tree[MAXN],l[MAXN],r[MAXN],a[MAXN],b[MAXN],hei[MAXN];
//tree��¼���ڵ��ֵ��l��r�ֱ�Ϊ�����Ӷ��ӵı�ţ�a��b�ֱ�Ϊ����������������
//hei��¼���ڵ�����
vector<int> ans[MAXN];//�洢��Ӧ��ȵ����ڵ�
int n,cnt,height;//cntΪ���Ľڵ��ţ�heightΪ����������
void solve(int rt,int left,int right,int L,int R) {
    //rtΪ��ǰ���ڵ㣬left��rightΪ��������ķ�Χ��L��RΪ��������ķ�Χ
    tree[rt] = a[R];
    if(left==right) return;//ֻ��һ���ڵ��򷵻�
    int pos = 0,Lnum = 0,Rnum = 0;//posΪ���ڵ������������λ��
    //LnumΪ�������ڵ�����RnumΪ�������ڵ���
    for(int i = left;i <= right;i++) {
        if(b[i]==a[R]) {//Ѱ�Ҹ��ڵ�λ��
            pos = i;break;
        }//λ��һ�����ҵ������Ը��ڵ��ʼ������ֵ����
    }
    Lnum = pos-left;//�ֱ����������������
    Rnum = right-pos;
    if(pos>left) {//����������
        ++cnt;
        l[rt] = cnt;//��¼����ӵı��
        hei[cnt] = hei[rt]+1;//��¼���
        height = max(height,hei[cnt]);//�����������
        ans[hei[cnt]].push_back(cnt);//��¼��Ӧ��ȵ����ڵ�
        solve(cnt,left,pos-1,L,L+Lnum-1);//�����ݹ�
    }
    if(pos<right) {//����������
        ++cnt;
        r[rt] = cnt;//��¼�Ҷ��ӵı��
        hei[cnt] = hei[rt]+1;//��¼���
        height = max(height,hei[cnt]);//�����������
        ans[hei[cnt]].push_back(cnt);//��¼��Ӧ��ȵ����ڵ�
        solve(cnt,pos+1,right,R-Rnum,R-1);//�����ݹ�
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin>>b[i];
    }
    cnt = 1;
    hei[1] = ++height;
    ans[1].push_back(1);//��ʼ��Ϊ���ڵ�
    solve(1,1,n,1,n);
    int flag = 0;
    for(int i = 1;i <= height;i++) {//�����������
        for(int j = 0;j < ans[i].size();j++) {
            int dot = ans[i][j];//��¼���ǽڵ���
            if(flag) cout<<" ";
            else flag = 1;
            cout<<tree[dot];//����ڵ�ֵ
        }
    }
    return 0;
}
