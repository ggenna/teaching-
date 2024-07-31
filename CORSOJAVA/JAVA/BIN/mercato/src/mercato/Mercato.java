package mercato;
import java.util.*;

public class Mercato 
{
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Cliente[] cliente=new Cliente[3];
		Venditore[] venditore=new Venditore[2];
		Prodotto[] prodotto=new Prodotto[5];
		
		Scanner input=new Scanner(System.in);
		cliente[0]=new Cliente("Mario","Rossi","coca cola","12345678000",100000);
		cliente[1]=new Cliente("Maria","Verdi","coca cola","12345678000",1000);
		cliente[2]=new Cliente("Dario","Neri","coca cola","12345678000",20000);
		//System.out.println(cliente);
		venditore[0]=new Venditore("Giulio","Gialli","Sony","12345678000",0);
		venditore[1]=new Venditore("Anna","Azzurro","Irradio","12345678000",0);
		//System.out.println(venditore);
		
		prodotto[0]=new Prodotto("tv",10000,"video",venditore[0]);
		prodotto[1]=new Prodotto("registratore",1000,"video",venditore[0]);
		prodotto[2]=new Prodotto("camera",1300,"video",venditore[0]);
		prodotto[3]=new Prodotto("video",100,"video",venditore[1]);
		prodotto[4]=new Prodotto("stereo",200,"video",venditore[1]);
		//System.out.println(prodotto);
		for (int i=0;i<cliente.length;i++)
		{
			//System.out.println(cliente[i]);
			for (int j=0;j<prodotto.length;j++)
			{
				
				if (cliente[i].compra(prodotto[j])==true)
				{
					System.out.println(prodotto[j]+" acquisto eseguito");
				}
				else
				{
					System.out.println(prodotto[j]+" non hai abbastanza soldi");
					System.out.println("fai un prelievo");
					
					int x=input.nextInt();
					System.out.println("nuovo saldo = "+ cliente[i].incassa(x));
					j--;
				}
			}
		}
		System.out.println(venditore[0]);
		System.out.println(venditore[1]);
		//System.out.println(cliente);
		for (int i=0;i<venditore.length;i++)
		{
			System.out.println(venditore[i]);
			for (int j=0;j<prodotto.length;j++)
			{
				 if(prodotto[j].getVenditore()==venditore[i])
				 {
					 System.out.println("\t \t"+prodotto[j]);
				 }
			}
		}
		
		
		//System.out.println("nuovo prezzo = "+ prodotto.applicaSconto(20));

	//	System.out.println("prezzo origine = "+ prodotto.rimuoviSconto());

		
		
		}
}
