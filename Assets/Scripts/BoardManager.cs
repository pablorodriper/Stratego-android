using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;

public class BoardManager : MonoBehaviour {

	public static BoardManager Instance{ set; get; }

	//Matriz del tamaño del tablero con true en las coordenadas xy a las que puede moverse
	private bool[,] movimientosPermitidos{ set; get; }
	//Matriz que señala al objeto pieza que esta en las coordenadas xy
	public Pieza[,]	 Piezas{ set; get; }		
	private Pieza piezaSeleccionada;
	private Pieza piezaSeleccionada2;

	//Tamaño casillas
	private const float TILE_SIZE = 1.0f;		//Tamaño de cuadrículas
	private const float TILE_OFFSET = 0.5f;		//Distancia entre cuadriculas
	//Número de casillas
	private int casillasAlto = 18;				//Número de casillas del tablero
	private int casillasLargo = 18;
	private int selectionX = -1;
	private int selectionY = -1;

	public List<GameObject> figuras;			//Lista de objetos figura, uno de cada tipo
	private List<GameObject> figurasActivas;	//Lista de figuras en la partida
	private List<GameObject> planosFigAzules = new List<GameObject>();		//Lista con planos buscados con Tag para desaparecer al acmbiar de turno
	private List<GameObject> planosFigRojos = new List<GameObject>();

	public bool turnoRojo = true;				//true para turno de jugador rojo, false para turno azul
	private bool seleccionable = false;			//No permite seleccionar piezas hasta que empiece la partida

	private bool[,] rRojo = new bool[10, 18];	//Matriz con las posibles posiciones al colocar ejercito
	private bool[,] rAzul = new bool[10, 18];

	//UI
	private bool redFlag = false;				//flag interfaz distinta primer turno
	private bool blueFlag = false;
	private bool menuPrincipal = true;			//Muestra el menú al abrir la aplicación
	//Panel
	public GameObject panelAzulRojo;			
	public GameObject panelRojoAzul;
	public GameObject panelReiniciar;
	public GameObject planeValor;				//Interfaz para mostrar valor
	//Texto
	public Text titulo;
	public Text	ganador;
	public Text nuevaPartida;
	public Text pulse;
	public Text	textoValorAtaque;
	public Text textoValorDefensa;

	/**
	 * Inicializa el tablero y la interfaz
	 * 
	 * Llamada al iniciar la aplicacion
	 */
	public void Start(){
		Instance = this;
		cambioTurnoRojo();		//Activa turno rojo

		//Set IU y camara
		planeValor.transform.position = new Vector3(5,6,18);
		textoValorAtaque.text = " ";
		textoValorAtaque.transform.position = new Vector3 (355,1150,0);
		textoValorDefensa.text = " ";

		//Necesario para menu principal la primera vez
		if (menuPrincipal) {
			panelReiniciar.SetActive (true);
			planeValor.SetActive (false);
			panelAzulRojo.SetActive (false);
		} else {
			panelReiniciar.SetActive (false);
			nuevaPartida.text = "Revancha";
			SpawnTodas();			//Crea TODAS figuras en el tablero
			//SpawnTodasDemo();		//Crea pocas figuras en el tablero (DEMO)
		}
		menuPrincipal = false;
	}
		
	/**
	 * Esta funcion se ejecuta en cada frame
	 * 
	 * Recoge los click y decide si quieres seleccionar o mover la pieza
	 */
	private void Update(){
		//Guarda coordenadas al hacer click selectionX selectionY
		UpdateSelection ();
		//Dibuja tablero
		DrawBoard ();			
		if (seleccionable) {
			if (Input.GetMouseButtonDown (0)) {
				//Borra highlights
				BoardHighlight.Instance.Hidehighlights ();
				//Borra textos
				textoValorAtaque.text = " ";				
				textoValorDefensa.text = " ";

				if (selectionX >= 0 && selectionY >= 0) {
					if (piezaSeleccionada == null) {
						//Selecciona figura
						SeleccionarPieza (selectionX, selectionY);
					} else {
						//Mueve figura
						MoverPieza (selectionX, selectionY);
					}
				}
			}
		}
	}

	/**
	 * Asigna la coordenada cuando haces click
	 */
	private void UpdateSelection(){
		if (!Camera.main)
			return;

		//Refresca en cada frame la posicion del raton
		RaycastHit hit;
		if (Physics.Raycast (Camera.main.ScreenPointToRay (Input.mousePosition), out hit, 25.0f, LayerMask.GetMask ("BoardPlane"))) {
			selectionX = (int)hit.point.x;
			selectionY = (int)hit.point.z;
		} else {
			selectionX = -1;
			selectionY = -1;
		}
	}

	private void SeleccionarPieza(int x, int y){
		if (Piezas [x, y] == null) //No puedes seleccionar casillas vacias
			return;

		if (Piezas [x, y].esAzul == turnoRojo) //Si es turno rojo no puedes seleccionar azules
			return;

		//Guardamos matriz movimientosPermitidos correspondiente
		if (Piezas [x, y].jugando) {	//Si ya se han colocado las piezas 
			movimientosPermitidos = Piezas [x, y].MovimientoPosible ();
			piezaSeleccionada = Piezas [x, y];
		} else {
			piezaSeleccionada = Piezas [x,y];
			if (piezaSeleccionada.esAzul) {
				movimientosPermitidos = rAzul;
			} else {
				movimientosPermitidos = rRojo;
			}
		}
		//Se encienden los cuadros a donde es posible moverse
		BoardHighlight.Instance.HighlightMovimientosPermitidos (movimientosPermitidos);

		//Mostramos el valor de la pieza seleccionada
		if (turnoRojo) {
			mostrarTexto (piezaSeleccionada, textoValorAtaque, Color.red);
		} else {
			mostrarTexto (piezaSeleccionada, textoValorAtaque, Color.blue);
		}
		planeValor.SetActive (true);
	}

	private void MoverPieza(int x, int y){
		//Si ya se han colocado las piezas
		if(piezaSeleccionada.jugando){	
			//Si pulsas otra pieza de tu equipo la selecciona automaticamente
			if (Piezas[x,y] != null && Piezas [x, y].esAzul != turnoRojo) {
				BoardHighlight.Instance.Hidehighlights ();
				SeleccionarPieza (x, y);
				return;
			}

			//Si puedes moverte a donde has pinchado
			if (movimientosPermitidos [x, y]) {
				Pieza piezaEnemiga = Piezas [x, y];
				//Borra highlights
				BoardHighlight.Instance.Hidehighlights ();	
				//Muestra las dos casillas que se ha movido este turno
				BoardHighlight.Instance.encenderCasilla (piezaSeleccionada.CurrentX, piezaSeleccionada.CurrentY);
				BoardHighlight.Instance.encenderCasilla (x, y);

				//Si atacas a un enemigo
				if (piezaEnemiga != null && piezaEnemiga.esAzul == turnoRojo) {
					//Mostramos textos
					if (turnoRojo) {
						mostrarTexto (piezaSeleccionada, textoValorAtaque, Color.red);
						mostrarTexto (piezaEnemiga, textoValorDefensa, Color.blue);					
					} else {
						mostrarTexto (piezaSeleccionada, textoValorAtaque, Color.blue);
						mostrarTexto (piezaEnemiga, textoValorDefensa, Color.red);					
					}

					//Calcula resultado del combate
					int combate = Combate (piezaSeleccionada, piezaEnemiga);

					//Si gana atacante
					if (combate == 1) {
						//Elimina de lista
						figurasActivas.Remove (piezaEnemiga.gameObject);

						//Destruye objeto del tablero
						Destroy (piezaEnemiga.gameObject);		

						//Calcula si quedan piezas movibles
						if (comprobarEmpateOrMovible ())
							return;
					}

					//Si gana defensa
					if (combate == -1) {
						//Elimina pieza
						figurasActivas.Remove (piezaSeleccionada.gameObject);
						Destroy (piezaSeleccionada.gameObject);
						Piezas [piezaSeleccionada.CurrentX, piezaSeleccionada.CurrentY] = null;	//Elimina figura de posicion anterior
						piezaSeleccionada = null;			//deselecciona pieza

						//Calcula si quedan piezas movibles
						if (comprobarEmpateOrMovible ())
							return;
						
						//Cambio de turno
						turnoRojo = !turnoRojo;
						if (turnoRojo) {
							cambioTurnoRojo ();
						} else {
							cambioTurnoAzul ();
						}
						return;
					}

					//Si las dos tienen el mismo valor 
					if (combate == 0) {
						//Elimina piezas
						figurasActivas.Remove (piezaSeleccionada.gameObject);
						figurasActivas.Remove (piezaEnemiga.gameObject);
						Destroy (piezaSeleccionada.gameObject);
						Destroy (piezaEnemiga.gameObject);
						Piezas [piezaSeleccionada.CurrentX, piezaSeleccionada.CurrentY] = null;
						Piezas [piezaEnemiga.CurrentX, piezaEnemiga.CurrentY] = null;
						piezaSeleccionada = null;

						//Calcula si quedan piezas movibles
						if (comprobarEmpateOrMovible ())
							return;
						
						//Cambio de turno
						turnoRojo = !turnoRojo;
						if (turnoRojo) {
							cambioTurnoRojo ();
						} else {
							cambioTurnoAzul ();
						}
						return;
					}

					//Si se captura la bandera
					if (combate == 2) {
						if (turnoRojo)
							FinDelJuego (1);
						else
							FinDelJuego (-1);
						return;
					}
				}

				//Mueve la pieza
				Piezas [piezaSeleccionada.CurrentX, piezaSeleccionada.CurrentY] = null;
				piezaSeleccionada.transform.position = GetTileCenter (x, y);
				piezaSeleccionada.setPosition (x, y); //Guardamos nueva posicion
				iTween.MoveTo(piezaSeleccionada.gameObject,new Vector3(x + 0.5f,0,y + 0.5f),4);
				Piezas [x, y] = piezaSeleccionada;

				//Cambia de turno
				turnoRojo = !turnoRojo;
				if (turnoRojo) {
					cambioTurnoRojo();
				} else {
					cambioTurnoAzul();
				}
			}

		} else {		//Si estamos colocando las piezas en el tablero
			if (movimientosPermitidos [x, y]) {
				Pieza posicionDeseada = Piezas [x, y];

				if (posicionDeseada == null) {	//No hay pieza en el sitio
					Piezas [piezaSeleccionada.CurrentX, piezaSeleccionada.CurrentY] = null;	//Borrar de anterior coordenada
					iTween.MoveTo (piezaSeleccionada.gameObject, new Vector3 (x + 0.5f, 0, y + 0.5f), 4);
					piezaSeleccionada.setPosition (x, y); 									//Guardamos nueva posicion		
					Piezas [x, y] = piezaSeleccionada;										//Añadimos a matriz
				} else {		//Ya había una pieza en el sitio
					Piezas [piezaSeleccionada.CurrentX, piezaSeleccionada.CurrentY] = null;	//Borrar de anterior coordenada
					iTween.MoveTo (piezaSeleccionada.gameObject, new Vector3 (x + 0.5f, 0, y + 0.5f), 4);
					piezaSeleccionada.setPosition (x, y); 									//Guardamos nueva posicion		

					piezaSeleccionada2 = Piezas [x, y];			//Guardamos pieza que vamos a devolver a la caja

					Piezas [x, y] = piezaSeleccionada;			//Añadimos a matriz la pieza movida							

					bool fin = false;	//Encontrada posicion en la caja = false
					//Distintas coordenadas dependiendo del color
					if (piezaSeleccionada2.esAzul) {		
						//Comprobamos uno a uno si hay algun hueco libre en la caja
						for (int j = 17; j >= 14; j--) {	
							for (int i = 9; i >= 0; i--) {
								if (Piezas [i, j] == null) {
									iTween.MoveTo (piezaSeleccionada2.gameObject, new Vector3 (i + 0.5f, 0, j + 0.5f), 4);
									piezaSeleccionada2.setPosition (i, j);									//Guardamos nueva posicion
									Piezas [i, j] = piezaSeleccionada2;
									fin = !fin;
									break;
								}
							}
							if (fin)
								break;
						} 
					} else {
						for (int j = 0; j < 4; j++) {
							for (int i = 0; i < 9; i++) {
								if (Piezas [i, j] == null) {
									iTween.MoveTo (piezaSeleccionada2.gameObject, new Vector3 (i + 0.5f, 0, j + 0.5f), 4);
									piezaSeleccionada2.setPosition (i, j);									//Guardamos nueva posicion
									Piezas [i, j] = piezaSeleccionada2;	
									fin = !fin;
									break;
								}
							}
							if (fin)
								break;
						} 
					}
					piezaSeleccionada2 = null;
				}
				// Durante la colocacion de piezas no se cambia turno hasta el final 
				if (RojasColocadas () && turnoRojo) {
					turnoRojo = false;		//Cambio de turno al colocar todas las rojas
					cambioTurnoAzul();
					planeValor.SetActive (false);
					planeValor.transform.position = new Vector3(5,5,0);
				}
				if (AzulesColocadas ()) {
					turnoRojo = true;
					cambioTurnoRojo();
					textoValorAtaque.transform.position = new Vector3 (360,60,0);
				}
			} else if (Piezas[x,y] != null && Piezas [x, y].esAzul != turnoRojo) {
				SeleccionarPieza (x, y);
				return;
			}
			BoardHighlight.Instance.Hidehighlights ();

		}
		piezaSeleccionada = null;
	}

	/**
	 * Acciones al acabar el turno azul
	 */
	private void cambioTurnoRojo(){
		panelAzulRojo.SetActive (true);

		//desaparecer imagenes azules
		for (int i = 0; i < planosFigAzules.Count; i++)
			if(planosFigAzules[i] != null)
				planosFigAzules [i].SetActive (false);
	} 

	/**
	 * Acciones al acabar el turno rojo
	 */
	private void cambioTurnoAzul(){
		panelRojoAzul.SetActive (true);
		//desaparecer imagenes rojas
		for (int i = 0; i < planosFigRojos.Count; i++)
			if(planosFigRojos[i] != null)
				planosFigRojos [i].SetActive (false);
	}
		
	/**
	 * Calcula el resultado de los combates introduciendo dos piezas
	 * 
	 * Devuelve 2 si se capturó la bandera, 1 si gana el atacante, 0 empate, -1 gana el defensa
	 */
	private int Combate(Pieza piezaAtaque, Pieza piezaDefensa){
		//Defiende una bandera
		if (piezaDefensa.GetType() == typeof(Bandera)) {
			return 2;
		}

		//Ataca espia a Mariscal
		if (piezaAtaque.valor == 1 && piezaDefensa.valor == 10) {
			return 1;
		}

		//Minero ataca bomba
		if (piezaAtaque.valor == 3 && piezaDefensa.GetType() == typeof(Bomba)) {
			return 1;
		}

		//Defiende una bomba
		if (piezaDefensa.GetType() == typeof(Bomba)) {
			return -1;
		}

		//Comparar valores
		if (piezaAtaque.valor > piezaDefensa.valor) 
			return 1;
		if (piezaAtaque.valor == piezaDefensa.valor)
			return 0;
		
		return -1;
	}

	/**
	 * Coloca una figura en el tablero, es llamada por SpawnTodas();
	 * Introduce posición del array de entrada y coordenadas de destino
	 */ 
	private void SpawnFiguras (int index, int x, int y){
		GameObject instanciacion = Instantiate (figuras [index], GetTileCenter(x,y), Quaternion.identity) as GameObject;
		instanciacion.transform.SetParent (transform);
		Piezas [x, y] = instanciacion.GetComponent<Pieza> ();
		Piezas [x, y].setPosition (x, y);
		figurasActivas.Add (instanciacion);
	}

	/**
	 * Coloca todas las figuras en el tablero
	 */
	private void SpawnTodas(){
		//Crea la matriz de movimientos de colocar piezas
		//Para elegir la posicion de las piezas rojas
		for (int i = 0; i < 10; i++) {
			for (int j = 4; j < 8; j++) {
				rRojo [i, j] = true;				
			}
		}
		/*Para elegir la posicion de las piezas azules*/
		for (int i = 0; i < 10; i++) {
			for (int j = 10; j < 14; j++) {
				rAzul [i, j] = true;				
			}
		}


		figurasActivas = new List<GameObject>();
		Piezas = new Pieza[10, 18];
		//Spawn rojas
		SpawnFiguras (12, 0, 0);		//1 bandera

		for(int i = 1; i<7; i++)		//6 bombas
			SpawnFiguras (13, i, 0);

		for(int i = 7; i<10; i++)		//3 comandantes
			SpawnFiguras (15, i, 0);

		for(int i = 0; i<8; i++)		//8 exploradores
			SpawnFiguras (18, i, 1);

		SpawnFiguras (16, 8, 1);		//2 coroneles
		SpawnFiguras (16, 9, 1);

		for(int i = 0; i<5; i++)		//5 minadores
			SpawnFiguras (21, i, 2);

		for(int i = 5; i<9; i++)		//4 sargentos
			SpawnFiguras (22, i, 2);

		SpawnFiguras (17, 9, 2);		//1 espia

		for(int i = 0; i<4; i++)		//4 tenientes
			SpawnFiguras (23, i, 3);
		for(int i = 4; i<8; i++)		//4 capitanes
			SpawnFiguras (14, i, 3);

		SpawnFiguras (19, 8, 3);		//1 general

		SpawnFiguras (20, 9, 3);		//1 mariscal


		//Spawn azules
		SpawnFiguras (0, 0, 17);		//1 bandera

		for(int i = 1; i<7; i++)		//6 bombas
			SpawnFiguras (1, i, 17);

		for(int i = 7; i<10; i++)		//3 comandantes
			SpawnFiguras (3, i, 17);

		for(int i = 0; i<8; i++)		//8 exploradores
			SpawnFiguras (6, i, 16);

		SpawnFiguras (4, 8, 16);		//2 coroneles
		SpawnFiguras (4, 9, 16);

		for(int i = 0; i<5; i++)		//5 minadores
			SpawnFiguras (9, i, 15);

		for(int i = 5; i<9; i++)		//4 sargentos
			SpawnFiguras (10, i, 15);

		SpawnFiguras (5, 9, 15);		//1 espia

		for(int i = 0; i<4; i++)		//4 tenientes
			SpawnFiguras (11, i, 14);
		
		for(int i = 4; i<8; i++)		//4 capitanes
			SpawnFiguras (2, i, 14);

		SpawnFiguras (7, 8, 14);		//1 general

		SpawnFiguras (8, 9, 14);		//1 mariscal

		//Inicializa y gestiona las imagenes de cada pieza, para poder hacerlas desaparecer despues
		GameObject[] arrayAddLista = GameObject.FindGameObjectsWithTag ("Plano Azul");
		for(int i = 0; i < arrayAddLista.Length; i++)
			planosFigAzules.Add(arrayAddLista[i]);
		arrayAddLista = GameObject.FindGameObjectsWithTag ("Plano Rojo");
		for(int i = 0; i < arrayAddLista.Length; i++)
			planosFigRojos.Add(arrayAddLista[i]);
	}

	/**
	 * Comprueba si has colocado todas las piezas rojas
	 */
	private bool RojasColocadas(){		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				if ( Piezas[i,j]!= null)
					return false;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 4; j < 8; j++) {
				if (Piezas [i, j] != null)
					Piezas [i, j].jugando = true;			
				}
			}

		return true;
	}

	/**
	 * Comprueba si has colocado todas las piezas azules
	 */
	private bool AzulesColocadas(){		
		for (int i = 0; i < 10; i++) {
			for (int j = 14; j <18; j++) {
				if ( Piezas[i,j]!= null)
					return false;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 10; j < 14; j++) {
				if (Piezas [i, j] != null)
					Piezas [i, j].jugando = true;			
			}
		}
		return true;
	}

	/**
	 * Llamado desde boton de panelRojoAzul
	 */
	public void desaparecerPanelRojo(){
		seleccionable = true;	//Permite interactuar con las piezas
		if (redFlag) {
			planeValor.transform.position = new Vector3 (5, 5, -3); //La primera vez no mueve el plano de cuero abajo
		}
		redFlag = true;
		panelAzulRojo.SetActive (false);
		//Mueve y rota camara
		iTween.MoveTo(Camera.main.gameObject,new Vector3(5f,5f,7.5f),4);	
		iTween.RotateTo(Camera.main.gameObject,new Vector3(70f,0,0),4);
		//Aparecen imagenes de figuras rojas
		for (int i = 0; i < planosFigRojos.Count; i++)
			if(planosFigRojos[i] != null)
				planosFigRojos [i].SetActive (true);
	}

	/**
	 * Llamado desde boton de panelAzulRojo
	 */
	public void desaparecerPanelAzul(){
		if (blueFlag) {
			planeValor.transform.position = new Vector3(5,5,21);  //La primera vez no mueve el plano de cuero abajo
		}
		blueFlag = true;
		panelRojoAzul.SetActive (false);
		//Mueve y rota camara
		iTween.MoveTo(Camera.main.gameObject,new Vector3(5f,5f,11f),4);
		iTween.RotateTo(Camera.main.gameObject,new Vector3(70f,180f,0),4);
		//Aparecen imagenes de figuras rojas
		for (int i = 0; i < planosFigAzules.Count; i++)
			if(planosFigAzules[i] != null)
				planosFigAzules [i].SetActive (true);
	}

	/** 
	 * Si final == 1 gana Rojo
	 * Si final == -1 gana Azul
	 * Si final == 0 empate
	 */
	private void FinDelJuego(int final){
		//Mostrar todas las piezas
		for (int i = 0; i < planosFigAzules.Count; i++)
			if(planosFigAzules[i] != null)
				planosFigAzules [i].SetActive (true);
		for (int i = 0; i < planosFigRojos.Count; i++)
			if(planosFigRojos[i] != null)
				planosFigRojos [i].SetActive (true);

		if (final == 0) {
			titulo.text = "Empate";
			ganador.text = " ";
			ganador.color = Color.black;
		} else {
			titulo.text = "Ganador:";
			if (final == 1) {
				ganador.text = "Jugador Rojo";
				ganador.color = Color.red;
			} else if (final == -1) {
				ganador.text = "Jugador Azul";
				ganador.color = Color.blue;
			}
		}
		//Que no aparezca boton de cambiar de turno
		panelAzulRojo.SetActive (false);
		panelRojoAzul.SetActive (false);
		seleccionable = false;
		panelReiniciar.SetActive (true);
	}

	/**
	 * Comprueba si hay empate y si no quedan figuras movibles
	 */
	private bool comprobarEmpateOrMovible(){
		if (NingunaAzulMovible () && NingunaRojaMovible()) {
			FinDelJuego (0);
			return true;
		}

		if (NingunaAzulMovible ()) {
			FinDelJuego (1);
			return true;
		}
		
		if (NingunaRojaMovible ()) {
			FinDelJuego (-1);
			return true;
		}
		return false;
	}

	/**
	 * Comprueba si no quedan rojas movibles
	 */
	private bool NingunaRojaMovible(){
		Pieza p;
		foreach (GameObject go in figurasActivas) {
			p=go.GetComponent<Pieza> ();
			if (!p.esAzul && (p.GetType() == typeof(Movible)||p.GetType() == typeof(Explorador)))
				return false;
		}
		return true;
	}

	/**
	 * Comprueba si no quedan azules movibles
	 */
	private bool NingunaAzulMovible(){
		Pieza p;
		foreach (GameObject go in figurasActivas) {
			p=go.GetComponent<Pieza> ();
			if (p.esAzul && (p.GetType() == typeof(Movible)||p.GetType() == typeof(Explorador)))
				return false;
		}
		return true;
	}

	/**
	 * Instancia las piezas para poder jugar
	 * 
	 * Llamado desde boton de panelReiniciar
	 */
	public void reiniciarPartida(){
		if (redFlag) {
			foreach (GameObject go in figurasActivas)
				Destroy (go);
			BoardHighlight.Instance.Hidehighlights ();
		}
		redFlag = false;
		blueFlag = false;
		Start ();
	}

	/**
	 * Dibuja los cuadrados del tablero
	 */
	private void DrawBoard(){
		Vector3 widthLine = Vector3.right * casillasLargo;
		Vector3 heightLine = Vector3.forward * casillasAlto;

		for (int i = 0; i <= casillasLargo; i++) {
			Vector3 start = Vector3.forward * i;
			Debug.DrawLine (start, start + widthLine);
			for (int j = 0; j <= casillasAlto; j++) {
				start = Vector3.right * j;
				Debug.DrawLine (start, start + heightLine);
			}
		}

		// Dibuja la seleccion
		if (selectionX >= 0 && selectionY >= 0) {
			Debug.DrawLine (
				Vector3.forward * selectionY + Vector3.right * selectionX,
				Vector3.forward * (selectionY + 1) + Vector3.right * (selectionX + 1));

			Debug.DrawLine (
				Vector3.forward * (selectionY + 1) + Vector3.right * selectionX,
				Vector3.forward * selectionY + Vector3.right * (selectionX + 1));
		}
	}

	/**
	 * Centra las piezas en el centro del cuadrado
	 */
	private Vector3 GetTileCenter(int x, int y){
		Vector3 origin = Vector3.zero;
		origin.x += (TILE_SIZE * x) + TILE_OFFSET;
		origin.z += (TILE_SIZE * y) + TILE_OFFSET;
		return origin;
	}

	/**
	 * Muestra el nombre, valor y color adecuado a la pieza seleccionada
	 */
	private void mostrarTexto(Pieza pieza, Text texto, Color color){
		if (pieza.GetType () == typeof(Bandera) || pieza.GetType () == typeof(Bomba)) {
			texto.text = pieza.nombre;
		} else {
			texto.text = pieza.nombre + ": " + pieza.valor;
		}
		//Cambiamos color
		texto.color = color;
	}

	/**
	 * Coloca unas pocas figuras en el tablero para hacer una demostracion
	 */
	private void SpawnTodasDemo(){
		//Crea la matriz de movimientos de colocar piezas
		/*Para elegir la posicion de las piezas rojas*/
		for (int i = 0; i < 10; i++) {
			for (int j = 4; j < 8; j++) {
				rRojo [i, j] = true;				
			}
		}
		/*Para elegir la posicion de las piezas azules*/
		for (int i = 0; i < 10; i++) {
			for (int j = 10; j < 14; j++) {
				rAzul [i, j] = true;				
			}
		}

		figurasActivas = new List<GameObject>();
		Piezas = new Pieza[10, 18];

		//Spawn rojas
		for(int i = 0; i <1; i++){
			for(int j = 0; j < 1; j++){
				SpawnFiguras (20, j, i);
			}
		}
		//SpawnFiguras (18, 2, 0);

		//Spawn azules
		for(int i = 17; i < 18; i++){
			for(int j = 1; j < 3; j++){
				SpawnFiguras (j,j,i	);
			}
		}

		//Inicializa y gestiona las imagenes de cada pieza, para poder hacerlas desaparecer despues
		GameObject[] arrayAddLista = GameObject.FindGameObjectsWithTag ("Plano Azul");
		for(int i = 0; i < arrayAddLista.Length; i++)
			planosFigAzules.Add(arrayAddLista[i]);
		arrayAddLista = GameObject.FindGameObjectsWithTag ("Plano Rojo");
		for(int i = 0; i < arrayAddLista.Length; i++)
			planosFigRojos.Add(arrayAddLista[i]);
	}
}