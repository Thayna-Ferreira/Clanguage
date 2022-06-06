# include <stdio.h>
FILE *file;
int feof(FILE *file);

struct dados
{
    char filme [30];
    char produtora [30];
    int quantidade;
    float preco;
};

void main ()
{
    struct dados locadora;
    struct dados *p;
    p = &locadora;
    int op;
    do
    {
        printf ("\nMENU LOCADORA\n\n");
        printf ("Selecione a opcao desejada:\n" );
        printf ("1 - Entrada de dados\n");
        printf ("2 - Listagem\n");
        printf ("3 - Pesquisa de filme pelo nome\n");
        printf ("4 - Pesquisa pelo nome da produtora\n");
        printf ("5 - Pesquisa de filme pelo preco\n");
        printf ("6 - Alterar quantidade\n");
        printf ("7 - Alterar preco pelo nome do filme\n");
        printf ("8 - Altera filme pelo nome\n");
        printf ("9 - Excluir filme pelo nome\n");
        printf ("10 - Saida\n\n");
        printf ("Opcao: ");
        scanf ("%d", &op);
        switch (op)
        {

        case 1:
            entradaDados(p);
            break;

        case 2:
            listarDados(p);
            break;

        case 3:
            pesquisaFilmeNome(p);
            break;

        case 4:
            pesquisaProdutoraNome(p);
            break;

        case 5:
            pesquisaFilmePreco(p);
            break;

        case 6:
            alterarQuantidade(p);
            break;

        case 7:
            alterarPrecoNome(p);
            break;

        case 8:
            alterarFilmeNome (p);
            break;

        case 9:
            excluirFilme(p);
            break;

        case 10:
            printf("\nFim do programa...\n");
            exit(0);
        }

    }
    while (op < 10);

}

void entradaDados(struct dados *p)
{
    char registro;
    file = fopen ("filmes.txt", "a");
    do
    {

        printf (" Entre com o nome do filme: ");
        scanf ("%s", &p->filme);
        printf (" Entre com o nome da produtora: ");
        scanf ("%s", &p->produtora);
        printf (" Entre com a quantidade que deseja comprar: ");
        scanf (" %d", &p->quantidade);
        printf (" Entre com o preco: ");
        scanf (" %f", &p->preco);
        printf ("Deseja continuar registrando? s/n ");
        scanf (" %c", &registro);
        system ("cls");
        fwrite(p, sizeof(*p),1,file);
    }
    while (registro == 's');



    fclose(file);

}

void listarDados(struct dados *p)
{
     printf ("\nLISTAGEM DE DADOS\n");
    int a;
    file = fopen("filmes.txt", "r");
    while (1)
    {
        a = fread(p, sizeof (*p), 1, file);
        if (a == 0)
        {
            break;
        }
         if(p->filme[0]!='*'){
        printf("\nNome: %s", p->filme);
        printf("\nProdutora: %s", p->produtora);
        printf("\nQuantidade: %d", p->quantidade);
        printf("\nPreco: R$ %.2f", p->preco);
        printf ("\n----------------------------------");
        }
    }
    printf("\n");
    fclose(file);
    system ("pause");
    system ("cls");

}

void pesquisaFilmeNome(struct dados *p)
{
    printf ("\nPESQUISA POR NOME\n");
    int v,l;
    char pesquisa[20];
    file = fopen ("filmes.txt", "r");
    printf ("Digite o nome do filme que deseja buscar: ");
    scanf ("%s", &pesquisa);

    while (1)
    {
        l =  fread(p, sizeof (*p), 1, file);
        if ( l == 0 )
        {
            break;
        }

        for (v=0; pesquisa[v]!="\0"; v++)
        {

            if (pesquisa[v] != p ->filme[v])
            {
                break;
            }

            if (pesquisa[v] == '\0' && p -> filme[v] == '\0')
            {
                printf("\nNome: %s\n", p->filme);
                printf("Produtora: %s\n", p->produtora);
                printf("Quantidade: %d\n", p->quantidade);
                printf("Preco: R$ %.2f\n", p->preco);
                break;
            }
        }
    }
    fclose (file);
    system ("pause");
    system ("cls");
}

void pesquisaFilmePreco(struct dados *p)
{

    printf ("\nPESQUISA POR PRECO\n");
    int v,l;
    int preco;
    file = fopen ("filmes.txt", "r");
    printf ("Digite o preco do filme que deseja buscar: ");
    scanf ("%d", &preco);

    while (1)
    {
        l =  fread(p, sizeof (*p), 1, file);
        if ( l == 0 )
        {
            break;
        }

        if (preco == p->preco){
            printf("\nNome: %s\n", p->filme);
            printf("Produtora: %s\n", p->produtora);
            printf("Quantidade: %d\n", p->quantidade);
            printf("Preco: R$ %.2f\n", p->preco);

        }


    }
    fclose (file);
        system ("pause");
    system ("cls");

}

void pesquisaProdutoraNome(struct dados *p)
{
    printf ("\nPESQUISA POR PRODUTORA\n");
    int v,l;
    char pesquisa[20];
    file = fopen ("filmes.txt", "r");
    printf ("Digite o nome do filme que deseja buscar: ");
    scanf ("%s", &pesquisa);

    while (1)
    {
        l =  fread(p, sizeof (*p), 1, file);
        if ( l == 0 )
        {
            break;
        }

        for (v=0; pesquisa[v]!="\0"; v++)
        {

            if (pesquisa[v] != p ->produtora[v])
            {
                break;
            }

            if (pesquisa[v] == '\0' && p ->produtora[v] == '\0')
            {
                printf("\nNome: %s\n", p->filme);
                printf("Produtora: %s\n", p->produtora);
                printf("Quantidade: %d\n", p->quantidade);
                printf("Preco: R$ %.2f\n", p->preco);
                break;
            }
        }
    }
    fclose (file);
        system ("pause");
    system ("cls");
}

void alterarFilmeNome(struct dados *p)
{
    printf ("\nALTERACAO DE QUANTIDADE\n");
    int v,l,contador = 0, tamanho;
    char pesquisa[20];
    file = fopen ("filmes.txt", "r+");
    printf ("Digite o nome do filme que deseja alterar: ");
    scanf ("%s", &pesquisa);

    while (1)
    {
        l =  fread(p, sizeof (*p), 1, file);
        if ( l == 0 )
        {
            break;
        }

        for (v=0; pesquisa[v]!='\0'; v++)
        {
            if (pesquisa[v] != p ->filme[v])
            {
                break;
            }
        }
        if (pesquisa[v] == '\0' && p -> filme[v] == '\0')
        {
            printf("Nome atual: %s\n", p->filme);
            printf ("Entre com o novo nome do filme: ");
            scanf (" %s", &p->filme);
            tamanho = contador * sizeof(*p);
            fseek(file,tamanho,0);
            fwrite(p, sizeof (*p), 1, file);
            fclose (file);
            system ("pause");
            system ("cls");
            return contador;
        }
          contador++;

    }

    }

void alterarQuantidade(struct dados *p)
{

    printf ("\nALTERACAO DE QUANTIDADE\n");
    int v,l,contador = 0, tamanho;
    char pesquisa[20];
    file = fopen ("filmes.txt", "r+");
    printf ("Digite o nome do filme que deseja alterar a quantidade: ");
    scanf ("%s", &pesquisa);

    while (1)
    {
        l =  fread(p, sizeof (*p), 1, file);
        if ( l == 0 )
        {
            break;
        }

        for (v=0; pesquisa[v]!='\0'; v++)
        {
            if (pesquisa[v] != p ->filme[v])
            {
                break;
            }
        }
        if (pesquisa[v] == '\0' && p -> filme[v] == '\0')
        {
            printf("Quantidade atual: %d\n", p->quantidade);
            printf ("Entre com a quantidade que deseja alterar para: ");
            scanf (" %d", &p->quantidade);
            tamanho = contador * sizeof(*p);
            fseek(file,tamanho,0);
            fwrite(p, sizeof (*p), 1, file);
            fclose (file);
            system ("pause");
            system ("cls");
            return contador;
        }
          contador++;

    }


    }

void alterarPrecoNome(struct dados *p)
{
    printf ("\nALTERACAO DE PREÇO\n");
    int v,l,contador=0,tamanho;
    char pesquisa[20];
    file=fopen("filmes.txt","r+");

    printf("\nDigite o nome do filme que deseja alterar o preco :");
    scanf("%s", &pesquisa);
    while(1)
    {


        l=fread(p,sizeof(*p),1,file);
        if(l==0)

        {
            printf("Não existe cadastro nesse nome");
            break;
        }
        for(v=0; pesquisa[v]!='\0'; v++)
        {
            if(pesquisa[v]!=p->filme[v])
            {
                break;
            }
        }
        if(pesquisa[v]=='\0'&&p->filme[v]=='\0')
        {
            {

                printf("Digite o novo preco: ");
                printf("preco atual: %2.f\n", p->preco);
                scanf ("%f", &p->preco);

                tamanho=contador*sizeof(*p);
                fseek(file,tamanho,0);
                fwrite(p,sizeof(*p),1,file);
                fclose(file);
                system ("pause");
                system ("cls");
            }
            return contador;

        }
        contador++;
    }
}


void excluirFilme(struct dados *p)
{

    printf ("\nALTERACAO DE QUANTIDADE\n");
    int v,l,contador = 0, tamanho;
    char pesquisa[20];
    file = fopen ("filmes.txt", "r+");
    printf ("Digite o nome do filme que deseja alterar: ");
    scanf ("%s", &pesquisa);

    while (1)
    {
        l =  fread(p, sizeof (*p), 1, file);
        if ( l == 0 )
        {
            printf("Não existe nenhum registro nesse nome. ");
            break;
        }

        for (v=0; pesquisa[v]!='\0'; v++)
        {
            if (pesquisa[v] != p ->filme[v])
            {
                break;
            }
        }
        if (pesquisa[v] == '\0' && p -> filme[v] == '\0')
        {

                p->filme[0]='*';

                tamanho = contador * sizeof(*p);
                fseek(file,tamanho,0);
            fwrite(p, sizeof (*p), 1, file);
            fclose (file);
            system ("pause");
            system ("cls");

            return contador;
        }
  contador++;
    }


}


