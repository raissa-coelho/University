/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistemacondominio;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author raiss
 */
public class Unidade{
    private short numeroDaUnidade;
    private List<Condomino> moradores;

    Unidade(short numero){
        this.numeroDaUnidade = numero;
        moradores = new ArrayList<>();
    }
    
    public boolean incluirMorador(Pessoa morador){
        
        for(Condomino cdm: moradores){
            if(cdm.getCPF().equals(morador.getCPF())){
                return false;
            }
        }
        Condomino novo = new Condomino(morador.getNome(), morador.getTelefone(), morador.getCPF());
        moradores.add(novo);
        return true;
    }
 
    public List<Condomino> excluirMorador(String cpf){
        for(Condomino cdm: moradores){
            if(cdm.getCPF().contentEquals(cpf)){
                moradores.remove(cdm);
                return moradores;
            }
        }
        return moradores;
    }
    
    public void setUnidade(short numeroUnidade){
        this.numeroDaUnidade = numeroUnidade;
    }
    
    public short getUnidade(){
        return this.numeroDaUnidade;
    }
    
    public boolean getMoradoresCPF(String cpf){
        for(Condomino k: moradores){
            if(k.getCPF().equals(cpf)){
                return true;
            }
        }
        return false;
    }
    
    public Condomino getMorador(String cpf){
        for(Condomino k: moradores){
            if(k.getCPF().equals(cpf)){
                return k;
            }
        }
        return null;
    }
    
    @Override
    public String toString(){
        return "Unidade: " + this.numeroDaUnidade + this.moradores.toString();
    }
    
}
