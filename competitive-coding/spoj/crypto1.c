/* 
	a^2%P = t, a = t^(p+1)/4 % P;
	P = 4p + 3
 	
*/

#include <stdio.h>
#include <math.h>
#include <time.h>

#define type long long int

type mulmod( type a, type b, type mod) {
   	type x = 0;
	type y = a%mod;
	 while(b > 0){
        	if(b%2 == 1){
            		x = ((x+y) >= mod ? (x+y)%mod : x+y);
        	}
       		y = ((y*2) >= mod? (y*2)%mod : y*2);
		b /= 2;
    	}
    	return x%mod;
}

type mod_exp( type a, type b, type q) {
	type var = 1;
	type mult = a;

	while (b > 0) {
		if( b%2 == 1) var = mulmod(var, mult,q);
		mult = mulmod(mult , mult , q);
		b = b/2;
	}
	return var;
}

int main()
{
	struct tm * tmp;
	type t;
	time_t result;

	scanf("%lld", &t);
	
	t = mod_exp ( t, 1000000002, 4000000007);

	if( t > 2000000003) {
		t = 4000000007 - t;
	}

	result = (time_t) t;
	tmp = gmtime(&result);
	printf("%s", asctime(tmp));

	return 0;
}
