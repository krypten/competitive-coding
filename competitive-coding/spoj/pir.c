#include <stdio.h>
#include <math.h>

int main()
{
		
	int t;
	double u,v,w,U,V,W;
	double a,b,c,d;
	double x,y,z,X,Y,Z;
	double vol, ans;

	scanf("%d", &t);
	while(t--) {
		scanf("%lf %lf %lf %lf %lf %lf",&w,&v,&u,&U,&V,&W);

		X = (w-U+v)*(U+v+w);
		x = (U-v+w)*(v-w+U);
		Y = (u-V+w)*(V+w+u);
		y = (V-w+u)*(w-u+V);
		Z = (v-W+u)*(W+u+v);
		z = (W-u+v)*(u-v+W);

		a = sqrt(x*Y*Z);
		b = sqrt(y*X*Z);
		c = sqrt(z*X*Y);
		d = sqrt(x*y*z);

		vol = sqrt((b+c+d-a)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d)) / (192.0*u*v*w);
		printf("%.4lf\n", vol);
	}			
	return 0;
}
		
