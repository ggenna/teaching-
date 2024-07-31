/*
 * Created on 23-ago-2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package biblio;

/**
 * @author Giovanni
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class scaffale {
    public static int NUM_RIPIANI = 6;
	private ripiano[] ripiani = new ripiano[NUM_RIPIANI];
	  
	public scaffale () {
		for (int i=0; i<NUM_RIPIANI; i++)
	  		ripiani[i] = new ripiano();
	}

	public boolean addScaffale(Libro libro, int ripiano, int piano, int scaffale) {
		return ripiani[ripiano].addRipiano(libro, ripiano, piano, scaffale);
	}

	public boolean verificaScaffale(Libro libro, int ripiano) {
		return ripiani[ripiano].verificaRipiano(libro);
	}

	public String getElenco_rip() {
		String elenco = ""; 
		for (int i=0; i< ripiani.length; i++) {
			int n_rip = i+1;	//Permette di stampare il numero dei piani a partire da 1 fino a 6 
			elenco += "Ripiano " + n_rip + "\n";
			elenco += ripiani[i].getElenco_libri() + "\n";
		}
		return elenco;
	}

	public Libro cercaScaffale(String autore, String titolo) {
		for (int i=0; i<NUM_RIPIANI; i++) {
			Libro temp = ripiani[i].cercaRipiani(autore,titolo);
			if (temp != null)
				return temp ;
		}
			return null;
	}


}
