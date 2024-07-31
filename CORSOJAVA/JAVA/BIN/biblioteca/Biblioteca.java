package biblioteca;

public class Biblioteca {
	public static int numscaffale;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Ripiano[] ripiano = new Ripiano[3];
		Libro libro1=new Libro("titolo libro1","dario");
		Libro libro2=new Libro("titolo libro2","carlo");
		Libro libro3=new Libro("titolo libro3","luca");
		ripiano[0]=new Ripiano("commedia",libro1,libro2,libro3);
		//System.out.println(ripiano1);
		Libro libro4=new Libro("titolo libro4","dario");
		Libro libro5=new Libro("titolo libro5","carlo");
		Libro libro6=new Libro("titolo libro6","luca");
		ripiano[1]=new Ripiano("thriller",libro4,libro5,libro6);
		//System.out.println(ripiano2);
		Libro libro7=new Libro("titolo libro7","dario");
		Libro libro8=new Libro("titolo libro8","carlo");
		Libro libro9=new Libro("titolo libro9","luca");
		ripiano[2]=new Ripiano("turismo",libro7,libro8,libro9);
		//System.out.println(ripiano3);
		
		//System.out.println(ripiano[2].ricerca("dario"));
		Scaffale scaffale1=new Scaffale(ripiano, "narrativa");
		System.out.println(scaffale1+" numero scaffale "+numscaffale);
	}

}
