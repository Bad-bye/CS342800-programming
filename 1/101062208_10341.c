#include<stdio.h>

int main(){
    double p,q,r,s,t,u,s1,s2,i;
    double mid,lower,upper,temp;
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF){

        s1 = p*(exp(0))+q*sin(0)+r*cos(0)+s*tan(0)+t*0+u;
        s2 = p*(exp(-1))+q*sin(1)+r*cos(1)+s*tan(1)+t*1+u;
        if(s1*s2>0){
            printf("No solution\n");
            continue;
        }

        upper=1.0;
        lower=0.0;



         while(upper-lower > 1e-9){
            mid = (lower+upper)/2;
            temp = p*(exp(-mid))+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid+u;
            if(temp < 0)
                upper = mid;
            else
                lower=mid;

         }
         printf("%.4lf\n" , mid);


    }
    return 0;
}
