#include<stdio.h>
void tower(int n, char beg, char aux, char end){
    if(n <= 0)
    printf("illegal entry");
    else if(n == 1)
    printf("move disc from %c to %c\n", beg, end);
    else{
    tower(n-1, beg, end, aux);
    printf("move disc from %c to %c\n", beg, end);
    tower(n-1, aux, beg, end);  
    }

}
int main(){
    int n;
    char a, b , c;
    scanf("%d", &n);
    tower(n, 'a', 'b', 'c');

    return 0;
}
