#include "funcoes.h"

char menu () {	
	char escolha = ' ';
	std::cout << "\n==============================";
	std::cout << "\n=======PROJETO FINAL==========";
	std::cout << "\n======POR CARLOS MELO========";
	std::cout << "\n==SELECIONE UMA OPCAO ABAIXO==";
	std::cout << "\n=========DIGITE A LETRA=======";
	std::cout << "\n==========C - CADASTRAR ALUNO===========";
	std::cout << "\n==========R - RELATORIO===========";
	std::cout << "\n==========F - FINALIZA========\n";
	std::cin >> escolha;
	system("cls");
	return escolha;
}

bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.csv", std::fstream::app);
	
	
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	arquivo << aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
	
	arquivo.close();
	return true;
}


bool realizaLeituraArquivo () {
	std::ifstream arquivo;
	arquivo.open("database.csv");
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	std::string linha;
	int indexAluno = 0;
	while (std::getline(arquivo, linha)) {
//		std::cout << linha << "\n"; string == array char
		int coluna = 0;
		int controleColuna = 0;
		std::string conteudo = "";
		for (int i = 0; i < linha.size(); i++) {
			if (coluna == 1 && controleColuna == 0)  {
				alunos[indexAluno].nome = conteudo;	
				conteudo = "";
				controleColuna = 1;
			} else if (coluna == 2 && controleColuna == 1) {
				alunos[indexAluno].matricula = conteudo;	
				conteudo = "";
				controleColuna = 2;
			} else if  (coluna ==3 && controleColuna == 2) {
				alunos[indexAluno].aep1;
				conteudo = "";
				controleColuna = 3;	
			} else if (coluna ==4 && controleColuna == 3) {
				alunos[indexAluno].prova1;
				conteudo = "";
				controleColuna = 4;	
			} else if (coluna ==5 && controleColuna == 4) {
				alunos[indexAluno].aep2;	
				conteudo = "";
				controleColuna = 5;	
			} else if (coluna ==6 && controleColuna == 5) {
				alunos[indexAluno].prova2;
				conteudo = "";
				controleColuna = 6;	
			} else if (coluna ==7 && controleColuna == 6) {
				alunos[indexAluno].media;
				conteudo = "";
				controleColuna = 7;	
			} else if (coluna ==8 && controleColuna ==7) {
				alunos[indexAluno].status;	
				conteudo = "";
				controleColuna = 8;	
			}
			if (linha[i] == ';') {
				coluna++;				
				continue;
			}
			conteudo.push_back(linha[i]);					
		}
		indexAluno++;
	}
	arquivo.close();
	
	// teste
	for (int i = 0; i < 100; i++) {
		std::cout << "Aluno n " << i+1 << "\n";
		std::cout << "Nome: " << alunos[i].nome << "\n";
		std::cout << "Matricula: " << alunos[i].matricula << "\n";
		std::cout << "AEP 1: " << alunos[i].aep1 << "\n";
		std::cout << "Prova 1 " << alunos[i].prova1 << "\n";
		std::cout << "AEP 2: " << alunos[i].aep2 << "\n";
		std::cout << "Prova 2 " << alunos[i].prova2 << "\n";
		std::cout << "Media: " << alunos[i].media << "\n";
		std::cout << "Status: " << alunos[i].status << "\n";
		
	}
	
	return true;
}

void cadastro () {
	Aluno cadastroAluno;
	std::cout << "Digite o nome do Aluno \n";
	std::cin >> cadastroAluno.nome;
	std::cout << "Digite a matricula do Aluno \n";
	std::cin >> cadastroAluno.matricula;
	std::cout << "Digite a nota da AEP 1 \n";
	std::cin >> cadastroAluno.aep1;
	std::cout << "Digite a nota da prova 1 \n";
	std::cin >> cadastroAluno.prova1;
	std::cout << "Digite a nota da AEP 2 \n";
	std::cin >> cadastroAluno.aep2;
	std::cout << "Digite a nota da prova 2 \n";
	std::cin >> cadastroAluno.prova2;
	
	cadastroAluno.media = (cadastroAluno.aep1 + cadastroAluno.prova1 + cadastroAluno.aep2 + cadastroAluno.prova2)/2;
	if (cadastroAluno.media >= 6){
		cadastroAluno.status = "Aprovado";
		cadastroAluno.sub = 0;		
 	}else {
 		std::cout << "Aluno Reprovado \n";
 		cadastroAluno.status = "Reprovado";
 		std::cout << "Digite a nota da prova substitutiva \n";
		std::cin >> cadastroAluno.sub;	
	 }	 
	 
	 if (cadastraAluno (cadastroAluno)) {
		std::cout <<"O aluno " << cadastroAluno.nome << " foi cadastrado com sucesso\n";
	} else {
		std::cout << "Erro ao cadastrar \n" << cadastroAluno.nome;
	}
}
