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
		destino.RecebeDano(ata);
		
	}
	void RecebeDano(int dano) {
		if (dano < def) {
			vid -= 1;
			cout << nome << " perdeu 1 de hp!" << endl;
		}
		else {
			vid -= dano - def;
			cout << nome << " recebeu " << dano-def <<" de dano." << endl;
			if (
				vid == 0
				) {
				cout << nome << " foi derrotado ;-(" << endl;
			}
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
			splitString >> name >> atk >> def >> hp >> type;
			if (index < n) {
			treinador1.push_back(Pokemon(name, atk, def, hp, type));
			}
			else {
				treinador2.push_back(Pokemon(name, atk, def, hp, type));
			}

			index++;
		}
	}
	else {
		cout << "Erro" << endl;
	}
	Pokemon& pokemon1 = treinador1[0];
	pokemon1.Nome();
	Pokemon& pokemon2 = treinador2[0];
	pokemon2.Nome();
	pokemon1.Ataque(pokemon2);
	pokemon1.Ataque(pokemon2);
	return 0;
}
