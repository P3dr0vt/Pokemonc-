﻿#include "Pokemon.H"
using namespace std;

class Pokemon {
	string nome, tipo;
	int hp, ata, def;
	unordered_map<string, vector<string>> eficacia;
public:
	Pokemon(string name, string atk, string defe, string life, string type) {
		nome = name;
		ata = stoi(atk);
		def = stoi(defe);
		hp = stoi(life);
		tipo = type;

		eficacia = {
		{"Elétrico", {"Água", "Pedra"}},
		{"Água", {"Fogo", "Elétrico"}},
		{"Fogo", {"Gelo", "Água"}},
		{"Gelo", {"Pedra", "Fogo"}},
		{"Pedra", {"Elétrico", "Gelo"}}
		};

	}
	void stats() {
		cout << nome << " " << ata << " " <<  def << " " << hp << " " << tipo << " " << endl;
	}
	void ataque(Pokemon& destino) {
		bool vantagem = false, desvantagem = false;
		for (const string& tipoDestino : eficacia[tipo]) {
			if (tipoDestino == destino.tipo) {
				vantagem = true;
				break;
			}
		}
		for (const string& tipoOrigem : eficacia[destino.tipo]) {
			if (tipoOrigem == tipo) {
				desvantagem = true;
				break;
			}
		}

		if (vantagem) {
			this->efetivo(destino);
			// Realizar o ataque com vantagem
		}
		else if (desvantagem) {
			this->fraco(destino);
			// Realizar o ataque com desvantagem
		}
		else {
			this->normal(destino);
			// Realizar o ataque normal
		}
	}
	void efetivo(Pokemon& destino) {
		if ((ata + (ata * 0.2)) < def) {
			hp -= 1;
		}
		else {
			hp -= ((ata + (ata * 0.2)) - def);
		}
	}
	void fraco(Pokemon& destino) {
		if ((ata - (ata * 0.2)) < def) {
			hp -= 1;
		}
		else {
			hp -= ((ata - (ata * 0.2)) - def);
		}
	}
	void normal(Pokemon& destino) {
		if (ata < def) {
			hp -= 1;
		}
		else {
			hp -= (ata - def);
		}
	}
	string getNome() {
		return nome;
	}
	int getVida() {
		return hp;
	}
};

ifstream entradaDados("pokemon.txt");
//Essa função pega a Qntia de pokemon/jogador 
void quantiaPokemons(int& qntj1, int& qntj2) {
	string linha,x,y;
	if (entradaDados.is_open()) {
		getline(entradaDados, linha);
		stringstream ss(linha);
		ss >> x>>y;
		qntj1 = stoi(x); 
		qntj2 = stoi(y);
	}

}
//Essa função aqui eu fiz para alocar os pokemons aos seus devidos jogadores
void alocarPokemons(vector<Pokemon>& t1, vector<Pokemon>& t2,int j1Qnt) {
	string pokemons,name,atk,def,hp,type; 
	int i = 0;
	if (entradaDados.is_open()) {
		while (getline(entradaDados, pokemons)) {
			stringstream splitString(pokemons);
			splitString >> name >> atk >> def >> hp >> type;
			if (i < j1Qnt) {
				t1.push_back(Pokemon(name, atk, def, hp, type));
			}
			else {
				t2.push_back(Pokemon(name, atk, def, hp, type));
			}
			i++;
		}
	}
}
void Destruir(vector<Pokemon>& treinador,vector<Pokemon>& destruidos) {
	Pokemon defeated = treinador[0];
	destruidos.push_back(defeated);
	treinador.erase(treinador.begin());
}
bool verificaVivo(Pokemon& pokemon) {
	if (pokemon.getVida() <= 0) {
		return false;
	}
	else { return true; }
}
int main() {
	int j1, j2;
	vector<Pokemon> treinador1; vector<Pokemon> treinador2; vector<Pokemon> destruidos;
	quantiaPokemons(j1, j2);
	alocarPokemons(treinador1, treinador2, j1);
	for (Pokemon& pokemons : treinador1) {
		pokemons.stats();
	}
	cout << "Jogador2: " << endl;
	for (Pokemon& pokemons : treinador2) {
		pokemons.stats();
	}
	do {
		{
			Pokemon poke1 = treinador1[0];
			Pokemon poke2 = treinador2[0];
			if (!verificaVivo(poke2)) {
				Destruir(treinador2, destruidos);
			}
			else {
				poke1.ataque(poke2);
			}

			if (!verificaVivo(poke1)) {
				Destruir(treinador1, destruidos);
			}
			else {
				poke2.ataque(poke1);
			}
		}
	}
	while (!treinador1.empty() || !treinador2.empty());
}