/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistemacondominio;

/**
 *
 * @author raiss
 */
public class Administrador extends Pessoa{
    
    Administrador(String nome, String telefone, String cpf){
        super(nome,telefone,cpf);
    }
    
    @Override
    public byte nivelDeAcesso(){
        return 2;
    }
    
    @Override
    public String toString(){
        return super.toString();
    }
    
}
