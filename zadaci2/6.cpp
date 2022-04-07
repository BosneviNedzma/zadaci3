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

FunkTip* odaberiZadatak(){
	int x;
	do{
		cout<<"Odaberite broj zadataka(1-4): ";
		cin>>x;
	}while (x<1 || x>4);
	
	switch(x){
		case 1:
			return zadatak1;
			break;
		case 2: 
		    return zadatak2;
		    break;
	    case 3:
	    	return zadatak3;
	    	break;
	    case 4:
	    	return zadatak4;
	    	break;
	    default:
	    	return zadatak1;
	}
	
}

int main(){
	
Raspored* danas = new Raspored;

cout<<"Odaberite zadatke za danas: "<<endl;
for (int i=0; i<4; i++){
	dodajZadatak(danas, odaberiZadatak());
}
izvrsiZadatke(danas);

	
	
	return 0;
}
