#include<stdio.h>
#include<string.h> 

int main() {
    char arr[60][60], str[50]; 
    int n, m, i, j, k = 0, s, a, z, b, p;

    printf("Enter Number of rows and columns : \n");
    scanf("%d %d", &a, &b); 

    printf("\nEnter the Elements:\n"); 
    for(i = 0; i < a; i++) 
        scanf("%s", arr[i]);

    printf("\nEnter initial point where maze starts : ");
    scanf("%d%d", &n, &m);
    
    n--;
    m--;
    arr[n][m] = 'R';

    printf("\nEnter the commands to the Robo :\n"); 
    scanf("%s", str);
    
    z = strlen(str); 
    for(i = n, j = m, s = 0; s < z; s++) {
        if(str[s] == 'R') {
            k++; 
            if(k == 4)
                k = 0;
        }
        if(str[s] == 'L') { 
            k--;
            if(k == -4) 
                k = 0;
        }
        if(str[s] == 'F') {
            if(k == 0 && arr[i-1][j] != 'X') { 
                i--;
                arr[i][j] = 'R';
            } else if(k == 1 && arr[i][j+1] != 'X') {
                j++; 
                arr[i][j] = 'R';
            } else if(k == 2 && arr[i+1][j] != 'X') {
                i++;
                arr[i][j] = 'R';
            } else if(k == 3 && arr[i][j-1] != 'X') { 
                j--;
                arr[i][j] = 'R';
            } else if(k == -1 && arr[i][j-1] != 'X') { 
                j--;
                arr[i][j] = 'R';
            } else if(k == -2 && arr[i+1][j] != 'X') { 
                i++; 
                arr[i][j] = 'R';
            } else if(k == -3 && arr[i][j+1] != 'X') {
                j++; 
                arr[i][j] = 'R';
            } else {
                continue;
            }
        }
    }

    i++;
    j++; 
    printf("\n"); 
    if(k == 0) 
        printf("%d %d N", i, j); 
    else if(k == 1 || k == -3) 
        printf("%d %d E", i, j); 
    else if(k == 2 || k == -2) 
        printf("%d %d S", i, j); 
    else
        printf("%d %d W", i, j); 

    printf("\n"); 
    for(i = 0; i < a; i++) {
        printf("%s", arr[i]); 
        printf("\n");
    }

    return 0;
}
