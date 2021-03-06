#include <iostream>
#include "dni.hpp"
#include "bubble.hpp"
#include "insertion_sort.hpp"
#include "heap_sort.hpp"
#include "quick_sort.hpp"
#include "shell.hpp"
#define ALGORITMOS 5

using namespace std;


void randomizar(vector<dni> &v){

    for (int i=0;i<v.size();i++)
        v[i].set_random();
}


void calcular_comp(vector<int> &comp, vector<vector<float>> &v, float suma, unsigned int algoritmo){

        heap_sort<int>(comp, comp.size(), true);

        v[algoritmo][0] = comp.front();
        v[algoritmo][1] = (suma/comp.size());
        v[algoritmo][2] = comp.back();
}


int main(){

    int opcion = 999;
    int size_prueba = 25;
    int algortimo_ordenacion = 100;
    int npruebas=0;

do{
        cout << "Modos posibles en los que se puede trabajar " << endl;
        cout << "1.Modo demonstracion" << endl;
        cout << "2.Modo estadistica" << endl;
        cout << "Opcion?" << endl;
        cin >> opcion;}

while((opcion!=1)&&(opcion!=2));

    if(opcion == 1){

    cout << "Se ha introducido el modo de demonstracion " << endl;

    while((algortimo_ordenacion!=1)&&(algortimo_ordenacion!=2)&&(algortimo_ordenacion!=3)&&(algortimo_ordenacion!=4)&&(algortimo_ordenacion!=5)){

        cout << "Introduzca el tamano de la secuencia(por defecto es 25): " << endl;
        cin >> size_prueba;
        if(size_prueba <= 0){
            size_prueba=25;
        }

        cout << "Algoritmos posibles para la ordenacion " << endl;
        cout << "1.Algoritmo BubbleSort" << endl;
        cout << "2.Algoritmo InsertionSort" << endl;
        cout << "3.Algoritmo HeapSort" << endl;
        cout << "4.Algoritmo QuickSort" << endl;
        cout << "5.Algoritmo ShellSort" << endl;
        cout << "Opcion?" << endl;
        cin >> algortimo_ordenacion;

    }

    vector<dni> vec(size_prueba);

    switch(algortimo_ordenacion){

    case 1:
        cout << "-------Demonstracion BubbleSort--------" << endl;
        randomizar(vec);
        bubble_sort<dni>(vec,size_prueba,false);break;
    case 2:
        cout << "-------Demonstracion InsertionSort--------" << endl;
        randomizar(vec);
        insertion_sort<dni>(vec,size_prueba,false);break;
    case 3:
        cout << "-------Demonstracion HeapSort--------" << endl;
        randomizar(vec);
        heap_sort<dni>(vec,size_prueba,false);break;
    case 4:
        cout << "-------Demonstracion QuickSort--------" << endl;
        randomizar(vec);
        quicksort<dni>(vec,size_prueba,false);break;
    case 5:
        cout << "-------Demonstracion ShellSort--------" << endl;
        randomizar(vec);
        shell_sort<dni>(vec,size_prueba,false);break;

    }
    }

    else{

        cout << "Se ha introducido el modo estadistico " << endl;
        cout << "Introduzca el tamano de la secuencia(por defecto es 25): " << endl;
        cin >> size_prueba;
        cout << "Introduzca el numero de pruebas que se quiere hacer: " << endl;
        cin >> npruebas;
        cout << "------------Número de Comparaciones-----------" << endl;
        cout << "------Mínimo----------Medio--------Máximo-------"  << endl;


        vector<dni> vector_prueba(size_prueba);
        vector<vector<float>> resultados(5,vector<float>(3));
        vector<int> comparacion(npruebas);
        float suma_total=0;
        int v=0;

        while(v<5){

          switch (v){

            case 0:

            for(int i=0;i<npruebas;i++){

                randomizar(vector_prueba);
                comparacion[i]=bubble_sort<dni>(vector_prueba,size_prueba,true);
                suma_total+=comparacion[i];
                                            }
                calcular_comp(comparacion, resultados, suma_total, 0);

                cout << "BubbleSort: " << setw(10) << resultados[0][0] << setw(10) << resultados[0][1] << setw(10) << resultados[0][2] << endl;
                suma_total=0;
                v++;
             break;


            case 1:


            for(int i=0;i<npruebas;i++){

                 randomizar(vector_prueba);
                 comparacion[i]=insertion_sort<dni>(vector_prueba,size_prueba,true);
                 suma_total+=comparacion[i];
                                            }

                calcular_comp(comparacion, resultados, suma_total, 1);

                cout << "InsertionSort: " << setw(10) << resultados[1][0] << setw(10) << resultados[1][1] << setw(10) << resultados[1][2] << endl;
                suma_total=0;
                v++;
              break;

           case 2:

           for(int i=0;i<npruebas;i++){

                randomizar(vector_prueba);
                comparacion[i]=heap_sort<dni>(vector_prueba,size_prueba,true);
                suma_total+=comparacion[i];
                                            }
                calcular_comp(comparacion, resultados, suma_total, 2);

                cout << "HeapSort: " << setw(10) << resultados[2][0] << setw(10) << resultados[2][1] << setw(10) << resultados[2][2] << endl;
                suma_total=0;
                v++;
              break;

            case 3:

            for(int i=0;i<npruebas;i++){

                randomizar(vector_prueba);
                comparacion[i]=quicksort<dni>(vector_prueba,size_prueba,true);
                suma_total+=comparacion[i];
                                         }
                calcular_comp(comparacion, resultados, suma_total, 3);

                cout << "QuickSort: " << setw(10) << resultados[3][0] << setw(10) << resultados[3][1] << setw(10) << resultados[3][2] << endl;
                suma_total=0;
                v++;
              break;


           case 4:

           for(int i=0;i<npruebas;i++){

                randomizar(vector_prueba);
                comparacion[i]=shell_sort<dni>(vector_prueba,size_prueba,true);
                suma_total+=comparacion[i];
                                             }
                calcular_comp(comparacion, resultados, suma_total, 4);

                cout << "ShellSort: " << setw(10) << resultados[4][0] << setw(10) << resultados[4][1] << setw(10) << resultados[4][2] << endl;
                suma_total=0;
                v++;
              break;
        }

    }
}
}
