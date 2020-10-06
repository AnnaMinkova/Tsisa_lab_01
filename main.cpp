#include <iostream>
#include <cmath>
using namespace std;
double myFunction(double x)
{
    return pow((1-x),2)+exp(x);
}
void Print1(double ak, double bk)
{
    cout<<ak<< ' ' <<bk<< ' ' <<bk-ak<< ' ' <<myFunction(ak)<< ' ' <<myFunction(bk)<< ' ' <<endl;
}

const double A=-2.;
const double B=4.;
const double Epsilon=0.1;

void Dichotomy(double a, double b)
{
    cout<<"Dichotomy search: "<<endl;
    const double Delta=.01;
    while (b-a>Epsilon)
    {
        Print1(a,b);
        double x1 = a+(b-a)/2-Delta, x2 = a+(b-a)/2+Delta;
        myFunction(x1) < myFunction(x2)
        ? b=x1
        : a=x2;
    }
    cout<<a<<' '<<b<<' '<<b-a<<' '<<"\nl<epsilon" <<"\nx = "<<(a+b)/2<<" +- "<<(a+b)/2-a<<endl;
}
int main()
{
    cout<<"Variant 10:"<<endl;
    Dichotomy(A,B);
    cout<<"Passive search: "<<endl;
    int N=1,a=-2,b=4;
    double eps,x,y;
    x=a;
    y=myFunction(x);
    eps=(b-a)/(N+1);

    while (eps>=0.1)
    {

        for (int k=1;k<N;k++)
        {
            double xk;
            xk=(double)(b-a)*k/(N+1)+a;
            if (myFunction(xk)<=y)
            {
                y=myFunction(xk);
                x=xk;
            }

        }
        cout<<"N: "<<N<<" ";
        cout<<"Minimum: "<<x<<" +- "<<eps<<endl;
        N++;
        eps=(double)(b-a)/(N+1);
    }

}
