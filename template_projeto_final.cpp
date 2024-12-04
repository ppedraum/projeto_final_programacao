#include <iostream>
#include <vector>

using namespace std;

// Pedro
class ItemBiblioteca {
protected:
    int id_, ano_;
    string titulo_;
    bool emprestado_ = false;

public:
    ItemBiblioteca(int id, string titulo, int ano) {
        id_ = id;
        titulo_ = titulo;
        ano_ = ano;
    };

    virtual void exibirDetalhes() {
        cout << "ID: " << id_ << endl;
        cout << "Titulo: " << titulo_ << endl;
        cout << "Ano: " << ano_ << endl;
        cout << "Emprestado: " << emprestado_ << endl;
    }
    int getId() {
        return id_;
    }
    bool isEmprestado() {
        return emprestado_;
    }
    void emprestar() {
        emprestado_ = true;
    }
    void devolver() {
        emprestado_ = false;
    }
};

class Livro : public ItemBiblioteca {
protected:
    string autor_;
    string genero_;

public:
    Livro(int id, string titulo, int ano, string autor, string genero) :
        ItemBiblioteca(id, titulo, ano), autor_(autor), genero_(genero) {};
    void exibirDetalhes() override {
        cout << "ID: " << id_ << endl;
        cout << "Titulo: " << titulo_ << endl;
        cout << "Ano: " << ano_ << endl;
        cout << "Autor: " << autor_ << endl;
        cout << "Genero: " << genero_ << endl;
        cout << "Emprestado: " << emprestado_ << endl;
    };

    string getTitulo() {
        return titulo_;
    }
};

// Rafael oi
class Usuario {
protected:
    int id_, limiteEmprestimos_, emprestimosAtuais_ = 0;
    string nome_;

public:
    Usuario(int id, string nome, int limiteEmprestimos) :
        id_(id), nome_(nome), limiteEmprestimos_(limiteEmprestimos) {};


    virtual void exibirUsuario() {
        cout << "ID: " << id_ << endl;
        cout << "Nome: " << nome_ << endl;
        cout << "Limite de emprestimos: " << limiteEmprestimos_ << endl;
        cout << "Emprestimos atuais: " << emprestimosAtuais_ << endl;
    };

    bool podeEmprestar() {
        if (emprestimosAtuais_ < limiteEmprestimos_) {
            return true;
        }
        return false;
    };
    void realizarEmprestimo(Livro livro) {
        if (podeEmprestar()) {
            livro.emprestar();
            emprestimosAtuais_ += 1;
        }
    };
    void realizarDevolucao(Livro livro) {
        if (emprestimosAtuais_ != 0) {
            livro.devolver();
            emprestimosAtuais_ -= 1;
        }

    };

    string getNome() {
        return nome_;
    }

    int getId() {
        return id_;
    };
};

class Aluno : public Usuario {
public:
    Aluno(int id, string nome) :
        Usuario(id, nome, limiteEmprestimos_ = 3) {};

    void exibirUsuario() override {
        cout << "ID: " << id_ << endl;
        cout << "Nome: " << nome_ << endl;
        cout << "Limite de emprestimos: " << limiteEmprestimos_ << endl;
        cout << "Emprestimos atuais: " << emprestimosAtuais_ << endl;
    };
};

class Professor : public Usuario {
public:
    Professor(int id, string nome) :
        Usuario(id, nome, limiteEmprestimos_ = 5) {};

    void exibirUsuario() override {
        cout << "ID: " << id_ << endl;
        cout << "Nome: " << nome_ << endl;
        cout << "Limite de emprestimos: " << limiteEmprestimos_ << endl;
        cout << "Emprestimos atuais: " << emprestimosAtuais_ << endl;
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
    void adicionarLivro() {
        int id, ano;
        string titulo, autor, genero;

        cout << "Digite o ID do livro: ";
        cin >> id;

        cout << "Digite o Titulo do livro: ";
        cin >> titulo;

        cout << "Digite o ano do livro: ";
        cin >> ano;

        cout << "Digite o autor do livro: ";
        cin >> autor;

        cout << "Digite o genero do livro: ";
        cin >> genero;

        livros_.push_back(Livro(id, titulo, ano, autor, genero));
    };
    //Pedro
    void listarLivros() {
        cout << "-------------------------" << endl;
        cout << "LIVROS" << endl;
        for (int i = 0; i < livros_.size(); i++) {
            cout << "-------------------------" << endl;
            livros_[i].exibirDetalhes();

        }
    };
    void adicionarUsuario() {
        int opcao, id;
        string nome;
        do {
            cout << "-------------------------" << endl;
            cout << "1. Adicionar professor" << endl;
            cout << "2. Adicionar aluno" << endl;
            cout << "0. Voltar" << endl;
            cout << endl;
            cout << "Digite: " << endl;
            cin >> opcao;
            cout << "-------------------------" << endl;

            switch (opcao) {
            case 1:
                cout << "Digite o ID do professor: ";
                cin >> id;

                cout << "Digite o nome do professor: ";
                cin >> nome;
                professores_.push_back(Professor(id, nome));

                cout << "Professor cadastrado com sucesso! " << endl;
                break;

            case 2:
                cout << "Digite o ID do aluno: ";
                cin >> id;

                cout << "Digite o nome do aluno: ";
                cin >> nome;
                alunos_.push_back(Aluno(id, nome));

                cout << "Aluno cadastrado com sucesso! " << endl;
                break;

            case 0:
                cout << "Voltando..." << endl;
                break;

            default:
                cout << "Por favor digite uma das opcoes!" << endl;
            }
        } while (opcao != 0);

    };

    void listarUsuarios() {
        cout << "-------------------------" << endl;
        cout << "Professores: " << endl;
        cout << "-------------------------" << endl;

        for (int i = 0; i < professores_.size(); i++) {
            professores_[i].exibirUsuario();
            cout << endl;
        }
        cout << "-------------------------" << endl;
        cout << endl;
        cout << "-------------------------" << endl;
        cout << "Alunos: " << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < alunos_.size(); i++) {
            alunos_[i].exibirUsuario();
            cout << endl;
        }
    };
    //Pedro
    void emprestarLivro() {
        int idxLivro, idxUsuario, opcao;

        if (livros_.size() == 0) {
            cout << "Por favor adicione um livro antes de emprestar!" << endl;
            return;
        }

        if (alunos_.size() == 0  && professores_.size() == 0) {
            cout << "Por favor adicione um usuario antes de emprestar!" << endl;
            return;
        }

        do {

            cout << "-------------------------" << endl;
            cout << "Digite o Index do livro a ser emprestado:" << endl;

            for (int i = 1; i <= livros_.size(); i++) {
                cout << i << ". " << livros_[i - 1].getTitulo() << endl;
            }

            cin >> idxLivro;
            idxLivro--;

            if(idxLivro < 0 || idxLivro >= livros_.size()) {
                cout << "Digite um dos indexes listados." << endl;
                idxLivro = -1;
            }
        } while (idxLivro == -1);

        do {

            cout << "-------------------------" << endl;
            cout << "Digite qual usuario irá emprestar o livro" << endl;
            cout << "1. Aluno" << endl;
            cout << "2. Professor" << endl;

            cin >> opcao;
            
            if (opcao == 1) {
                cout << "Digite qual aluno irá emprestar o livro" << endl;
                for (int i = 1; i <= alunos_.size(); i++) {
                    cout << i << ". " << alunos_[i - 1].getNome() << endl;
                }

                cin >> idxUsuario;
                idxUsuario--;

                if (idxUsuario < 0 || idxUsuario >= alunos_.size()) {
                    cout << "Digite um dos indexes listados." << endl;
                    idxUsuario = -1;
                }

            }
            else {
                cout << "Digite qual professor irá emprestar o livro" << endl;
                for (int i = 1; i <= professores_.size(); i++) {
                    cout << i << ". " << professores_[i - 1].getNome() << endl;
                }

                cin >> idxUsuario;
                idxUsuario--;

                if (idxUsuario < 0 || idxUsuario >= professores_.size()) {
                    cout << "Digite um dos indexes listados." << endl;
                    idxUsuario = -1;
                }
            }

        } while (idxUsuario == -1);

        if (opcao == 1) {
            alunos_[idxUsuario].realizarEmprestimo(livros_[idxLivro]);
        }
        else {
            professores_[idxUsuario].realizarEmprestimo(livros_[idxLivro]);
        }
    };
    void devolverLivro() {
        int idxLivro, idxUsuario, opcao;

        if (livros_.size() == 0) {
            cout << "Por favor adicione um livro antes de devolver!" << endl;
            return;
        }

        if (alunos_.size() == 0 && professores_.size() == 0) {
            cout << "Por favor adicione um usuario antes de devolver!" << endl;
            return;
        }

        do {

            cout << "-------------------------" << endl;
            cout << "Digite o Index do livro a ser devolvido:" << endl;

            for (int i = 1; i <= livros_.size(); i++) {
                cout << i << ". " << livros_[i - 1].getTitulo() << endl;
            }

            cin >> idxLivro;
            idxLivro--;

            if (idxLivro < 0 || idxLivro >= livros_.size()) {
                cout << "Digite um dos indexes listados." << endl;
                idxLivro = -1;
            }
        } while (idxLivro == -1);

        do {

            cout << "-------------------------" << endl;
            cout << "Digite qual usuario irá devolver o livro" << endl;
            cout << "1. Aluno" << endl;
            cout << "2. Professor" << endl;

            cin >> opcao;

            if (opcao == 1) {
                cout << "Digite qual aluno irá devolver o livro" << endl;
                for (int i = 1; i <= alunos_.size(); i++) {
                    cout << i << ". " << alunos_[i - 1].getNome() << endl;
                }

                cin >> idxUsuario;
                idxUsuario--;

                if (idxUsuario < 0 || idxUsuario >= alunos_.size()) {
                    cout << "Digite um dos indexes listados." << endl;
                    idxUsuario = -1;
                }

            }
            else {
                cout << "Digite qual professor irá devolver o livro" << endl;
                for (int i = 1; i <= professores_.size(); i++) {
                    cout << i << ". " << professores_[i - 1].getNome() << endl;
                }

                cin >> idxUsuario;
                idxUsuario--;

                if (idxUsuario < 0 || idxUsuario >= alunos_.size()) {
                    cout << "Digite um dos indexes listados." << endl;
                    idxUsuario = -1;
                }
            }

        } while (idxUsuario == -1);

        if (opcao == 1) {
            alunos_[idxUsuario].realizarDevolucao(livros_[idxLivro]);
        }
        else {
            professores_[idxUsuario].realizarDevolucao(livros_[idxLivro]);
        }
    }
    void menu() {
        int opcao;

        cout << "-------BEM VINDO!--------" << endl;
        cout << "GESTOR DE BIBLIOTECAS 2000" << endl;
        cout << "Versao 1.0" << endl;
        cout << endl;

        do {
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

            switch (opcao) {
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
                emprestarLivro();
                break;
            case 6:
                devolverLivro();
                break;
            case 0:
                cout << "Saindo do sistema..." << endl;
                break;
            default:
                cout << "Por favor digite uma das opcoes!" << endl;
            }
        } while (opcao != 0);
    };
};

//Deletar os testes

int main() {

    Biblioteca bib;

    bib.menu();


    return 0;
}

