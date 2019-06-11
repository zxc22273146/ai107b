# include <stdio.h>
# define N 4         // �i�H�վ� 

int count=0;
// Q[i][j] �O�_�s�b�Ĭ� 
int isCorrect(int i, int j, int (*Q)[N]) {
    int s,t;
    // �C 
    for(s=i,t=0; t<N; t++)
        if(Q[s][t]==1 && t!=j)
            return 0;
    // �� 
    for(s=0,t=j; s<N; s++)
        if(Q[s][t]==1 && s!=i)
            return 0;
    // ���W
    for(s=i-1,t=j-1; s>=0&&t>=0; s--,t--)
        if(Q[s][t]==1)
            return 0;
    // �k�U
    for(s=i+1,t=j+1; s<N&&t<N; s++,t++)
        if(Q[s][t]==1)
            return 0;
    // �k�W
    for(s=i-1,t=j+1; s>=0&&t<N; s--,t++)
        if(Q[s][t]==1)
            return 0;
    // ���U
    for(s=i+1,t=j-1; s<N&&t>=0; s++,t--)
        if(Q[s][t]==1)
            return 0;

    return 1;
}

// ���j�A�� i+1 �C���M�� 
void Queue(int i, int (*Q)[N]) {
     
     int j,k;
     
     // �ĥ|�C�w�M����
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
      
     // �M���� i+1 �C�� j+1 �� 
     for(j=0;j<N; j++) {
                  
         if(isCorrect(i,j,Q)) {
                              
             Q[i][j]=1;
             Queue(i+1,Q);   // �M���U�@�C 
             Q[i][j]=0;      // �p�G�U�@�C�����ߡA�h�^���A���m 0
         
         }  
     }  
}

int main() {
    int Q[N][N];
    int i,j;
    // ��l�ƤG���}�C 
    for (i=0; i<N; i++) { 
        for(j=0; j<N; j++) {
            Q[i][j] = 0;
            //printf("%-5d",Q[i][j]);
        }
    }
    Queue(0, Q); // �q�Ĥ@�C�}�l���j 
    printf("solve count is %d\n", count);
    return 0; 
}
