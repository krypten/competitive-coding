#include <iostream>
#include <cmath>

using namespace std;

int main()
{
      int t;
      long double x;
      long double y;
      long double z;
      long double d;
      long double a;
      long double n;
      long double tmp;
      long long int p;
      long long int q;
      long long int r;
      long long int i;
      long long int term = 0;

      cin>>t;

      while(t--) {
            cin>>x>>y>>z;

            tmp = 1 + (2.5*x+1.5*y+z)/(x+y);
            n = (tmp + sqrtl(tmp*tmp-(12*z)/(x+y)));
            p = llrintl(n);
            d = (y - x )/(p - 6);
            q = llrintl(d);
            a = x - 2 * q;
            r = llrintl(a);

            cout<<p<<"\n";
            for ( i = 0, term = r; i < p; i++, term += q)
                  cout<<term<<" ";
            cout<<"\n";
      }
      return 0;
}
