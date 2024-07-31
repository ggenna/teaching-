
public class Rettangolo {
	int larghezza;
	int altezza;
	Punto origine;
	public Rettangolo (int x, int y, int l, int h) {
		origine = new Punto(x, y);
		larghezza = l;
		altezza = h;
	}
	public void sposta (int a, int b) {
		origine.sposta(a, b);
	}
	public void print() {
		System.out.println("r: x=" + origine.x + " y=" + origine.y + " l=" + larghezza + " a=" +altezza);
	
	
	
	}

}
