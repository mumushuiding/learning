#ifndef HEADER_COMPSWAP
#define HEADER_COMPSWAP
typedef int Item;
#define key(A)(A)
#define less(A,B)(key(A)<key(B))
#define eq(A,B)(key(A)==key(B))
#define swap(A,B){Item t=A;A=B;B=t;}
#define compswap(A,B) if(less(B,A)) swap(A,B)
#endif