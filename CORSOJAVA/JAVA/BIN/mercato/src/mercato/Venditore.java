package mercato;

public class Venditore 
{
	private String nome;
	private String cognome;
	private String azienda;
	private String p_iva;
	private int ricavo;
	
	public Venditore(String nome,String cognome,String azienda,String p_iva,int ricavo)
	{
		this.nome=nome;
		this.cognome=cognome;
		this.azienda=azienda;
		this.p_iva=p_iva;
		this.ricavo=ricavo;	
	}
	public String toString()
	{
		return "Venditore nome:"+nome+" cognome:"+cognome+" azienda:"+azienda+" partita iva:"+p_iva+" ricavo:"+ricavo;
	}
	public void add_soldi(int prezzo)
	{
		ricavo=ricavo+prezzo;
	}
}
