/*
 *  Problema del fontanero 
 * 
 *  Hecho por Daniel Roa
 *  27-03-2020
 * 
 */
#include <iostream>
#include <stdio.h>

using namespace std;

//Comienza la implementación de Bubble Sort
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
//Termina la implementación de Bubble sort

int  main() {

  int hogar = 0;        //Cantidad de casas que va a visitar
  int demora[hogar];    //Arreglo con los tiempos que se va a tardar
  int totalT=0;         //Tiempo total

  cout << "¿Cuántos lugares va a visitar el fontanero?"<<endl;
  cin >> hogar;         //Se insertan la cantidad de casas que se van a visitar.

  for (int i = 0; i < hogar; i++) {
    cout << "Tiempo "<< i+1 <<": ";
    cin >> demora[i];
    cout << "\n";
  }

  bubbleSort(demora, hogar);

  cout<<"El orden de los tiempos es el siguiente: "<<endl;

  for (int j = 0; j < hogar; j++) {

    totalT = demora [j]+totalT;
    cout << "Tiempo que va a tardarse:" << j+1 << " " << totalT << " minutos" << endl;

    if (j==hogar) {
      totalT += demora [j];
      cout << "Tiempo que tarda: " << hogar << " " << totalT << " minutos" << endl;
    }

  }

}