#include<stdio.h>  
#include<string.h>  
#define max(x,y)  ( x>y?x:y )  
#define n 1010  
// 大数模拟
int main()  
{  
    //freopen("in.txt", "r", stdin);  
    //freopen("out.txt", "w", stdout);  
    char a1[n]={0};  
    char b1[n]={0};  
    int a2[n]={0}, b2[n]={0};  
    int num ,n1,n2,j,digit,k,i,m1,m2;  
    scanf("%d", &num);  
    for(i = 1; i <=num; i++){  
        scanf("%s %s",a1,b1);  
        n1 = strlen(a1);  
        n2 = strlen(b1);  
        for(j = 0 ; j < n1; j++){  
            if(a1[j] != '0'&& a1[j] != NULL){  
                m1 = j;  
                break;  
            }else if(a1[j] == '0' && j == n1-1){  
                m1 = 0;  
                n1 = 1;  
                break;  
            }  
        }  
        for(j = 0 ; j < n2; j++){  
            if(b1[j] != '0' && b1[j] != NULL){  
                m2 = j;  
                break;  
            }else if(b1[j] == '0' && j == n2-1){  
                m2 = 0;  
                n2 = 1;  
                break;  
            }  
        }  
        for(j = n1-1,k = 0;j >=m1 ;j--,k++){  
            a2[k] = a1[j] - '0';  
        }  
          
        for(j = n2-1,k = 0;j >=m2 ;j--,k++){  
            b2[k] = b1[j] - '0';  
        }  
        digit = max(n1-m1,n2-m2);  
        int c2[n] = {0};  
        for(j = 0; j < digit ; j++){  
            c2[j] = a2[j] + b2[j] + c2[j];  
            c2[j+1] = c2[j] / 10;  
            c2[j] = c2[j] % 10;  
        }  
        if(c2[digit] == 0) digit--;  
        printf("Case %d:\n",i);  
        for(j = m1; j<n1;j++){  
            printf("%c",a1[j]);  
        }  
        printf(" + ");  
        for(j = m2; j<n2;j++){  
            printf("%c",b1[j]);  
        }  
        printf(" = ");  
        for(j = digit; j>= 0; j--) printf("%d",c2[j]);  
        if(i != num) {  
            printf("\n\n");  
        }else{  
            printf("\n");  
        }  
        for(j = 0; j<=digit; j++){  
            a2[j] = b2[j] = 0;  
        }  
    }  
    //fclose(stdin);  
    //fclose(stdout);  
    return 0;  
}  
