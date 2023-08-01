//#ifndef __CELULA__
//#define __CELULA__

#ifndef CELULA_H
#define CELULA_H

class Celula {

	private:
	int dado;
	Celula * prox;
    Celula * ant;

	public:
	Celula(int);
	int  getInfo();
	void setInfo(int);
	Celula * getProx();
	Celula * getAnt();
	void setProx(Celula * );
	void setAnt(Celula * );
};
#endif
