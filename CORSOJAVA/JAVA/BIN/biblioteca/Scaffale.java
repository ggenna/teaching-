package biblioteca;

public class Scaffale {
	public static int n_ripiano=3;
	private Ripiano[] ripiani=new Ripiano[n_ripiano];
 	private String nomescaffale;
	public Scaffale (Ripiano[] rip, String nome)
	{
		for (int i=0; i<n_ripiano; i++)
		{
			ripiani[i]=rip[i];
		}
		this.nomescaffale=nome;
	 Biblioteca.numscaffale++;
	}
	public String toString() 
	{	
		StringBuffer result=new StringBuffer();
		result.append("nome scaffale: "+this.nomescaffale+"\n");
		for(int i=0; i<ripiani.length;i++)
		{
			result.append(ripiani[i]+"\n");
		}
		//System.out.println("debug="+result.toString());
	return result.toString();
	}
}
