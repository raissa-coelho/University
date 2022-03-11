import java.util.*;

public class diceR 
{
    public static void main(String[] args)
    {
        Random numero = new Random();

        int frequencia1 = 0;
        int frequencia2 = 0;
        int frequencia3 = 0;
        int frequencia4 = 0;
        int frequencia5 = 0;
        int frequencia6 = 0;

        int face;

        for(int roll = 1; roll <= 6000; roll++)
        {
            face = 1 + numero.nextInt(6);

            switch(face)
            {
                case 1:
                    ++frequencia1;
                    break;
                case 2:
                    ++frequencia2;
                    break;
                case 3:
                    ++frequencia3;
                    break;
                case 4:
                    ++frequencia4;
                    break;
                case 5:
                    ++frequencia5;
                    break;
                case 6:
                    ++frequencia6;
                    break;
            }
        }

        System.out.println("Face\tFrequencia");
        System.out.printf("1\t%d\n2\t%d\n3\t%d\n4\t%d\n5\t%d\n6\t%d\n", 
        frequencia1, frequencia2, frequencia3, frequencia4, frequencia5, frequencia6);
    }    
}
