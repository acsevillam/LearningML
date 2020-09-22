#include<iostream>
#include<cmath>
#include <cstdlib>
class pair{
private:
        double q1,p1,q2,p2,dt;
        double a,D,m;
public:
  pair(double q10,double p10,double q20,double p20,double dt);
  ~pair(){};
  double dhdp(double p,double q);
  double dhdq(double p,double q);
  double H(double p,double q);
  void timestep(void);
  double get_q1(void){return q1;};
  double get_p1(void){return p1;};
  double get_q2(void){return q2;};
  double get_p2(void){return p2;};
};

int main(int argc, char const *argv[]) {

int N=atoi(argv[1]);
pair midpoint(3,1,6,2,0.01);
for(int i=0;i<N;i++){
  midpoint.timestep();
  std::cout<<midpoint.get_q1()<<' '<<midpoint.get_p1()<<' '<<midpoint.get_q2()<<' '<<midpoint.get_p2()<<std::endl;
}

  return 0;
}


pair::pair(double q10,double p10,double q20,double p20,double dt0){
q1=q10;
p1=p10;
q2=q20;
p2=p20;
dt=dt0;
a=0.18;
D=15.;
m=1.;
}
double pair::dhdp(double p,double q){
    return p/m;
}
double pair::dhdq(double p,double q){
    return 2.*D*a*(exp(-a*q)-exp(-2*a*q));
  }
double pair::H(double p,double q){
    return p*p/(2*m)+D*pow((1.-exp(-a*q)),2);
  }
void pair::timestep(void){
    p1-=dhdq(p1,q1)*dt;
    q1+=dhdp(p1,q1)*dt;
    p2-=dhdq(p2,q2)*dt;
    q2+=dhdp(p2,q2)*dt;
  }
