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

void f2 (float d, float e, float f, float* r3, float* r4, bool *greska1){
	float F = (e*e-4*d*f);
	if (F<0 || d==0){
		*greska1 = true;
	}else {
		*greska1 = false;
		*r3 = (-1*e-sqrt(F))/(2*d);
		*r4 = (-1*e+sqrt(F))/(2*d);
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
	
	cout<<endl;
	
float d,e,f,x3,x4;
bool greska;	
	
cout<<"Unesite koeficijente kvadratne jednacine ax"<<char(253)<<"+bx+c=0 (a,b,c): ";
cin>>d>>e>>f;


f2(d,e,f,&x3,&x4,&greska);
if(greska == true){
	if(d==0){
		cout<<"Greska, ovo nije kvadratna jednacina!";
	}else{
		cout<<"Greska, jednacina nema realna rjesenja!";
	}
}else{
	cout<<"Rjesenja su: ";
	cout<<endl;
	cout<<"x3 = "<<x3<<endl;
	cout<<"x4 = "<<x4<<endl;
}
	
	
	
	return 0;
}
