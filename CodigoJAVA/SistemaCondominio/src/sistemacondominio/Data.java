/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistemacondominio;

/**
 *
 * @author raiss
 */
public class Data {
    private byte dia;
    private byte mes;
    private short ano;
    
    Data(byte dia, byte mes, short ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }
    
    @Override
    public String toString(){
        return " " + this.dia + " " + this.mes + " " + this.ano;
    }
    
    
}
