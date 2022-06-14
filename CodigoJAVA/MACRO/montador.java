package MACRO;

import java.util.*;
import java.io.File;
import java.util.Scanner;

public class montador {
    private HashMap<String,Integer> table;
    private List<String> operador;
    private List<String> rotulo;
    private int contLine = 0;
    private int contMemory;

    public void Montador(String fileNameInput, String fileNameOutput){
        table = new HashMap<String,Integer>();
        operador = new ArrayList<String>();
        rotulo = new ArrayList<String>();

        File entrada = new File(fileNameInput);
        File saida = new File(fileNameOutput);

        try{
            Scanner leitura = new Scanner(entrada);

            while(leitura.hasNextLine()){
                String line = leitura.nextLine();
                System.out.println(line);
                
                String[] token = line.split(" ");

                if(token.length == 2){

                    operador.add(token[0]);
                    table.put(token[1],0);

                    contMemory = contMemory+2;
               
                }else if (token.length == 3){
               
                    rotulo.add(token[0]);
                    operador.add(token[1]);
                    table.put(token[2],0);

                    contMemory = contMemory+3;
               
                }else if(token.length == 4){

                    rotulo.add(token[0]);
                    operador.add(token[1]);
                    table.put(token[2],0);
                    table.put(token[3],0);
                    
                    contMemory = contMemory+4;
               
                }

                contLine++;
            }

            System.out.println(table);
            System.out.println(operador);
            System.out.println(rotulo);
            System.out.println(contLine);
            System.out.println(contMemory);
            leitura.close();

        }catch(Exception e){
            System.out.println("ERRO.");
        }

    }
}
