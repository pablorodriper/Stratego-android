using UnityEngine;
using System.Collections;

public class Explorador : Pieza {

	/**
	 * Calcula a que casillas puede moverse la pieza
	 */
	public override bool[,] MovimientoPosible(){
		bool[,] r = new bool[10, 18];
	
		Pieza futuroSitio;
		int i;

		//Derecha
		i = CurrentX;
		while (true) {
			//Suma 1 a la coordenada donde está
			i++;	
			//Si se ha acabado el tablero break
			if (i >= 10)
				break;	
			//Si es una casilla de la zona central break
			if ((CurrentY == 8 || CurrentY == 9) && (i == 2 || i == 3 || i == 6 || i == 7))
				break;
			
			//Guardamos dicha posicion en una variable
			futuroSitio = BoardManager.Instance.Piezas [i, CurrentY];

			if (futuroSitio == null) {
				r [i, CurrentY] = true; //No hay pieza y podemos movernos hacia ahí
			} else {
				if (futuroSitio.esAzul != esAzul) 	//Si la pieza es contraria, podemos comerla
					r [i, CurrentY] = true;			//La añadimos a posibles movimientos
				break;	
			}
		}

		//Izquierda
		i = CurrentX;
		while (true) {
				i--;
				if (i < 0)
					break;

				futuroSitio = BoardManager.Instance.Piezas [i, CurrentY];

				if ((CurrentY == 8 || CurrentY == 9) && (i == 2 || i == 3 || i == 6 || i == 7))
					break;
				
				if (futuroSitio == null) {
					r [i, CurrentY] = true; //No hay pieza y podemos movernos hacia ahí
				} else {
					if (futuroSitio.esAzul != esAzul) 	//Si la pieza es contratia, podemos comerla
						r [i, CurrentY] = true;

					break;		
				}
			}
	
		//Arriba
		i = CurrentY;
		while (true) {
				i++;
				if (i >= 14)
					break;

				futuroSitio = BoardManager.Instance.Piezas [CurrentX, i];

				if ((i == 8 || i == 9) && (CurrentX == 2 || CurrentX == 3 || CurrentX == 6 || CurrentX == 7))
					break;
				
				if (futuroSitio == null) {
					r [CurrentX, i] = true; //No hay pieza y podemos movernos hacia ahí
				} else {
					if (futuroSitio.esAzul != esAzul) 	//Si la pieza es contraria, podemos comerla
						r [CurrentX, i] = true;

					break;	
				}
			}

		//Abajo
		i = CurrentY;
		while (true) {
				i--;
				if (i < 4)
					break;

				futuroSitio = BoardManager.Instance.Piezas [CurrentX, i];

				if ((i == 8 || i == 9) && (CurrentX == 2 || CurrentX == 3 || CurrentX == 6 || CurrentX == 7))
					break;
				
				if (futuroSitio == null) {
					r [CurrentX, i] = true; //No hay pieza y podemos movernos hacia ahí
				} else {
					if (futuroSitio.esAzul != esAzul)	//Si la pieza es contratia, podemos comerla
						r [CurrentX, i] = true;

					break;	
				}
			}
		return r;
	}
}