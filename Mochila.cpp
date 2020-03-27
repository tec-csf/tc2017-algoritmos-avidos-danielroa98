/*
 *  Problema de la mochila 
 * 
 *  Hecho por Daniel Roa
 *  27-03-2020
 * 
 */
#include <iostream>
using namespace std;

void Ruksak(int n, int m, int comp, int conv, int peso[], int beneficio[]){

    int morral[n][m]; 

    for(int i=0; i<m; i++){
        morral[0][i] = 0;
        if(i<n){
            morral[i][0] = 0;
        }
    }

    for(int i=1; i<=n-1; ++i){
        for(int j=1; j<=m-1; ++j){
            if(j-peso[i] < 0){
                    morral[i][j] = morral[i-1][j];
            }
            else{
            morral[i][j] = max(morral[i-1][j], morral[i-1][j-peso[i]] + beneficio[i]);
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(morral[i][j]>comp){
                comp=morral[i][j];
                conv=morral[i][j];
            }

        }
    }

    cout<<"\n";
    cout<<"El mejor beneficio total es: "<< conv << endl;   //imprime el mejor valor total que se puede insertar

}

int main(int argc, char const *argv[]){
    int n,m;
    int comp=-1;
    int conv=0;

    cout<<"Escribe la cantidad de objetos que puede cargar la mochila:" << endl;
    cin >> n;
    
    cout << "Escribe cual es el peso máximo de la mochila:" << endl;
    cin >> m;
    
    n=n+1;
    m=m+1;

    int peso[n+1];
    int beneficio[n+1];
    
    peso[0]=0;
    beneficio[0]=0;

    for(int i=1; i<n; ++i){
        cout<<"Peso "<<i<<": "<<endl;
        cin>>peso[i];
    }

    for(int j=1; j<n; ++j){
        cout<<"Beneficio "<<j<<": "<<endl;
        cin>>beneficio[j];
    }

    Ruksak(n, m, comp, conv, peso, beneficio);
    
    return 0;
}