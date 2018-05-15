#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include <algorithm>


using namespace std;


template<class clave>
long int bubble_sort(vector<clave> &v,unsigned int size,bool mode){

    bool cambio=false;
    unsigned long int comparacion=0;
    //clave temporal;

    if(mode==false){

cout << "Vector antes de aplicar el algoritmo" << endl;
for(unsigned int i=0;i<size;i++)
    cout << i+1 << " " << v[i] << endl;

for(unsigned int i=0;i<size;i++){
    cambio=false;
    for(int j=size-1;j>=1;j--){

   cout << endl;
   cout << "Se compara:" << j << " y " << j+1 << endl;
   cout << j << " " << v[j-1] << endl;
   cout << j+1 << " " << v[j] << endl;
   cout << endl;
   comparacion++;

   if (v[j] < v[j-1]){

       cout << "El valor " << v[j-1] << " de la posicion:" << j << " es mayor que " << v[j] << " de la posicion:" << j+1 << endl;
       cout << "Se intercambian los valores" << endl;
       swap(v[j],v[j-1]);
       //temporal=v[j];
       //v[j]=v[j-1];
       //v[j-1]=temporal;
       cambio=true;
       cout << endl << "La secuencia queda asi: " << endl;
       for (unsigned int i=0; i < size; i++)
       cout << i+1 << " " << v[i] << endl;

    }

    else {

           cout << "El valor " << v[j-1] << " de la posicion:" << j << " NO es mayor que " << v[j] << " de la posicion:" << j+1 << endl;
           cout << "La secuencia queda asi: " << endl;
           for (unsigned int i=0; i < size; i++)
           cout << i+1 << " " << v[i] << endl;
       }
       }

    if(!cambio){
        cout <<endl << "No se producen otros cambios" << endl;
        cout << "La secuencia ha acabado" << endl;
        break;

    }
}}

    else if(mode==true){


        for(unsigned int i=0;i<size;i++){
            cambio=false;
            for(int j=size-1;j>=1;j--){
           comparacion++;

           if (v[j] < v[j-1]){
               swap(v[j],v[j-1]);
               cambio=true;}
               }

            if(!cambio){
                break;

            }
        }
    }
return comparacion;

}




#endif // BUBBLE_HPP
