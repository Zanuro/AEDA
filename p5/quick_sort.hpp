#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include <algorithm>

using namespace std;


template<class clave>
void quicksort(vector<clave> &v, unsigned int inicio, unsigned int final, unsigned long int &comparacion,bool mode){

    //clave temporal;
    int i=inicio;
    int j=final;
    clave pivote = v[((inicio+final)/2)+1];

while (i <= j) {

    if(mode==false){
    cout << endl << "El indice:" << i+1 << " es menor que:" << j+1 << endl;
    cout << endl << "El pivote es " << pivote << endl;}

while (v[i] < pivote){

    if(mode==false){
    cout << "El valor " << v[i] << " es menor que " << pivote << endl;}
    i++;
    comparacion++;
}
comparacion++;  // en el caso de que sea mayor que el pivote

while (v[j] > pivote){

    if(mode==false){
    cout << "El valor " << v[j] << " es mayor que " << pivote << endl;}
    j--;
    comparacion++;
}
comparacion++; // en el caso de que sea mayor que el pivote

if (i < j){

    if(mode==false){
    cout << "El indice:" << i+1 << " es menor que: " << j+1 << endl;
    cout << "Se intercambia el elemento " << v[i] << " y " << v[j] << endl;}
    swap(v[i],v[j]);
    i++;
    j--;
}
else if(i==j){i++;j--;}
}


if (inicio < j){

    if(mode==false){
    cout << "La secuencia queda asi: " << endl;
    for (int z=0; z < v.size(); z++)
          cout << z+1 << " " << v[z] << endl;

    cout << endl << "----------Se ordena el lado izquierdo-------" << endl;}
    quicksort(v,inicio,j,comparacion,mode);

}


//comparacion++; // compara con el indice del borde ????

if (i < final){

    if(mode==false){
    cout << "La secuencia queda asi: " << endl;
    for (int z=0; z < v.size(); z++)
          cout << z+1 << " " << v[z] << endl;

    cout << endl << "--------Se ordena el lado derecho-----------" << endl;}
    quicksort(v,i,final,comparacion,mode);

}
        //comparacion++;
}

template<class clave>
long int quicksort(vector<clave> &v, unsigned int size,bool mode){

unsigned long int comparacion=0;

if(mode==false){

cout << "Vector antes de aplicar el algoritmo" << endl;

   for(int i=0;i<size;i++)
     cout << i+1 << " " << v[i] << endl;}

   quicksort(v, 0, v.size()-1, comparacion,mode);

   if(mode==false){
   cout << "La secuencia queda asi: " << endl;
   for (int i=0; i < size; i++)
         cout << i+1 << " " << v[i] << endl;}

   return comparacion;

}

#endif // QUICK_SORT_HPP
