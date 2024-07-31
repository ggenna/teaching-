package mercato;

public class Cliente 
{
	private String nome;
	private String cognome;
	private String azienda;
	private String p_iva;
	private int soldi;
	
	public Cliente(String nome,String cognome,String azienda,String p_iva,int soldi)
	{
		this.nome=nome;
		this.cognome=cognome;
		this.azienda=azienda;
		this.p_iva=p_iva;
		this.soldi=soldi;	
	}
	public String toString()
	{
		return "Cliente nome:"+nome+" cognome:"+cognome+" azienda:"+azienda+" partita iva:"+p_iva+" soldi:"+soldi;
	}
	public boolean compra(Prodotto p )
	{
		if (soldi - p.getPrezzo()>=0)
		{
			soldi=soldi - p.getPrezzo();
			p.getVenditore().add_soldi(p.getPrezzo());
			return true;
		}
		else
		{
			return false;
		}
	}
	public int incassa(int incasso)
	{
		soldi=soldi+incasso;
		return soldi;
	}
}
