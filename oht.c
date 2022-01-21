#include <stdio.h>
#include <math.h>

#define rmax 20.0  //distância máxima de integração.
#define dr 0.001 //passo de integração.

/* função F(l,r,E) -----------------------------------------------------------*/

double f(int l, double r, double E){
  
  double V = pow(r,2); //potencial utilizado.
  
  return V - E; //nesse caso, não há termo centrífugo porque estamos utilizando l=0.
  
}

/* ---------------------------------------------------------------------------*/

/* início da função main() ---------------------------------------------------*/
main(){
  
  double u, u_old, u_new, w, w_new, w_old, uderiv_old, r = 0.0;
  int i;
  
  u_old = 0.0;  //condição de contorno necessária.
  uderiv_old = 1.0; // determina a constante de normalização na solução analítica.
  
  double dr2 = pow(dr,2);
  
  //calcula o primeiro valor de u após u_old, em um intervalo dr.
  u = ((2 + (5*dr2*f(0,0.0,3.0)/6))*(1-(dr2*f(0,-dr,3.0)/12))*u_old + (2*dr*uderiv_old*(1 - (dr2*f(0,-dr,3.0)/6)))) / (((1-(dr2*f(0,dr,3.0)/12))*(1 - (dr2*f(0,-dr,3.0)/6))) + ((1-(dr2*f(0,-dr,3.0)/12))*(1 - (dr2*f(0,dr,3.0)/6))));
  
  w = (1- (dr*dr/12)*f(0,dr,3.0))*u;
  w_old = (1- (dr*dr/12)*f(0,0.0,3.0))*u_old;
  
  //inicialização do algoritmo.
  for(i=1;i<=rmax/dr;i++){
    r=i*dr;
    w_new = 2*w - w_old + dr2*f(0,r,3.0)*u;
    u_new = w_new/(1 - dr*dr/12*f(0,r,3.0));
    printf("%f %f \n", r, u_new); // imprime os valores de r e o u(r) correspondente.
    u = u_new;
    w_old = w;
    w = w_new;
    
  }
  
} 

/* ------------------------------- FIM ------------------------------------*/
