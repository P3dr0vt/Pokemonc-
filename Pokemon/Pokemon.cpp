// Pokemon.cpp: define o ponto de entrada para o aplicativo.
//

#include "Pokemon.h"
using namespace std;

class Pokemon
{
	string nome, tipo,status;
	int ata, def, vid;
public:
	Pokemon(string name, string atk, string deff, string life, string type ) {
		nome = name;
		tipo = type;
		ata = stoi(atk);
		def = stoi(deff);
		vid = stoi(life);
	}
	void Nome() {
		cout << "Nome: " << nome << endl;
	}
	void Tipo() {
		cout << "Tipo: " << tipo << endl;
	}
	void teste() {
		cout << def + vid;
	}
	void Ataque(Pokemon& destino) {
		destino.Dano(ata);
		
	}
	void Dano(int dano) {
		vid -= dano;
		if (vid <= 0) {
			cout << nome << " derrotado!" << endl;
		}
		else {
			cout << nome << " recebeu " << dano << " de dano, HP restante: " << vid << endl;
		}
	}
};

int main()
{
	ifstream txtpokemon("pokemon.txt");
	vector<Pokemon> treinador1;
	vector<Pokemon> treinador2;
	string n1, n2,name, hp, atk, def, type, linha;
	int n = 0, m = 0, index = 0;
	if (txtpokemon.is_open()) {
		getline(txtpokemon, linha);
		stringstream numPoke(linha);
		numPoke >> n1 >> n2;
		n = stoi(n1);
		m = stoi(n2);
		while (getline(txtpokemon, linha)) {
			stringstream splitString(linha);
			splitString >> name >> hp >> atk >> def >> type;
			if (index < n) {
			treinador1.push_back(Pokemon(name, hp, atk, def, type));
			}
			else {
				treinador2.push_back(Pokemon(name, hp, atk, def, type));
			}

			index++;
		}
	}
	else {
		cout << "Erro" << endl;
	}
	for (Pokemon& pokemon : pokemons) {

		}

	
	return 0;
}
