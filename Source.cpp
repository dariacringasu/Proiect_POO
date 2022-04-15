#include <iostream>
#include <string>

using namespace std;

class Lista;

class Produse_magazin {
protected:
	int tip_derivat;
	string producator;
	int cod_produs;
	Produse_magazin* next;
public:
	Produse_magazin(int _tip_derivat, string _producator, int _cod_produs) {
		tip_derivat = _tip_derivat;
		producator = _producator;
		cod_produs = _cod_produs;
	}

	virtual void afisare() {
		cout << "------------------------\n";
		cout << "Producator: " << producator << '\n';
		cout << "Cod produs: " << cod_produs << '\n';
	}

	friend class Lista;
};

class Scaner : public Produse_magazin {
	string soft_inclus;
public:
	Scaner(int _tip_derivat, string _producator, int _cod_produs, string _soft_inclus) :Produse_magazin(_tip_derivat, _producator,
		_cod_produs) {
		soft_inclus = _soft_inclus;
	}

	void afisare() {
		Produse_magazin::afisare();
		cout << "Soft inclus: " << soft_inclus << '\n';
	}

	friend class Lista;
};

class Imprimanta : public Produse_magazin {
	string format;
public:
	Imprimanta(int _tip_derivat, string _producator, int _cod_produs, string _format) :Produse_magazin(_tip_derivat, _producator,
		_cod_produs) {
		format = _format;
	}

	void afisare() {
		Produse_magazin::afisare();
		cout << "Format: " << format << '\n';
	}
	friend class Lista;
};

class Lista {
public:
	Produse_magazin *head;
	void adaugare(Produse_magazin *prod);
	void afisare_lista();
};

void Lista::adaugare(Produse_magazin *prod) {

	Produse_magazin *p;
	p = head;
	if (!p) {
		head = prod;
	}
	else {
		while (p->next) p = p->next;
		p->next = prod;
	}
}

void Lista::afisare_lista() {
	Produse_magazin *p = head;
	if (!p) cout << "Lista este vida!\n";
	while (p) {
		p->afisare();
		p = p->next;
	}
}
class Supraincarcare {
	string producator;
	int cod_produs;
public:
	friend ostream&operator<<(ostream &out, Supraincarcare &a);
	friend istream&operator>>(istream &in, Supraincarcare &a);
	string Producator() { return producator; }
	int Cod() { return cod_produs; }

};

ostream&operator<<(ostream &out, Supraincarcare &a) {
	cout << "Vom citi datele pentru scanere si imprimante:" << endl;
	return out;
}

istream&operator>>(istream &in, Supraincarcare &a) {
	cout << "Introduceti producator: ";
	cin >> a.producator;
	cout << "Cod produs: ";
	cin >> a.cod_produs;
	return in;

}
void introducere(Lista &l, int x) {
	int cod_produs;
	string producator, soft_inclus, format;
	Produse_magazin *prodMag;

	Supraincarcare supr;
	cout << supr;
	cin >> supr;

	if (x == 0) {
		Scaner *sc;
		cout << "Introduceti soft inclus: "; cin >> soft_inclus;
		sc = new Scaner(1, supr.Producator(), supr.Cod(), soft_inclus);
		prodMag = sc;
		l.adaugare(prodMag);
	}
	else if (x == 1) {
		Imprimanta *imp;
		cout << "Introduceti format: "; cin >> format;
		imp = new Imprimanta(2, supr.Producator(), supr.Cod(), format);
		prodMag = imp;
		l.adaugare(prodMag);
	}
}

int main() {

	int opt;
	Lista l;
	l.head = NULL;

	do {
		cout << "1. Adaugare scaner\n";
		cout << "2. Adaugare imprimanta\n";
		cout << "3. Afisare articole magazin\n";
		cout << "0. Iesire\n";
		cout << "Optiunea dvs: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			introducere(l, 0);
			break;
		case 2:
			introducere(l, 1);
			break;
		case 3:
			l.afisare_lista();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Optiune gresita!\n";
			break;
		}
	} while (1);

	return 0;
}