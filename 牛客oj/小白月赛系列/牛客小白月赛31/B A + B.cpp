#include<iostream>//ac
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
string s[5];
string val[11] = {"####.##.##.####", "..#..#..#..#..#", "###..#####..###",
"###..####..####", "#.##.####..#..#", "####..###..####", "####..####.####",
"####.##.#..#..#", "####.#####.####", "####.####..####", "....#.###.#...."};
map<string,int> num;//val������ת�ַ�����num���ַ���ת����
vector<int> pnum;//�����������������λ
int main() {
    for(int i = 0;i <= 10;i++) num[val[i]] = i;//��¼��Ӧ�ַ���������
    int t;
    cin>>t;
    while(t--) {
        getchar();//����س���
        for(int i = 0;i < 5;i++) {
            getline(cin,s[i]);
        }
        int len = s[0].size(),ans = 0,tnum = 0;//ansΪ��������tnumΪÿ�����ֵ
        for(int i = 0;i < len;i += 4) {//4��Ϊһ������
            string tmp = "";
            for(int j = 0;j < 5;j++) {
                for(int z = i;z <= i+2;z++) {
                    tmp += s[j][z];//�����ַ���
                }
            }
            if(num[tmp]==10) {//Ϊ�Ӻ�ʱ
                ans += tnum;//��ӽ��
                tnum = 0;//����
            }
            else {
                tnum = tnum*10 + num[tmp];//��������
            }
        }
        ans += tnum;//�������һ������
        pnum.clear();//����գ�����
        while(ans) {
            pnum.push_back(ans%10);//�洢ÿ����λ
            ans /= 10;
        }
        int snum = pnum.size()-1;//��λ����
        for(int i = 0;i < 5;i++) {//�������������
            for(int j = snum;j >= 0;j--) {//��snum��
                if(j!=snum) cout<<".";//�м����� .
                for(int z = i*3;z < i*3+3;z++) {//pnum[j]Ϊ��ǰ����
                    cout<<val[pnum[j]][z];//zΪ�����λ��
                }
            }
            cout<<"\n";
        }
        if(t) cout<<"\n";//�м�����
    }
    return 0;
}
