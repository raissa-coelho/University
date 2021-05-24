import javax.swing.*;
//import java.awt.event.*;
import java.awt.*;

public class MainMenu extends JFrame{

    public MainMenu(){

        super("Batalha Naval");

        Container MainSCREEN = getContentPane();
        MainSCREEN.setBackground(Color.WHITE);
        setSize(1000, 600);

        JLabel titulo = new JLabel("Batalha Naval");
        titulo.setFont( new Font("Serif", Font.BOLD, 70));
        titulo.setForeground(Color.BLACK);

        JPanel panel = new JPanel();
        panel.add(new JLabel("Jogador: "));
        JTextField texto = new JTextField("Digite Nome");
        panel.add(texto);
        panel.setBackground(Color.WHITE);

        FlowLayout Layout = new FlowLayout();

        MainSCREEN.setLayout(Layout);

        JButton NovoJogoA = new JButton();
        NovoJogoA.setBackground(Color.GRAY);
        NovoJogoA.setText("Novo Jogo Aleatorio");

        JButton NovoJogoD  = new JButton();
        NovoJogoD.setBackground(Color.GRAY);
        NovoJogoD.setText("Novo Jogo Definido");

        MainSCREEN.add(titulo);
        MainSCREEN.add(panel);
        MainSCREEN.add(NovoJogoA);
        MainSCREEN.add(NovoJogoD);

        setVisible(true);
    } 
}
