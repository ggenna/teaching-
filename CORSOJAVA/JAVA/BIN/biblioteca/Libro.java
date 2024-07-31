package biblioteca;

public class Libro 
{
	private String titolo;
	private String autore;
	private String scaffale;
	private int ripiano;
	public Libro(String titolo,String autore) 
	{
		this.autore=autore;
		this.titolo=titolo;
	}
	public String getAutore() {
		return autore;
	}
	public String getTitolo() {
		return titolo;
	}
	public String toString() {
		return "dati libro: "+this.autore+" "+ this.titolo;
	}
}
