# include <math.h>
# include <stdio.h>
// Abc.c
int global_i = 100;
double m_1(double);//declaration
int main () {
double db = m_1(global_i);
printf("%lf\n",db);
}
double m_1(double param_d){
double local_d =
sqrt(param_d);
return local_d;
}
