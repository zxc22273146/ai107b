# include <stdio.h>
# define N 4         // 可以調整 

int count=0;
// Q[i][j] 是否存在衝突 
int isCorrect(int i, int j, int (*Q)[N]) {
    int s,t;
    // 列 
    for(s=i,t=0; t<N; t++)
        if(Q[s][t]==1 && t!=j)
            return 0;
    // 行 
    for(s=0,t=j; s<N; s++)
        if(Q[s][t]==1 && s!=i)
            return 0;
    // 左上
    for(s=i-1,t=j-1; s>=0&&t>=0; s--,t--)
        if(Q[s][t]==1)
            return 0;
    // 右下
    for(s=i+1,t=j+1; s<N&&t<N; s++,t++)
        if(Q[s][t]==1)
            return 0;
    // 右上
    for(s=i-1,t=j+1; s>=0&&t<N; s--,t++)
        if(Q[s][t]==1)
            return 0;
    // 左下
    for(s=i+1,t=j-1; s<N&&t>=0; s++,t--)
        if(Q[s][t]==1)
            return 0;

    return 1;
}

// 遞迴，第 i+1 列的遍歷 
void Queue(int i, int (*Q)[N]) {
     
     int j,k;
     
     // 第四列已遍歷完
     if(i==N) {
         
         count++;
         printf("No.%d slove way\n",count);   
         for(k=0;k<N; k++) {
         
             for(j=0; j<N; j++)
                 printf("%-5d", Q[k][j]);
             printf("\n");
             
             //return;
         }
         printf("\n");
              
     }
      
     // 遍歷第 i+1 列的 j+1 行 
     for(j=0;j<N; j++) {
                  
         if(isCorrect(i,j,Q)) {
                              
             Q[i][j]=1;
             Queue(i+1,Q);   // 遍歷下一列 
             Q[i][j]=0;      // 如果下一列不成立，則回溯，重置 0
         
         }  
     }  
}

int main() {
    int Q[N][N];
    int i,j;
    // 初始化二維陣列 
    for (i=0; i<N; i++) { 
        for(j=0; j<N; j++) {
            Q[i][j] = 0;
            //printf("%-5d",Q[i][j]);
        }
    }
    Queue(0, Q); // 從第一列開始遞迴 
    printf("solve count is %d\n", count);
    return 0; 
}
