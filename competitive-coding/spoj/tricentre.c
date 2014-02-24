#include <stdio.h>
#include <math.h>

int main()
{
      int t;
      double a;
      double b;
      double c;
      double R;
      double ga;
      double gb;
      double gc;
      double s;
      double area;
      double hg;

      scanf("%d", &t);
      while (t--) {
            scanf("%lf %lf %lf %lf",&a, &ga, &gb, &gc);
            b = a*ga/gb;
            c = a* ga/gc;
            s = (a+b+c)/2;

            area = sqrt(s*(s-a)*(s-b)*(s-c));

            R = a*b*c/(4.0)/area;
            hg = (2*sqrt(9*R*R - (a*a + b*b + c*c)))/3;

            if(hg<0) { hg = 0; }

            printf("%.3lf %.3lf\n", area, hg);
      }
      return 0;
}


/*
area = (1/3)*sqrt(2*((u*u + w*w)*v*v + u*u*w*w) - (u*u*u*u + v*v*v*v + w*w*w*w))

1. I will denote the centroid G, the orthocenter H and the
circumcenter O.

Let H_a, H_b, H_c be the feet of the altitudes to the
sides a = BC, b = CA, c = AB,
 M_a, M_b, M_c be the midpoints of thesides a, b, c
and N_a, N_b, N_c be the feet of normals from the centroid G to the sides a, b, c.

If the distances a = BC, GN_a, GN_b, GN_c are all known, the problem is overdetermined, but I will assume
that the data is consistent.

The medians m_a = AM_a, m_b = BM_b, m_c = CM_c meet at the centroid G
and

AM_a = 3*GM_a, BM_b = 3*GM_b, CM_c = 3*GM_c

It follows that the altitudes

h_a = AH_a = 3*GN_a, h_b = BH_b = 3*GN_b, h_c = CH_c = 3*GN_c

are also known. The area of the triangle ABC is then

S(ABC) = 1/2*a*h_a = 3/2*GN_a*a


The remaining sides b and c of the triangle ABC are

b = 2*S(ABC)/h_b = 2/3*S(ABC)/GN_b
c = 2*S(ABC)/h_c = 2/3*S(ABC)/GN_c

The radius R of the circumcircle is equal to

R = abc/[4*S(ABC)]

and the distance HO between the orthocenter H and the circumcenter O
is known to be

HO = sqrt[9*R^2 - (a^2 + b^2 + c^2)]

The points H, G, O are collinear (Euler line) and HG = 2*GO. This is
easily seen from the fact that the circumcenter O of the triangle ABC
is the orthocenter of the medial triangle M_aM_bM_c, this medial
triangle is centrally similar to the triangle ABC with the similarity
center G and coefficient -1/2. The similarity coefficient is
considered to be negative because the corresponding points of the 2
triangles lie on the opposite sides from the point G.

Consequently,

HG = 2/3*HO = 2/3*sqrt[9*R^2 - (a^2 + b^2 + c^2)] =
 = 2/3*sqrt[9*a^2*b^2*c^2/[16*S(ABC)] - (a^2 + b^2 + c^2)]

where a is known and b, c, S(ABC) have been calculated previously.


// CMMENT TODO:
#Consequently,
#
#HG = 2/3*HO = 2/3*sqrt[9*R^2 - (a^2 + b^2 + c^2)] =
#= 2/3*sqrt[9*a^2*b^2*c^2/[16*S(ABC)] - (a^2 + b^2 + c^2)]

Re:
i think you forgot to square the area of triangle :S(ABC)^2.Isn't it?
Beautiful Solution though. Keep it Up.


*/
