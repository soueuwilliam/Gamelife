#include <iostream>
#include "Celula.h"

using namespace std;




    bool vivo = false;
    int qtddeVizinhosVivo = 0;
    char Caractere = '.';

    // construtor padrão, aplicado a todas as casas na criação do objeto
    celula::celula()
    {
        Caractere = '.';
        vivo = false;
        qtddeVizinhosVivo = 0;
    }
    // método para retornar qual o caractere na casa
    char celula::caractereget()
    {
        return Caractere;
    }
    // método para substituir o caractere na casa selecionada, logo após ocorre a checagem se aquela casa está viva ou não
    void celula::Caractereset(char EntradaCaractere)
    {
        Caractere = EntradaCaractere;
        if (Caractere == '.')
        {
            vivo = false;
        }else
        {
            vivo = true;
        }
    }
    // método que retorna o estado atual da casa (vivo ou morto)
    bool celula::VivoGet()
    {
        return vivo;
    }