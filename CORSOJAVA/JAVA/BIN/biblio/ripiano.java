/*
 * Created on 22-ago-2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package biblio;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * @author Giovanni
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class ripiano {

    private final int NUM_LIBRI=10;
    private Libro[] libri = new Libro[NUM_LIBRI];
    
    public ripiano()
    {
        for(int i=0;i<NUM_LIBRI;i++)
        {
            libri[i]=new Libro(null,null);
        }
        
    }
    
    

/*  Inserisco il libro nel primo ripiano libero ossia dove il posto del 
  *  libro è vuoto (l'autore è null)
   */
    public boolean addRipiano(Libro libro, int ripiano, int piano, int scaffale) 
    {
		for (int i=0; i<NUM_LIBRI; i++)
			if (libri[i].getAutore() == null) {
				libro.setValori(ripiano, piano, scaffale);
				libri[i]=libro;
				return true;
			}
		return false;
	}
    
    public boolean verificaRipiano(Libro libro) {
		for (int i=0; libri[i].getAutore()!=null; i++)
			if ( libri[i].getAutore().equals(libro.getAutore()) && libri[i].getTitolo().equals(libro.getTitolo()))
				return true;
		return false;
	}

	public String getElenco_libri() {
		String elenco = "";
		for (int i=0; libri[i].getAutore()!=null; i++) 
			elenco += libri[i].toString() + "\n";			
		return elenco;
	}

	public Libro cercaRipiani(String autore, String titolo) {
		for (int i=0; libri[i].getAutore()!=null; i++) {
			Libro temp = libri[i].cercaLibri(autore,titolo);
			if (temp != null)
				return temp ;
		}
		return null;
	}
	
}

    
    

