#include <iostream>
using namespace std;
#include <fstream>
//////////////////////PIAN///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

class Instrumente {
	string nume;

public:
	virtual void descrieInstrument() = 0;

	Instrumente() {
		this->nume = "Nume Instrument";
	}
	string getNume() {
		return this->nume;
	}
	void setNume(string nume) {
		if (nume.length() > 3) {
			this->nume = nume;
		}
	}
};

class Accesorii {
	string nume;
public:
	virtual void descrieAccesoriu() = 0;

	Accesorii() {
		this->nume = "Nume acccesoriu";
	}
	string getNume() {
		return this->nume;
	}
	void setNume(string nume) {
		if (nume.length() > 3) {
			this->nume = nume;
		}
	}


};


class Pian :public Instrumente {
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

	Pian() : Instrumente(), nrInventar(nrGenerator++) {
		this->producator = "Yamaha";
		this->pret = 4460.99;
		this->nrPorturi = 0;
		this->numePorturi = NULL;

	}

	Pian(string producator, float pret) :Instrumente(), nrInventar(nrGenerator++) {
		this->producator = producator;
		this->pret = pret;
		this->nrPorturi = 0;
		this->numePorturi = NULL;
	}
	Pian(string producator, float pret, int nrPorturi, string* numePorturi) :Instrumente(), nrInventar(nrGenerator++) {
		this->producator = producator;
		this->pret = pret;
		this->nrPorturi = nrPorturi;
		this->numePorturi = new string[nrPorturi];
		for (int i = 0; i < nrPorturi; i++) {
			this->numePorturi[i] = numePorturi[i];
		}
	}
	Pian(const Pian& p) : Instrumente(), nrInventar(nrGenerator++) {
		this->producator = p.producator;
		this->pret = p.pret;
		this->nrPorturi = p.nrPorturi;
		this->numePorturi = new string[p.nrPorturi];
		for (int i = 0; i < p.nrPorturi; i++) {
			this->numePorturi[i] = p.numePorturi[i];
		}
	}
	~Pian() {
		if (this->numePorturi != NULL) {
			delete[]this->numePorturi;
		}
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
	static int careNrGenerator() {
		return nrGenerator;
	}
	Pian operator=(const Pian& p) {
		if (this != &p) {
			Instrumente::operator=(p);
			this->producator = p.producator;
			this->pret = p.pret;
			this->nrPorturi = p.nrPorturi;
			if (this->numePorturi != NULL) {
				delete[]this->numePorturi;
			}
			this->numePorturi = new string[p.nrPorturi];
			for (int i = 0; i < nrPorturi; i++) {
				this->numePorturi[i] = p.numePorturi[i];
			}
		}
		return *this;
	}
	void descrieInstrument() {
		cout << "Pianul de la firma " << this->producator << " costa " << this->pret << " lei." << endl;
	}
	friend ostream& operator<<(ostream& pian, const Pian& p);
	friend istream& operator>>(istream& pintr, Pian& p);
	friend ofstream& operator<<(ofstream& fis, const Pian& p) {
		fis << p.producator << endl;
		fis << p.pret << endl;
		fis << p.nrPorturi << endl;
		if (p.nrPorturi > 0) {
			for (int i = 0; i < p.nrPorturi; i++) {
				fis << p.numePorturi[i];
			}
		}
		else {
			fis << "NA";
		}
		fis << endl;
		return fis;

	}
	friend ifstream& operator>>(ifstream& intr, Pian& p) {
		intr >> p.producator;
		intr >> p.pret;
		intr >> p.nrPorturi;
		if (p.numePorturi != NULL) {
			delete[]p.numePorturi;
		}
		for (int i = 0; i < p.nrPorturi; i++) {
			intr >> p.numePorturi[i];

		}
		return intr;

	}
	Pian operator+=(const Pian& p) {
		int aux = this->nrPorturi;
		this->nrPorturi += p.nrPorturi;
		string* vector = new string[nrPorturi];
		for (int i = 0; i < aux; i++) {
			vector[i] = this->numePorturi[i];
		}
		for (int i = aux; i < this->nrPorturi; i++) {
			vector[i] = p.numePorturi[i - aux];
		}
		if (this->numePorturi != NULL) {
			delete[]this->numePorturi;
		}
		this->numePorturi = vector;
		return *this;
	}
	
	void fisBin(fstream& f) {
		f.write((char*)&this->pret, sizeof(float));
		int lungime = this->producator.length();
		f.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++) {
			f.write((char*)&this->producator[i], sizeof(string));
		}
		int len = sizeof(numePorturi);
		f.write((char*)&len, sizeof(int));
		for (int i = 0; i < len; i++) {
			f.write((char*)&this->numePorturi[i], sizeof(string));
		}
	}
	void citBin(fstream& f) {
		f.read((char*)&this->pret, sizeof(float));
		int lungime;
		f.read((char*)&lungime, sizeof(int));
		if (this->numePorturi != NULL) {
			delete[]this->numePorturi;
		}
		this->numePorturi = new string[lungime + 1];
		for (int i = 0; i < lungime; i++) {
			f.read((char*)&this->numePorturi[i], sizeof(string));
		}
		this->numePorturi[lungime] = '/0';
		f.read((char*)&this->pret, sizeof(float));
		f.read((char*)&this->nrPorturi, sizeof(int));

	}

		 
};
int Pian::nrGenerator = 1000;
ostream& operator<<(ostream& pian, const Pian& p) {
	pian << "Pianul este de la producatorul " << p.producator << " , are pretul de " << p.pret << " si are " << p.nrPorturi << " porturi, cu numele ";
	if (p.nrPorturi > 0) {
		for (int i = 0; i < p.nrPorturi; i++) {
			pian << p.numePorturi[i] << " ";
		}
		cout << ".";
	}
	else {
		pian << "NA";
	}
	pian << endl;
	return pian;
}
istream& operator>>(istream& pintr, Pian& p) {
	cout << "Introduceti numele producatorului";
	pintr >> p.producator;
	cout << "Introduceti pretul produsului:";
	pintr >> p.pret;
	cout << "Introduceti numarul de porturi:";
	pintr >> p.nrPorturi;
	cout << "Introduceti numele porturilor:";
	if (p.numePorturi != NULL) {
		delete[]p.numePorturi;
	}
	p.numePorturi = new string[p.nrPorturi];
	for (int i = 0; i < p.nrPorturi; i++) {
		pintr >> p.numePorturi[i];
	}
	return pintr;
}
////////////////////////////////////////////////////AMP///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

class Amp : public Accesorii {
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

	Amp() :nrInventar(nrGenerator++) {
		this->producator = "Fender";
		this->pret = 499, 99;
		this->nrButoane = 0;
		this->numeButoane = NULL;

	}

	Amp(string producator, float pret) :nrInventar(nrGenerator++) {
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
	Amp(const Amp& a) : nrInventar(nrGenerator++) {
		this->producator = a.producator;
		this->pret = a.pret;
		this->nrButoane = a.nrButoane;
		this->numeButoane = new string[a.nrButoane];
		for (int i = 0; i < a.nrButoane; i++) {
			this->numeButoane[i] = a.numeButoane[i];
		}
	}
	~Amp() {
		if (this->numeButoane != NULL) {
			delete[]this->numeButoane;
		}
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
	static int careNrGenerator() {
		return nrGenerator;
	}
	Amp operator=(const Amp& a) {
		Accesorii :: operator=(a);
		if (this != &a) {
			this->pret = a.pret;
			this->producator = a.producator;
			this->nrButoane = a.nrButoane;
			if (this->numeButoane != NULL) {
				delete[]this->numeButoane;
			}
		}
		this->numeButoane = new string[nrButoane];
		for (int i = 0; i < nrButoane; i++) {
			this->numeButoane[i] = a.numeButoane[i];
		}
	}
	void descrieAccesoriu() {
		cout << "Amplficatorul de la firma " << this->producator << " costa " << this->pret << " lei." << endl;
	}
	friend void pretamp(Amp a);
	friend ostream& operator<<(ostream& boxa, const Amp& a);
	friend istream& operator>>(istream& aintr, Amp& a) {
		cout << "Introduceti producatorul produsului";
		aintr >> a.producator;
		cout << "Pretul";
		aintr >> a.pret;
		cout << "Numar butoane";
		aintr >> a.nrButoane;
		cout << "Nume buton";
		if (a.numeButoane != NULL) {
			delete[]a.numeButoane;
		}
		for (int i = 0; i < a.nrButoane; i++) {
			aintr >> a.numeButoane[i];
		}
		return aintr;
	}
	Amp operator+=(const Amp& a) {
		int aux = this->nrButoane;
		this->nrButoane += a.nrButoane;
		string* vector = new string[nrButoane];
		for (int i = 0; i < aux; i++) {
			vector[i] = this->numeButoane[i];
		}
		for (int i = aux; i < this->nrButoane; i++) {
			vector[i] = a.numeButoane[i - aux];
		}
		if (this->numeButoane != NULL) {
			delete[]this->numeButoane;
		}
		this->numeButoane = vector;
		return *this;

	}
	friend ofstream& operator<<(ofstream& fis, const Amp& a) {
		fis << a.producator << endl;
		fis << a.pret << endl;
		if (a.nrButoane > 0) {
			for (int i = 0; i < a.nrButoane; i++) {
				fis << a.numeButoane[i];
			}
		}
		fis << endl;
		return fis;

	}
	friend ifstream& operator>>(ifstream& intr, Amp& a) {
		intr >> a.producator;
		intr >> a.pret;
		intr >> a.nrButoane;
		if (a.numeButoane != NULL) {
			delete[]a.numeButoane;
		}
		for (int i = 0; i < a.nrButoane; i++) {
			intr >> a.numeButoane[i];

		}
		return intr;

	}
	void fisBin(fstream& f) {
		f.write((char*)&this->pret, sizeof(float));
		int lungime = this->producator.length();
		f.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++) {
			f.write((char*)&this->producator[i], sizeof(string));
		}
		int len = sizeof(numeButoane);
		f.write((char*)&len, sizeof(int));
		for (int i = 0; i < len; i++) {
			f.write((char*)&this->numeButoane[i], sizeof(string));
		}
	}
	void citBin(fstream& f) {
		f.read((char*)&this->pret, sizeof(float));
		int lungime;
		f.read((char*)&lungime, sizeof(int));
		if (this->numeButoane != NULL) {
			delete[]this->numeButoane;
		}
		this->numeButoane = new string[lungime + 1];
		for (int i = 0; i < lungime; i++) {
			f.read((char*)&this->numeButoane[i], sizeof(string));
		}
		this->numeButoane[lungime] = '/0';
		f.read((char*)&this->pret, sizeof(float));
		f.read((char*)&this->nrButoane, sizeof(int));
	}
};

	ostream& operator<<(ostream& boxa, const Amp& a) {
		boxa << "Amplificatorul este de la producatorul" << a.producator << ", are pretul de " << a.pret << " si are " << a.nrButoane
			<< " butoane" << " cu denumirile";
		if (a.nrButoane > 0) {
			for (int i = 0; i < a.nrButoane; i++) {
				boxa << a.numeButoane[i] << " ";
			}
		}
		else {
			boxa << "NA";
		}
		boxa << endl;
		return boxa;
	}

	////////////////////////////////////////////CHITARA//////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////
	class Chitara : public Instrumente{
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
		Chitara() :Instrumente(), nrInventar(nrGenerator++) {
			this->producator = "Gibson";
			this->pret = 1500;
			this->nrPedale = 0;
			this->numePedale = NULL;

		}

		Chitara(string producator, float pret) :Instrumente(), nrInventar(nrGenerator++) {
			this->producator = producator;
			this->pret = pret;
			this->nrPedale = 0;
			this->numePedale = NULL;
		}
		Chitara(string producator, float pret, int nrPedale, string* numePedale) : Instrumente(), nrInventar(nrGenerator++) {
			this->producator = producator;
			this->pret = pret;
			this->nrPedale = nrPedale;
			this->numePedale = new string[nrPedale];
			for (int i = 0; i < nrPedale; i++) {
				this->numePedale[i] = numePedale[i];
			}
		}
		Chitara(const Chitara& c) :Instrumente(), nrInventar(nrGenerator++) {
			this->producator = c.producator;
			this->pret = c.pret;
			this->nrPedale = c.nrPedale;
			this->numePedale = new string[c.nrPedale];
			for (int i = 0; i < c.nrPedale; i++) {
				this->numePedale[i] = c.numePedale[i];
			}
		}
		~Chitara() {
			if (this->numePedale != NULL) {
				delete[]this->numePedale;
			}
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
			if (nrPedale > 0) {
				this->nrPedale = nrPedale;
				if (this->numePedale != NULL) {
					delete[]this->numePedale;
				}
				this->numePedale = new string[nrPedale];
				for (int i = 0; i < nrPedale; i++) {
					this->numePedale[i] = numePedale[i];
				}
			}
		}
		void setnrPedale(int nrPedale) {
			if (nrPedale > 0) {
				this->nrPedale = nrPedale;
			}

		}
		static int careNrGenerator() {
			return nrGenerator;
		}
		Chitara operator=(const Chitara& c) {
			Instrumente:: operator=(c);
			if (this != &c) {
				this->producator = c.producator;
				this->pret = c.pret;
				this->nrPedale = c.nrPedale;
				if (this->numePedale != NULL) {
					delete[]this->numePedale;
				}
				this->numePedale = new string[nrPedale];
				for (int i = 0; i < nrPedale; i++) {
					this->numePedale[i] = c.numePedale[i];
				}

			}
			return *this;
		}
		void descrieInstrument() {
			cout << "Chitara de la firma " << this->producator << " costa " << this->pret << " lei." << endl;
		}
		friend ostream& operator<<(ostream& chitara, Chitara& c);
		friend istream& operator>>(istream& cintr, Chitara& c) {
			cout << "Introduceti producatorul:";
			cintr >> c.producator;
			cout << "Introduceti pretul:";
			cintr >> c.pret;
			cout << "Introduceti numarul de pedale";
			cintr >> c.nrPedale;
			cout << "Introduceti numele pedalelor:";
			if (c.numePedale != NULL) {
				delete[]c.numePedale;
			}
			c.numePedale = new string[c.nrPedale];
			for (int i = 0; i < c.nrPedale; i++) {
				cintr >> c.numePedale[i];
			}
			return cintr;
		}
		Chitara operator+=(const Chitara& c) {
			int aux = this->nrPedale;
			this->nrPedale += c.nrPedale;
			string* vector = new string[nrPedale];
			for (int i = 0; i < aux; i++) {
				vector[i] = this->numePedale[i];
			}
			for (int i = aux; i < this->nrPedale; i++) {
				vector[i] = c.numePedale[i - aux];
			}
			if (this->numePedale != NULL) {
				delete[]this->numePedale;
			}
			this->numePedale = vector;
			return *this;

		}
		friend ofstream& operator<<(ofstream& fis, const Chitara& c) {
			fis << c.producator << endl;
			fis << c.pret << endl;
			if (c.nrPedale > 0) {
				for (int i = 0; i < c.nrPedale; i++) {
					fis << c.numePedale[i];
				}
			}
			fis << endl;
			return fis;

		}
		friend ifstream& operator>>(ifstream& intr, Chitara& c) {
			intr >> c.producator;
			intr >> c.pret;
			intr >> c.nrPedale;
			if (c.numePedale != NULL) {
				delete[]c.numePedale;
			}
			for (int i = 0; i < c.nrPedale; i++) {
				intr >> c.numePedale[i];

			}
			return intr;

		}
	};
	int Chitara::nrGenerator = 1000;

	ostream& operator<<(ostream& chitara, Chitara& c) {
		if (c.nrPedale > 0) {
			chitara << "Chitara este de la producatorul " << c.producator << ", are pretul de " << c.pret << " si are " << c.nrPedale << " pedale, cu numele";
			for (int i = 0; i < c.nrPedale; i++) {
				chitara << c.numePedale[i];
			}
		}
		else {
			chitara << "NA";
		}
		chitara << endl;
		return chitara;
	}

	class SetInstrumente {
		int nrInstrumente;
		Pian pian;
		Amp amplificator;
		Chitara chitara;
	public:
		SetInstrumente() :nrInstrumente(3) {
		}

		int getnrInstrumente() {
			return nrInstrumente;
		}
		Pian getPian() {
			return pian;
		}
		Amp getAmp() {
			return amplificator;
		}

		void setnrInstrumente(int nrInstrumente) {
			this->nrInstrumente = nrInstrumente;
		}
		void setPian(Pian pian) {
			this->pian = pian;
		}
		void setAmp(Amp amplificator) {
			this->amplificator = amplificator;
		}

		SetInstrumente operator=(const SetInstrumente& s) {
			if (this != &s) {
				this->nrInstrumente = s.nrInstrumente;
				this->pian = s.pian;
				this->amplificator = s.amplificator;
			}
			return *this;
		}
		friend class Amp;
		friend class Pian;
		friend ostream& operator<<(ostream& out, SetInstrumente& s);
		friend istream& operator>>(istream& in, SetInstrumente& s) {
			cout << "SPECIFICATII AMPLIFICATOR" << endl;
			in >> s.amplificator;
			cout << "SPECIFICATII PIAN" << endl;
			in >> s.pian;

			return in;
		}
		friend ofstream& operator>>(ofstream& out, SetInstrumente& s) {
			out << s.pian << endl;
			out << s.amplificator << endl;
		}
		friend ifstream& operator>>(ifstream& in, SetInstrumente& s) {
			in >> s.pian;
			in >> s.amplificator;

		}

	};
	ostream& operator<<(ostream& out, SetInstrumente& s) {
		out << "Setul de instrumente contine" << s.nrInstrumente << " instrumente, anume pianul cu specificatiile:" << s.pian << ", amplificatorul cu specificatiile:" <<
			s.amplificator << endl;
		return out;
	}




	void pretamp(Amp a) {
		if (0 < a.pret < 500) {
			cout << "Range: 0-500" << endl;
		}
		else {
			if (500 < a.pret < 1000) {
				cout << "Range: 500-1000" << endl;
			}
		}
	}

	void compar1(Pian p, Chitara c) {
		if (p.getPret() > c.getPret()) {
			cout << "Pianul este mai scump decat chitara" << endl;
		}
		else {
			cout << "Chitara este mai scumpa decat pianul" << endl;
		}
	}

	void producatorComun(Pian p, Chitara c) {
		if (p.getProducator() == c.getProducator()) {
			cout << "Pianul si chitara au acelasi producator" << endl;
		}
	}

	class InstrumenteTrupa {
		int nrInstrumente;
			Instrumente** instrumente;
			Accesorii** accesorii;
	public:
		InstrumenteTrupa() {
			this->nrInstrumente = 10;
			this->instrumente = new Instrumente * [10];
			for (int i = 0; i < 10; i++) {
				this->instrumente[i] = new Pian;
			}
		}
		Instrumente*& operator[](int i) {
			if (i >= 0 && i < this->nrInstrumente) {
				return this->instrumente[i];
			}
		}
		void utilizareInstrumente(Instrumente* i) {
				i->descrieInstrument();
			}
			
			void utilizarePian(Pian* p) {
				p->descrieInstrument();
			}
			void utilizareAccesorii(Accesorii* i) {
				i->descrieAccesoriu();
			}

			void utilizareAmp(Amp* p) {
				p->descrieAccesoriu();
			}
	};

	class PianAcustic :public Pian {
	private:
		int nrclape;
		bool fullsize;

	public:
		PianAcustic() :Pian() {
			this->nrclape = 84;
			this->fullsize = true;
		}
		int getNrClape() {
			return nrclape;
		}
		bool getFullsize() {
			return fullsize;
		}
		void setnrClape(int nrclape) {
			this->nrclape = nrclape;
		}
		void setfullsize(bool fullsize) {
			this->fullsize = fullsize;
		}
	};

	class ChitaraAcustica : public Chitara {
	private:
		int nrcoarde;
		float greutate;
	public:
		ChitaraAcustica() :Chitara() {
			this->nrcoarde = 6;
			this->greutate = 4.6;
		}
		int getnrcoarde() {
			return nrcoarde;
		}
		float getGreutate() {
			return greutate;
		}
		void setNrcoarde(int nrcoarde) {
			this->nrcoarde = nrcoarde;
		}
		void setgreutate(float greutate) {
			this->greutate = greutate;
		}

	};

	//////////////////////////////////////////////MAIN//////////////////////////////
	void main() {
		
		/*int p;
		Pian* vectorP;
		cout << "Numarul obiectelor din vector";
		cin >> p;
		vectorP = new Pian[p];
		for (int i = 0; i < p; i++) {
			cin >> vectorP[i];
		}
		cout << endl;
		for (int i = 0; i < p; i++) {
			cout << vectorP[i] << endl;
		}
		cout << endl;

		int a;
		Amp* vectorA;
		cout << "Numarul obiectelor din vector";
		cin >> a;
		vectorA = new Amp[a];
		for (int i = 0; i < a; i++) {
			cin >> vectorA[i];
		}
		cout << endl;
		for (int i = 0; i < a; i++) {
			cout << vectorA[i] << endl;
		}
		cout << endl;


		int c;
		Chitara* vectorC;
		cout << "Numarul obiectelor din vector";
		cin >> c;
		vectorC = new Chitara[c];
		for (int i = 0; i < c; i++) {
			cin >> vectorC[i];
		}
		cout << endl;
		for (int i = 0; i < c; i++) {
			cout << vectorC[i] << endl;
		}
		cout << endl;
		Pian pian1;

		string* numePorturi = new string[3];
		numePorturi[0] = "Jack 3.5";
		numePorturi[1] = "Jack 6.3";
		numePorturi[2] = "USB";
		int nrPorturi = 3;
		float pret1 = 6000;
		string producator1 = "Yamaha";
		Pian pian2(producator1, pret1, nrPorturi, numePorturi);



		string producator = "DunLop";
		int pret = 5000;
		Pian pian3(producator, pret);




		Amp amp1;
		cout << amp1 << endl;
		string* numeButoane = new string[3];
		numeButoane[0] = "Gain";
		numeButoane[1] = "Volume";
		numeButoane[2] = "Treble";
		int nrButoane = 3;
		float pretAmp2 = 700;
		string prodAmp2 = "Gibson";
		Amp amp2(prodAmp2, pretAmp2, nrButoane, numeButoane);
		cout << amp2 << endl;
		string numeprod3 = "Yamaha";
		float pretAmp3 = 1000;
		Amp amp3(numeprod3, pretAmp3);
		cout << amp3 << endl;
		cout << endl;
		pretamp(amp1);

		Chitara chitara1;
		cout << chitara1 << endl;
		string* numePedale = new string[3];
		numePedale[0] = "Sustain";
		numePedale[1] = "Reverb";
		numePedale[2] = "Gain";
		int nrPedale = 3;
		float pretC2 = 1000;
		string prodC2 = "Yamaha";
		Chitara chitara2(prodC2, pretC2, nrPedale, numePedale);
		cout << chitara2 << endl;
		string prodC3 = "Squier";
		float pretC3 = 4000;
		Chitara chitara3(prodC3, pretC3);
		cout << chitara3 << endl;
		compar1(pian1, chitara1);
		producatorComun(pian2, chitara2);

		pian1 += pian2;
		cout << pian1 << endl << pian2 << endl;

		pian1 = pian2;
		cout << pian1 << pian2 << endl;*/

Pian p1("steinway", 40000);
p1.descrieInstrument();



InstrumenteTrupa it;
it[0] = new Pian("Steinway", 44000);
it[1]= new Chitara("Yamaha", 1000);
it[2]= new Pian();
it[3]= new Chitara();
it[4]= new Pian("Yamaha", 4000.522, 1, NULL);
it[5]= new Chitara();
it[6]= new Pian("Ramm", 10000);
it[7]= new Pian();
it[8]= new Chitara("Gibson", 44000);
it[9]= new Pian();

for (int i = 0; i < 10; i++) {
	it[i]->descrieInstrument();
}

	}
