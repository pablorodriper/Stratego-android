using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class BoardHighlight : MonoBehaviour {

	public static BoardHighlight Instance { set; get; }

	public GameObject highlightPrefab;
	private List<GameObject> highlights;

	private void Start(){
		Instance = this;
		highlights = new List<GameObject> ();
	}

	/**
	 * Instancia el prefab
	 */
	private GameObject GetHighlightObject(){
		//Devuelve algo si (activeSelf == false)
		GameObject go = highlights.Find (g => !g.activeSelf);

		if(go == null){
			go = Instantiate (highlightPrefab);
			highlights.Add (go);
		}

		return go;
	}

	/**
	 * Introduce un array de movimientos posibles e ilumina las casillas xy correspondientes
	 */
	public void HighlightMovimientosPermitidos(bool[,] movimientosPermitidos){
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 18; j++) {
				if (movimientosPermitidos [i, j]) {
					GameObject go = GetHighlightObject ();
					go.SetActive (true);
					go.transform.position = new Vector3 (i + 0.5f, 0.01f, j + 0.5f);
				}
			}
		}
	}
		
	public void encenderCasilla(int i, int j){
		GameObject go = GetHighlightObject ();
		go.SetActive (true);
		go.transform.position = new Vector3 (i + 0.5f, 0.01f, j + 0.5f);
	}
		
	public void Hidehighlights(){
		foreach (GameObject go in highlights)
			go.SetActive (false);
	}
}
