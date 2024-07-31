package mercato;

public class Prodotto 
{
	private String nome;
	private int prezzo;
	private int prezzo_origine;
	private String categoria;
	private Venditore venditore;
	public Prodotto(String nome,int prezzo,String categoria,Venditore venditore)
	{
		this.nome=nome;
		this.prezzo=prezzo;
		this.prezzo_origine=prezzo;
		this.categoria=categoria;
		this.venditore=venditore;
	}
	public String toString()
	{
		return "Prodotto nome:"+nome+" Categoria:"+categoria+" Prezzo:"+prezzo;
	}
	public Venditore getVenditore()
	{
		return venditore;
	}
	public int getPrezzo()
	{
		return prezzo;
	}
	public int applicaSconto(int sconto)
	{
		prezzo=prezzo-(prezzo*sconto/100);
		return prezzo;
	}
	public int rimuoviSconto()
	{
		prezzo=prezzo_origine;
		return prezzo;
	}
}