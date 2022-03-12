import java.util.ArrayList;
import java.util.Scanner;

public class cores {
    public static void main(String[] args)
    {
        ArrayList<String> item = new ArrayList<String>();
        
        item.add("Vermelho"); // add na lista
        item.add(0, "Amarelo"); // add a cor na posicao zero

        int count;

        for(count = 0; count < item.size(); count++)
        {
            System.out.printf(" %s ", item.get(count));
        }

        String novacor;
        Scanner input = new Scanner(System.in);

        System.out.println("\nAdicione uma cor: ");
        novacor = input.nextLine();
        item.add(novacor);

        for(count = 0; count < item.size(); count++)
        {
            System.out.printf(" %s ", item.get(count));
        }

        item.remove(0); //remove pela posicao
        item.remove("Verde");  //remove pelo nome

        System.out.println();
        for(count = 0; count < item.size(); count++)
        {
            System.out.printf(" %s ", item.get(count));
        }

        boolean contem = item.contains("Vermelho");

        if( contem == true)
            System.out.printf("\n Contem vermelho");


        input.close();
    }
}
