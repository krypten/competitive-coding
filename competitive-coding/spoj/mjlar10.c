#include <stdio.h>

int a,b,c,x,y;

int check (int z)
{
      int i = 5;
      while(i--) {
            if (z == a || z == b || z == c || z == x ||z == y) {
                  z++;
            }
      }
      return z;
}
int main()
{
      int min1,min2,min3,max1,max2;
      int ctr;
      int mini, maxi;
      while(scanf("%d %d %d %d %d", &a,&b,&c,&x,&y) != EOF) {
            if ( a == 0 && b == 0 && c == 0 && x == 0 && y == 0) break;

            ctr = 0;

            if ( x > y ) {
                  max1 = x;
                  max2 = y;
            } else {
                  max1 = y;
                  max2 = x;
            }

            if ( a > b) {
                  if ( a > c ) {
                        min3 = a;
                        if ( c > b) {
                              min2 = c;
                              min1 = b;
                        } else {
                              min2 = b;
                              min1 = c;
                        }
                  } else {
                        min1 = b;
                        min2 = a;
                        min3 = c;
                  }
            } else {
                  if ( b > c ) {
                        min3 = b;
                        if ( c > a) {
                              min2 = c;
                              min1 = a;
                        } else {
                              min2 = a;
                              min1 = c;
                        }
                  } else {
                        min1 = a;
                        min2 = b;
                        min3 = c;
                  }
            }
      //      printf("%d %d %d %d %d",min1,min2,min3,max1,max2);
//Algo::

ctr = 4;

      if ( min3 < max1 ) {
                  if (min3 < max2) {
//                        case :: mini card;
ctr = 0;
                  } else if (min2 < max2 ) {
    //                    case :: card > min2;
ctr = 2;
                  } else if (min1 < max2 ) {
  //                      case :: card > min2;
ctr = 3;
                  } else {
//                        case :: card > min3;
ctr = 3;
                  }
      } else {
                  if ( max2 > min2) {
 //                       card :: card > mini2;
   ctr = 2;
                  } else {
 //                       case ::loss;
ctr = 4;
                  }
      }

      switch(ctr) {
            case 0: mini = 1; mini = check(mini);
                    printf("%d\n", mini);
                    break;
            case 2: maxi = min2 + 1; maxi = check(maxi);
                    if (maxi > 52) printf("-1\n"); else printf("%d\n", maxi);
                    break;
            case 3: maxi = min3 + 1; maxi = check(maxi);
                    if (maxi > 52) printf("-1\n"); else printf("%d\n", maxi);
                        break;
            case 4:printf("-1\n");
                  break;

      }
      }
      return 0;
}
/*case 0: mini = 1; if (mini == min3) mini = min3; else mini = max2;
                    if (mini == 0) printf("-1\n"); else printf("%d\n", mini -1);
                    break;
            case 2: maxi = min2 + 1; if(maxi == min3) maxi++; if(maxi == max2) maxi++; if(maxi == max1) maxi++;
                    if (maxi > 52) printf("-1\n"); else printf("%d\n", maxi);
                    break;
            case 3: maxi = min3 + 1; if(maxi == max2) maxi++; if(maxi == max1) maxi++;
                    if (maxi > 52) printf("-1\n"); else printf("%d\n", maxi);
                        break;
            case 4:printf("-1\n");
                  break;
*/
