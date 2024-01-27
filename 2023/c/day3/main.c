#include <stdio.h>
#include <string.h>
#include <ctype.h>


int min(int a, int b){
    return a < b?a:b;
}

int max(int a, int b){
    return a > b?a:b;
}

int build_number(char data[][1028], int i, int j, int nl){
    int num = 0;
    int k = j;
    while(k >= 0 && isdigit(data[i][k]))
        k--;
    k++;
    while(k < nl && isdigit(data[i][k])){
        num = num * 10 + (data[i][k] - '0');
        data[i][k] = '.';
        k++;
    }
    printf("i:%d, num:%d\n", i, num);
    return num;
}

int main(void){
    /* 
     * read from a file and store in an array of arrays
     * for all chars if the current char is not a dot or a number stop
     * check all directions for a digit if found
     * go to that digit and reconstruct the number
     * else continue
     */
    int n = 0, nl = 0, l, r, u, d;
    int il, ir, ul, uj, ur, dl, dj, dr;
    int c = 0;
    char data[1028][1028];
    char buff[1028];
    int res = 0;
    FILE* fp = fopen("input.txt", "r");
    while(fgets(buff, 1028, fp) != NULL && strcpy(data[n], buff) && ++n)
        ;
    nl = strlen(data[0]) - 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < nl; j++){
            if(!isdigit(data[i][j]) && data[i][j] != '.' && data[i][j] == '*'){
                l = max(0 , j - 1); r = min(nl - 1, j + 1); u = max(0, i - 1); d = min(n - 1, i + 1);
                il = ir = ul = uj = ur = dl = dj = dr = 1; c = 0;
                if(isdigit(data[i][l])){
                    il = build_number(data, i, l, nl);
                    c++;
                }
                if (isdigit(data[i][r])){
                    ir = build_number(data, i, r, nl);
                    c++;
                }
                if (isdigit(data[u][l])){
                    ul = build_number(data, u, l, nl);
                    c++;
                }
                if (isdigit(data[u][j])){
                    uj = build_number(data, u, j, nl);
                    c++;
                }
                if (isdigit(data[u][r])){
                    ur = build_number(data, u, r, nl);
                    c++;
                }
                if (isdigit(data[d][l])){
                    dl = build_number(data, d, l, nl);
                    c++;
                }
                if (isdigit(data[d][j])){
                    dj = build_number(data, d, j, nl);
                    c++;
                }
                if (isdigit(data[d][r])){
                    dr = build_number(data, d, r, nl);
                    c++;
                }
                if(c == 2)
                    res += il * ir * ul * uj * ur * dl * dj * dr;
            }
        }
    }
    printf("%d\n", res);
    fclose(fp);
    return 0;
}

