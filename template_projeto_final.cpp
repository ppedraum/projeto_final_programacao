#include <iostream>
#include <vector>

using namespace std;

// Pedro
class ItemBiblioteca {
protected:
    int id_, ano_;
    string titulo_;
    bool emprestado_;

public:
	ItemBiblioteca(int id, string titulo, int ano){
		id_ = id;
		titulo_ = titulo;
		ano_ = ano;
		emprestado_ = false;
	};
	
    virtual void exibirDetalhes(){
    	cout << "ID: " << id_ << endl;
    	cout << "Titulo: " << titulo_ << endl;
    	cout << "Ano: " << ano_ << endl;
	}
    int getId(){
    	return id_;
	}
    bool isEmprestado(){
    	return emprestado_;
	}
    void emprestar();
    void devolver();
};

class Livro : public ItemBiblioteca {
protected:
	string autor_;
	string genero_;
	
public:
    Livro(int id, string titulo, int ano, string autor, string genero):
	ItemBiblioteca(id,titulo,ano), autor_(autor), genero_(genero){};      
    void exibirDetalhes() override{
		cout << "ID: " << id_ << endl;
    	cout << "Titulo: " << titulo_ << endl;
    	cout << "Ano: " << ano_ << endl;
    	cout << "Autor: " << autor_ << endl;
    	cout << "Genero: " << genero_ << endl;
	};
};

// Rafael oi
class Usuario {
protected:
    int id_, limiteEmprestimos_, emprestimosAtuais_=0;
    string nome_;

public:
    Usuario(int id, string nome, int limiteEmprestimos):
	id_(id), nome_(nome), limiteEmprestimos_(limiteEmprestimos){};
    
    Usuario(int id, string nome):
	id_(id), nome_(nome){};
	

    virtual void exibirUsuario(){
    	cout << "ID: " << id_ << endl;
    	cout << "Nome: " << nome_ << endl;
    	cout << "Limite de empréstimos: " << limiteEmprestimos_ << endl;
	};

    bool podeEmprestar(){
    	if (limiteEmprestimos_ > 0 && getId() == id_){
    		return true;
		}
	};
    void realizarEmprestimo(){
    	if (podeEmprestar()==true ){
    		limiteEmprestimos_ -=1;
    		emprestimosAtuais_ +=1;
		}
	};
    void realizarDevolucao(){
    	if (emprestimosAtuais_ !=0){
    		limiteEmprestimos_ +=1;
		}
    	
	};
	
    int getId(){
    	return id_;
	};
};

class Aluno : public Usuario {
public:
    Aluno(int id, string nome):
	Usuario(id, nome,limiteEmprestimos_=4){};
	
	void exibirUsuario() override {
		cout << "ID: " << id_ << endl;
    	cout << "Nome: " << nome_ << endl;
    	cout << "Limite de emprestimos: " << limiteEmprestimos_ << endl;
	};
};

class Professor : public Usuario {
public:
    Professor(int id, string nome):
	Usuario(id, nome, limiteEmprestimos_=5){};
	
	void exibirUsuario() override {
		cout << "ID: " << id_ << endl;
    	cout << "Nome: " << nome_ << endl;
    	cout << "Limite de emprestimos: " << limiteEmprestimos_ << endl;
	};
};

// Todo
class Biblioteca {
	private:
    	vector<Livro> livros_;
    	vector<Aluno> alunos_;
    	vector<Professor> professores_;

public:
	//Pedro
    void adicionarLivro(){
    	int id, ano;
    	string titulo, autor, genero;
    	
    	cout << "Digite o ID do livro: ";
		cin  >> id;    	
		
		cout << "Digite o Titulo do livro: ";
		cin  >> titulo;
		
		cout << "Digite o ano do livro: ";
		cin  >> ano;
		
		cout << "Digite o autor do livro: ";
		cin  >> autor;
		
		cout << "Digite o genero do livro: ";
		cin  >> genero;
		
    	livros_.push_back(Livro(id,titulo,ano,autor,genero));
	};
    //Pedro
    void listarLivros(){
    	cout << "-------------------------" << endl;
    	cout << "LIVROS" << endl;
    	for(int i = 0; i < livros_.size(); i++){
    		cout << "-------------------------" << endl;
    		livros_[i].exibirDetalhes();
    		
		}	
	};
    void adicionarUsuario(){
    	int opcao, id;
    	string nome;
    	do {
    		cout << "-------------------------" << endl;
    		cout << "1. Adicionar professor"    << endl;
    		cout << "2. Adicionar aluno"    << endl;
    		cout << "0. Voltar"    << endl;
    		cout << endl;
			cout << "Digite: "    << endl;
			cin >> opcao; 
			cout << "-------------------------" << endl;
    	
    	switch (opcao){
    		case 1 :
    			cout << "Digite o ID do professor: ";
				cin  >> id;    	
		
				cout << "Digite o nome do professor: ";
				cin  >> nome;
				professores_.push_back(Professor(id, nome));
		
				cout << "Professor cadastrado com sucesso! " << endl;
				break;
			
			case 2:
				cout << "Digite o ID do aluno: ";
				cin  >> id;    	
		
				cout << "Digite o nome do aluno: ";
				cin  >> nome;
				alunos_.push_back(Aluno(id, nome));
		
				cout << "Aluno cadastrado com sucesso! " << endl;
				break;
				
			case 0:
				cout << "Voltando..." << endl;
				break;
				
			default:
    			cout << "Por favor digite uma das opcoes!" << endl;
		}
	}
			while(opcao !=0);
		
	};
	
    void listarUsuarios(){
    		cout << "-------------------------" << endl;
    		cout << "Professores: " << endl;
    		cout << "-------------------------" << endl;
    	
    	for (int i = 0; i < professores_.size(); i++){
    		professores_[i].exibirUsuario();
    		cout << endl;
		}
    		cout << "-------------------------" << endl;
    		cout << endl;
    		cout << "-------------------------" << endl;
    		cout << "Alunos: " << endl;
    		cout << "-------------------------" << endl;
    	for (int i = 0; i < alunos_.size(); i++){
    		alunos_[i].exibirUsuario();
    		cout << endl;
		}
	};
    //Pedro
    void emprestarLivro(){
    	
	};
    void devolverLivro();
    //Pedro
    void menu(){
    	int opcao;
		
		cout << "-------BEM VINDO!--------" << endl;
    	cout << "GESTOR DE BIBLIOTECAS 2000" << endl;
    	cout << "Versao 1.0" << endl;
    	cout << endl;
    	
    	do{
    		cout << "-------------------------" << endl;
    		cout << "Digite a opcao desejada:" << endl;
    		cout << "1. Adicionar livro" << endl;
    		cout << "2. Listar livros" << endl;
    		cout << "3. Adicionar usuario" << endl;
    		cout << "4. Listar usuarios" << endl;
    		cout << "5. Emprestar livro" << endl;
    		cout << "6. Devolver livro" << endl;
    		cout << "0. Sair" << endl;
    		cout << endl;
    		cout << "Digite: ";
    		cin >> opcao;
    		
    		switch(opcao){
    			case 1:
    				adicionarLivro();
    				break;
    			case 2:
    				listarLivros();
    				break;
    			case 3:
    				adicionarUsuario();
    				break;
    			case 4:
    				listarUsuarios();
    				break;
    			case 5:
    				break;
    			case 6:
    				break;
    			case 0:
    				cout << "Saindo do sistema..." << endl;
    				break;
    			default:
    				cout << "Por favor digite uma das opcoes!" << endl;
			}
		}
		while(opcao != 0);
	};
};

//Deletar os testes

int main() {
	
	Biblioteca bib;
	
	bib.menu();
	
    return 0;
}

