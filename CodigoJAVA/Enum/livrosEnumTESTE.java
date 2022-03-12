import java.util.EnumSet;

public class livrosEnumTESTE 
{
        public static void main(String[] args)
        {
            System.out.println("\n Livros: \n");

            for(eLivros livros : eLivros.values())
            {
                System.out.printf("%-10s%-45s%s \n", livros,
                livros.getTitulo(), livros.getAno());
            }

        }   
}
