#include <stdio.h>
#include <string.h>


int main(void){
    FILE* fp = fopen("input.txt", "r");
    int sum = 0, game_id;
    char buf[64], inbuf[3][16];
    int nc = 0;
    char color[8], ch;
    while(fscanf(fp, "Game %d:", &game_id) != EOF){
        while(fscanf(fp, " %[^;\n];", buf)){
            int n = sscanf(buf, "%[^,], %[^,], %[^,]",
                        inbuf[0], inbuf[1], inbuf[2]);
            for(int i = 0; i < n; i++){
                sscanf(inbuf[i], "%i %s", &nc, color);
                if(!strcmp("red", color)){
                    if(nc > 12) game_id = 0;
                }else if (!strcmp("green", color)){
                    if(nc > 13) game_id = 0;
                } else {
                    if(nc > 14) game_id = 0;
                }
            }
            ch = fgetc(fp);
            if(ch != '\n')
                ungetc(ch, fp);
            else
                break;
        }
        sum += game_id;
    }
    printf("%i\n", sum);
    fclose(fp);
    return 0;
}
