/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistemacondominio;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author raiss
 */
public class Condominio {
    private String nomeCondominio;
    private Pessoa administrador;
    private List<Unidade> unidades;
    private List<Visitante> visitantes;
    private List<RegistrodeVisitante> registroDeVisitante;
    
    Condominio(String nomeCondominio, Pessoa administradora){
        this.nomeCondominio = nomeCondominio;
        unidades = new ArrayList<>();
        Pessoa nova = new Administrador(administradora.getNome(), administradora.getTelefone(), administradora.getCPF());
        this.administrador = nova;
        visitantes = new ArrayList<>();
        registroDeVisitante = new ArrayList<>();
    }
    
    public boolean salvou(Pessoa administrador){
        if(administrador != null){
            return true;
        }else{
            return false;
        }
    }
    
    public boolean encontraVisitante(String cpf){
        if(visitantes == null){
            return false;
        }
        for(Visitante k: visitantes){
            if(k.getCPF().equals(cpf)){
                return true;
            }
        }
        return false;
    }
    
    public boolean encontraAdmin(String cpf){
        if(administrador.getCPF().equals(cpf)){
            return true;
        }
        return false;
    }
    
    public boolean encontraMorador(String cpf){
        for(Unidade uni: unidades){
            if(uni.getMoradoresCPF(cpf)){
                return true;
            }
        }
        return false;
    }
    
    public boolean incluirUnidade(Unidade u){
        for(Unidade uni: unidades){
            if(uni.getUnidade() == u.getUnidade()){
                return false;
            }
        }
        unidades.add(u);
        return true;
    }
    
    public List<Unidade> excluirUnidade(short numero){
        for(Unidade k: unidades){
           if(k.getUnidade() == numero){
               unidades.remove(k);
            return unidades;
           }
        }
        return unidades;
    }
    
    public boolean incluirVisitante(Pessoa p){
        for(Visitante k: visitantes){
            if(k.getCPF().equals(p.getCPF())){
                return false;
            }
        }
        Visitante novo = new Visitante(p.getNome(), p.getTelefone(), p.getCPF());
        visitantes.add(novo);
        return true;
    }
    
    public List<Visitante> excluirVisitante(String cpf){
        for(Visitante k: visitantes){
           if(k.getCPF().equals(cpf)){
               visitantes.remove(k);
                return visitantes;
           }
        }
        return visitantes;
    }
    
    public boolean registrarVisitante(Pessoa autorizou, Pessoa visitante, Unidade unidade, Data entrada, Data saida){
        for(RegistrodeVisitante k: registroDeVisitante){
             if(k.getCpfVisitante() == visitante.getCPF()){
                 return false;
             }
         }
         registroDeVisitante.add(new RegistrodeVisitante(autorizou, visitante, unidade, entrada, saida));
         return true;
    }
    
   
    public Visitante getVisitante(String cpf){
        for(Visitante k: visitantes){
           if(k.getCPF().equals(cpf)){
                return k;
           }
        }
        return null;
    }
    
    public Pessoa getPessoa(String cpf, byte nivel){
        if(nivel == 1){
            for(Unidade k: unidades){
                if(k.getMorador(cpf) != null){
                    return k.getMorador(cpf);
                }
            }
        }else if(nivel == 2){
            return this.administrador;
        }
        return null;
    }
    
    public Unidade getUnidades(short num){
        for(Unidade k: unidades){
            if(k.getUnidade() == num){
                return k;
            }
        }
        return null;
    }
    
    public void gravaRegistro(File registro) throws IOException{
        FileWriter file = new FileWriter(registro);
        for(RegistrodeVisitante k: registroDeVisitante){
                file.write(k.toString());
        }
        file.close();
    }
    
    //TESTE DAS UNIDADES E ETC PRINTS DELAS PRA VER SE ESTAO FUNCIOANDO
    public void pritnUni(){
        for(Unidade k: unidades){
            System.out.println(k.toString());
        }
    }
    
    public void printV(){
        for(Visitante k: visitantes){
            System.out.println(k);
        }
    }
    
    public void printRegistro(){
        for(RegistrodeVisitante k: registroDeVisitante){
            System.out.println(k.toString());
        }
    }
    
    @Override
    public String toString(){
        return "Condominio: " + this.nomeCondominio + "Admin: " + this.administrador.toString();
    }
    
}
