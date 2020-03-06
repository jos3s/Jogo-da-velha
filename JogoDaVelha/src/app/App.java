package app;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);

        char[][] jogo=new char[3][3];

        System.out.println("O 1 jogador é o 'X'");
        System.out.println("O 2 jogador é o 'O'");

        boolean ganhou = false;
        int jogada = 1;
        char sinal;
        int linha = 0, coluna = 0;
        
        while(!ganhou){
            if(jogada%2==1){
                System.out.println("Vez do jogador 1");
                sinal='X';
            }else{
                System.out.println("Vez do jogador 2");
                sinal='O';
            }

            boolean linhaValida=false;
            while(!linhaValida){
                System.out.println("Digite a linha (1-3)");
                linha=sc.nextInt();
                if(linha>=1 && linha<=3){
                    linhaValida=true;
                }else{
                    System.out.println("Valor inválido, tente novamente");
                }
            }

            boolean colunaValida=false;
            while(!colunaValida){
                System.out.println("Digite a coluna (1-3)");
                coluna=sc.nextInt();
                if(coluna>=1 && coluna<=3){
                    colunaValida=true;
                }else{
                    System.out.println("Valor inválido, tente novamente");
                }
            }

            linha--;
            coluna--;

            if (jogo[linha][coluna] == 'X' || jogo[linha][coluna] == 'O'){
                System.out.println("Posição já usada, tente novamente");
            } else { //jogada válida
                jogo[linha][coluna] = sinal;
                jogada++;
            }

            for (int i=0; i<jogo.length; i++){
                for (int j=0;j<jogo[i].length; j++){
                    System.out.print(jogo[i][j] + " | ");
                }
                System.out.println();
            }

            if( (jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') ||     //linha 1
                (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') || //linha 2
                (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') || //linha 3
                (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') || //coluna 1
                (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') || //coluna 2
                (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') || //coluna 3
                (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') || //diagonal
                (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')){
                    System.out.println("O jogador 1 ganhou");
                    ganhou=true;
            }else if((jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O') ||     //linha 1
                    (jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O') || //linha 2
                    (jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O') || //linha 3
                    (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O') || //coluna 1
                    (jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O') || //coluna 2
                    (jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O') || //coluna 3
                    (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') || //diagonal
                    (jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O')){
                System.out.println("O jogador 2 ganhou");
                ganhou=true;
            }else if(jogada>9){
                System.out.println("Deu , ninguem ganhou");
                ganhou=true;
            }
        }


        sc.close();
    }
}