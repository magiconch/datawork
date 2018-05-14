#include <stdio.h>
#include <assert.h>
//注释转化
typedef enum Comment{
    IS_SLASH,//状态是
    IS_STAR,
    DAFAULT,
    C_COMMENT,
    CPP_COMMENT,
    }Comment;


int main() {
    FILE* pIN;
    FILE* pOUT;
    pIN = fopen("input.c","r");
    pOUT = fopen("output.c","w");
    //打开文件input和output
    assert(pIN);
    int ch = '0';
    int nextCh;
    Comment x = DAFAULT;
   // int i = 1;
    while(1){
        //++i;
        ch = fgetc(pIN);
        if (ch == 'x')
            printf("注意");
        if (ch == EOF)
            break;
        switch(x){
            case DAFAULT:{
                if (ch == '/'){
                    x = IS_SLASH;
                } else{
                    fputc(ch,pOUT);
                }
                break;
            }
            case IS_SLASH:{
                if (ch == '/'){
                    fputc('/',pOUT);
                    fputc('/',pOUT);
                    x = C_COMMENT;
                } else if (ch == '*'){
                    x = CPP_COMMENT;
                    fputc('/',pOUT);
                    fputc('/',pOUT);
                } else{
                    x = DAFAULT;
                    fputc('/',pOUT);
                    fputc(ch,pOUT);
                }
                break;
            }
            case C_COMMENT: {
                if (ch == '\n') {
                    x = DAFAULT;
                } else {
                    fputc(ch, pOUT);
                }
                break;
            }
            case CPP_COMMENT:{
                if (ch == '*'){
                    x = IS_STAR;
                } else if (ch == '\n'){
                    fputc('\n',pOUT);
                    fputc('/',pOUT);
                    fputc('/',pOUT);
//                    ch = fgetc(pIN);
//                    if (ch != '\n'){
//                        fputc('\n',pOUT);
//                    }
//                    ungetc(ch,pIN);
                } else{
                    fputc(ch,pOUT);
                }
                break;
            }
            case IS_STAR:{
                if (ch == '*'){
                    fputc(ch,pOUT);
                    x = IS_STAR;
                } else if (ch == '/'){
                    //fputc('\n',pOUT);
                    ch = fgetc(pIN);
                    if (ch != '\n'){
                        fputc('\n',pOUT);
                    }
                    ungetc(ch,pIN);
                    x = DAFAULT;
                } else{
                    fputc('*',pOUT);
                    fputc(ch,pOUT);
                    x = CPP_COMMENT;
                }
                break;
            }
//            default:{
//                return 1;
//                break;

        }
    }
    fclose(pIN);
    fclose(pOUT);
    printf("修改成功\n");
    return 0;
}

