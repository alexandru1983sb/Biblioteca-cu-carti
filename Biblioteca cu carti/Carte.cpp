#include "Carte.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

int nr_linii = 0;

void Carte::print_info() {
	std::string linie;
	int contor_culoare = 0;
	ifstream fisier("fisier_biblioteca.txt");
	if (fisier.is_open()) {
		while (getline(fisier, linie)) {
			if (contor_culoare == 0) {
				std::cout << CYAN;
			}
			std::cout << linie << "\n";
		}
		std::cout << RESET;
		fisier.close();
	}
	else {
		cout << "Nu putem sa deschidem fisierul.\n";
		std::cout << "Fisierul nu este creat.\n";
		std::cout << "Va rugam sa creati fisierul :-).\n";
		std::cout << RED << "Atentie!! " << RESET << "Fisierul se afla in biblioteca cu carti.\n";
	}
}

void Carte::preluare_inregistrari() {
	
	ifstream fisier("fisier_biblioteca.txt");
	if (fisier.is_open()) {
		std::string line;
		int lineContor = 0;
		while (std::getline(fisier, line)) {
			lineContor++;
		}
		nr_linii = lineContor;
		fisier.close();
	}
}

void Carte::adaugare_carte() {
	std::string spatiu = " ";
	ofstream fisier("fisier_biblioteca.txt", std::ios::app);
	if (fisier.is_open()) {
		std::string spatii = " ";
		// Adaugam automat nr cartii
		std::cout << "Nr. carte : " << nr_linii;
		nr_carte << nr_linii;
		std::cout << "\n";
		fisier << nr_linii << " ";
		
		// Adaugam manual Numele autorului
		std::cout << "Nume autor : ";
		std::cin >> numeAutor;
		std::cout << "\n";
		fisier << numeAutor << " ";
		int Nume_Autor = numeAutor.size();
		for (int i = 0; i < 15 - Nume_Autor; i++) {
			fisier << spatiu;
		}
		
		// Adaugam manual Prenumele autorului
		std::cout << "Prenumele autor : ";
		std::cin >> prenumeAutor;
		std::cout << "\n";
		fisier << prenumeAutor << " ";
		int Prenume_Autor = prenumeAutor.size();
		for (int i = 0; i < 15 - Prenume_Autor; i++) {
			fisier << spatiu;
		}
		
		// Adaugam manual Titlul cartii
		std::cout << "Titlul : ";
		std::cin >> Titlu_carte;
		std::cout << "\n";
		fisier << Titlu_carte << " ";
		int Titlu_Autor = Titlu_carte.size();
		for (int i = 0; i < 15 - Titlu_Autor; i++) {
			fisier << spatiu;
		}
		
		// Adaugam manual nr de pagini
		std::cout << "Numar pagini carte : ";
		std::cin >> nr_pagini_carte;
		std::cout << "\n";
		fisier << nr_pagini_carte << " ";
		if (nr_pagini_carte <= 9) {
			for (int i = 0; i < 5; i++) {
				fisier << spatiu;
			}
		}
	    if (nr_pagini_carte <= 99) {
			for (int i = 0; i < 4; i++) {
				fisier << spatiu;
			}
		}
		
		// Adaugam manual nr de pagini citite
		std::cout << "Numar pagini citite : ";
		std::cin >> nr_pagini_citite;
		std::cout << "\n";
		fisier << nr_pagini_citite << std::endl;
		fisier.close();
	}
	else cout << "Nu putem sa deschidem fisierul\n";
}

void Carte::creare_fisier(){
	std::ofstream fisier("fisier_biblioteca.txt");
	if (fisier.is_open()) {
		fisier << 0 << " ";
		fisier << "Nume Autor     " << " ";
		fisier << "Prenume Autor  " << " ";
		fisier << "Titlul cartii  " << " ";
		fisier << "Pagini" << " ";
		fisier << "Citite" << std::endl;
		fisier.close();
	}
	else std::cout << "Eroare fisier\n";
	system("CLS");
	std::cout << "Facem un fisier : fisier_biblioteca.txt\n";
	std::string caracter;
	caracter = static_cast<char>(175);
	for (int i = 0; i < 20; i++) {
		std::cout << caracter;
		Sleep(150);
	}
	system("CLS");
	std::cout << GREEN << "Fisierul a fost creat.\n" << RESET;
	
}






