import javax.swing.JOptionPane;

public class nome 
{
        public static void main(String[] args)
        {
            String nome1 = JOptionPane.showInputDialog("Nome: ");

            String mensagem = String.format("Bem Vindo(a), %s .", nome1);

            JOptionPane.showMessageDialog(null, mensagem);
        }    
}
