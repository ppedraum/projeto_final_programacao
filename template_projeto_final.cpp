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

// Rafael
class Usuario {
protected:
    int id, limiteEmprestimos, emprestimosAtuais;
    string nome;

public:
    Usuario(int id, string nome, int limiteEmprestimos);
        
    virtual void exibirUsuario(){
	};

    bool podeEmprestar();
    void realizarEmprestimo();
    void realizarDevolucao();
    int getId();
};

class Aluno : public Usuario {
public:
    Aluno(int id, string nome);
};

class Professor : public Usuario {
public:
    Professor(int id, string nome);
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
    void adicionarUsuario();
    void listarUsuarios();
    //Pedro
    void emprestarLivro();
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
    				break;
    			case 4:
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

