package MACRO;

import java.util.ArrayList;
import java.util.List;
import java.io.File;
import java.util.Scanner;

public class processador{
    private macro[] marcoList; //lista de macros do código assembly
    private String[] parametros;
    private List<String> resultado = new ArrayList<>(); //Lista de strings do código objeto

    int modeDEF = 0; //modo de definição/contagem de nível
    boolean modeEXT = false; //modo de extensão

    public void processaMacro(){

        File entrada = new File("arquivo_entrada.asm");
        File saida = new File("arquivo_saida.asm");

      try{ 

        Scanner leitura = new Scanner(entrada);

        while(leitura.hasNextLine()){
            String line = leitura.nextLine();
                while(line != ""){
                    //resto do codigo aqui
                }
        } 

        leitura.close();

        } catch(Exception e){
            System.out.println("\\ERRO//");
        }
    }
}
