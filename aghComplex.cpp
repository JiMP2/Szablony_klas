#include "aghComplex.h"
	aghComplex::aghComplex(){
		this->Re = 0.0;
		this->Im = 0.0;
	}

	aghComplex::aghComplex(double rzeczywista, double urojona){
		this->Re = rzeczywista;
		this->Im = urojona;
	}
	
	aghComplex::aghComplex(const aghComplex &zespolona){
		this->Re = zespolona.Re;
		this->Im = zespolona.Im;
	}
	aghComplex::~aghComplex(){};
	
	ostream & operator<< (ostream &wyjscie, const aghComplex &zespolona){
   		wyjscie << zespolona.Re;
   		if(zespolona.Im>=0.0) wyjscie << "+";
   		wyjscie << zespolona.Im << "i";   		
   		return wyjscie;
	}


	aghComplex aghComplex::operator +(const aghComplex skladnik){
		aghComplex wynik;
		wynik.Re = this->Re + skladnik.Re;
		wynik.Im = this->Im + skladnik.Im;
		return wynik;
	}
	
	aghComplex aghComplex::operator -(const aghComplex skladnik){
		aghComplex wynik;
		wynik.Re = this->Re - skladnik.Re;
		wynik.Im = this->Im - skladnik.Im;
		return wynik;
	}
	
	void aghComplex::operator +=(const aghComplex skladnik){
		this->Re += skladnik.Re;
		this->Im += skladnik.Im;
	}
	
	void aghComplex::operator -=(const aghComplex skladnik){
		this->Re -= skladnik.Re;
		this->Im -= skladnik.Im;
	}
	
	aghComplex aghComplex::operator *(const aghComplex skladnik){
		aghComplex wynik;
		wynik.Re = (this->Re)*(skladnik.Re)-(this->Im)*(skladnik.Im);
		wynik.Im = (this->Im)*(skladnik.Re)+(this->Re)*(skladnik.Im);
		return wynik;
	}
	
	aghComplex aghComplex::operator / (const aghComplex skladnik){
		aghComplex wynik;
		wynik.Re = ((this->Re)*(skladnik.Re) + (this->Im)*(skladnik.Im)) / ((skladnik.Re)*(skladnik.Re)+(skladnik.Im)*(skladnik.Im));
		wynik.Re = ((this->Im)*(skladnik.Re) - (this->Re)*(skladnik.Im)) / ((skladnik.Re)*(skladnik.Re)+(skladnik.Im)*(skladnik.Im));
		return wynik;
		
	}
	
	bool aghComplex::operator == (const aghComplex druga){
		if(this->Re == druga.Re && this->Im == druga.Im) return true;
		else return false;
	}
	
	bool aghComplex::operator != (const aghComplex druga){
		if(this->Re != druga.Re && this->Im != druga.Im) return true;
		else return false;
	}

