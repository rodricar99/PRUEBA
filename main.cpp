# include <iostream>
using namespace std ;

int main (){
  int n=0,mejor=0;
  double precio=0,peso=0,posicion=0;
  cout<<"Ingrese la cantidad de productos: ";
  cin>>n;
  cout<<"Ingrese los productos (precio peso)"<<endl;
  double listaPrecio[n],listaPeso[n],total[n];
  for(int i=0; i<n;i++){
    cout<<"Producto "<<i+1<<": ";
    cin>>precio>>peso;
    listaPrecio[i] = precio;
    listaPeso[i] = peso;
    total[i]=listaPrecio[i]/listaPeso[i];
  }
  double menor = total[0];
  for(int i=0;i<n;i++){
    if(menor>total[i])
      menor = total[i];
      posicion=i;
  }
  cout<<"El producto con mejor relacion es el: "<<posicion+1;
  return 0;
}