/*by Qkolj, 2019
  za filozofiju*/

#include "pch.h"
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
#include <cmath>

#define MAX 10000

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //za boju teksta
using namespace std;

void enkript(long n) {

	srand(n); // seed za (pseudo)nasumicne brojeve (kljuc)

	int range = 1000 - 100 + 1;     // Generise jedan broj za kasniju operaciju
	int y = rand() % range + 100;

	char niz[MAX];
	float arr[MAX];
	string ulaz[MAX];
	int i = 0;

	while (getline(cin, ulaz[i])) {      // uzima input iz vise linija dok se ne otkuca "stop"
		if (ulaz[i] == "stop" || ulaz[i] == "STOP" || ulaz[i] == "Stop") {
			ulaz[i].clear();
			break;
		}
		i++;
	}
	cout << "Obradjen tekst je: " << endl;
	SetConsoleTextAttribute(hConsole, 11); // sve ovakve linije menjaju boju teksta, 11 je svetloplava boja
	for (int j = 0; j < i; j++) {
		int duzina = ulaz[j].length();
		for (int i = 0; i < duzina; i++) { // generise random broj za svaki uneti karakter
			arr[i] = rand() % 100 + 1;
		}

		for (int i = 0; i < duzina; i++) {  
			int x = y / arr[i];
			niz[i] = ulaz[j][i] + x;   // za enkripciju | povecava vrednost karaktera za x koje se dobija od y generisanog na pocetku i malopre generisanog broja
			//niz[i] = ulaz[j][i] - x;	  // za dekripciju
			if (niz[i] == 127) {
				niz[i] = 14;
			}
			cout << niz[i]; //ispisuje promenjen karakter
		}
		cout << endl;
	}
}

void dekript(long n) { // isto kao enkript samo suprotno

	srand(n);

	int range = 1000 - 100 + 1;
	int y = rand() % range + 100;

	char niz[10000];
	float arr[10000];
	string ulaz[10000];
	int i = 0;

	while (getline(cin, ulaz[i])) {
		if (ulaz[i] == "stop" || ulaz[i] == "STOP" || ulaz[i] == "Stop") {
			ulaz[i].clear();
			break;
		}
		i++;
	}
	cout << "Obradjen tekst je: " << endl;
	SetConsoleTextAttribute(hConsole, 11);
	for (int j = 0; j < i; j++) {
		int duzina = ulaz[j].length();
		for (int i = 0; i < duzina; i++) {
			arr[i] = rand() % 100 + 1;
		}

		for (int i = 0; i < duzina; i++) {
			int x = y / arr[i];
			if (ulaz[j][i] == 14) {
				ulaz[j][i] = 127;
			}
			//niz[i] = ulaz[j][i] + x;   // za enkrpiciju
			niz[i] = ulaz[j][i] - x;	  // za dekripciju
			cout << niz[i];
		}
		cout << endl;
	}
}

void pokreni() { // uzima unos od korisnika i pokrece enkripciju/dekripciju 
	SetConsoleTextAttribute(hConsole, 15);
	float kljuc;
	char provera;
	do {
		cout << "Za enkripciju pritisni E, za dekripciju D" << endl;
		cin >> provera;
		if (provera == 'E' || provera == 'e' || provera == 'D' || provera == 'd')
			break;
	} while (provera != 'E' || provera != 'e' || provera != 'D' || provera != 'd');

	cout << "Unesite svoj kljuc:" << endl;
	cin >> kljuc;

	cout << "Unesite tekst, u poslednjoj liniji napisite stop da prekinete unos" << endl;
	if (provera == 'E' || provera == 'e')
		enkript(kljuc);
	if (provera == 'D' || provera == 'd')
		dekript(kljuc);
}
 
void start() { // skelet programa, pre nego se izvede f-ja pokreni() posle, omogucava ponovno koriscenje
	string pocetna;
	do {
		cout << "Ukucaj 'start' za pokretanje" << endl;
		getline(cin, pocetna);
		if (pocetna == "start" || pocetna == "START" || pocetna == "Start") {
			pokreni();
			break;
		}
	} while (pocetna != "start" || pocetna != "START" || pocetna != "Start");

	SetConsoleTextAttribute(hConsole, 10);
	string upit;
	do {
		cout << endl << "Ukucaj 'izlaz' za izlaz, 'opet' za ponovno pokretanje" << endl;
		getline(cin, upit);
		if (upit == "izlaz") {
			cout << endl << "Hvala na koriscenju!" << endl;
			Sleep(1000);
			exit(0);
		}
		else if (upit == "opet" || upit == "Opet" || upit == "UPIT") {
			start();
			break;
		} 
	} while (upit != "opet" || upit != "Opet" || upit != "UPIT");
}

int main() //odakle se sve pokrece
{
	SetConsoleTextAttribute(hConsole, 10);

	cout << " _    _    ___  ____  TM " << endl;
	cout << "| |  | |  |_  ||_  _|  " << endl;
	cout << "| |__| |_   | |_/ /    " << endl;
	cout << "|____   _|  |  __'.    " << endl;
	cout << "    _| |_  _| |  \ \_  " << endl;
	cout << "   |_____||____||____| " << endl;
	cout << "                       " << endl;

	start();

	getchar();
}
