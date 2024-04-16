/*
Jurnal de Cărți Citite
Scop: Elaborează o clasă Carte pentru a reprezenta cărțile dintr-un jurnal personal.
Clasa va avea membri pentru titlu, autor și număr de pagini citite,
și un constructor pentru inițializarea acestora.
De asemenea, adaugă o clasă Jurnal care gestionează o colecție de cărți citite.

Clasa Carte:

Membri: titlu (string), autor (string), număr de pagini citite (int).
Constructor pentru inițializarea membrilor.

Clasa Jurnal:
Membri: vector de Carte.
Metode pentru adăugarea unei noi cărți și afișarea jurnalului.
*/ 
#include <iostream>
// Instantiem libraria "Carte.h"
#include "Carte.h"
// Adaugam biblioteca care se ocupa de fisiere
#include <fstream>
// Folosim biblioteca pentru a crea un delay
#include <Windows.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define resetare system("CLS");

int contor = 0;
int cnt = 0;

void meniu();
void creare_fisier();
void afisare();
void adaugare_carte();
void iesire();

int main() {	
		meniu();
		creare_fisier();
		afisare();
		adaugare_carte();
		iesire();
}

void meniu() {
	std::cout << "\n\n";
	std::string spatiu = " ";
	for (int i = 0; i < 20; i++) {
		std::cout << spatiu;
		if (i == 18) {
			std::cout << GREEN << "Biblioteca virtuala." << RESET;
		}	
	}
	std::cout << "\n\n\n";
	std::cout << " 1 - Creati un fisier cu extensia biblioteca_virtuala.txt.\n";
	std::cout << " 2 - Adaugati o carte.\n";
	std::cout << " 3 - Afisati toate cartile din biblioteca virtuala.\n";
	std::cout << " 4 - Iesire.\n\n";
	std::cout << " Bibliografie : \n\n";
	std::cout << " La prima rulare a aplicatiei fisierul : fisier_biblioteca.txt. Nu este creat.\n";
	std::cout << " Dupa ce se creaza fisierul se pot adauga Carti. Iar autorii raman salvati in acel afisier\n";
	std::cout << " Iar dupa inchiderea aplicatiei si redeschidere ulterioara se pot vizualiza si adauga Carti.\n";
	std::cout << " fisier_biblioteca.txt se poate deschide din : Biblioteca cu carti/fisier_biblioteca.txt\n\n";
	std::cout << "Optiunea dumneavoastra este : ";
	std::cin >> contor;
	std::cout << "\n\n";
}

void creare_fisier() {
	if (contor == 1) {
		Carte Acces;
		Acces.creare_fisier();
		contor = 0;
		main();
	}
}

void afisare() {
	if (contor == 3) {
		Carte Acces;
		resetare;
		Acces.print_info();
		contor = 0;
		main();
	}
}

void adaugare_carte() {
	if (contor == 2) {
		Carte Acces;
		resetare;
		Acces.preluare_inregistrari();
		Acces.adaugare_carte();
		contor = 0;
		main();
	}
}

void iesire() {
	if (contor == 4) {
		exit(0);
	}
}


	