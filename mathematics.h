long double fact( int n)
{
    if(n <= 0 || n == 1 )
    return 1;
    else
    return n * fact(n-1);
}
long double power(double a ,  int n)
{
    long double sum=1;
    for(int i=0 ; i < n ; i++)
      sum*=a;
      return sum;
}
long double exponential(double a)
{
    long double result=0;
    for(int i=0; i < 20 ; i++ )
    {
        result+=power(a,i)/fact(i);
    }
    return result;
}

long double sine(long double angle)
{
    int count=0;
    long double result=0;
    for(int i=1;i<20;i+=2)
    {
        if(count%2==0)
        {
            result+=power(angle,i)/fact(i);
            count++;
        }
        else
        {
            result-=power(angle,i)/fact(i);
            count++;
        }
    }
     return result;
}

long double cosine(long double angle)
{
    int count=0;
    long double result=0;
    for(int i=0;i<20;i+=2)
    {
       
        if(count%2==0)
        {
            result+=power(angle,i)/fact(i);
            count++;
        }
        else
        {
            result-=power(angle,i)/fact(i);
            count++;
        }
    }
     return result;
}

long double tangent(long double angle)
{
    return sine(angle)/cosine(angle);
}


