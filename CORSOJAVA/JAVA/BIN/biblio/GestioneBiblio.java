package biblio;

import org.polito.po.Console;

public class GestioneBiblio {
	private Console console;
	private Biblioteca biblio;
	
	public GestioneBiblio(Console console, Biblioteca biblio) {
		this.console = console;
		this.biblio = biblio;
	}

	public void start() {
		console.println("* Gestione Biblioteca *");
		while (true) {
			console.print(">");
			String cmd = console.readLine();

			if (cmd.equals("add")) {
				console.print("Autore: ");
				String autore = console.readLine();
				console.print("Titolo: ");
				String titolo = console.readLine();

				console.print("Piano: ");
				int piano = Integer.parseInt(console.readLine());
				console.print("Scaffale: ");
				String scaffale = console.readLine();
				console.print("Ripiano: ");
				int ripiano = Integer.parseInt(console.readLine());

				if (biblio
					.add(new Libro(autore, titolo), piano, scaffale, ripiano)) {
					console.println("OK");
				} else {
					console.println("Errore");
				}
			} else if (cmd.equals("list")) {
				console.print("Piano: ");
				int piano = Integer.parseInt(console.readLine());
				console.print("Scaffale: ");
				String scaffale = console.readLine();
				console.println(biblio.getLibri(piano, scaffale));
			} else if (cmd.equals("libro")) {
				console.print("Autore: ");
				String autore = console.readLine();
				console.print("Titolo: ");
				String titolo = console.readLine();

				Libro libro = biblio.cerca(autore, titolo);  //Modificato!
				if (libro == null) {
					console.println("Libro non trovato");
				} else {
					console.println(
						"Piano "
							+ libro.getPiano()
							+ " Scaffale "
							+ libro.getScaffale()
							+ " Ripiano "
							+ libro.getRipiano());
				}

			} else if (cmd.equals("quit")) {
				break;
			}
		}
		console.println("Arrivederci!");
	}

	public static void main(String[] args) {
		Console console = new Console();
		Biblioteca biblio = new Biblioteca();
		GestioneBiblio ui = new GestioneBiblio(console, biblio);
		ui.start();  // Forse serve per poter gestire più biblioteche
	}
        

	}
	

