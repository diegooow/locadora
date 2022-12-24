#include <stdio.h>
#include <stdlib.h>
struct sVeiculos
{
    int numero ;
    char descricao[200];
    char placa[20];
    char marca[30];
    char modelo[30];
    char ano[5];
    char categoria[30];
    char cor[20];
    char status[20];
    char ocupantes[10];
    char valorDiaria[10];

};
typedef struct sVeiculos tVeiculos;
tVeiculos vetVeiculos[100];

int carregaVeiculos()
{
    int i=0,r=0;
    char nomeCampo[256],valorCampo[256];
    FILE *arqVeiculos;
    arqVeiculos = fopen("veiculos.txt","r");
    if (arqVeiculos != NULL)
    {
        r = fscanf(arqVeiculos,"%s %[^\n]",&nomeCampo,&valorCampo);
        i=0;
        while (r!=EOF)
        {
            if (strcmp(nomeCampo,"veiculo")==0 && strcmp(valorCampo,"inicio")==0 )
            {
                i = i + 1;
                vetVeiculos[i].numero = i;
                strcpy(vetVeiculos[i].descricao,"");
                strcpy(vetVeiculos[i].modelo,"");
                strcpy(vetVeiculos[i].cor,"");
                strcpy(vetVeiculos[i].placa,"");
                strcpy(vetVeiculos[i].valorDiaria,"");
                strcpy(vetVeiculos[i].marca,"");
                strcpy(vetVeiculos[i].ano,"");
                strcpy(vetVeiculos[i].categoria,"");
                strcpy(vetVeiculos[i].ocupantes,"");
                strcpy(vetVeiculos[i].status,"");


            }

            if (strcmp(nomeCampo,"descricao")==0)
                strcpy(vetVeiculos[i].descricao,valorCampo);
            if (strcmp(nomeCampo,"modelo")==0)
                strcpy(vetVeiculos[i].modelo,valorCampo);
            if (strcmp(nomeCampo,"cor")==0)
                strcpy(vetVeiculos[i].cor,valorCampo);
            if (strcmp(nomeCampo,"placa")==0)
                strcpy(vetVeiculos[i].placa,valorCampo);
            if(strcmp(nomeCampo,"vDiaria")==0)
                strcpy(vetVeiculos[i].valorDiaria,valorCampo);
            if (strcmp(nomeCampo,"marca")==0)
                strcpy(vetVeiculos[i].marca,valorCampo);
            if (strcmp(nomeCampo,"ano")==0)
                strcpy(vetVeiculos[i].ano,valorCampo);
            if (strcmp(nomeCampo,"categoria")==0)
                strcpy(vetVeiculos[i].categoria,valorCampo);
            if (strcmp(nomeCampo,"ocupantes")==0)
                strcpy(vetVeiculos[i].ocupantes,valorCampo);
            if (strcmp(nomeCampo,"status")==0)
                strcpy(vetVeiculos[i].status,valorCampo);

            r = fscanf(arqVeiculos,"%s %[^\n}]",&nomeCampo,&valorCampo);
        }
        i = i + 1;
        vetVeiculos[i].numero = 999;
        fclose(arqVeiculos);

    }
    else {
        printf("arquivo veiculos.txt nao encontrado");
        r = -1;
    }
    return r;
    modificaVeiculos();
}

void printVeiculos() {
    for (int i = 1; i<100 && vetVeiculos[i].numero != 999; i++) {
        printf("\nCodigo do veiculo %i \ndescricao %s \nmodelo %s \ncor %s \nplaca %s \nvalor Diaria %s \nmarca %s \nano %s \ncategoria %s \nocupantes %s \nstatus %s\n\n", vetVeiculos[i].numero,
               vetVeiculos[i].descricao,
               vetVeiculos[i].modelo,
               vetVeiculos[i].cor,
               vetVeiculos[i].placa,
               vetVeiculos[i].valorDiaria,
               vetVeiculos[i].marca,
               vetVeiculos[i].ano,
               vetVeiculos[i].categoria,
               vetVeiculos[i].ocupantes,
               vetVeiculos[i].status
                );
    }
}
typedef struct
{
char rua[30];
char numero[5];
char bairro[30];
char cidade[30];
}sEndereco;

typedef struct
{
int contador;
char codigo[30];
char nome[30];
char cnh[12];
char celular[10];
char fidelidade[30];
sEndereco endereco;
}sCliente;
sCliente vetCliente[100];

typedef struct
{
    int contador;
    char data_retirada[20];
    char data_devolucao[20];
    char seguro[20];
    char qtdDiarias[10];
    char codCliente[20];
    char codVeiculo[20];
    char andamento[10];
    char avaliacao[10];

}sLocacao;
sLocacao vetLocacao[100];
void carregaLocacao()
{
    int i=0,r=0;
    char nomeCampo[256],valorCampo[256];
    FILE *arqLocacao;

    arqLocacao = fopen("locacoes.txt","r");

    if(arqLocacao != NULL)
    {
        r = fscanf(arqLocacao,"%s %[^\n]",&nomeCampo,&valorCampo);

        while(r!=EOF)
        {
            if(strcmp(nomeCampo,"locacao")==0 && strcmp(valorCampo,"inicio")==0)
            {

            i= i+ 1;
            vetLocacao[i].contador = i;
            strcpy(vetLocacao[i].data_retirada,"");
            strcpy(vetLocacao[i].seguro,"");
            strcpy(vetLocacao[i].qtdDiarias,"");
            strcpy(vetLocacao[i].codCliente,"");
            strcpy(vetLocacao[i].codVeiculo,"");
            strcpy(vetLocacao[i].andamento,"");
            strcpy(vetLocacao[i].avaliacao,"");
            }
            if(strcmp(nomeCampo,"datRetira")==0)
                strcpy(vetLocacao[i].data_retirada,valorCampo);
            if(strcmp(nomeCampo,"seguro")==0)
                strcpy(vetLocacao[i].seguro,valorCampo);
            if(strcmp(nomeCampo,"qtdDiarias")==0)
                strcpy(vetLocacao[i].qtdDiarias,valorCampo);
            if(strcmp(nomeCampo,"codCliente")==0)
                strcpy(vetLocacao[i].codCliente,valorCampo);
            if(strcmp(nomeCampo,"codVeiculo")==0)
                strcpy(vetLocacao[i].codVeiculo,valorCampo);
            if(strcmp(nomeCampo,"andamento")==0)
                strcpy(vetLocacao[i].andamento,valorCampo);
            if(strcmp(nomeCampo,"avaliacao")==0)
                strcpy(vetLocacao[i].avaliacao,valorCampo);

            r = fscanf(arqLocacao,"%s %[^\n}]",&nomeCampo,&valorCampo);
        }
        i+=1;
        vetLocacao[i].contador = 999;
        fclose(arqLocacao);
    }
    else{
        printf("O arquivo locacoes.txt nao foi encontrado");
        r = -1;
    }
    return r;
    modificaLocacao();
}
void modificaLocacao()
{
    FILE *arqLocacao;
    int i =0;
    arqLocacao = fopen("locacoes.txt","w+");

    while(vetLocacao[i + 1].contador != 999){
        i+=1;
        fprintf(arqLocacao,"locacao inicio\n  numero %d\n  datRetira %s\n  seguro %s\n  qtdDiarias %s\n  codCliente %s\n  codVeiculo %s\n  andamento %s\n  avaliacao %s\nlocacao fim\n\n ",vetLocacao[i].contador,
                vetLocacao[i].data_retirada,
                vetLocacao[i].seguro,
                vetLocacao[i].qtdDiarias,
                vetLocacao[i].codCliente,
                vetLocacao[i].codVeiculo,
                vetLocacao[i].andamento,
                vetLocacao[i].avaliacao);
    }
    fclose(arqLocacao);
}
void printLocacao()
{
    for(int i=1;i<100 && vetLocacao[i].contador != 999 ;i++ )
    {
        printf("locacao inicio\n  numero %d\n  datRetira %s\n  seguro %s\n  qtdDiarias %s\n  codCliente %s\n  codVeiculo %s\n  andamento %s\nlocacao fim\n\n ",vetLocacao[i].contador,
                vetLocacao[i].data_retirada,
                vetLocacao[i].seguro,
                vetLocacao[i].qtdDiarias,
                vetLocacao[i].codCliente,
                vetLocacao[i].codVeiculo,
                vetLocacao[i].andamento,
                vetLocacao[i].avaliacao);
    }
}
int printLocacaoAndamento()
{
int contado=0;
    for(int i=1;i<100 && vetLocacao[i].contador != 999 ;i++ )
    {
        if(strcmp(vetLocacao[i].andamento,"sim")==0){
            printf("locacao inicio\n  numero %d\n  datRetira %s\n  seguro %s\n  qtdDiarias %s\n  codCliente %s\n  codVeiculo %s\n  andamento %s\nlocacao fim\n\n ",vetLocacao[i].contador,
                vetLocacao[i].data_retirada,
                vetLocacao[i].seguro,
                vetLocacao[i].qtdDiarias,
                vetLocacao[i].codCliente,
                vetLocacao[i].codVeiculo,
                vetLocacao[i].andamento);

                contado +=1;
        }
    }
 if (contado==0){
    printf("Nao existem locacoes atuais para fechar o pagamento ou vizualizar\n");
 }
 return contado;
}
void cadastraLocacao()
{
    int i=1,carro =0,resultado=0,seguro = 0,fidelidade=0,cliente=0,saida=0;
    char aux[30],pergunta[10];
    while(vetLocacao[i].contador != 999){
        i+=1;
    }
    vetLocacao[i].contador = i;
    printf("\nDigite a data de retirada no formato xx/xx/xxxx\n");
    scanf("%s",&vetLocacao[i].data_retirada);
    printf("\nDigite se o cliente deseja seguro\n");
        while(seguro != 1){
        scanf(" %s",&vetLocacao[i].seguro);
        if(strcmp(vetLocacao[i].seguro,"nao") == 0){
            seguro =1;
        }
        else if(strcmp(vetLocacao[i].seguro,"sim")==0){
            seguro =1;
        }
        else{
            printf("\nDigite apenas sim ou nao\n");
        }
    }
    printf("\nDigite a quantidade de diarias\n");
    scanf("%s",&vetLocacao[i].qtdDiarias);
    printClientes();
    printf("\nDigite qual o codigo do cliente que deseja fazer a locacao\n");
    scanf("%s",&vetLocacao[i].codCliente);
    printVeiculos();
    printf("\nDigite qual o codigo do veiculo o cliente deseja alugar\n");
    while(carro != 1){
        scanf("%s",&vetLocacao[i].codVeiculo);
        resultado = atoi(vetLocacao[i].codVeiculo);
        cliente = atoi(vetLocacao[i].codCliente);
        if(strcmp(vetVeiculos[resultado].status,"locado") == 0){
            printf("Voce digitou um carro ja locado");
        }
        else if(strcmp(vetVeiculos[resultado].status,"manutencao") == 0){
            printf("Voce digitou um veiculo em manutencao");
        }
        else{
            carro =1;
            strcpy(vetVeiculos[resultado].status,"locado");
            fidelidade = atoi(vetCliente[cliente].fidelidade);
            fidelidade += 10;
            itoa(fidelidade,aux,10);
            strcpy(vetCliente[cliente].fidelidade,aux);
            strcpy(vetLocacao[i].andamento,"sim");

            system ("CLS");
            if(fidelidade >=500){
                printf("\n\nCliente fidelidade Locamais");
            }
            printf("\n\tCarro alugado com sucesso\n");

        }

    }
    vetLocacao[i + 1].contador = 999;
    modificaVeiculos();
    modificaClientes();
    modificaLocacao();
            printf("\nDeseja voltar para o menu?\n");
            while(saida != 1){
            scanf(" %s",&pergunta);
            if(strcmp(pergunta,"sim")==0){
                    saida =1;
                menu();
            }
            else if(strcmp(pergunta,"nao")==0){
                system ("CLS");
                sair();
            }
            else{
                printf("\nDigite apenas sim ou nao\n");
            }
            }
}

int carregaCliente()
{
    int i=0, r=0;
    char nomeCampo[256],valorCampo[256];
    FILE *arqCliente;

    arqCliente = fopen("clientes.txt","r");

    if(arqCliente != NULL)
        {
            r = fscanf(arqCliente,"%s %[^\n]",&nomeCampo,&valorCampo);

            while(r!=EOF)
            {
                if(strcmp(nomeCampo,"Cliente")==0 && strcmp(valorCampo,"inicio")==0)
                {
                    i = i + 1;
                    vetCliente[i].contador = i;
                    strcpy(vetCliente[i].nome,"");
                    strcpy(vetCliente[i].cnh,"");
                    strcpy(vetCliente[i].celular,"");
                    strcpy(vetCliente[i].endereco.rua,"");
                    strcpy(vetCliente[i].endereco.numero,"");
                    strcpy(vetCliente[i].endereco.bairro,"");
                    strcpy(vetCliente[i].endereco.cidade,"");
                    strcpy(vetCliente[i].fidelidade,"");


                }
                if(strcmp(nomeCampo,"nome")==0)
                    strcpy(vetCliente[i].nome,valorCampo);
                if(strcmp(nomeCampo,"cnh")==0)
                    strcpy(vetCliente[i].cnh,valorCampo);
                if(strcmp(nomeCampo,"celular")==0)
                    strcpy(vetCliente[i].celular,valorCampo);
                if(strcmp(nomeCampo,"rua")==0)
                    strcpy(vetCliente[i].endereco.rua,valorCampo);
                if(strcmp(nomeCampo,"numero")==0)
                    strcpy(vetCliente[i].endereco.numero,valorCampo);
                if(strcmp(nomeCampo,"bairro")==0)
                    strcpy(vetCliente[i].endereco.bairro,valorCampo);
                if(strcmp(nomeCampo,"cidade")==0)
                    strcpy(vetCliente[i].endereco.cidade,valorCampo);
                if(strcmp(nomeCampo,"fidelidade")==0)
                    strcpy(vetCliente[i].fidelidade,valorCampo);

                r = fscanf(arqCliente,"%s %[^\n}]",&nomeCampo,&valorCampo);


            }
            i = i +1;
            vetCliente[i].contador = 999;
            fclose(arqCliente);


        }
        else{
            printf("Arquivo  cliente.txt nao encontrado");
            r = -1;
        }
        return r;
        modificaClientes();



}
void modificaVeiculos()
{
    FILE *arqVeiculos;
    int i=0;
    arqVeiculos = fopen("veiculos.txt","w+");
    while(vetVeiculos[i +1].numero != 999)
    {
        i+=1;
        fprintf(arqVeiculos,"veiculo inicio\n  numero %d\n  descricao %s\n  modelo %s\n  cor %s\n  placa %s\n  vDiaria %s\n  marca %s\n  ano %s\n categoria %s\n  ocupantes %s\n  status %s\nveiculo fim\n\n",
                vetVeiculos[i].numero,vetVeiculos[i].descricao,vetVeiculos[i].modelo,vetVeiculos[i].cor,vetVeiculos[i].placa,vetVeiculos[i].valorDiaria,vetVeiculos[i].marca,vetVeiculos[i].ano,
                vetVeiculos[i].categoria,vetVeiculos[i].ocupantes,vetVeiculos[i].status);
    }
    fclose(arqVeiculos);
}
void modificaClientes()
{
    FILE *arqCliente;
    int i = 0;

    arqCliente = fopen("clientes.txt","w+");

    while(vetCliente[i + 1].contador != 999)
        {
            i += 1;
            fprintf(arqCliente,"\n\nCliente inicio\n  numero  %d\n  nome %s\n  cnh %s\n  celular %s\n  rua %s\n  numero %s\n  bairro %s\n  cidade %s\n  fidelidade %s\ncliente fim\n\n",vetCliente[i].contador,vetCliente[i].nome,
                    vetCliente[i].cnh,vetCliente[i].celular,vetCliente[i].endereco.rua,vetCliente[i].endereco.numero,vetCliente[i].endereco.bairro,vetCliente[i].endereco.cidade,vetCliente[i].fidelidade);


        }
        fclose(arqCliente);


}
void cadastraVeiculos()
{
    int i=1;
    while(vetVeiculos[i].numero != 999){
        i+=1;
    }
    vetVeiculos[i].numero = i;
    printf("\nDigite a descricao do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].descricao);
    printf("\nDigite o modelo do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].modelo);
    printf("\nDigite a cor do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].cor);
    printf("\nDigite a placa do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].placa);
    printf("\nDigite o valor da diaria do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].valorDiaria);
    printf("\nDigite a marca do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].marca);
    printf("\nDigite a ano do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].ano);
    printf("\nDigite a categoria do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].categoria);
    printf("\nDigite quantos ocupantes eh possivel para o uso do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].ocupantes);
    printf("\nDigite o status do veiculo\n");
    scanf(" %[^\n}]",&vetVeiculos[i].status);
    vetVeiculos[i + 1].numero = 999;

    modificaVeiculos();
    modificaClientes();
    modificaLocacao();
}
void printClientes()
{
    for(int i =1;i<100 && vetCliente[i].contador != 999 ;i++){
        printf("\nCodigo: %d\n Nome: %s\n CNH: %s\n celular: %s\n rua: %s numero: %s bairro: %s cidade: %s\n fidelidade: %s\n",vetCliente[i].contador,vetCliente[i].nome,vetCliente[i].cnh,vetCliente[i].celular,vetCliente[i].endereco.rua,vetCliente[i].endereco.numero,
               vetCliente[i].endereco.bairro,vetCliente[i].endereco.cidade,vetCliente[i].fidelidade);
    }
}
void especificaCliente()
{
    char cliente[20];
    int j=0,numero=0,locacao=0,teste=0;
    char *ponteiro;
    printf("\nDigite o nome do cliente: \n");
    scanf("%s",&cliente);
    for(int i=1;vetCliente[i].contador != 999;i++){
            ponteiro = strstr(vetCliente[i].nome,cliente);

                if(ponteiro){

                printf("\nCliente inicio\n  numero  %d\n  nome %s\n  cnh %s\n  celular %s\n  rua %s\n  numero %s\n  bairro %s\n  cidade %s\n  fidelidade %s\ncliente fim\n\n",vetCliente[i].contador,vetCliente[i].nome,
                    vetCliente[i].cnh,vetCliente[i].celular,vetCliente[i].endereco.rua,vetCliente[i].endereco.numero,vetCliente[i].endereco.bairro,vetCliente[i].endereco.cidade,vetCliente[i].fidelidade);
                    }
    }
            printf("\nCaso deseja ver todas locacoes deste cliente digite o numero de identificacao,caso nao queira digite 0: \n");
            scanf("%d",&numero);
            if(numero==0){
                system("CLS");
                menu();
            }else{
            for(int k=0;vetLocacao[k].contador != 999;k++){
                locacao = atoi(vetLocacao[k].codCliente);
                if(numero == locacao){
                    printf("locacao inicio\n  numero %d\n  datRetira %s\n  seguro %s\n  qtdDiarias %s\n  codCliente %s\n  codVeiculo %s\n  andamento %s\nlocacao fim\n\n ",vetLocacao[k].contador,
                vetLocacao[k].data_retirada,
                vetLocacao[k].seguro,
                vetLocacao[k].qtdDiarias,
                vetLocacao[k].codCliente,
                vetLocacao[k].codVeiculo,
                vetLocacao[k].andamento,
                vetLocacao[k].avaliacao);
                teste++;
                }
            }
            if(teste==0){
                printf("\nEste cliente nao possui locacoes\n");
            }


    }

}
void cadastraCliente()
{
    int i=1;
    while(vetCliente[i].contador != 999){
        i+=1;
    }
    vetCliente[i].contador = i;
    printf("\nDigite o nome do Cliente\n");
    scanf(" %[^\n}]",&vetCliente[i].nome);
    printf("\nDigite a cnh do Cliente\n");
    scanf(" %[^\n}]",&vetCliente[i].cnh);
    printf("\nDigite o celular do Cliente\n");
    scanf(" %[^\n}]",&vetCliente[i].celular);
    printf("\nDigite a rua do Cliente\n");
    scanf(" %[^\n}]",&vetCliente[i].endereco.rua);
    printf("\nDigite o numero da casa do Cliente\n");
    scanf(" %[^\n}]",&vetCliente[i].endereco.numero);
    printf("\nDigite o bairro da casa do Cliente\n");
    scanf(" %[^\n}]",&vetCliente[i].endereco.bairro);
    printf("\nDigite a cidade da casa do Cliente\n");
    scanf(" %[^\n}]",&vetCliente[i].endereco.cidade);
    strcpy(vetCliente[i].fidelidade,"0");
    system("CLS");
    printf("\n\nCliente Cadastrado com sucesso\n\n");

    vetCliente[i + 1].contador = 999;
    modificaVeiculos();
    modificaClientes();
    modificaLocacao();

}
void statusVeiculo()
{
    int veiculo = 0,saida=0;
    char status[20];
    printVeiculos();
    printf("\nDigite qual o codigo do veiculo que deseja modificar: \n");
    scanf("%d",&veiculo);
    for(int i=0;vetVeiculos[i].numero != 999 ;i++){
        if(vetVeiculos[i].numero == veiculo){
            printf("\nDigite qual status voce deseja colocar no veiculo %s: \n",vetVeiculos[i].modelo);
            while(saida != 1){
                scanf(" %s",&status);
                if(strcmp(status,"livre")==0){
                    system("CLS");
                    strcpy(vetVeiculos[i].status,status);
                    printf("\nStatus alterado para livre com sucesso \n");
                    saida =1;
                }
                else if(strcmp(status,"manutencao")==0){
                    system("CLS");
                    strcpy(vetVeiculos[i].status,status);
                    printf("Status alterado para manutencao com sucesso \n");
                    saida =1;
                }
                else{
                    printf("\n O status pode ser a palavra livre ou manutencao \n");
                }
            }

        }
    }
    modificaVeiculos();
}
void especificaVeiculo()
{
    int digito,lugar;
    printf("\n\nO carro eh para quantas pessoas? \n");
    scanf("%d",&digito);


    for(int i=1;vetVeiculos[i].numero != 999;i++){
        lugar=atoi(vetVeiculos[i].ocupantes);
            if (lugar >= digito){
                printf("veiculo inicio\n  numero %d\n  descricao %s\n  modelo %s\n  cor %s\n  placa %s\n  vDiaria %s\n  marca %s\n  ano %s\n categoria %s\n  ocupantes %s\n  status %s\nveiculo fim\n\n",
                vetVeiculos[i].numero,vetVeiculos[i].descricao,vetVeiculos[i].modelo,vetVeiculos[i].cor,vetVeiculos[i].placa,vetVeiculos[i].valorDiaria,vetVeiculos[i].marca,vetVeiculos[i].ano,
                vetVeiculos[i].categoria,vetVeiculos[i].ocupantes,vetVeiculos[i].status);
                printf("\nModelos de veiculos que poderao te atender\n");
            }

    }
}
void sair()
{   system ("CLS");
    printf("\nObrigado pela preferencia!\n");
    exit(0);
    return 0;
}
void avaliacao()
{
    int cliente =0,soma =0,avaliar=0,contador =0;
    float media =0;
    for(int i=1;vetLocacao[i].contador != 999; i++){
        cliente = atoi(vetLocacao[i].codCliente);
        printf("\nCliente: %s avaliacao %s\n",vetCliente[cliente].nome,vetLocacao[i].avaliacao);
        avaliar = atoi(vetLocacao[i].avaliacao);
        soma += avaliar;
        contador +=1;
    }
    media = soma/contador;
    printf("\nA media eh de ");
    for(int j=1;j<=media;j++){
        printf(" * ");

    }
    printf(" %2.f estrelas\n\n",media);

}
void pagamento()
{
    int locacao =0,converter=0,loop=0,aux=0,qtdDias=0,conferirdia =0,conferirmes =0,conferirano =0,seguro=0,vVeiculo=0,vTotal=0,passado=0,atraso=0,preco=0;
    float multa=0;
    int saida =0,estrela=0,inteiro =0;
    char pergunta[10],avaliar[10];
    char diaE[3],mesE[3],anoE[5];
    char diaR[3],mesR[3],anoR[5];
    int idiaE,imesE,ianoE;
    int idiaR,imesR,ianoR;
    char resposta[5],entrega[11],retirada[11];
    int contado = printLocacaoAndamento();
    printf("\nDigite qual o numero da locacao deseja entregar\n");
    if(contado==0){
        //menu();
        return;
    }
    else{
    scanf("%d",&locacao);
    converter = atoi(vetLocacao[locacao].codVeiculo);
    if(strcmp(vetVeiculos[converter].status,"locado")!=0){
        system("CLS");
        printf("\n\nNao eh possivel retornar esse veiculo pois ele nao esta locado\n\n");

    }
    else{
    if(vetLocacao[locacao].contador == locacao){
        printf("\nVoce deseja retornar o %s?\n",vetVeiculos[converter].modelo);
        while(loop!=1){
            scanf(" %s",&resposta);
            if(strcasecmp(resposta,"sim")==0){
            printf("\nDigite a data que o veiculo esta sendo entregue no formato xx/xx/xxxx\n");
            scanf("%s",&entrega);
            while(passado != 1){
            strcpy(vetLocacao[locacao].data_devolucao,entrega);

            qtdDias = atoi(vetLocacao[locacao].qtdDiarias);

            vVeiculo= atoi(vetVeiculos[converter].valorDiaria);

            strncpy(diaE,entrega + 0,2); // Separando o dia da entrega em dia mes e ano.
            strncpy(mesE,entrega + 3,2);
            strncpy(anoE,entrega + 6,4);
            diaE[2]= '\0';
            mesE[2]= '\0';
            anoE[4]= '\0';
            strcpy(retirada,vetLocacao[locacao].data_retirada);

            strncpy(diaR,retirada + 0,2); // Separando o dia da retirada em dia mes e ano.
            strncpy(mesR,retirada + 3,2);
            strncpy(anoR,retirada + 6,4);
            diaR[2]= '\0';
            mesR[2]= '\0';
            anoR[4]= '\0';

            idiaE = atoi(diaE);  //convertendo para inteiro o dia da entrega
            imesE = atoi(mesE);
            ianoE = atoi(anoE);

            idiaR = atoi(diaR);  //convertendo para inteiro o dia da retirada
            imesR = atoi(mesR);
            ianoR = atoi(anoR);

            conferirano = ianoE - ianoR;
            conferirmes = (imesE - imesR)+(conferirano*12);
            conferirdia = (idiaE - idiaR)+(conferirmes*30);

            atraso= conferirdia-qtdDias;

            if(conferirdia<0){
                printf("\n\n Nao eh possivel voltar no passado\n\n");
                scanf(" %s",&entrega);
            }
            else{
                    passado =1;

            if(strcmp(vetLocacao[locacao].seguro,"sim")==0){
                seguro = 50;
            }

            if(conferirdia == qtdDias){
                printf("\nParabens voce entregou no prazo certo\n");
                vTotal = seguro + qtdDias*vVeiculo;
                preco=multa+ vTotal;

            }
            else if(conferirdia < qtdDias){
                printf("\nParabens voce entregou adiantado,porem devera pagar o que foi combinado\n");
                vTotal = seguro + (qtdDias*vVeiculo);
                multa = 0;
                preco=multa+ vTotal;
            }
            else{
                printf("\nVoce tera que pagar multa\nVoce esta entregando com %d dias de atraso\n",atraso);
                vTotal = seguro + (qtdDias*vVeiculo);
                multa = (0.30*vTotal)+(atraso * 30);
                preco=multa+ vTotal;
            }
            printf("\nValor do seguro: %d\nValor do veiculo: %d\nDias com o veiculo:%d\nMulta a pagar: %d\n Valor total: %d",seguro,vVeiculo,qtdDias,multa,preco);

            strcpy(vetVeiculos[converter].status,"livre");
            strcpy(vetLocacao[locacao].andamento,"nao");

            printf("\nDigite a avaliacao do cliente para o servico 1(muito ruim) ate 5(muito bom): \n");
            while(estrela != 1){
                scanf(" %s",&avaliar);

                inteiro = atoi(avaliar);
                if(inteiro<0){
                    printf("\n Comece a partir do 1: \n");
                }
                else if(inteiro>5){
                    printf("\n A avaliacao deve ser menor que 5: \n");
                }
                else{
                    strcpy(vetLocacao[locacao].avaliacao,avaliar);
                    printf("\n A avaliacao foi registrada\n");
                    estrela=1;
                }
            }


            loop=1;
        }
        }
    }
    if(strcasecmp(resposta,"nao")==0){
        return;
    }
    else{
        printf("\nDigite sim ou nao\n");
    }
    }
    }
    modificaClientes();
    modificaLocacao();
    modificaVeiculos();
    }
    }
}
void fiel()
{
    int pontos = 0;
    for(int i=0;vetCliente[i].contador != 999;i++){
        pontos = atoi(vetCliente[i].fidelidade);
        if(pontos>=500){
            printf("\nCliente inicio\n  numero  %d\n  nome %s\n  cnh %s\n  celular %s\n  rua %s\n  numero %s\n  bairro %s\n  cidade %s\n  fidelidade %s\ncliente fim\n\n",vetCliente[i].contador,vetCliente[i].nome,
                    vetCliente[i].cnh,vetCliente[i].celular,vetCliente[i].endereco.rua,vetCliente[i].endereco.numero,vetCliente[i].endereco.bairro,vetCliente[i].endereco.cidade,vetCliente[i].fidelidade);
        }
    }

}

void menu()
{
    system("cls || clear");
int continuar=1;
    printf("\n\n\tBem vindo a LocaMais\n\n");
    printf("\n\nDigite uma opcao\n\n\n");

    do
    {
        printf("\n 1. Cadastrar novo cliente\n");
        printf("\n 2. Cadastrar novo veiculo\n");
        printf("\n 3. Cadastrar nova locacao de veiculos\n");
        printf("\n 4. Confirmar o pagamento\n");
        printf("\n 5. Listar todos os clientes\n");
        printf("\n 6. Listar todos os veiculos\n");
        printf("\n 7. Listar todas as locacoes\n");
        printf("\n 8. Listar cliente especifico e suas locacoes\n");
        printf("\n 9. Listar veiculo especifico\n");
        printf("\n 10. Listar clientes fieis\n");
        printf("\n 11. Mudar status do veiculo\n");
        printf("\n 12. Mostrar avaliacoes de clientes e sua media \n");
        printf("\n 0. Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                cadastraCliente();
                break;

            case 2:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                cadastraVeiculos();
                break;

            case 3:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                cadastraLocacao();
                break;

            case 4:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                pagamento();
                break;

            case 5:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                printClientes();
                break;

            case 6:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                printVeiculos();
            break;

            case 7:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                printLocacao();
            break;

            case 8:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                especificaCliente();

            break;

            case 9:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                especificaVeiculo();
            break;

            case 10:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                fiel();

            break;

            case 11:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                statusVeiculo();

            break;

            case 12:
                carregaCliente();
                carregaLocacao();
                carregaVeiculos();
                avaliacao();
            break;

            case 0:
                sair();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}

int main()
{
    menu();
}
