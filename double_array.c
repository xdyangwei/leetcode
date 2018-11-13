#include<stdio.h>
int main(){
    int n,j=0,k=0;
    scanf("%d",&n);
    int a[n][n];
    for(int j=0;j<n;j++){
    for(int k=0;k<n;k++)
    scanf("%d",&a[j][k]);
    }
    for(int j=0;j<n;j++){
    for(int k=0;k<n;k++)
    printf("%d ",a[j][k]);
    }
    return 0;
}