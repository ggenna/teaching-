package biblio;

public class Biblioteca {
    /**
     * Costruisce un oggetto bibioteca con 3 piani, 
     * 30 scaffali per piano, 6 ripiani per scaffale
     * ciascuno con posto per 10 libri
     */
  	
  	  public static int NUM_PIANI = 3;
  	  private piano[] piani =  new piano[NUM_PIANI];
  	  	  
    public Biblioteca() {
    	for (int i=0; i<NUM_PIANI; i++)
    		piani[i] = new piano();
    }
   
    /**
     * Aggiunge il libro specificato nel ripano, scaffale
     * e piano specificati.
     * NOTA: Poichè Java numera i vettori a partire da 0, è necessario
     * iniziare la numerazione decrementando di 1 i valori passati (questo
     * vale anche per gli altri metodi). 
     * @return <code>true</code> se l'inserimento è andato a buon fine
     */
    public boolean add(Libro libro, int piano, String scaffale, int ripiano) {
    	int scaff_int = Integer.parseInt(scaffale.substring(2));	//prende il numero dopo il codice "SC"
    	scaff_int--;
    	piano--;
    	ripiano--;
    	return piani[piano].addPiano(libro,scaff_int,ripiano,piano);
    }

  /**
     * Verifica se il libro specificato si trova al
     * ripiano, scaffale e piano dati
     * @return <code>true</code> se il libro è presente
     */
    public boolean contiene(int piano, String scaffale, int ripiano, Libro libro) {
    	int scaff_int = Integer.parseInt(scaffale.substring(2));
    	scaff_int--;
    	piano--;
    	ripiano--;
    	return piani[piano].verificaPiano(libro,scaff_int,ripiano);
    }

    /**
     * Restituisce l'elenco dei libri contenuti in uno scaffale
     * Per ogni ripiano nella stringa compare l'indicazione del 
     * ripiano nella forma "Ripiano 1" seguito, nelle righe 
     * successive dai libri contenuti nel ripiano.
     */
    public String getLibri(int piano, String scaffale) {
    	int scaff_int = Integer.parseInt(scaffale.substring(2));
    	scaff_int--;
    	piano--;
      return piani[piano].getElenco_scaff(scaff_int);
    }

    /**
     * Ricerca un libro inserito nella biblioteca in base
     * a autore e titolo. Se uno dei due è <code>null</code>
     * la ricerca viene fatta solo su un parametro.
     * @return il libro ricercata o <code>null</code> se
     * 		non è stato trovato alcun libro
     */
    public Libro cerca(String autore, String titolo) {
    	for (int i=0; i<piani.length; i++) {
  		Libro temp = piani[i].cercaPiano(autore,titolo);
  		if (temp != null)
  			return temp ;
  	}
  	return null;
    }
}
