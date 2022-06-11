/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistemacondominio;

/**
 *
 * @author raiss
 */
public class Condomino extends Pessoa{
    
    Condomino(String nome, String telefone, String cpf){
        super(nome,telefone,cpf);
    }
    
    @Override
    public byte nivelDeAcesso(){
        return 1;
    }
    
    @Override
    public String toString(){
        return super.toString();
    }
}
