#ifndef CONJUNTO_H
#define CONJUNTO_H

#include<iostream>
using namespace std;

template <class T>
class Conjunto;

template <class T>
ostream &operator<<(ostream &,const Conjunto<T> &);

template <class T>
istream &operator>>(istream &, Conjunto<T> &);


template <class T>
class Conjunto{
    friend ostream &operator<< <T>(ostream &, const Conjunto<T> &); 
    friend istream &operator>> <T>(istream &, Conjunto<T> &);

    private:
        int tam_array;
        int num_elementos; //tamanho do vetor
        T *v;

    public:
        Conjunto();
        Conjunto( int );
        Conjunto(const Conjunto<T> &);
        ~Conjunto();
        Conjunto & operator=(const Conjunto<T> &);
        bool operator==(const Conjunto<T> &) const;
        bool pertence(const T) const;
        bool insere( T );
        int numelementos () const;     
};

template <class T>
Conjunto<T>::Conjunto(){
    tam_array = 10;
    num_elementos = 0;
    v = new T[tam_array];
}

template <class T>
Conjunto<T>::Conjunto( int n ) : tam_array(n){
    num_elementos = 0;
    v = new T[tam_array];
}

template <class T>
Conjunto<T>::Conjunto(const Conjunto<T> &other){
    v = new T[other.tam_array];
    tam_array = other.tam_array;
    num_elementos = other.num_elementos;

    for(int i = 0; i < other.num_elementos; i++)
        v[i] = other.v[i];
}

template <class T>
Conjunto<T>::~Conjunto(){
    delete[] v;
}

template <class T>
Conjunto<T> & Conjunto<T>::operator=(const Conjunto<T> &other){
    cout << "atribuicao" << endl;
    if(&other == this) return *this;

    delete[] v;

    tam_array = other.tam_array;
    num_elementos = other.numelementos();
    v = new T[tam_array];

    for(int i = 0; i < num_elementos; i++)
        v[i] = other.v[i];
    
    return *this;
}

template <class T>
bool Conjunto<T>::operator==(const Conjunto<T> &other) const{
    if(num_elementos != other.num_elementos) return false;

    for(int i = 0; i < num_elementos; i++)
        if(v[i] != other.v[i])
            return false;
    
    return true;
}

template <class T>
bool Conjunto<T>::pertence(const T n) const{
    for(int i = 0; i < num_elementos; i++)
        if(v[i] == n) 
            return true;

    return false;
}

template <class T>
bool Conjunto<T>::insere(T n){
    if(pertence(n)) return false;
    else if(num_elementos == tam_array) return false;

    for(int i = 0; i < num_elementos; i++)
        if(v[i] == n) return false;
    
    num_elementos += 1;

    v[num_elementos-1] = n;

    return true;
}

template <class T>
int Conjunto<T>::numelementos() const{
    return num_elementos;
}

template <class T>
ostream &operator<<(ostream &out, const Conjunto<T> &other){
    cout << "{";

    for(int i = 0; i < other.num_elementos; i++){
        out << other.v[i];
        if( i+1 < other.num_elementos ) cout << ",";
    }
    cout << "}";

    return out;
}

template <class T>
istream &operator>>(istream &in, Conjunto<T> &other){
    T aux;
    int cont = 0;   

    do{
        // se o array de conjunto estiver cheio, não pode inserir mais elementos.
        if( other.numelementos() >= other.tam_array ){
            cout << "Conjunto cheio" << endl;
            break;
        }

        //recebe o elemento do usuário ou do arquivo
        in >> aux;

        //se o elemento não estiver no conjunto, insere ele
        if( !other.pertence(aux) ) 
                other.insere(aux);

        else {
            cont -= 1;
        }

        //contador para percorrer o array
        cont += 1; 
    }while( cont < other.tam_array && in);
    
    return in;
}

#endif