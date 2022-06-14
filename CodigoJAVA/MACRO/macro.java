package MACRO;

import java.util.ArrayList;
import java.util.List;

public class macro {
    public String chamada; // chamada da macro
    public List<String> def = new ArrayList<>(); //definição da macro
    public List<String> args = new ArrayList<>(); // argumentos da macro
    public List<String> labels = new ArrayList<>(); // labels da macro
    public int Nível; //qual o nivel da macro

    public void print(){
        System.out.println(chamada);
        System.out.println(def);
        System.out.println(args);
        System.out.println(labels);
    }

}
