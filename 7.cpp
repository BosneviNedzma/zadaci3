#include <iostream>
#include <Windows.h>
using namespace std;

struct Bolnica{
	char naziv[100];
	char grad[100];
	int brZaposlenih;
};

struct Odjel{
	Bolnica bolnica;
	char naziv[100];
	float cijenaPoDanu;
};

struct Pacijent{
	char imePrezime[60];
	Odjel odjel;
	int godiste;
	bool osiguran;
};

Pacijent unosPacijenta(){
	Pacijent p;
	cout<<"Unesite ime i prezime pacijenta: ";
	cin.getline(p.imePrezime, 60);
	cout<<"Unesite naziv bolnice u kojoj je pacijent: ";
	cin.getline(p.odjel.bolnica.naziv, 100);
	cout<<"Unesite grad u kojem je bolnica: ";
	cin.getline(p.odjel.bolnica.grad, 100);
	cout<<"Unesite naziv odjela u kojem je pacijent: ";
	cin.getline(p.odjel.naziv, 100);
	cout<<"Unesite cijenu lezanja jednog dana na odjelu: ";
	cin>>p.odjel.cijenaPoDanu;
	cout<<"Unesite godiste pacijenta: ";
	cin>>p.godiste;
	int temp;
	do{
		cout<<"Da li je pacijent osiguran: \n";
		cout<<"\t0 - NE\n";
		cout<<"\t1 - DA\n";
		cout<<"\tOdabir: ";
		cin>>temp;
	}while (temp<0 || temp>1);
	p.osiguran = static_cast<bool>(temp);
	cin.ignore();
	return p;
}

void ispisPacijenta(Pacijent &p){
	cout<<"-------------------------------";
	cout<<"\nPodaci o pacijentu: ";
	cout<<"\nIme i prezime: "<<p.imePrezime<<endl;
	cout<<"Bolnica: "<<p.odjel.bolnica.naziv<<" iz grada "<<p.odjel.bolnica.grad<<". ("<<p.odjel.bolnica.brZaposlenih<<" zaposlenih)"<<endl;
	cout<<"Odjel: "<<p.odjel.naziv<<" - "<<p.odjel.cijenaPoDanu<<" KM cijena po danu."<<endl;
	cout<<"Godina: "<<p.godiste<<endl;
	cout<<"Osiguran: "<<p.osiguran<<endl;
	cout<<"-------------------------------";
}

float cijena (Odjel o, int dan){
	if (dan==0){
		return o.cijenaPoDanu;
	}else {
		return o.cijenaPoDanu+cijena(o, dan-1)*0.95;
	}
}

int main(){

Pacijent novi = unosPacijenta();

ispisPacijenta(novi);

cout<<"Cijena odjela "<<novi.odjel.naziv<<" na 10. dan: "<<cijena(novi.odjel, 10);
float suma = 0;
for (int i=0; i<=10; i++){
	suma += cijena (novi.odjel, i);
}

cout<<"\nUkupna cijena: "<<suma;
	
	return 0;
}
