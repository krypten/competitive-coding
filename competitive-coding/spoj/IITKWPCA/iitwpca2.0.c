#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int partn(char *a[5500], int, int);
void swap(char *a[5500], int, int);
void quicksort(char *a[5500], int, int);


int main(){
    int t;
    char c;
    scanf("%d", &t);
    while (t --) {
        char string[10005];
        scanf("%c",&c);
        char *strz[5500], *p;
        int j = 0,i;
        scanf("%[^\n]s", string);
        p = strtok (string," ");
        while (p != NULL)
        {
            strz[j] = p;
            j ++;
            p = strtok (NULL, " ");
        }
        if(j > 2){
            quicksort(strz, 0, j - 1);
        }
        int count = 1;
        for(i = 0; i < j - 1; i ++){
        if(strcmp(strz[i],strz[i + 1]) != 0){
            count ++;
        }
        }
        if(j == 0)
        printf("%d\n", count - 1);
        else printf("%d\n", count);
        }
    return 0;
}
void quicksort(char *a[5500], int p, int r)
{
    int q;
    if(p >= r) {
        return;
    } else {
        q = partn(a, p ,r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
    return;
}
int partn(char *a[5500], int p, int r)
{
    int i;
    int j;
    char *x;
    x = a[r];
    j =  p - 1;
    for(i = p; i < r; i++) {
        if(strcmp(a[i], x) < 0) {
            j++;
            swap(a, i, j);
        }
    }
    swap(a, r, j+1);
    return j+1;
}
   void swap(char *a[550], int l, int u)
{
    char* tmp;

    tmp = a[l];
    a[l] = a[u];
    a[u] = tmp;

    return;
}
//            printf ("%s --> %d\n",strz[j], strlen(strz[j]));
