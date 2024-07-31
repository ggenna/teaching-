//*******************************************************************
// Java compiler created in PHP to quickly and safely test code.
// NOTE: please read the 'More Info' tab to the right for shortcuts.
//*******************************************************************






/*
 * potevo usare una lista con il relativo iteratore di scorrimento
 *
 import java.util.ArrayList;
 import java.util.List;
 */
public class Rubrica {
    
    /**
     * crea una nuova rubrica con il nome dato
     */
    
    //  private List lista=new ArrayList();
    private String nomerubrica;
    private String[] anome=new String[100];
    private String[] acognome=new String[100];
    private  String[] atelefono=new String[100];
    private int contatore;
    
    
    public Rubrica(String nomerubrica)
    {
        this.nomerubrica=nomerubrica;
        this.contatore =0;
    }
    
    /**
     * inserisce una nuova voce nella rubrica
     */
    public void aggiungi(String nome, String cognome, String telefono)
    {
    
        anome[contatore]=nome;
        acognome[contatore]=cognome;
        atelefono[contatore]=telefono;
        contatore++;
        System.out.println("contatore="+contatore);
        
    }
    
    /**
     * restituisce la prima voce inserita nella rubrica
     */
    public String primo() {
        
        //  String prime =anome[0]+" "+acognome[0]+" "+atelefono[0]+" ";
        String prime =anome[0];
        return "Il primo in elenco "+prime;
    }
    
    /**
     * restituisce il nome della rubrica
     */
    public String getNome() {
        return "Il nome della rubrica "+nomerubrica;
    }
    
    /**
     * Restituisce la voce i-esima inserita nella rubrica
     */
    public String voce(int i) {
        
        String voc =anome[i]+" "+acognome[i]+" "+atelefono[i]+" ";
        
        return voc;
    }
    
    /**
     * Restituisce una stringa con l'elenco delle voci
     * della rubrica separate da ", ".
     * L'elenco inizia con "(" e termina con ")"
     */
    public String elenco() {
        StringBuffer result = new StringBuffer();
        String temp=null;
        for (int i=0; i<contatore; i++){
            if (anome[i]!= null){
                temp =voce(i);
                if(i==0)
                    result.append("( "+(i+1)+" ");
                else
                    result.append(", "+(i+1)+" ");
                
                result.append(temp);
            }
            if(i==(contatore-1))
                result.append(" )");
        }
        return result.toString();
        
    }
    /**
     * Restituisce la stringa con la prima voce che
     * contiene il parametro daCercare come nome,
     * cognome oppure telefono.
     */
    public String ricerca(String daCercare)
    {
        StringBuffer result = new StringBuffer();
        String temp=null;
        for(int i=0;i<anome.length;i++)
        {
            if(daCercare.commpareTo(anome[i])==0)           if(daCercare.equalsIgnoreCase(anome[i])||daCercare.equalsIgnoreCase(acognome[i]))
            {
                temp = voce(i);
               	result.append(temp+"\n");
                
            }
        }
        return result.toString();
    }
    
    void PrintClassName(Object obj) {
        System.out.println("The Object's class is " +
                           obj.getClass());
    }
    
}


/**
 * @author Giovanni
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class prova {
    
    public static void main(String[] args) {
        
        Rubrica rubrica11=new Rubrica("LaMiaRubrica");
        rubrica11.aggiungi("Giovanni","Genna","3288115580");
        rubrica11.aggiungi("Alessandro","Genna","3288115580");
        

        System.out.println("elemento="+rubrica11.voce(2));
        
        System.out.println(rubrica11.ricerca("Giovanni"));
        
        
        
        System.out.println(rubrica11.primo());
        
        System.out.println(rubrica11.getNome());
        System.out.println(rubrica11.elenco());
        
        System.out.println(rubrica11.ricerca("cic"));
        
        rubrica11.PrintClassName(rubrica11);
        
        
        
        
    }
}
