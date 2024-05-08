#include <stdio.h>
#include <string.h>

#define MAXN 100

typedef struct{
    char name[MAXN];
    int age; 
} time; 

void lerdados(time v[], int n){
    for(int i = 0; i < n; i++){
        scanf("%s %d", v[i].name, &v[i].age);
    }
}

void exchange(time v[], int i, int j){
    time temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

void sortduendes(time v[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(v[i].age < v[j].age){
                exchange(v, i, j);
            }
            else if(v[i].age == v[j].age){
                int res = strcmp(v[i].name, v[j].name);
               // printf("%s %s", v[i].name, v[j].name);
                if(res < 0) continue;
                else{
                    exchange(v, j, i);
                }
            }
        }
    }
}

void printtimes(time v[], int st, int n, int m){
    printf("Time %d\n", st+1);
    for(int i = st; i < n; i += m){
        printf("%s %d\n", v[i].name, v[i].age);
    }
}



int main(){
    int n; 
    time duendes[MAXN];
    scanf("%d", &n);
    lerdados(duendes, n);
    sortduendes(duendes, n);
    for(int i = 0; i < n/3; i++){
        printtimes(duendes, i, n, n/3);
        //if(i == (n/3)-1) continue;
        printf("\n");
    }

}