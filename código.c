#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

int**mt;

void criar(int m, int n){  //Cria a matriz a ser exibida
    int i,j,t=49;
    mt=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++){
        mt[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i%2==1 || j%2==1){
                mt[i][j]=179;
                if(i%2==1)
                    mt[i][j]=196;
            }else{
                mt[i][j]=t;
                t++;
            }
        }
    }
}

void imprimirmatriz(int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        printf("%c",mt[i][j]);
        }
        puts("");
    }
}

void colocarx(int dig){
    if(dig>=1 && dig<=3){
        if(dig==1){
            if(mt[0][0]!=111 && mt[0][0]!=120)
                mt[0][0]=120;
        }else if(dig==2){
            if(mt[0][2]!=111 && mt[0][2]!=120)
                mt[0][2]=120;
        }else{
            if(mt[0][4]!=111 && mt[0][4]!=120)
                mt[0][4]=120;
        }
    }else if(dig>=4 && dig<=6){
        if(dig==4){
            if(mt[2][0]!=111 && mt[2][0]!=120)
                mt[2][0]=120;
        }else if(dig==5){
            if(mt[2][2]!=111 && mt[2][2]!=120)
                mt[2][2]=120;
        }else{
            if(mt[2][4]!=111 && mt[2][4]!=120)
                mt[2][4]=120;
        }
    }else{
        if(dig==7){
            if(mt[4][0]!=111 && mt[4][0]!=120)
                mt[4][0]=120;
        }else if(dig==8){
            if(mt[4][2]!=111 && mt[4][2]!=120)
                mt[4][2]=120;
        }else{
            if(mt[4][4]!=111 && mt[4][4]!=120)
                mt[4][4]=120;
        }
    }
}

void colocaro(int dig){
    if(dig>=1 && dig<=3){
        if(dig==1){
            if(mt[0][0]!=111 && mt[0][0]!=120)
                mt[0][0]=111;
        }else if(dig==2){
            if(mt[0][2]!=111 && mt[0][2]!=120)
                mt[0][2]=111;
        }else{
            if(mt[0][4]!=111 && mt[0][4]!=120)
                mt[0][4]=111;
        }
    }else if(dig>=4 && dig<=6){
        if(dig==4){
            if(mt[2][0]!=111 && mt[2][0]!=120)
                mt[2][0]=111;
        }else if(dig==5){
            if(mt[2][2]!=111 && mt[2][2]!=120)
                mt[2][2]=111;
        }else{
            if(mt[2][4]!=111 && mt[2][4]!=120)
                mt[2][4]=111;
        }
    }else{
        if(dig==7){
            if(mt[4][0]!=111 && mt[4][0]!=120)
                mt[4][0]=111;
        }else if(dig==8){
            if(mt[4][2]!=111 && mt[4][2]!=120)
                mt[4][2]=111;
        }else{
            if(mt[4][4]!=111 && mt[4][4]!=120)
                mt[4][4]=111;
        }
    }
}

int verificaro(){
    if(mt[0][0]==111 && mt[0][2]==111 && mt[0][4]==111){
        return 0;
    }else if(mt[2][0]==111 && mt[2][2]==111 && mt[2][4]==111){
        return 0;
    }else if(mt[4][0]==111 && mt[4][2]==111 && mt[4][4]==111){
        return 0;
    }else if(mt[0][0]==111 && mt[2][0]==111 && mt[4][0]==111){
        return 0;
    }else if(mt[0][2]==111 && mt[2][2]==111 && mt[4][2]==111){
        return 0;
    }else if(mt[0][4]==111 && mt[2][4]==111 && mt[4][4]==111){
        return 0;
    }else if(mt[0][0]==111 && mt[2][2]==111 && mt[4][4]==111){
        return 0;
    }else if(mt[4][0]==111 && mt[2][2]==111 && mt[0][4]==111){
        return 0;
    }else{
        return -1;
    }
}

int verificarx(){
    if(mt[0][0]==120 && mt[0][2]==120 && mt[0][4]==120){
        return 0;
    }else if(mt[2][0]==120 && mt[2][2]==120 && mt[2][4]==120){
        return 0;
    }else if(mt[4][0]==120 && mt[4][2]==120 && mt[4][4]==120){
        return 0;
    }else if(mt[0][0]==120 && mt[2][0]==120 && mt[4][0]==120){
        return 0;
    }else if(mt[0][2]==120 && mt[2][2]==120 && mt[4][2]==120){
        return 0;
    }else if(mt[0][4]==120 && mt[2][4]==120 && mt[4][4]==120){
        return 0;
    }else if(mt[0][0]==120 && mt[2][2]==120 && mt[4][4]==120){
        return 0;
    }else if(mt[4][0]==120 && mt[2][2]==120 && mt[0][4]==120){
        return 0;
    }else{
        return -1;
    }
}

int jogadax(){
    int a,vx;
    printf("Digite o numero correspondente a posição a ser ocupada:");
    scanf("%d", &a);
    colocarx(a);
    imprimirmatriz(5,5);
    vx=verificarx();
    if(vx==0){
        return 0;
    }else
        return 1; 
}

int jogadao(){
    int a,vo;
    printf("Digite o numero correspondente a posição a ser ocupada:");
    scanf("%d", &a);
    colocaro(a);
    imprimirmatriz(5,5);
    vo=verificaro();
    if(vo==0){
        return 0;
    }else
        return 1; 
}


int jogo(int x, int o){
    if(x!=0 || o!=0){
        x=jogadax();
        system("cls");
        imprimirmatriz(5,5);
        if(x==0){
            puts("O jogador do 'x' venceu");
            return 0;
        }
        o=jogadao();
        system("cls");
        imprimirmatriz(5,5);
        jogo(x,o);
        if(o==0){
            puts("O jogador do 'o' venceu");
            return 0;
        }
    }else if(x==0){
        puts("O jogador do 'x' venceu");
        return 0;
    }else if(o==0){
        puts("O jogador do 'o' venceu");
        return 0;
    }else{
        return -1;
    }
}

int main(){
    int a;
    criar(5,5);
    imprimirmatriz(5,5);
    a=jogo(1,1);
    system("pause");
return 0;
}
