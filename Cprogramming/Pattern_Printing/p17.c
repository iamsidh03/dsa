/*
1
2 3
4 5 6
7 8 9 10


*/

#include <stdio.h>
int main(){
    printf("Enter number of rows");
    int n;
    scanf("%d",&n);
    int k=1;
    for(int i=1;i<=n;i++){
       
        for(int j=1;j<=i;j++){
            printf("%d ",k);
            k++;
    }
    printf("\n");
}
return 0;
}