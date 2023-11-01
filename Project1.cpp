#include <iostream>
using namespace std;

class Pian {
private:
	const int nrInventar;
	static int nrGenerator;
	string producator;
	float pret;
	int nrPorturi;
	string* numePorturi;

public:
	static int getNrGenerator() {
		return nrGenerator;
	}

	Pian() : nrInventar(nrGenerator++) {
		this->producator = "Yamaha";
		this->pret = 4460.99;
		this->nrPorturi = 0;
		this->numePorturi = NULL;

	}

	Pian(string producator, float pret) : nrInventar(nrGenerator++) {
		this->producator = producator;
		this->pret = pret;
		this->nrPorturi = 0;
		this->numePorturi = NULL;
	}
	Pian(string producator, float pret, int nrPorturi, string* numePorturi) : nrInventar(nrGenerator++) {
		this->producator = producator;
		this->pret = pret;
		this->nrPorturi = nrPorturi;
		this->numePorturi = new string[nrPorturi];
		for (int i = 0; i < nrPorturi; i++) {
			this->numePorturi[i] = numePorturi[i];
		}
	}
	~Pian() {
		if (this->numePorturi != NULL) {
			delete[]this->numePorturi;
		}
	}
	void afisarePian() {
		cout << "Pianul de la producatorul " << producator << " costa " << pret << " lei. ";
		if (nrPorturi > 0) {
			cout << " Acesta are " << nrPorturi << " porturi, cu numele: ";
			for (int i = 0; i < nrPorturi; i++) {
				cout << numePorturi[i] << ", ";
			}
		}
		else {
			cout << "Nu are porturi.";
		}
		cout << endl;
	}

	const int getnrInventar() {
		return nrInventar;
	}
	string getProducator() {
		return producator;
	}
	void setProducator(string producator) {
		if (producator.length() > 0) {
			this->producator = producator;
		}
	}
	float getPret() {
		return pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	void setPorturi(int nrPorturi, string* numePorturi) {
		if (nrPorturi > 0) {
			this->nrPorturi = nrPorturi;
			if (this->numePorturi != NULL) {
				delete[]this->numePorturi;
			}
			this->numePorturi = new string[nrPorturi];
			for (int i = 0; i < nrPorturi; i++) {
				this->numePorturi[i] = numePorturi[i];
			}
		}
	}
	string* getnumePorturi() {
		return numePorturi;
	}
	void setNrPorturi(int nrPorturi) {
		if (nrPorturi > 0) {
			this->nrPorturi = nrPorturi;
		}
	}
	string getnumePort(int i) {
		if (i >= 0 && i < nrPorturi) {
			return numePorturi[i];
		}
	}

};
int Pian::nrGenerator = 1000;



class Amp {
private:
	const int nrInventar;
	static int nrGenerator;
	string producator;
	float pret;
	int nrButoane;
	string* numeButoane;

public:
	static int getNrGenerator() {
		return nrGenerator;
	}

	Amp() : nrInventar(nrGenerator++) {
		this->producator = "Fender";
		this->pret = 499, 99;
		this->nrButoane = 0;
		this->numeButoane = NULL;

	}

	Amp(string producator, float pret) : nrInventar(nrGenerator++) {
		this->producator = producator;
		this->pret = pret;
		this->nrButoane = 0;
		this->numeButoane = NULL;
	}
	Amp(string producator, float pret, int nrButoane, string* numeButoane) : nrInventar(nrGenerator++) {
		this->producator = producator;
		this->pret = pret;
		this->nrButoane = nrButoane;
		this->numeButoane = new string[nrButoane];
		for (int i = 0; i < nrButoane; i++) {
			this->numeButoane[i] = numeButoane[i];
		}
	}
	~Amp() {
		if (this->numeButoane != NULL) {
			delete[]this->numeButoane;
		}
	}
	void afisareAmp() {
		cout << "Amplificatorul de la producatorul " << producator << " costa " << pret << "lei. ";
		if (nrButoane > 0) {
			cout << " Acesta are " << nrButoane << " butoane, cu numele: ";
			for (int i = 0; i < nrButoane; i++) {
				cout << numeButoane[i] << ", ";
			}
		}
		else {
			cout << "Nu are butoane.";
		}
		cout << endl;
	}
	const int getnrInventar() {
		return nrInventar;
	}
	string getProducator() {
		return producator;
	}
	void setProducator(string producator) {
		if (producator.length() > 0) {
			this->producator = producator;
		}
	}
	float getPret() {
		return pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	string* getnumeButoane() {
		return numeButoane;
	}
	string getnumeButon(int i) {
		if (i >= 0 && i < nrButoane) {
			return numeButoane[i];
		}
	}
	void setButoane(int nrButoane, string* numeButoane) {
		if (nrButoane > 0) {
			this->nrButoane = nrButoane;
			if (this->numeButoane != NULL) {
				delete[]this->numeButoane;
			}
			this->numeButoane = new string[nrButoane];
			for (int i = 0; i < nrButoane; i++) {
				this->numeButoane[i] = numeButoane[i];
			}
		}
	}
	void setnrButoane(int nrButoane) {
		if (nrButoane > 0) {
			this->nrButoane = nrButoane;
		}
	}

};
int Amp::nrGenerator = 1000;


class Chitara {
private:
	const int nrInventar;
	static int nrGenerator;
	string producator;
	float pret;
	int nrPedale;
	string* numePedale;
public:
	static int getNrGenerator() {
		return nrGenerator;
	}
	Chitara() : nrInventar(nrGenerator++) {
		this->producator = "Gibson";
		this->pret = 1500;
		this->nrPedale = 0;
		this->numePedale = NULL;

	}

	Chitara(string producator, float pret) : nrInventar(nrGenerator++) {
		this->producator = producator;
		this->pret = pret;
		this->nrPedale = 0;
		this->numePedale = NULL;
	}
	Chitara(string producator, float pret, int nrPedale, string* numePedale) : nrInventar(nrGenerator++) {
		this->producator = producator;
		this->pret = pret;
		this->nrPedale = nrPedale;
		this->numePedale = new string[nrPedale];
		for (int i = 0; i < nrPedale; i++) {
			this->numePedale[i] = numePedale[i];
		}
	}
	~Chitara() {
		if (this->numePedale != NULL) {
			delete[]this->numePedale;
		}
	}
	void afisareChitara() {
		cout << "Chitara de la producatorul " << producator << " costa " << pret << " lei. ";
		if (nrPedale > 0) {
			cout << " Acesta are " << nrPedale << " pedale, cu numele: ";
			for (int i = 0; i < nrPedale; i++) {
				cout << numePedale[i] << ", ";
			}
		}
		else {
			cout << "Nu are pedale.";
		}
		cout << endl;
	}
	const int getnrInventar() {
		return nrInventar;
	}
	string getProducator() {
		return producator;
	}
	void setProducator(string producator) {
		if (producator.length() > 0) {
			this->producator = producator;
		}
	}
	float getPret() {
		return pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	string* getNumepedale() {
		return numePedale;
	}
	string getnumePedala(int i) {
		if (i >= 0 && i < nrPedale) {
			return numePedale[i];
		}
	}
	void setPeale(int nrPedale, string* numePedale) {
		if (nrPedale> 0) {
			this->nrPedale = nrPedale;
			if (this->numePedale != NULL) {
				delete[]this->numePedale;
			}
			this->numePedale = new string[nrPedale];
			for (int i = 0; i < nrPedale; i++) {
				this->numePedale [i] = numePedale[i];
			}
		}
	}
	void setnrPedale(int nrPedale) {
		if (nrPedale > 0) {
			this->nrPedale = nrPedale;
		}
	}
};
int Chitara::nrGenerator = 1000;



void main() {
	Pian pian1;
	pian1.afisarePian();
	string* numePorturi = new string[3];
	numePorturi[0] = "Jack 3.5";
	numePorturi[1] = "Jack 6.3";
	numePorturi[2] = "USB";
	int nrPorturi = 3;
	float pret1 = 6000;
	string producator1 = "Steinway";
	Pian pian2(producator1, pret1, nrPorturi, numePorturi);
	pian2.afisarePian();


	string producator = "DunLop";
	int pret = 5000;
	Pian pian3(producator, pret);
	pian3.afisarePian();
	cout << endl;


	Amp amp1;
	amp1.afisareAmp();
	string* numeButoane = new string[3];
	numeButoane[0] = "Gain";
	numeButoane[1] = "Volume";
	numeButoane[2] = "Treble";
	int nrButoane = 3;
	float pretAmp2 = 700;
	string prodAmp2 = "Gibson";
	Amp amp2(prodAmp2, pretAmp2, nrButoane, numeButoane);
	amp2.afisareAmp();
	string numeprod3 = "Yamaha";
	float pretAmp3 = 1000;
	Amp amp3(numeprod3, pretAmp3);
	amp3.afisareAmp();
	cout << endl;

	Chitara chitara1;
	chitara1.afisareChitara();
	string* numePedale = new string[3];
	numePedale[0] = "Sustain";
	numePedale[1] = "Reverb";
	numePedale[2] = "Gain";
	int nrPedale = 3;
	float pretC2 = 1000;
	string prodC2 = "Yamaha";
	Chitara chitara2(prodC2, pretC2, nrPedale, numePedale);
	chitara2.afisareChitara();
	string prodC3 = "Squier";
	float pretC3 = 4000;
	Chitara chitara3(prodC3, pretC3);
	chitara3.afisareChitara();















}