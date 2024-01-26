#include <stdio.h>
#include <string.h>


int main(void){
    FILE* fp = fopen("input.txt", "r");
    int sum = 0, game_id;
    char buf[64], inbuf[3][16];
    int nc, r, g, b;
    nc = r = g = b = 0;
    char color[8], ch;
    while(fscanf(fp, "Game %d:", &game_id) != EOF){
        nc = r = g = b = 0;
        while(fscanf(fp, " %[^;\n];", buf)){
            int n = sscanf(buf, "%[^,], %[^,], %[^,]",
                        inbuf[0], inbuf[1], inbuf[2]);
            for(int i = 0; i < n; i++){
                sscanf(inbuf[i], "%i %s", &nc, color);
                if(!strcmp("red", color)){
                    if(nc > r) r = nc;
                }else if (!strcmp("green", color)){
                    if(nc > g) g = nc;
                } else {
                    if(nc > b) b = nc;
                }
            }
            ch = fgetc(fp);
            if(ch != '\n')
                ungetc(ch, fp);
            else
                break;
        }
        sum += r*g*b;
    }
    printf("%i\n", sum);
    fclose(fp);
    return 0;
}
