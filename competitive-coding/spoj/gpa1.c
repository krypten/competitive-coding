#include <stdio.h>
#include <string.h>
#include <math.h>

double process (char * str) {
      int len = strlen(str);
      int i = 0;
      double ans = 0.0;
      double var;
      if (str[i] == 'a') return 0;

      while(str[i] <= '9' && str[i] >='0' && i < len)
            ans = ans*10 + str[i++]-'0';
      if(i < len && str[i] == '.') {
            i++;
            var = 10.0;
            while(str[i] <= '9' && str[i] >='0') {
                  ans = ans + (str[i++]-'0')/var;
                  var = var*10.0;
            }
      }
      return ans;
}

int main()
{
      int t;
      int i,flag;
      int cr[6];
      int pts[6];
      double a1,a2,a3,f1,att,ans_ass;
      double tot;
      double gpa;
      double sum;

      scanf("%d", &t);

      while(t--) {
            scanf("%d %d %d %d %d %d", &cr[0], &cr[1], &cr[2], &cr[3], &cr[4], &cr[5]);

            for ( i = 0; i < 6; i++) {
                  char ass1[6],ass2[6],ass3[6];
                  scanf("%s %s %s %lf %lf", ass1, ass2, ass3, &f1, &att);
                  a1 = process(ass1);
                  a2 = process(ass2);
                  a3 = process(ass3);

                  //printf("%lf %lf %lf\n", a1,a2,a3);

                  if ( a1 > a2) {
                        if(a3 > a2) {
                              ans_ass = ((a1+a3)/40.0)*45.00;
                        } else { ans_ass = ((a1+a2)/40.0)*45.00; }
                  } else {
                        if(a3 > a1) {
                              ans_ass = ((a2+a3)/40.0)*45.00;
                        } else { ans_ass = ((a1+a2)/40.0)*45.00; }
                  }
                  //printf("%lf\n", ans_ass);
                  f1 = f1/2.0;

                  if(att < 51) att = 5;
                  else if (att < 61) att = 4;
                  else if (att < 71) att = 3;
                  else if (att < 81) att = 2;
                  else if (att < 91) att = 1;
                  else att = 0;


                  tot = (ans_ass + att + f1);

                  if(tot >= 91) pts[i] = 10;
                  else if (tot >= 81) pts[i] = 9;
                  else if (tot >= 71) pts[i] = 8;
                  else if (tot >= 61) pts[i] = 7;
                  else if (tot > 50) pts[i] = 6;
                  else if (tot == 50) pts[i] = 5;
                  else pts[i] = 0;
                  //printf("\n%d\t", pts[i]);
            }


            flag = 0;
            gpa = 0.0;
            sum = 0.0;
            for(i = 0; i < 6; i++) {
                  if(pts[i] == 0) flag = 1;
                  gpa = gpa + pts[i]*cr[i];
                  sum = sum + cr[i];
                  }
            //printf("%lf %lf\n", gpa, sum);
            gpa = gpa/sum;
            if (flag) printf("FAILED, %.2lf\n", gpa);
            else printf("PASSED, %.2lf\n", gpa);
      }
      return 0;
}

