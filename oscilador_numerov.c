#include <stdio.h>
#include <math.h>

#define tmax 10.0
#define dt 0.01 

main(){
  
  double i, x, x_old, w, w_new, w_old, v_old, t=0.0, f;
  
  x_old = 2.0; // valor inicial de x.
  v_old = 1.0; // valor inicial de v.
  f = -3.0;    // termo f(t) --> para este caso é constante.
  
  double dt2 = pow(dt,2);
  
  //expressão para calcular o valor de x no ponto seguinte.
  x = ((2 + (5*dt2*f/6))*(1-(dt2*f/12))*x_old + (2*dt*v_old*(1 - (dt2*f/6)))) / (((1-(dt2*f/12))*(1 - (dt2*f/6))) + ((1-(dt2*f/12))*(1 - (dt2*f/6))));

  w = (1- (dt*dt/12)*f)*x;
  w_old = (1- (dt*dt/12)*f)*x_old;
  
  //inicialização do algoritmo.
  for(i=0;i<tmax;i+=dt){
    
    w_new = 2*w - w_old + dt2*f*x;
    x = w_new/(1 - dt*dt/12*f);
    printf("%f %f \n", t, x);
    w_old = w;
    w = w_new;
    
    t = t + dt;
    
  }
  
} 
