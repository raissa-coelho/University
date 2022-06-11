/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistemacondominio;

/**
 *
 * @author raiss
 */
abstract class Pessoa {
    private String nome;
    private String telefone;
    private String cpf;
    
    Pessoa(String nome, String telefone, String cpf){
        this.nome = nome;
        this.cpf = cpf;
        this.telefone = telefone;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public String getCPF(){
        return this.cpf;
    }
    
    public String getTelefone(){
        return this.telefone;
    }
    
    public abstract byte nivelDeAcesso();
    
    @Override
    public String toString(){
        return "\nNome:" + this.nome + "\nCpf:" + 
                this.cpf + "\nTelefone:" + this.telefone + "\n";
    }
}
