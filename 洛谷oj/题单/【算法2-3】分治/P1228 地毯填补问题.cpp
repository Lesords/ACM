#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���η���ԭ�����Թ��ֳ��Ĳ���
//��������д��λ�������õ�̺���ֽ�λ�ò���������д��λ�ã��ս���б����
//�����м�㣨���Ͻ���������½�λ�ã������+���ȵ�һ��-1������
//Ȼ����ά���ĸ�λ�õ����ݼȿ�

int k,px,py,width;//widthΪ��ȣ�(px,py)Ϊ������λ��
void dfs(int x,int y,int sx,int sy,int len) {
    //(x,y)Ϊ����д��λ�� (sx,sy)Ϊ�������Ͻǵ����꣬lenΪ���䳤��
    if(len==1) return;//����Ϊ1��������
    int midx = sx+len/2-1;//�����м�㣡������len��һ�������㣩
    int midy = sy+len/2-1;
    if(x<=midx&&y<=midy) {//���Ͻ���������д
        cout<<midx+1<<" "<<midy+1<<" 1\n";//��̺���������½�λ��
        dfs(x,y,sx,sy,len/2);//���¶�Ӧ��д��λ�ú����λ��
        dfs(midx,midy+1,sx,sy+len/2,len/2);
        dfs(midx+1,midy,sx+len/2,sy,len/2);
        dfs(midx+1,midy+1,sx+len/2,sy+len/2,len/2);
    }
    if(x<=midx&&y>midy) {//���Ͻ���������д
        cout<<midx+1<<" "<<midy<<" 2\n";//��̺���������½�λ��
        dfs(midx,midy,sx,sy,len/2);
        dfs(x,y,sx,sy+len/2,len/2);
        dfs(midx+1,midy,sx+len/2,sy,len/2);
        dfs(midx+1,midy+1,sx+len/2,sy+len/2,len/2);
    }
    if(x>midx&&y<=midy) {//���½�λ������д
        cout<<midx<<" "<<midy+1<<" 3\n";//��̺���������Ͻ�λ��
        dfs(midx,midy,sx,sy,len/2);
        dfs(midx,midy+1,sx,sy+len/2,len/2);
        dfs(x,y,sx+len/2,sy,len/2);
        dfs(midx+1,midy+1,sx+len/2,sy+len/2,len/2);
    }
    if(x>midx&&y>midy) {//���½�λ������д
        cout<<midx<<" "<<midy<<" 4\n";//��̺���������Ͻ�λ��
        dfs(midx,midy,sx,sy,len/2);
        dfs(midx,midy+1,sx,sy+len/2,len/2);
        dfs(midx+1,midy,sx+len/2,sy,len/2);
        dfs(x,y,sx+len/2,sy+len/2,len/2);
    }
}
int main() {
    cin>>k>>px>>py;
    width = 1<<k;//�������䳤��
    dfs(px,py,1,1,width);
    return 0;
}
