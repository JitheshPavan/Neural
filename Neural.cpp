#include <iostream>
#include <math.h>
#include "Neural.h"
double LR =0.1000;
namespace ann{

double parameter::function(const double& x) const {return w * x;}
double parameter::derivate(const double& x) const { return x;}
void parameter::learning(const double& x, const double& y,const double& y1) {w=w +(LR *2.0 * (y-y1)*derivate(x));}
double parameter::getw(){return w;}


double bias::function(const double& x) const { return x+b;}
double bias::derivate(const double& x)   const {return 1.00;}
void bias::learning(const double& x, const double& y,const double& y1){b=b +(LR *2.0 * (y-y1)*derivate(x));}
double bias::getb(){return b;}

double MSE(const double& x, const double& y){
return std::pow(x-y, 2.00);}
}
int main(){
//hyperparameters and data
  int epochs=10;
  double weight=2;
  double bias=1;
  double input[]={0,1,2,3,4,5};
  double error=0.00;
  double truey[6]={0,1,2,3,4,5};
  for(int i=0;i<5;i++){
       truey[i]=(input[i] * weight) +bias;
  }
// Initialization of ANN
  ann::parameter w;
  ann::bias b;
// Training
  for(int j=0;epochs>j;j++){
  for(int i=0;i<5;i++){
  int x= input[i];
  int y=truey[i];
  double output =b.function(w.function(x));
  error=error + ann::MSE(y,output);
  w.learning(x,y,output);
  b.learning(x,y,output); }
   error=error/6.0;
   std::cout << "EPOCH:: "<< j+1 << "|| average error:" <<error << "|| new weight:"<<w.getw() <<" || new bias:" <<b.getb() <<std::endl;}
   error=0.00;
  return 0;    
}
