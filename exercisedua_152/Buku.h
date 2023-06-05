#pragma once
#ifndef BUKU_H
#define BUKU_H
#include <iostream>
#include <string>
using namespace std;

class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	buku(string pNama) :nama(pNama) {
		cout << "Buku \"" << nama << "\" dibuat\n";
	}
	~buku() {
		cout << "Buku \"" << nama << "\" dihapus\n";
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};
#endif // !BUKU_H

