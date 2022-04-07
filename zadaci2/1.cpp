#include <iostream>
#include <cmath>
using namespace std;

void f1(float a, float b, float c, float &r1, float &r2, bool &greska){
	float D = (b*b-4*a*c);
	if (D<0 || a==0){
		greska = true;
	}else {
		greska = false;
		r1 = (-1*b+(sqrt(D)))/(2*a);
		r2 = (-1*b-(sqrt(D)))/(2*a);
	}
}



int main(){
	
float a,b,c,x1,x2;
bool error;
cout<<"Unesite koeficijente kvadratne jednacine ax"<<char(253)<<"+bx+c=0 (a,b,c): ";
cin>>a>>b>>c;

void (*pf1)(float, float, float, float&, float&, bool&) = f1;
pf1(a,b,c,x1,x2,error);
if(error == true){
	if(a==0){
		cout<<"Greska, ovo nije kvadratna jednacina!";
	}else{
		cout<<"Greska, jednacina nema realna rjesenja!";
	}
}else{
	cout<<"Rjesenja su: ";
	cout<<endl;
	cout<<"x1 = "<<x1<<endl;
	cout<<"x2 = "<<x2<<endl;
}
	
	
	
	
	
	
	
	
	
	return 0;
}
