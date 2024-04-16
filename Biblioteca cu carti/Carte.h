#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class Carte
{
private:
	// Atribute
	int nr_carte = 0;
	std::string numeAutor;
	std::string prenumeAutor;
	std::string Titlu_carte;
	int nr_pagini_carte = 0;
	int nr_pagini_citite = 0;
	// Metoda
public:
	void print_info();
	void preluare_inregistrari();
	void adaugare_carte();
	void creare_fisier();
};



