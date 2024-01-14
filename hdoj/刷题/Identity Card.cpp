#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		string tmp,pos,day,year,month;//定义可初始化为空
		cin>>tmp;
		for(int i = 0;i < 2;i++) pos += tmp[i];
		for(int i = 6;i < 10;i++) year += tmp[i];
		for(int i = 10;i < 12;i++) month += tmp[i];
		for(int i = 12;i < 14;i++) day += tmp[i];
		cout<<"He/She is from ";
		if(pos=="33") cout<<"Zhejiang";
		else if(pos=="11") cout<<"Beijing";
		else if(pos=="71") cout<<"Taiwan";
		else if(pos=="81") cout<<"Hong Kong";
		else if(pos=="82") cout<<"Macao";
		else if(pos=="54") cout<<"Tibet";
		else if(pos=="21") cout<<"Liaoning";
		else if(pos=="31") cout<<"Shanghai";
		cout<<",and his/her birthday is on "<<month<<','<<day;
		cout<<','<<year<<" based on the table."<<endl;
	}
	return 0;
} 
