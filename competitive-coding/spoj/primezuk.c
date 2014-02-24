/* Fermet little theorem based pseudo primility testing
*/

#include <stdio.h>

#define type long long int

type mulmod( type a, type b, type mod) {
   	type x = 0;
	type y = a%mod;
	 while(b > 0){
        	if(b%2 == 1){
            		x = (x+y)%mod;
        	}
       		y = (y*2)%mod;
		b /= 2;
    	}
    	return x%mod;
}
type mod_exp (type a, type n, type q)
{
	type var = 1;
	type mult = a;
	while ( n != 0 ) {
		if (n%2 == 1) {
			var  = mulmod(var, mult, q);
		}
		mult = mulmod(mult, mult, q);
		n = n>>1;
	}
	return var;
}

int power2 ( type n , type * u)
{
	type var;
	for (var = 0; n%2 == 0; (n = n>>1)&& var++);
	*u = n;
	return var;
}

int witness(type a,type n)
{
	type i;
	type t;
	type u;
	type x;
	type y;

	t = power2(n-1, &u);
	y = mod_exp(a, u, n);
	
	for (i = 0; i < t; i++) {
		x = mulmod(y,y,n) ;
		if (x == 1 && y != 1 && y != n-1) {
			return 1;
		}
		y = x;
	}
	if ( y != 1 ) {
		return 1;
	}
	
	return 0;
}

int miller_rabin(type n, int s)
{
	type j;
	type a;

	if(n<2) return 0;
	//if(n == 2) return 1;
	if(n != 2 && n%2 == 0) return 0;

	for (j = 0; j < s; j++) {
		a = rand() % (n-1) + 1 ;
		if ( witness(a, n) ) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int t;
	int n;
	type i;
	int j;
	type tmp;
	int arr[16];	
	type var = 1;
	scanf("%d", &t);
	for(j =1; j <= t; j++) {
		var = 1;
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			var = var * arr[i];
		}
		var++;
		tmp = miller_rabin(var, 5);
		
		if ( tmp == 0 ) {
			for(i = 2; ; i++) {
				if((var - (var/i) * i) == 0) {
					var = var/i;
					i--;
				}
				tmp = miller_rabin(var, 5);
				if( tmp == 1) {
					printf("Case #%d: %lld\n",j, var);
					break;
				}
			}
		} else {
			printf("Case #%d: %lld\n",j, var);
		}
	}
	return 0;
}
