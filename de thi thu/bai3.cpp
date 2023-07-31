#include <iostream>
using namespace std;

int main(){
	int viettel;
	string n;
	do{
	
	cin>>n;
	if (n.size()>11 || n.size()<10 || n[0]!='0') cout<<"vui long nhap so dien thoai hop le\n";
	
	} while (n.size()>11 || n.size()<10 || n[0]!='0');
	
	if (
	n[0] == '0' && n[1]== '9' 
	&& (n[2]== '6' || n[2]=='7' || n[2]=='8')
	) viettel=1;
	
	if (
	n[0] == '0' && n[1]== '1'&& n[2]== '6' && (n[3]=='2' || n[3]=='3' || n[3]=='4' || n[3]=='5' || n[3]=='6' || n[3]=='7' || n[3]=='8' || n[3]=='9')
	) viettel=1;
	
	if (viettel==1) cout<<"so dien thoai thuoc mang viettel voi "<<n.size()<<" chu so"; 
	else cout<<"so dien thoai tren khong thuoc mang viettel voi "<<n.size()<<" chu so";
	
	return 0;
}
