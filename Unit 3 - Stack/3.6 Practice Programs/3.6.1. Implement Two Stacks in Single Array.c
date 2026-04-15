#include<stdio.h>

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int top1 = -1;
    int top2 = n;
    int arr[n];
    
    while(q--) {
        int temp;
        scanf("%d", &temp);
        
        if(temp == 1) {
            int x;
            scanf("%d", &x);
            
            if(top1 + 1 < top2) {
                arr[++top1] = x;
            }
            
        } 
        else if(temp == 2) {  
            int x;
            scanf("%d", &x);
            
            if(top1 + 1 < top2) {
                arr[--top2] = x;
            }
            
        } 
        else if(temp == 3) {  
            if(top1 == -1) {
                continue;  
            }
            top1--;
        } 
        else if(temp == 4) {  
            if(top2 == n) {
                continue;  
            }
            top2++;
        }
    }
    
    for(int i = 0; i <= top1; i++) {
        printf("%d ", arr[i]);
    }
    
    for(int i = n-1; i >=top2; i--) {
        printf("%d ", arr[i]);
    }
    
    
    if(top1 == -1 && top2 == n) {
        printf("-1");
    }
    
    printf("\n");
    return 0;
}