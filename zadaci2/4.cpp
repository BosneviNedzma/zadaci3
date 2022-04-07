#include <iostream>
#include <Windows.h>
using namespace std;

typedef void (FunkTip)();
void zadatak1(){
	Sleep(1000);
	cout<<"Radni zadatak 1 je zavrsen!";
}
void zadatak2(){
	Sleep(1000);
	cout<<"Radni zadatak 2 je zavrsen!";
}
void zadatak3(){
	Sleep(1000);
	cout<<"Radni zadatak 3 je zavrsen!";
}
void zadatak4(){
	Sleep(1000);
	cout<<"Radni zadatak 4 je zavrsen!";
}

struct Raspored{
	int brojacZadatakNiz = 0;
	FunkTip* zadaci[10];
};

void dodajZadatak(Raspored* todo, FunkTip* noviZadatak){
	todo->zadaci[todo->brojacZadatakNiz++] = noviZadatak;
}

void ukloniZadatak(Raspored* todo){
	int rb;
	cout<<"Unesite redni broj zadatka za obrisati: ";
	cin>>rb;
	todo->brojacZadatakNiz--;
	todo->zadaci[rb] = todo->zadaci[todo->brojacZadatakNiz];
}

void izvrsiZadatke(Raspored* todo){
	for (int i=0; i<todo->brojacZadatakNiz; i++){
		todo->zadaci[i]();
		cout<<endl;
	}
}

int main(){
	
Raspored* danas = new Raspored;
dodajZadatak(danas, zadatak1);
dodajZadatak(danas, zadatak3);
FunkTip* pZ2 = zadatak2;
dodajZadatak(danas, pZ2);

cout<<"Danasnji zadaci: \n";
izvrsiZadatke(danas);
cout<<endl;
ukloniZadatak(danas);
cout<<endl;
izvrsiZadatke(danas);
	
	
	return 0;
}
