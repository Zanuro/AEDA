#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

template<class clave>
void max_heap(vector<clave> &v,unsigned int size, int i, unsigned long int &comparacion,bool mode){

int root = i;
int hijo_izq = 2*i + 1;
int hijo_dch = 2*i + 2;


if(mode==false){
cout << endl<< "Posicion:" << i+1 << endl;
cout << endl << "Comparamos el padre " << v[root] << " de la posicion:" << root+1 << " con sus hijos " << v[hijo_izq] << " y " << v[hijo_dch] << "(si es 0 significa que esta fuera del vector)" << endl;
cout << endl << "Se intercambia solo si " << v[root] << " es menor que uno de sus dos hijos " << " y " << hijo_izq << " o " << hijo_dch << " es menor que:" << size << endl;}
if (hijo_izq < size){

    if((v[hijo_izq] > v[root])){
    if(mode==false){
      cout <<"El valor " << v[root] << " de la posicion:" << root+1 << " es menor que " << v[hijo_izq] << " de la posicion:" << (2*i)+1 << endl;
      cout <<"El valor " << v[hijo_izq] << " es ahora el root " << endl;}
      root = hijo_izq;}
      comparacion++;
}


if (hijo_dch < size){
    if(v[hijo_dch] > v[root]){
    if(mode==false){
      cout <<"El valor " << v[root] << " de la posicion:" << root+1 << " es menor que " << v[hijo_dch] << " de la posicion:" << (2*i)+2 << endl;
      cout <<"El valor " << v[hijo_dch] << " es ahora el root " << endl;}
      root = hijo_dch;}
      comparacion++;
}

        if (root != i){
            if(mode==false){
            cout << "Como el root inicial " << v[i] << " es distinto del root actual " << v[root] << "........." << " INTERCAMBIAMOS " << endl;}
            swap(v[i], v[root]);
            if(mode==false){
            cout << "La secuencia queda asi: " << endl;
            for (int x=0; x < size; x++)
            cout << x+1 << " " << v[x] << endl;
            cout << endl;}
            max_heap(v, size, root,comparacion,mode);
        }
}

template<class clave>
long int heap_sort(vector<clave> &v,unsigned int size,bool mode){

unsigned long int comparacion=0;

if(mode==false){
cout << "Vector antes de aplicar el algoritmo" << endl;

 for(int i=0;i<size;i++)
   cout << i+1 << " " << v[i] << endl;

cout << endl << "--------Primero creamos el Max Heap---------" << endl;}

for (int i = size / 2 - 1; i >= 0; i--) //max heap
        max_heap(v, size, i, comparacion,mode);
if(mode==false){
cout << endl << "Asi queda el vector como Max Heap....." << endl;
    for (int z=0; z < size; z++)
    cout << z+1 << " " << v[z] << endl;


cout << endl <<  "----------Ordenamos el vector-------" << endl;}
for (int i=size-1; i>=0; i--){          //ordenar

    if(mode==false){
   cout << endl << "Se intercambia el primer elemento " << v[0] << " con el ultimo elemento " << v[i] << endl;}
   swap(v[0], v[i]);
   if(mode==false){
   cout << endl << "Rehacemos la condicion de MaxHeap " << endl;}
   max_heap(v, i, 0, comparacion,mode);
   if(mode==false){
   for (int z=0; z < size; z++)
   cout << z+1 << " " << v[z] << endl;}}

if(mode==false){
cout << "La secuencia queda asi: " << endl;
for (int i=0; i < size; i++)
cout << i+1 << " " << v[i] << endl;}

return comparacion;

}

#endif // HEAP_SORT_HPP
