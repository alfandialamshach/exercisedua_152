#include <iostream>
#include <vector>
#include <string>
#include "Buku.h"
using namespace std;

class pengarang;
class penerbit {
	string nama;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}
	~penerbit() {
		cout << "Penerbit \"" << nama << "\" dihapus\n";
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

class pengarang {
	string nama;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \"" << nama << "\" ada\n";
	}
	~pengarang() {
		cout << "Penerbit \"" << nama << "\" dihapus\n";
	}
	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
	void tambahBuku(buku*);
	void cetakBuku();
};
void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}
void penerbit::cetakPengarang() {
	cout << "Daftar Pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void pengarang::tambahPenerbit(penerbit* pPenerbit) {
		daftar_penerbit.push_back(pPenerbit);
		pPenerbit->tambahPengarang(this);
}
void pengarang::cetakPenerbit() {
	cout << "Daftar Penerbit yang diikuti \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void buku::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
	pPengarang->tambahBuku(this);
}
void buku::cetakpengarang() {
	cout << "Daftar Buku yang dikarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;


	int main() {
		pengarang* varPengarang1 = new pengarang("Fandi");
		pengarang* varPengarang2 = new pengarang("Ghofiq");
		penerbit* varPenerbit1 = new penerbit("Abadi Jaya");
		penerbit* varPenerbit2 = new penerbit("Sumber Makmur");

		varPengarang1->tambahPenerbit(varPenerbit1);
		varPengarang2->tambahPenerbit(varPenerbit2);
		varPengarang1->tambahPenerbit(varPenerbit1);

		varPengarang1->cetakPenerbit();
		varPengarang2->cetakPenerbit();
		varPengarang1->cetakPenerbit();

		delete varPenerbit1;
		delete varPenerbit2;
		delete varPengarang1;
		delete varPengarang2;

		return 0;
	}