#ifndef SHELL_HPP
#define SHELL_HPP
#include <math.h>

using namespace std;

template<class clave>
long int shell_sort(vector<clave> &v, unsigned int size,bool mode){

    unsigned long int comparacion=0;
    double alpha=0;

    if(mode==false){


cout << endl << "Vector antes de aplicar el algoritmo" << endl;

  for(int i=0;i<size;i++)
    cout << i+1 << " " << v[i] << endl;


while((alpha <= 0) || (alpha >= 1)){
  cout << "Introduzca un valor de alpha entre 0.00 y 1.00 " << endl;
  cin >> alpha;}

double delta = size;

while(delta >= 1){

    delta = delta * alpha;

    cout << "Valor alpha: " << alpha << " y delta: " << delta  << endl;
    for(int i=delta;i<size;i++){
        clave temp = v[i];
        int j=i;
        comparacion++;

        while((j > delta) && (temp < v[j-delta])){

            cout << "El valor: " << v[i] << " de la posicion:" << i+1 << " es menor que " << v[j-delta] << " de la posicion:" << floor(((j-delta)+1)) << endl;
            cout << "Intercambiamos!" << endl;

            v[j] = v[j-delta];
            j = j - delta;
            comparacion++;
        }
        cout << comparacion << endl;
        v[j]=temp;

     cout << "La secuencia queda asi: " << endl;

     for (int i=0; i < size; i++)
     cout << i+1 << " " << v[i] << endl;
    }}}

    else if(mode==true){

        alpha=0.333;
        double delta = size;

        while(delta >= 1){

            delta = delta * alpha;

            for(int i=delta;i<size;i++){
                clave temp = v[i];
                int j=i;
                comparacion++;

                while((j > delta) && (temp < v[j-delta])){

                    v[j] = v[j-delta];
                    j = j - delta;
                    comparacion++;
                }
                v[j]=temp;

    }}}

    cout << comparacion << endl;
    return comparacion;


}


#endif // SHELL_HPP
