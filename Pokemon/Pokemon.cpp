// Pokemon.cpp: define o ponto de entrada para o aplicativo.
//

#include "Pokemon.h"
using namespace std;

class Pokemon
{
	string nome, tipo, status;
	int ata, def, vid;
public:
	Pokemon(string name, string atk, string deff, string life, string type) {
		nome = name;
		tipo = type;
		ata = stoi(atk);
		def = stoi(deff);
		vid = stoi(life);
	}
	string Nome() {
		return nome;
	}
	void Tipo() {
		cout << "Tipo: " << tipo << endl;
	}
	int vida() {
		return vid;
	}
	void Ataque(Pokemon& destino) {
		destino.RecebeDano(ata);

	}
	void RecebeDano(int dano) {
		if (dano < def) {
			vid -= 1;
		}
		else {
			vid -= dano - def;
		}

	}
};

int main()
{
	ifstream txtpokemon("pokemon.txt");
	vector<Pokemon> treinador1;
	vector<Pokemon> treinador2;
	vector<Pokemon> derrotados;
	string n1, n2, name, hp, atk, def, type, linha;
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
		cout << "Erro arquivo inexistente!" << endl;
	}
	while (!treinador1.empty() && !treinador2.empty()) {
		Pokemon& pokemon1 = treinador1[0];
		Pokemon& pokemon2 = treinador2[0];
		pokemon1.Ataque(pokemon2);
		if (pokemon2.vida() == 0) {
			Pokemon pokemonDerrotado = treinador2[0];
			cout << pokemon1.Nome() << " venceu " << pokemon2.Nome() << endl;
			derrotados.push_back(pokemonDerrotado);
			treinador2.erase(treinador2.begin());
		}
		pokemon2.Ataque(pokemon1);
		if (pokemon1.vida() == 0) {
			Pokemon pokemonDerrotado = treinador1[0];
			cout << pokemon2.Nome() << " venceu " << pokemon1.Nome() << endl;
			derrotados.push_back(pokemonDerrotado);
			treinador1.erase(treinador1.begin());
		}
	}
	if (treinador1.empty()) {
		cout << "Jogador 2 venceu" << endl;
		cout << "Pokemons sobreviventes:" << endl;
		for (Pokemon& pokemons : treinador2) {
			cout << pokemons.Nome() << endl;
		}
	}
	if (treinador2.empty()) {
		cout << "Jogador 1 venceu" << endl;
		cout << "Pokemons sobreviventes:" << endl;
		for (Pokemon& pokemons : treinador1) {
			cout << pokemons.Nome() << endl;
		}
	}
	cout << "Pokemons derrotados: " << endl;
	for (Pokemon& pokemons : derrotados) {
		cout << pokemons.Nome() << endl;
	}
	return 0;
}
