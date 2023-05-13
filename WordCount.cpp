#include<stdio.h>
#include<string.h>

int main(int argc , char *argv[]){
    FILE *fp;
    int cnt = 0;
    if((fp = fopen(argv[2],"r")) == NULL){
        puts("error!\n");
        return 0;
    }
    if(argv[1][1] == 'w'){
        char s[1024];
        while(fscanf(fp,"%s",s) != EOF){
            cnt++;
            for (int = 1; i < strlen(s) - 1; i++)
                if(s[i]==',' && s[i - 1]!=',' && s[i + 1]!=',')
                    cnt++;
        }
        print("µ¥´ÊÊý=%d\n",cnt);
    }
    else if((argv[1][1]=='c'){
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("×Ö·ûÊý=%d", cnt);
    }
    fclose(fp);
    return 0;
}
