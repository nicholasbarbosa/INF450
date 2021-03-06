
#include "Circulo.h"
#include <iostream>
using namespace std;

const float PI = 3.141592653589;

Circulo::Circulo(double x, double y, double r, 
                     int esp, int c, int t) 
                     : FigBase(x,y,esp,c,t){

    setRaio(r);
}

double Circulo::getRaio() const {
    return raio;
}

void Circulo::setRaio(double r) {
    raio = r;
}

float Circulo::area() const {
    return PI * raio * raio;    
}      
          
float Circulo::perimetro() const {
    return 2 * PI * raio;      
}


void Circulo::imprime() const {
    cout << "--- [Circulo] ---" << endl;
    FigBase::imprime();
    cout << " raio = " << getRaio() << endl; 
    cout << " area = " << area() << " perimetro = " << perimetro() << endl; 
}

void Circulo::le(){
    double r, x, y;
    int e, c, t;

    cin >> r >> x >> y;
    cin >> e >> c >> t;

    FigBase::setX(x);
    FigBase::setY(y);
    FigBase::setEspessura(e);
    FigBase::setCor(c);
    FigBase::setTipo(t);
    this-> raio = r;
}

ostream& operator<< (ostream& out, const Circulo& x){
    x.imprime();

    return out;
}

istream& operator>> (istream& in, Circulo& x){
    x.le();

    return in;
}