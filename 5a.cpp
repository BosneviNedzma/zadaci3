#include <iostream>
using namespace std;

struct Drzava{
	char naziv[100];
	char kontinent[100];
	int brStanovnika;
};

struct Grad{
	Drzava drzava;
	char naziv[100];
	int brStanovnika;
};

struct Stanovnik{
	char imePrezime[100];
	Grad grad;
	int godiste;
	bool zaposlen;
};

Stanovnik unosStanovnika(){
	Stanovnik s;
	cout<<"Unesite ime i prezime stanovnika: ";
	cin.getline(s.imePrezime,100);
	cout<<"Unesite naziv drzave iz koje je stanovnik: ";
	cin.getline(s.grad.drzava.naziv, 100);
	cout<<"Unesite kontinent drzave: ";
	cin.getline(s.grad.drzava.kontinent, 100);
	cout<<"Unesite broj stanovnika drzave: ";
	cin>>s.grad.drzava.brStanovnika;
	cout<<"Unesite naziv grada iz kojeg je stanovnik: ";
	cin.getline(s.grad.naziv, 100);
	cout<<"Unesite broj stanovnika grada: ";
    cin>>s.grad.brStanovnika;
    cout<<"Unesite godiste stanovnika: ";
    cin>>s.godiste;
    int temp;
    do{
    	cout<<"Da li je stanovnik zaposlen: "<<endl;
    	cout<<"\t0 - NE\n";
    	cout<<"\t1 - DA\n";
    	cout<<"\tOdabir: ";
    	cin>>temp;
	}while (temp<0 || temp>1);
    s.zaposlen = (static_cast<bool>(temp));
	cin.ignore();
	return s;
	}

void ispisStanovnika(Stanovnik s){

	cout<<"----------------------------------------"<<endl;
	cout<<"Ime i prezime: "<<s.imePrezime<<endl;
	cout<<"Grad: "<<s.grad.naziv<<" ("<<s.grad.brStanovnika<<" stanovnika)"<<endl;
	cout<<"Drzava: "<<s.grad.drzava.naziv<<" - "<<s.grad.drzava.kontinent<<" ("<<s.grad.drzava.brStanovnika<<" stanovnika)"<<endl;
	cout<<"Godina: "<<2022-s.godiste<<endl;
	cout<<"Zaposlenje: "<<s.zaposlen<<endl;
	cout<<"----------------------------------------";
}

int prirastajStanovnika(Drzava A, int n){
	if (n==0){
		return A.brStanovnika;
	}else {
		return A.brStanovnika+prirastajStanovnika(A, n-1 )*0.01;
	}
}

int main(){
	
	Stanovnik novi = unosStanovnika();
	
	ispisStanovnika(novi);
	int a;
	cout<<endl;
	cout<<"Unesite broj godina za koji zelite vidjeti prirastaj stanovnika drzave unesenog stanovinka: ";
	cin>>a;
	cout<<"\nNakon "<<a<<" godina ce biti "<<prirastajStanovnika(novi.grad.drzava, a)<<" stanovnika.";
	
	
	
	
	
	
	
	return 0;
}
