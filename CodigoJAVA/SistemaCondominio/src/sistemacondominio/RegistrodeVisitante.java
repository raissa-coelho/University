/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistemacondominio;

/**
 *
 * @author raiss
 */
public class RegistrodeVisitante{
    private Pessoa quemAutorizou;
    private Pessoa visitante;
    private Unidade unidade;
    private Data dataDeEntrada;
    private Data dataDeSaida;
    
    RegistrodeVisitante(Pessoa a, Pessoa visitante, Unidade u, Data entrada, Data saida){
        this.quemAutorizou = a;
        this.unidade = u;
        this.visitante = visitante;
        this.dataDeEntrada = entrada;
        this.dataDeSaida = saida;
    }
    
    public String getCpfVisitante(){
        return this.visitante.getCPF();
    }
    
    @Override
    public String toString(){
        return this.quemAutorizou.getNome() + " " + this.quemAutorizou.getCPF() + " " + 
                this.visitante.getNome() + " " +  this.visitante.getCPF() +  " " + 
                this.dataDeEntrada.toString() + " " + this.dataDeSaida.toString();
    }
}
