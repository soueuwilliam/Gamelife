//.h Variveis e chamada das funções
class celula
{
private:
    bool vivo ;
    int qtddeVizinhosVivo;
    char Caractere;

public:
    // construtor padrão
    celula();
    /*======== Metodos ========*/
    // Retorna qual é o caractere que tem na posição [i,j] do mapa
    char caractereget();
    // Set a caractere de uma determinada posição
    void Caractereset(char EntradaCaractere);
    // retorna dizendo se a celula tá viva ou morta
    bool VivoGet();
};