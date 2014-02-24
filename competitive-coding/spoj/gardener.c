#include <stdio.h>
#include <math.h>

#define sqr3 1.7320508075688772935274463415059

int main()
{
	double ans, tmp,s;
	int a,b,c, t;
	
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d %d %d",&a ,&b, &c);
		s = (a+b+c)/2.0;		
		ans = (1.0/2.0) * ( sqr3 *(a*a + b*b + c*c)/4.0 + 3.0*sqrt(s*(s-a)*(s-b)*(s-c)));
		tmp = llrint(ans*100);
		printf("%.2lf\n", tmp/100.0);
	}
	return 0;
}
