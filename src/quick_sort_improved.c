#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    if(n <= 0) return;
    
    int i, j, pivot;
    pivot = A[0];
    
    for(i = j = 0; i < n; i++){
        if(A[i] <= pivot){
            swap(A + i, A + j);
            j++;
        }
        
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == A[j-1]) cnt++;
    }
    
    for(int i = 0; i < j - 1; i++){
        swap(A + i, A + i + 1);
    }
    
    
    int t = n-1;
    for(i = 0; i < j-cnt; i++){
        if(A[i] < pivot) continue;
        while(1){
            if(A[t] < pivot){
                swap(A + i, A + t);
                t--;
                break;
            }
            t--;
        }
    }
    
    t = n - 1;
    for(;i < j; i++){
        if(A[i] == pivot) continue;
        while(1){
            if(A[t] == pivot){
                swap(A + i, A + t);
                break;
            }
            t--;
        }
    }
    
    quick_sort(A, j-cnt);
    quick_sort(A+j, n-j);
    
    return;
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
