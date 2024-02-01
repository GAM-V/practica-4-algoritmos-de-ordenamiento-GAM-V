#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>

#include "ordenamiento.h"

using namespace std;
using namespace std::chrono;


duration<double> crear_arreglo(int *A, int TAM_ARREGLO, int RANGO_MAX) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < TAM_ARREGLO; i++) {
        int x = rand() % RANGO_MAX;
        A[i] = x;
    }
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_insertion_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    insertion_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_selection_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    selection_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_bubblesort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubblesort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}

duration<double> ordenar_merge_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    merge_sort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_quicksort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    quicksort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


int* copiar_arreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}


void mostrar_arreglo(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}


duration<double> ejecutarAlgoritmo(int* B, int tam, string opcion) {
       
    duration<double> tiempo;        
    if (opcion == "is") {
        
        cout << "Iniciando ordenamiento con INSERTION SORT... ";
        tiempo = ordenar_insertion_sort(B, tam);
        cout << "\tOrdenado. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        delete [] B;
    }
    if (opcion == "ss") {
        cout << "Iniciando ordenamiento con SELECTION SORT... ";
        tiempo = ordenar_selection_sort(B, tam);
        cout << "\tOrdenado. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        delete [] B;
    }
    if (opcion == "bs") {
        cout << "Iniciando ordenamiento con BUBBLESORT... ";
        tiempo = ordenar_bubblesort(B, tam);
        cout << "\tOrdenado. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        delete [] B;
    }
    if (opcion == "ms") {
        cout << "Iniciando ordenamiento con MERGE SORT... " << flush;
        tiempo = ordenar_merge_sort(B, tam);
        cout << "\tOrdenado. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        delete [] B;
    }
    if (opcion == "qs") {
        cout << "Iniciando ordenamiento con QUICKSORT... " << flush;
        tiempo = ordenar_quicksort(B, tam);
        cout << "\tOrdenado. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        delete [] B;
    }
    
    cout << endl;
    return tiempo;
    
    
}




int main(int argc, char * argv[]) { 
    if (argc != 3) {
        cout << "\nSintaxis: ordenamiento <número_arreglos_a_generar_y_ordenar> <tamaño_arreglo>\n" << endl; 
    } else {
        
        int NUM_ARREGLOS = atoi(argv[1]);
        int TAM_ARREGLO = atoi(argv[2]);
        int RANGO = 10 * TAM_ARREGLO;

        std::string titulo = "" + std::to_string(TAM_ARREGLO)+".txt";
        std::ofstream salida(titulo);
        salida << "MUNERO DE ARREGLO \t insertion sort \t selection sort \t bubblesort \t\t merge sort \t\t quicksort" << endl;

        cout << "\n\tTAMAÑO DE ARREGLOS: " << TAM_ARREGLO <<"\tNUMERO DE ARREGLOS: " << NUM_ARREGLOS << endl;

        string algoritmos[] = {"is", "ss", "bs", "ms", "qs"};
        for (int i = 0; i < NUM_ARREGLOS; i++) // Itera el numero de arreglos
        {
            int *A = new int[TAM_ARREGLO];// declara los arreglos
            int *B = new int[TAM_ARREGLO];
            salida << "\t" << i+1 << "\t""\t";

            duration<double> tiempo;
            duration<double> tiempo1;
            cout << "\n** NUMERO DE ARREGLO: " << i + 1 << " **" << endl;// Crea numeros aleatorios
            cout << "\nCreando arreglo aleatorio de tamaño " << TAM_ARREGLO << "...";
            tiempo = crear_arreglo(A, TAM_ARREGLO, RANGO);
            cout << "\tCreado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl << "\n";

            for (string algoritmo : algoritmos)
            {
                B = copiar_arreglo(A, TAM_ARREGLO);
                tiempo1 = ejecutarAlgoritmo(B, TAM_ARREGLO, algoritmo);
                salida << std::fixed << std::setprecision(8) << tiempo1.count() << "\t""\t"; 

            }
            salida << endl;
        }
    }
    return EXIT_SUCCESS;
}