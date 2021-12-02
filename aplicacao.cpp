#include "funcoes.cpp"

int main () {
	char opcao = ' ';
	do {
	   opcao = menu();	
	   switch (opcao) {
	   		case 'C':
	   			cadastro();
	   		break;
	   		case 'R':
	   			realizaLeituraArquivo();
	   		break;
	   		case 'F':
	   			std::cout << "Finalizando aplicacao...\n";
	   		break;
	   		// demais funcoes deverão ser chamadas aqui
	   		default:
	   			std::cout << "Opcao invalida\n Tente Novamente!\n";
	   }
	} while(opcao != 'F');	
}
