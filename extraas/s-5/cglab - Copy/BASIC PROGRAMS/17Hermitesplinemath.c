/* Hermite interpolation 

Input: 
----------
1.no of vertices
2.vertices
3.slopes to the vertices

Theory
----------
b/w two control points p(k) and p(k+1)
the intermediate points can be calculated from the following
eqns by taking p(k)=p(0) and p(i+1)=p(1) and substituting in
p(u)=u^3+u^2+u+1

pk		0 0 0 1		a
pk+1            1 1 1 1		b
dpk	=	0 0 1 0		c
dpk+1		3 2 1 0		d

from the above matrix
a		 2 -2  1  1	pk
b		-3  3 -2  1	pk+1
c	=	 0  0  1  0	dpk
d		 1  0  0  0	dpk+1

			 2 -2  1  1	pk
			-3  3 -2  1	pk+1
p(u)	= u^3 u^2 u 1	 0  0  1  0	dpk
			 1  0  0  0	dpk+1


p(u)=(2u^3-3u^2+1)p(k)+(-2u^3+3u^2)p(k+1)+(u^3-2u^2+u)dp(k)+(u^3-u^2)dp(k+1)
p(u)= h0(u)*p(k) + h1(u)*p(k+1) + h2(u)*dp(k) + h3(u)*dp(k+1)

where h(u= 1 to 4) are the blending functions
pk and pk+1 are vertices and
dpk and dpk+1 are the slopes

Calculations
---------------
the curve points can be calculated in the following manner

for(k=0;k<ncpoints;k++)
 for(u=0;u<1;u+=0.01)
  {
  x[u]= h0(u)*p[k].x + h1(u)*p[k+1].x + h2(u)*p[k].slopex + h3(u)*p[k+1].slopex;
  y[u]= h0(u)*p[k].y + h1(u)*p[k+1].y + h2(u)*p[k].slopey + h3(u)*p[k+1].slopey;
  }
*/

