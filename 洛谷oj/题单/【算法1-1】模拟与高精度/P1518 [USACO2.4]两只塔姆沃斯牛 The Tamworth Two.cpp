#include<cstdio>//ac
#include<iostream>
#include<algorithm>
using namespace std;
int vis[11][11][11][11][5][5];//ר�ҵ����꣬ţ�����꣬ר�ҵķ���ţ�ķ���
int fx,fy,fdir,cx,cy,cdir;
int nextt[4][2] = {-1,0,0,1,1,0,0,-1};//���ϡ��ҡ��¡��� (0,1,2,3) �ߣ�����
char s[12][12];
bool judge() {//�ж��Ƿ�ץ��ţ��
    if(fx==cx&&fy==cy) return 0;
    return 1;
}
void change() {//�ƶ�ţ���˵�λ��
    int tx = fx+nextt[fdir][0];
    int ty = fy+nextt[fdir][1];//�������λ��
    //�ж��Ƿ�Խ�����ǽ������ת�򣬷���ǰ��
    if(tx<1||tx>10||ty<1||ty>10||s[tx][ty]=='*') fdir = (fdir+1)%4;
    else fx = tx,fy = ty;
    tx = cx+nextt[cdir][0];
    ty = cy+nextt[cdir][1];//ţ�����λ��
    if(tx<1||tx>10||ty<1||ty>10||s[tx][ty]=='*') cdir = (cdir+1)%4;
    else cx = tx,cy = ty;
}
int main() {
    for(int i = 1;i <= 10;i++) scanf("%s",s[i]+1);//��ͼ
    for(int i = 1;i <= 10;i++) {
        for(int j = 1;j <= 10;j++) {//��ţ���˵�λ��
            if(s[i][j]=='F') fx=i,fy=j;
            if(s[i][j]=='C') cx=i,cy=j;
        }
    }
    int flag = 0,ans = 0;//flag�ж��Ƿ��н�
    fdir = cdir = 0;//��ʼ��������
    while(judge()) {//��δץ���ͼ���
        if(vis[fx][fy][cx][cy][fdir][cdir]++) {//�ظ���λ�úͷ�����˵���޽⣡����
            flag = 1;break;
        }
        ans++;
        change();
    }
    cout<<(flag?0:ans);
    return 0;
}
