public class Rombo {
int diag_maggiore; // attributi
int diag_minore;
Punto origine; // associazione con il punto origine

public Rettangolo (int x, int y, int dmagg, int dmin) {
origine = new Punto(x, y);
diag_maggiore = dmagg;
diag_minore = dmin;
}
public void sposta (int a, int b) { // metodo
origine.sposta(a, b); // interazione tra oggetti
}
public void print() {
System.out.println("r: x=" + origine.x + " y="
+ origine.y + " diag_maggiore=" + diag_maggiore + " diag_minore=" + diag_minore); }

public void get_centro() {
	int x;
	int y;
	
	x=origine.x;
	y=origine.y + (diag_maggiore/2);
	
	System.out.println("punto centrale x="+x +" y="y);
}
	
}









for(int i=0;i<10;i++)
{
	System.out.print("Ciao ");
	
}









