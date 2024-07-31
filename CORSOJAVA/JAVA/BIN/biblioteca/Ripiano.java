package biblioteca;

public class Ripiano {
	private Libro[] libri = new Libro[3];
	private String categoria;
	public Ripiano(String categoria,Libro libro1,Libro libro2,Libro libro3)
	{
		libri[0]=libro1;
		libri[1]=libro2;
		libri[2]=libro3;
		this.categoria=categoria;
        																			
	}
	public String toString() {
		return "categoria ripiano: "+this.categoria+"\n Libro 1 "+libri[0]+"\n Libro 2 "+libri[1]+"\n Libro 3 "+libri[2];
	}
	public String ricerca(String da_cercare)
	{
		StringBuffer result=new StringBuffer();
		String temp=null;
		for(int i=0; i<libri.length;i++)
		{
//			System.out.println("anome[i]="+anome[i]+" "+da_cercare.toString());
			if(da_cercare.equalsIgnoreCase(libri[i].getTitolo())||da_cercare.equalsIgnoreCase(libri[i].getAutore())==true)
			{		
				result.append(categoria+" ");
				result.append(libri[i]+"\n");
			}
		}
		//System.out.println("debug="+result.toString());
		return result.toString();
	}
}
