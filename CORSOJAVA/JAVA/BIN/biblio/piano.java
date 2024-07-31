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
public class piano {
    

	public static int NUM_SCAFFALI = 30; 
	private scaffale[] scaffali = new scaffale[NUM_SCAFFALI];
	
	public piano (){
		for (int i=0; i<NUM_SCAFFALI; i++)
	  		scaffali[i] = new scaffale();
	}

	public boolean addPiano(Libro libro, int scaffale, int ripiano, int piano) {
		return scaffali[scaffale].addScaffale(libro, ripiano, piano, scaffale);
	}

	public boolean verificaPiano(Libro libro, int scaffale, int ripiano) {
		return scaffali[scaffale].verificaScaffale(libro, ripiano);
	}
	
	public String getElenco_scaff(int scaffale) {
		return scaffali[scaffale].getElenco_rip();
	}

	public Libro cercaPiano(String autore, String titolo) {
		for (int i=0; i<NUM_SCAFFALI; i++) {
			Libro temp = scaffali[i].cercaScaffale(autore,titolo);
			if (temp != null)
				return temp ;
		}
		return null;
	}

}
