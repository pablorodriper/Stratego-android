using UnityEngine;
using System.Collections;

/**
 * De aquí heredan todas las piezas que se mueven una sola casilla por turno
 */
public class Movible : Pieza {
	/**
	 * Calcula a que casillas puede moverse la pieza
	 */
	public override bool[,] MovimientoPosible(){
		bool[,] r = new bool[10, 18];

		Pieza futuroSitio;

		//Arriba
		if (CurrentY != 13) {
			//Cargamos la posicion + 1 en una variable
			futuroSitio = BoardManager.Instance.Piezas [CurrentX, CurrentY + 1];
			if (futuroSitio == null || (futuroSitio.esAzul != this.esAzul))
				r [CurrentX, CurrentY + 1] = true;	//Si no hay nadie o alguien del equipo contrario, podemos movernos ahí
		}

		//Abajo
		if (CurrentY != 4) {
				futuroSitio = BoardManager.Instance.Piezas [CurrentX, CurrentY - 1];
				if (futuroSitio == null || (futuroSitio.esAzul != this.esAzul))
					r [CurrentX, CurrentY - 1] = true;
			}


		//Derecha
		if (CurrentX != 9) {
				futuroSitio = BoardManager.Instance.Piezas [CurrentX + 1, CurrentY];
				if (futuroSitio == null || (futuroSitio.esAzul != this.esAzul))
					r [CurrentX + 1, CurrentY] = true;
			}

		//Izquierda
		if (CurrentX != 0) {
				futuroSitio = BoardManager.Instance.Piezas [CurrentX - 1, CurrentY];
				if (futuroSitio == null || (futuroSitio.esAzul != this.esAzul))
					r [CurrentX - 1, CurrentY] = true;
			}

		//Desactivamos casillas centrales
		r [2, 8] = false;
		r [2, 9] = false;
		r [3, 8] = false;
		r [3, 9] = false;
		r [6, 8] = false;
		r [6, 9] = false;
		r [7, 8] = false;
		r [7, 9] = false;

		return r;
	}
}
