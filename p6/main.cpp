#include <iostream>
#include "dni.hpp"
#include "tree.hpp"
#include "node.hpp"
#include "bubble.hpp"


/* SONAR QUBE  use online */

using namespace std;

void randomizar(vector<dni> &v){

    for (unsigned int i=0;i<v.size();i++)
        v[i].set_random();
}



int main(){

    int opcion = 999;
    int size_tree = 10;
    int npruebas=0;
    int option = 999;

do{
        cout << "Modos posibles en los que se puede trabajar " << endl;
        cout << "1.Modo demonstracion" << endl;
        cout << "2.Modo estadistica" << endl;
        cout << "Opcion?" << endl;
        cin >> opcion;}

while((opcion!=1)&&(opcion!=2));

    if(opcion == 1){

    tree<long int> tree_;
    do {
    while((option!=1)&&(option!=2)&&(option!=3)&&(option!=4)&&(option!=5)&&(option!=6)&&(option!=7)&&(option!=8)){

        cout << endl << "-------------Modo Demonstracion-------------" << endl;
        cout << "Modos posibles en los que se puede trabajar " << endl;
        cout << "1.Insertar clave" << endl;
        cout << "2.Eliminar clave" << endl;
        cout << "3.Mostrar arbol" << endl;
        cout << "4.Salir" << endl;
        cout << "Opcion?" << endl;
        cin >> option;
        }

    switch(option){

      case 1:{
        long int clave = 0;
        cout << "-------Modo insercion de una clave--------" << endl;
        cout << "Introduzca la clave que quiere insertar: " << endl;
        cin >> clave;
        tree_.insert(clave);
        option = 999;
        break;}
      case 2:{
        long int clave = 0;
        cout << "-------Modo eliminacion de una clave--------" << endl;
        cout << "Introduzca la clave que quiere eliminar: " << endl;
        cin >> clave;
        tree_.eliminate(clave);
        option = 999;
        break;}
      case 3:{
        cout << "-------Modo mostrar el arbol por niveles----------" << endl;
        tree_.print_level(tree_.get_root());
        option = 999;
        break;}
      case 4:{
        cout << "Se ha salido del programa" << endl;
        return 0;
        break;}

         }}
    while(option!=4);

 }

    else if(opcion == 2){

        cout << "Se ha introducido el modo estadistico " << endl;
        cout << "Introduzca el tamano de la secuencia(por defecto es 10): " << endl;
        cin >> size_tree;
        cout << "Introduzca el numero de pruebas que se quiere hacer: " << endl;
        cin >> npruebas;
        cout << "------------Número de Comparaciones-----------" << endl;
        cout << "------Mínimo----------Medio--------Máximo-------"  << endl;


        vector<dni> vector_prueba(size_tree);
        //vector<vector<float>> resultados(2,vector<float>(3));
        vector<float> comparacion(vector_prueba.size());
        vector<float> min(npruebas);
        vector<float> max(npruebas);
        float suma = 0;

            for(int i=0;i<npruebas;i++){

                tree<dni> test_tree;
                randomizar(vector_prueba);

                for(unsigned int j=0;j<vector_prueba.size();j++){
                comparacion[j]=test_tree.insert(vector_prueba[j]);
                suma+=comparacion[j];}
                bubble_sort<float>(comparacion, comparacion.size(), true);
                min[i] = comparacion.front();
                max[i] = comparacion.back();
        }
            bubble_sort<float>(min,  min.size(), true);
            bubble_sort<float>(max,  max.size(), true);


            cout << "Comparaciones insercion: " << setw(12) << min.front() << setw(12) << (suma/(npruebas*vector_prueba.size())) << setw(12) << max.back() << endl;

            suma = 0;

            vector<dni> vector_prueba_2((2*size_tree));
            vector<float> comparacion_2(vector_prueba_2.size()/2);

                for(int i=0; i<npruebas; i++){

                    tree<dni> test_tree;
                    randomizar(vector_prueba_2);
                    for(unsigned int j=0;j<vector_prueba_2.size()/2;j++){
                        test_tree.insert(vector_prueba_2[j]);}

                        for (unsigned int j=0;j<vector_prueba_2.size()/2;j++){
                             test_tree.search(vector_prueba_2[j]);
                             comparacion_2[j] = test_tree.get_comparison();
                             suma+=comparacion_2[j];
                        }
                        bubble_sort<float>(comparacion_2, comparacion_2.size(), true);
                        min[i] = comparacion_2.front();
                        max[i] = comparacion_2.back();
                    }

                        bubble_sort<float>(min,  min.size(), true);
                        bubble_sort<float>(max,  max.size(), true);


                    cout << "Comparaciones búsqueda:  " << setw(12) << min.front() << setw(12) << (suma/(npruebas*(vector_prueba_2.size()/2))) << setw(12) << max.back() << endl;
        }

    else{
            cout << "Se ha salido del programa" << endl;
            return 0;
    }
    return 0;

    }



