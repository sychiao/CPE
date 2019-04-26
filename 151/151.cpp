#include <iostream>
#include <list>

using namespace std;

int main()
{
    aa:
    int N;
    cin >> N;
    if(N==0)
        return 0;
    for (int m = 1; m <= 239; m++)
    {
        int *A = new int[N]();
        int i = 1;
        int k = 1;
        int c = 0;
        while (i <= N)
        {
            if (A[k - 1] == 0)
            {
                c--;
                if (c <= 0)
                {
                    //printf("%d ", k);
                    A[k - 1] = i;
                    i++;
                    c = m;
                }
            }
            if (k == N)
                k = 1;
            else
                k++;
        }
        //printf("\n");
        if(A[12]==N){
            printf("%d\n",m);
            break;
        }
    }
    
    goto aa;
}