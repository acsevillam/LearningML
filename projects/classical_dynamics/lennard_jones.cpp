#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <cstdlib>
#include <omp.h>


const double epsilon = 1.;
const double sigma = 1.;

class particles{
  public:
    void initial_conditions(double q0,double p0,double dt);
    double H();
    double V();
    void single_time_step();
    void time_evolution(int N);
    double dhdq(double q, double p);
    double dhdp(double q, double p);
    double get_q(void){return q;};
    double get_p(void){return p;};
    double get_t(void){return t;};
  private:
      double q;
      double p;
      double t;
      double dt;
      double m;
};


int main(int argc, char const *argv[]) {
  int N=atoi(argv[1]);
  int M=atoi(argv[2]);

  std::mt19937 gen;
  std::uniform_real_distribution<double> distq(1,2);
  std::uniform_real_distribution<double> distp(-1,1);

  std::ofstream file1;
  std::ofstream file2;

  file1.open ("initial_state.dat");
  file2.open ("final_state.dat");
  particles p[N];
  double q0=0.0,p0=0.0;
  for(int i=0; i<N;i++){
    p[i].initial_conditions(distq(gen),distp(gen),0.01);
    file1<<p[i].get_q()<<' '<<p[i].get_p()<<std::endl;
  }
  file1.close();
  #pragma omp parallel for
  for(int i=0; i<N;i++){
    if (i%1000==0)
    std::cout<<i<<std::endl;
    p[i].time_evolution(M);
  }

  for(int i=0; i<N;i++){
    file2<<p[i].get_q()<<' '<<p[i].get_p()<<std::endl;
  }
file2.close();
  return 0;
}
void particles::initial_conditions(double q0,double p0,double dt0){
  q=q0;
  p=p0;
  t=0.0;
  dt=dt0;
  m=1.;
}

void particles::time_evolution(int N){
  for (int i=0; i<N;i++){
    single_time_step();
  }
}
void particles::single_time_step(){
  double a[]={0.78451361047756, 0.23557321335936, -1.1776799841789, 1.3151863206839,-1.1776799841789,0.23557321335936,0.78451361047756,0.};
  double b[]={0.39225680523878, 0.51004341191846,-0.47105338540976, 0.068753168252520, 0.068753168252520, -0.47105338540976, 0.51004341191846, 0.39225680523878};

  for(int ts=0;ts<8;ts++){
    q+=b[ts]*dt*dhdp(q,p);
    p-=a[ts]*dt*dhdq(q,p);
  }
  t+=dt;
}
double particles::H(){
  return pow(p,2)/(2.*m)+V();
}
double particles::V(){
  return 4*epsilon*(pow(sigma/q,12)-pow(sigma/q,6));
}
double particles::dhdq(double q, double p){
return 4*epsilon*(6*pow(sigma/q,6)/q-12*pow(sigma/q,12)/q);
}
double particles::dhdp(double q, double p){
return p/m;
}
