
public enum eLivros {
        
    JHTP("Java How To Program", "2010"),
    CHTP("C How To Program", "2007");

    private final String titulo;
    private final String anoR;

    eLivros(String tituloL , String ano){
        titulo = tituloL;
        anoR = ano;
    }

    public String getTitulo()
    {
        return titulo;
    }

    public String getAno()
    {
        return anoR;
    }
    
}
