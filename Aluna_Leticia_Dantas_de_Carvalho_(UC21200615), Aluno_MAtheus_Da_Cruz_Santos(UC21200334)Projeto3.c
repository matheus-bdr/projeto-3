//Aluna: Leticia Dantas de Carvalho (UC21200615)
//Aluno: Matheus Da Cruz Santos (UC21200334)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <locale.h>

typedef struct{
 int codPiloto;
 int idade;
 char nome_piloto[400];
 char sexo;
 char pais_origem[120];
}cadastro_piloto;

typedef struct {
 int cod_ci;
 int idPilotoMenorTemp;
 char nome_ci[400];
 char pais_ci[120];
 float tamanho;
 double menor_temp;
}cadastro_circuito;

typedef struct {
 cadastro_piloto id_piloto;
 cadastro_circuito id_ci;
 char nome_equi[400];
 int dia;
 int mes;
 int ano;
 double tem_melhor;
}cadastro_melhor_volta;

void ConsultaGeral (int, cadastro_piloto*, cadastro_circuito*, cadastro_melhor_volta*);
void PesquisarPilotos (int, cadastro_piloto*,char*);
cadastro_piloto incluirPiloto(cadastro_piloto);
cadastro_circuito incluirCircuito(cadastro_circuito);
cadastro_melhor_volta incluirMv(cadastro_melhor_volta);
void voltaRapida(int, cadastro_melhor_volta*, cadastro_circuito*,char*);


int main() {
		setlocale(LC_ALL,"portuguese");
		cadastro_piloto pl[250];
		cadastro_piloto cad_p[250];
		cadastro_circuito cad_c[250];
		cadastro_melhor_volta melhor_v[250];
		int opcao,op;
		char nome_p[400];
		char nome_c[400];
		 setlocale(LC_ALL, "Portuguese");
 		int escolha, i=0;
		 do {
			  system("cls");
		        printf("\n------MENU------\n"
		        "1 - Cadastrar piloto\n"
		        "2 - Cadastrar circuito\n"
		        "3 - Cadastrar melhor volta\n"
		        "4 - Pesquisar\n"
		        "5 - Sair\n");
		        scanf("%d", &opcao);
			  	switch(opcao){
				    case 1:	
				   		cad_p[i]=incluirPiloto(cad_p[i]); 
						fflush(stdin);					
					    i++;
					    break;
					case 2:
						cad_c[i]=incluirCircuito(cad_c[i]);	
						i++;
						break;
				    case 3:
				    	melhor_v[i]=incluirMv(melhor_v[i]);
				     	break; 
				     	i++;
				    case 4:
				    	do{
							
							system("cls");
							printf("1 - Pesquisar os dados atravez da chave única do usuario\n");
							printf("2 - Pesquisar os pilotos registrados pelo nome\n");
							printf("3 - Pesquisar por um circuito específico\n");
							printf("4 - Para sair\n");
							scanf("%d",&op);
							getchar();				
							switch (op){
							    case 1: 
									ConsultaGeral(i,cad_p, cad_c,melhor_v);
							    	break;
							   case 2:
							   		printf("Insira o nome desejado:");
							   		fflush(stdin);
							   		fgets(nome_p,20,stdin);	   
							   		PesquisarPilotos(i,cad_p,nome_p);
							    	break;
							   case 3: 
							   		voltaRapida(i,melhor_v,cad_c,nome_c);
							   break;
							   case 4:
							  		break; 	
							}
				        } while(op!=4);       
				   	case 5:
					   	exit(1);
	            		break;
	       				default:
	            		break;
			 	}
			}while(opcao != 6);
}


cadastro_piloto incluirPiloto (cadastro_piloto cond){
	int pais=0;	 
	printf("\nInsira o Codigo de identificação do Piloto: ");	 
    fflush(stdin);
	scanf("%d", &cond.codPiloto);
		if( !(cond.codPiloto>=100 && cond.codPiloto<=500)) {
		    printf("Valor invalido! \n");
			getchar();	
			getchar();
			return;
		}
	fflush(stdin);
	printf("\nNome do piloto: ");
	fgets(cond.nome_piloto,20,stdin);
	fflush(stdin);
	printf("\nIdade do piloto: ");
	scanf("%d", &cond.idade);
	fflush(stdin);
	printf("\nSexo do pilotof/m: ");
	scanf("%c", &cond.sexo);
	fflush(stdin);
	printf("De qual desses paises voce e?\n");
	printf("1-Brasil\n2-EUA\n3-Alemanha\n4-Japao\n");
	scanf("%d", &pais);
	getchar();
		switch (pais){
			case 1:
			strcpy(cond.pais_origem, "Brasil");
				break;
			case 2:
			strcpy(cond.pais_origem, "EUA");
				break;
			case 3:
			strcpy(cond.pais_origem, "alemanha");
				break;
			case 4:
			strcpy(cond.pais_origem, "Japao");
				break;
		}
 	fflush(stdin);
 return cond;
}

cadastro_circuito incluirCircuito(cadastro_circuito cond){
	int pais=0;
	printf("\nDigite o codigo de identificação do iircuito: \n");
	scanf("%d", &cond.cod_ci);
	fflush(stdin);
	printf("\nNome do circuito: ");
	scanf("%[^\n]s", cond.nome_ci);
	fflush(stdin);	
	printf("De qual desses paises e o circuito?\n");
	printf("1-Brasil\n2-EUA\n3-Alemanha\n4-Japao\n");
	scanf("%d", &pais);
	getchar();
		switch (pais){
			case 1:
			strcpy(cond.pais_ci, "Brasil");
				break;
			case 2:
			strcpy(cond.pais_ci, "EUA");
				break;
			case 3:
			strcpy(cond.pais_ci, "alemanha");
				break;
			case 4:
			strcpy(cond.pais_ci, "Japao");
				break;
		}
 	fflush(stdin);	
	printf("\nTamanho do Circuito em km: ");
	scanf("%f", &cond.tamanho);
	fflush(stdin);
	printf("\nMenor tempo de circuito: ");
	scanf("%lf", &cond.menor_temp);
	fflush(stdin);
	printf("\nIdentificação do piloto que obteve o menor tempo do circuito: ");
	scanf("%i", &cond.idPilotoMenorTemp);
	fflush(stdin);	 
return cond;
}

cadastro_melhor_volta incluirMv (cadastro_melhor_volta cond){
	 printf("\nIdentificação do piloto: ");
	 scanf("%d", &cond.id_piloto.codPiloto);
	 fflush(stdin);
	 printf("\nIdentificação do circuito: ");
	 scanf("%[^\n]s", cond.id_ci.nome_ci);
	 fflush(stdin);
	 printf("\nNome da equipe do piloto: ");
	 fflush(stdin);
	 scanf("%[^\n]s", cond.nome_equi);
	 fflush(stdin);
	 printf("\nData da volta com dia, mes e ano: ");
	 scanf("%i:%i:%i", &cond.dia, &cond.mes, &cond.ano );
	 fflush(stdin);
	 printf("\nTempo da melhor volta em minutos, segundos e milissegundos: ");
	 scanf("%lf", &cond.tem_melhor);
	 fflush(stdin);
	 getchar();
	 getchar();
 return cond;
}

void ConsultaGeral(int tam, cadastro_piloto * pilot, cadastro_circuito * circuit, cadastro_melhor_volta * melhorV) {
	int i;
	for(i=0;i<tam; i++) {
		printf("Identificação do Piloto:%d \n", pilot[i].codPiloto);
		printf("Nome:%s\n", pilot[i].nome_piloto);
		printf("Idade:%d \n", pilot[i].idade);
		printf("Sexo:%c \n", pilot[i].sexo);
		printf("País origem:%s\n", pilot[i].pais_origem);
		printf("Identificação Circuito:%d \n", circuit[i].cod_ci);
		printf("Nome do Circuito:%s\n", circuit[i].nome_ci);
		printf("Nome do país: %s\n", circuit[i].pais_ci);
		printf("Tamanho co Circuito em km: %f\n", circuit[i].tamanho);
		printf("Menor tempo do Circuito:%lf\n", circuit[i].menor_temp);
		printf("Piloto:%i\n", circuit[i].idPilotoMenorTemp);
		printf("\n===== Melhor Volta======== \n");
		printf("Identificação do Piloto:%d", melhorV[i].id_piloto.codPiloto);
		printf("Identificação do Circuito:%s \n", melhorV[i].id_ci.nome_ci);
		printf("Nome da Equipe:%s\n", melhorV[i].nome_equi);
		printf("Data da Volta%i/%i/%i:\n", melhorV[i].dia, melhorV[i].mes, melhorV[i].ano);
		printf("Tempo:%lf\n", melhorV[i].tem_melhor);
	}
}

void PesquisarPilotos (int tam, cadastro_piloto*pilot,char *nome) {
	int i;
	for(i=0;i<tam; i++){
		if(strcmp(nome, pilot[i].nome_piloto) == 0){
			printf("Nome do Piloto:%s \n", pilot[i].nome_piloto);
			printf("Identificação do Piloto:%d \n", pilot[i].codPiloto);
			printf("Idade:%d \n", pilot[i].idade);
			printf("Sexo:%c \n", pilot[i].sexo);
			printf("País origem:%s\n", pilot[i].pais_origem);
			getchar();
		}
	}
}

void voltaRapida(int tam, cadastro_melhor_volta* mv, cadastro_circuito*circ, char *nome_c) {
	int i;	
	for(i=0;i<tam;i++){
		if(strcmp(nome_c, circ[i].nome_ci) == 0){
			 printf("\nIdentificação do piloto:%d", mv[i].id_piloto.codPiloto);
			 printf("\n Identificação do circuito: %s ", mv[i].id_ci.nome_ci);
			 printf("\nNome da equipe do piloto: %s", mv[i].nome_equi);
			 printf("\nData da volta com dia, mes e ano:%i/%i/%i", mv[i].dia, mv[i].mes, mv[i].ano);
			 printf("\nTempo da melhor volta em minutos, segundos e milissegundos:%lf ", mv[i].tem_melhor);
		}
	}
}
	
