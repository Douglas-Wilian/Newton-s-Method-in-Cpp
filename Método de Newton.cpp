#include <iostream>
#include <cmath>
#include <iomanip>

#define alpha -0.1
#define beta 1
#define N 5
using namespace std;

double function(double x[5], double f[]){
  int n=4;
  f[0] = (-1)*(-1*(3+alpha*x[0])*x[0] + 2*x[1] - beta);
  for(int i=1; i<n;i++){
  f[i] = (-1)*(x[i-1] - (3+alpha*x[i])*x[i] + 2*x[i+1] - beta); 
  }
  f[n] = (-1)*(x[n-1] - (3+alpha*x[n])*x[n] - beta);
return *f;
}

double jacobiana(double x[5], double J[5][5]){
for(int i=0; i<5; i++){
  for(int j=0; j<5; j++){
    if(i == j){
      J[i][j] = -3 - 2*alpha*x[i];
      J[i][j+1] = 2;
    if(i>=1){
      J[i][j-1] = 1;
    }
    }
  }
}
return **J;
}

double Gauss(double B[5][5], double ind[5], double chute[5]){
  for(int k = 0; k<10; k++){
    for(int i=0; i<5; i++){
      double b1 = ind[i];
        for(int j=0; j<5; j++){
          if(j != i){
            b1 -= B[i][j] * chute[j];
          }
        }
      b1 /= B[i][i];
      chute[i] = b1;
   }
    }
  return *chute;
  }


int main() {
double J[5][5]={0}, x0[5]={0}, prec, f[5]={0}, p[5], teste[5], verify =0, invJ[5][5];
double atual[5]={0};
int n;

// ENTRADA DAS VARIAVEIS
cout << "\nRESOLUÇÃO DE SISTEMA NÃO LINEAR DETERMINADO:\n\n";
cout << "Chute inicial?\n";
  for(int i=0; i<5; i++){
    cout << "x0[" << i << "] = ";
    cin >> x0[i];
  }
cout << "\nPrecisao desejada?\n";
cin >> prec;
cout << "\nNumero de iteracoes?\n";
cin >> n;

for(int k=0; k<n; k++){
  for(int i=0; i<5; i++){
      p[i] = x0[i]; 
    } 

*f = function(x0,f);
**J = jacobiana(x0, J);
*x0 = Gauss(J, f, x0);
  for(int i=0; i<5; i++){
    atual[i] = p[i] + x0[i];
  }
  for(int i=0; i<5; i++){
    teste[i] = (atual[i] - p[i])/p[i];
    verify = verify + pow(teste[i], 2);
  }
  if(sqrt(verify) <= prec){
    cout << "\nATINGIU A PRECISAO!\n";
    cout << "\nAs raizes sao:\n";
    for(int i=0; i<5; i++){
      cout << "x_" << i+1 << " = " << setprecision(16) << p[i] << endl;
    }
    break;
  }else{
    for(int i=0; i<5; i++){
      x0[i] = atual[i];
    }
    verify =0;
  }
}
if(verify ==0){
  cout << "\nNAO ATINGIU A PRECISAO\n";
  cout << "\nAs raizes sao:\n";
  for(int i=0; i<5; i++){
    cout  << "x_" << i+1 << " = "<< setprecision(16) << atual[i] << endl;
    x0[i] = 0;
  }
}
return 0;
}