#include<stdio.h>
#include<math.h>

typedef struct{
    int exp;
    float coeff;
}polynomial;


void Polyread(polynomial a[],int start,int end){
    int i,k=0;
    for(i=start;i<=end;i++,k++)
    {
        printf("Enter coefficient and exponent of term : %d in order of increasing exponents: \n",k+1);
        scanf("%f",&a[i].coeff);
        scanf("%d",&a[i].exp);
    }
}

void Polyprint(polynomial a[],int start,int end){
    int i,k=0;
    for(i=start;i<=end;i++,k++)
    {
        printf("(%f)x^%d",a[i].coeff,a[i].exp);
        if(i!=end){
            printf(" + ");
        }
    }
    printf("\n");
}

float Polyeval(polynomial a[],int start,int end,int x){
    float result = 0.0;
    while(start<=end){
        result += a[start].coeff * pow(x,a[start].exp);
        start++;
    }
    return result;
}


void main(){
    polynomial a[100];
    int n1,x,startA,endA;
    printf("Enter no. of terms of the polynomial: \n");
    scanf("%d",&n1);
    printf("\n");
    startA = 0;
    endA = n1-1;
    Polyread(a,startA,endA);
    printf("Entered polynomial is : \n");
    Polyprint(a,startA,endA);
    printf("\n");
    printf("Enter value of x: ");
    scanf("%d",&x);
    printf("\n");
    printf("Value of Polynomial = %f\n",Polyeval(a,startA,endA,x));
    printf("\n");
    
}
