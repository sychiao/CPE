#include <cstdio>

using namespace std;

int main(){
    int size;
    scanf("%d",&size);

    int *inputa = new int[size];
    int *inputb = new int[size];
    for(int i = 0;i<size;i++){
        scanf("%d %d",&inputa[i],&inputb[i]);
    }
    char *str[7]{
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    int doomday[]={
        10,
        21,
        7,
        4,
        9,
        6,
        11,
        8,
        5,
        10,
        7,
        12
    };

    for(int i=0;i<size;i++){
        int days = inputb[i] - doomday[inputa[i]-1];
        if(days%7 >=0)
            printf("%s\n",str[days%7]);
        else
            printf("%s\n",str[7+days%7]);
    }
    return 0;
}