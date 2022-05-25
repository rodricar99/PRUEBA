#include <iostream>

using namespace std;



int* generar_arreglo(int cantidad, int valor, int step){
    int lista[100000];
    for(int i=0;i<cantidad;i++){
        if(i%step==0 or i==0)
            lista[i] = valor;
        else
            lista[i] = 0;
    }
    return lista;
}

int main() {
    int cantidad = 0, valor = 0, step = 0;
    cin>>cantidad>>valor>>step;
    int* lista = generar_arreglo(cantidad,valor,step);
    cout<<"--------------"<<endl;
    for(int i=0;i<cantidad;i++)
        cout<<*(lista+i)<<" ";
    return 0;
}