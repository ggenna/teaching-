package biblio;

public class Libro {
   private String autore,titolo,scaffale;
   private int ripiano, piano;
	/**
	 * Costruisce un libro a partire da autore e titolo
	 */
	public Libro(String autore, String titolo) {
	    this.autore=autore;
	    this.titolo=titolo;
	}


	/**
	 * Metodo <i>getter</i> per accedere all'autore del libro
	 */
	public String getAutore() {
		return autore;
	}

	/**
	 * Metodo <i>getter</i> per accedere al titolo del libro
	 */
	public String getTitolo() {
		return titolo;
	}
	
	/**
	 * Restitiuisce la string corrispondente al libro
	 * nella forma "autore, titolo"
	 */
	public String toString() {
		return "Dati libro: "+this.autore+", "+this.titolo;
	}
	
	/**
	 * Restituisce il numero del ripiano in cui si trova il libro
	 */
	public int getRipiano() {
		return this.ripiano;
	}

	/**
	 * Restituisce il codice dello scaffale in cui si trova il libro
	 */
	public String getScaffale() {
		return this.scaffale;
	}

	/**
	 * Restituisce il numero del piano in cui si trova il libro
	 */
	public int getPiano() {
		return this.piano;
	}


    /**
     * @param ripiano
     * @param piano
     * @param scaffale
     */
    public void setValori(int ripiano, int piano, int scaffale) 
    {
	   this.ripiano=++ripiano;
	   this.piano=++piano;
	   this.scaffale = "SC" + ++scaffale;//Ritrasformo lo scaffale da intero a codice numerico       
    }
    

	public Libro cercaLibri(String autore, String titolo) 
	{
		if (autore!=null && titolo!=null && this.autore.equals(autore) && this.titolo.equals(titolo))
			return this;
		if (autore==null && titolo!=null && this.titolo.equals(titolo))
			return this;
		if (autore!=null && titolo==null && this.autore.equals(autore))
			return this;
		return null;
	}
    
    
    
    
    
    
    
    
    
    
}













