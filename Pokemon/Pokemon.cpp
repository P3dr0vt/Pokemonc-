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
	}
	void Tipo() {
		cout << "Tipo: " << tipo << endl;
	}
	}
	void Ataque(Pokemon& destino) {
		
	}
		}
		else {
		}
		
	}
};

int main()
{
	ifstream txtpokemon("pokemon.txt");
	vector<Pokemon> treinador1;
	vector<Pokemon> treinador2;
	int n = 0, m = 0, index = 0;
	if (txtpokemon.is_open()) {
		getline(txtpokemon, linha);
		stringstream numPoke(linha);
		numPoke >> n1 >> n2;
		n = stoi(n1);
		m = stoi(n2);
		while (getline(txtpokemon, linha)) {
			stringstream splitString(linha);
			if (index < n) {
			}
			else {
			}

			index++;
		}
	}
	else {
		cout << "Erro" << endl;
	}
		}

	
	return 0;
}
