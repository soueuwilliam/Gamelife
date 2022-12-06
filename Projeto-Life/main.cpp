#include <iostream>
#include <fstream>
#include "Celula.h"


class menu(){
    private:
        int maxgen; // Maxima geração que o programa roda , no default 
        int fps; //Velocidade de reprodução da Life
        string path; // Onde salvar as imagens
        int blocksize; // tamanho do pixel , defalt = 5
        string bkgcolor // cor de backgraound ,default = Grenn 
        string alivecoor // Cor das celulas viva, default = Red
    public:
        //construtor padrão
        menu(maxgen = NULL,fps = 2, path = NULL, blocksize = 5 , bkgsize)
        
}
using namespace std;

// função para checar se dadas coordenadas estão dentro de um limite
bool valid(int l, int c, int linha, int coluna){
    if(l>=0 && l<linha && c>=0 && c<coluna){
        return true;
    }else{
        return false;
    }
}



int main(int argc, char const *argv[])
{
    int linha, coluna;
    char tipo;
    string filename;
    ifstream arq;

    // Recebe e abre o arquivo contendo as configurações do mapa
    cout << "Nome/caminho do arquivo: ";
    cin >> filename;

    arq.open(filename);

    // Impede a execução do resto do programa caso o input seja inválido
    if(!arq.is_open()){
        cout << "Não foi possível abrir o arquivo. (arquivo/caminho inválido)" << endl;
        return 0;
    }

    cout << "Arquivo aberto com sucesso. Procedendo com a execução." << endl;

    // Processa as informações no arquivo e cria o mapa

    arq >> linha;
    arq >> coluna;
    arq >> tipo;

    celula mapa[linha][coluna];
    celula mapaAuxiliar[linha][coluna];
    char entrada[linha][coluna];
    char letra;
    int i=0, j=0;

    while(arq >> letra){
        entrada[i][j] = letra;

        if(j==coluna-1){
            j=0;
            i++;
        }else{
            j++;
        }
    }

    // Começo da impressão e geração dos mapas posteriores
    int cont = 1;
    cout << "-----------------------------------" << endl;
    cout << "Geração " << cont << ":" << endl;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (entrada[i][j] != '.')
            {
                mapa[i][j].Caractereset(entrada[i][j]);
                mapaAuxiliar[i][j] = mapa[i][j];
            }
            cout << mapa[i][j].caractereget();
        }
        cout << "\n";
    }
    cont++;

    bool continuar;
    
    do{
        // para o programa caso ele chegue na geração 1000 para impedir que entre em loop infinitamente
        if(cont==1001){
            cout << "Limite de gerações (1000) atingido. Abortando programa." << endl;
            break;
        }

        continuar = false;

        for (int i = 0; i < linha; i++){
            for (int j = 0; j < coluna; j++){
                int n=0;
                // segundo par de loops "for" checa por casas ao redor que sejam válidas e estejam vivas
                for(int k = i-1; k<i+2; k++){
                    for(int l = j-1; l<j+2; l++){
                        // conta a quantidade de vizinhos vivos
                        if(valid(k, l, linha, coluna) && (k!=i || l!=j) && mapa[k][l].VivoGet()){
                            n++;
                        }
                    }
                }

                // se vivo e vizinhos <= 1 ou vizinhos >= 4
                if (mapa[i][j].VivoGet() && (n <= 1  || n >= 4)){
                    mapaAuxiliar[i][j].Caractereset('.');
                }

                else if (!mapa[i][j].VivoGet() && n == 3){
                    mapaAuxiliar[i][j].Caractereset(tipo);
                }
            }
        }

        // compara a principal com a auxiliar pra ver se houveram mudanças e encerra o programa se forem iguais (já que não houveram mudanças)
        for(int i=0; i<linha; i++){
            for(int j=0; j<coluna; j++){
                if(mapa[i][j].caractereget()!=mapaAuxiliar[i][j].caractereget()){
                    continuar = true;
                    break;
                }
            }
        }

        if(!continuar){
            cout << "Fim da simulação." << endl;
            break;
        }else{
            cout << "-----------------------------------" << endl;
            cout << "Geração " << cont << ":" << endl;
            cout << endl;
        }

        // imprime a auxiliar
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                cout << mapaAuxiliar[i][j].caractereget();
            }
          cout << "\n";
        }

        // re-copia no mapa principal
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                mapa[i][j] = mapaAuxiliar[i][j];
            }
          
        }
        cont++;
    }while (continuar);

    return 0;
}