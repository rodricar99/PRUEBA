#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime> 
using namespace std;

int main() {
  // Generador de numeros aleatorios entre 1 y 1000 //

  srand(time(NULL));
  int random = rand()%1001, resto = 0, verificador = 0;
  cout<<random<<endl;
  unsigned t0, t1;
  t0=clock();

  // ---------------------------------------------- //

  // Convertidor de numeros a binario //

  string binario = "", llave = " ";

  while(!verificador){
    resto = random%2;
    random = random /2;
    if(random/2==0){
      binario = to_string(resto)+binario ;
      if(resto==0)
        llave = "11"+llave;
      else
        llave = "00"+llave;
      binario = "1" + binario ;
      llave = "00" + llave;
      break;
    }
    binario = to_string(resto)+binario ;
    if(resto==0)
      llave = "11"+llave;
    else
      llave = "00"+llave;
    resto = 0;
  }

  // ---------------------------------------------- //

  // Tiempo de ejecucion de un programa //

  t1 = clock();
 
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;

  // Claves generadas //

  cout<<binario<<endl;
  cout<<llave;
 
  return 0;
}