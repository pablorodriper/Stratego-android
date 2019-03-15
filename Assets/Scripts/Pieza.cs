using UnityEngine;
using System.Collections;

public abstract class Pieza : MonoBehaviour {

	public int CurrentX{ set; get; }	//Coordenadas
	public int CurrentY{ set; get; }
	public bool esAzul;					//Equipo: true = Azul
	public int valor;					//Valor: 1-10
	public bool jugando;				//false = colocacion de piezas
	public string nombre;

	public void setPosition(int x, int y){
		CurrentX = x;
		CurrentY = y;
	}

	public virtual bool[,] MovimientoPosible(){
		return new bool[10,18];
	}
}