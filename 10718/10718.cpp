#include <stdio.h>
#include <iostream>
#define BIT(i) (1LL << i)
#define OR(x,i) (x | BIT(i))
#define AND(x,i) (x & BIT(i))
using namespace std;
int main()
{
	long long n, L, U, ans, i;
	while (scanf("%lld%lld%lld", &n, &L, &U) != EOF)
	{
		ans = 0;
		for (i = 31; i >= 0; i--){
            if(AND(n, i) == 0){//should become 1
                if(OR(ans, i) <= U) //become 1 will be too big
                    ans |= BIT(i);
            }else{//should become 0
                if(OR(ans, i) <= L) //become 0 will be too small
                    ans |= BIT(i);
            }
        }
		printf("%lld\n", ans);
	}
}