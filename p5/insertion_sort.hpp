#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

using namespace std;


template<class clave>
long int insertion_sort(vector<clave> &v,unsigned int size,bool mode){

    clave temporal;
    unsigned long int comparacion=0;

    if(mode==false){

cout << "Vector antes de aplicar el algoritmo" << endl;

for(int i=0;i<size;i++)
  cout << i+1 << " " << v[i] << endl;
  cout << endl;

for(int i=1;i<size;i++){

   temporal=v[i];
   int j=i-1;

   cout << "Se compara: " << j+1 << " y " << i+1 << endl;
   cout << j+1 << " " << v[j] << endl;
   cout << i+1 << " " << v[i] << endl;
   cout << endl;
   comparacion++;

while((temporal<v[j])&&(j>=0)){

    cout <<"El valor " << v[j] << " de la posicion:" << j+1 << " es mayor que " << temporal << " de la posicion:" << j+2 << endl;
    cout << endl;
    v[j+1]=v[j];
    comparacion++;
    j--;

}
if(j==-1){comparacion--;}

cout << "El valor " << temporal << " de la posicion:" << i+1 << " sustituye el valor " << v[j+1] << " de la posicion:" << j+2 << endl;
v[j+1]=temporal;

cout << "La secuencia queda asi: " << endl;
for (int i=0; i < size; i++)
cout << i+1 << " " << v[i] << endl;
cout << endl;}}

    else if(mode==true){

        for(int i=1;i<size;i++){

           temporal=v[i];
           int j=i-1;
           comparacion++;

        while((temporal<v[j])&&(j>=0)){
            v[j+1]=v[j];
            comparacion++;
            j--;}
        if(j==-1){comparacion--;}
        v[j+1]=temporal;}

    }

return comparacion;


}


#endif // INSERTION_SORT_HPP
