#include <iostream>
using namespace std;
class Player
{
private:
	int lowerLimit;
	int upperLimit;
	int health;
	int defaultHealth;
	int damage;
	int heal;
public:
	Player(int _health, int _damage, int _heal, int _lowerLimit, int _upperLimit)
	{
		defaultHealth = _health;
		health = _health;
		damage = _damage;
		heal = _heal;
		lowerLimit = _lowerLimit;
		upperLimit = _upperLimit;
	}
	int GetHealth()
	{
		return health;
	}
	int GetDamage()
	{
		return damage;
	}
	int GetHeal()
	{
		return heal;
	}
	void SetHeal()
	{
		if (health == defaultHealth)
		{
			cout << "YOUR HELATH IS ALREADY FULL/n";

		}
		else if (health + heal > defaultHealth)
		{
			cout << "HEALTH IS FULL/n";
			health = health + (defaultHealth - health);
		}
		else
		{
			cout << "HEALTH IS INCREASED BY " << heal << endl;
			health = health + heal;
		}
	}
	void SetDamage(int _damage)
	{
		health = health - _damage;
	}
	int SpecialAbility(int _damage)
	{
		int l = lowerLimit + rand() % (upperLimit - lowerLimit + 1);
		l = l + _damage;
		return l;
	}

};
class Spiderman : public Player
{
public:
	Spiderman(int _health, int _damage, int _heal, int _lowerLimit, int _upperLimit) :Player(_health, _damage, _heal, _lowerLimit, _upperLimit)
	{
	}

};
class Ironman : public Player
{
public:
	Ironman(int _health, int _damage, int _heal, int _lowerLimit, int _upperLimit) :Player(_health, _damage, _heal, _lowerLimit, _upperLimit)
	{
	}
};
class Hulk : public Player
{
public:
	Hulk(int _health, int _damage, int _heal, int _lowerLimit, int _upperLimit) :Player(_health, _damage, _heal, _lowerLimit, _upperLimit)
	{
	}
};

void DisplayCharacter()
{
	cout << "\n\n\t\t\t\t\tCHARACTERS\n\n";
	cout << "1.NAME= SPIDER MAN  HEALTH= 100  DAMAGE= 25  HEALING= 25\n\n";
	cout << "2.NAME= IRON MAN  HEALTH= 60  DAMAGE= 50  HEALING= 40\n\n";
	cout << "3.NAME= HULK  HEALTH= 40  DAMAGE= 75  HEALING= 40\n\n";
}
void DisplayGameName()
{
	cout << "\t\t\t\tSHADOW FIGHT\n\n\n";
}
void Winner(Player* playerA, Player* playerB)
{
	int healthA, healthB;
	healthA = playerA->GetHealth();
	healthB = playerB->GetHealth();
	if (healthA <= 0)
		cout << "\nPLAYER 2 WINS";
	else if (healthB <= 0)
		cout << "\nPLAYER 1 WINS";
}
Player* SelectCharacter()
{
	int option;
	cin >> option;
	if (option == 1)
	{
		Player* S = new Spiderman(100, 25, 25, 20, 35);
		return S;
	}
	else if (option == 2)
	{
		Player* I = new Ironman(60, 50, 40, 5, 15);
		return I;
	}
	else if (option == 3)
	{
		Player* H = new Hulk(40, 75, 40, 5, 10);
		return H;
	}
	else
	{
		cout << "ENTERED CHARACTER IS NOT AVAILABLE\n";
		exit(0);
	}
	//cout<<selection;
	//return selection;
}
void Turn(int x, Player* player)
{
	switch (x)
	{
	case 1:
		cout << "\nPLAYER 1's TURN ";
		break;
	case 2:
		cout << "\nPLAYER 2's TURN ";
		break;
	}
}
int Option()
{
	int x;
	cout << "\nSELECT YOUR OPTION :\n";
	cout << "\n1.ATTACK\n2.HEAL\n";
	cin >> x;
	if (x > 2)
	{
		cout << "ENTERED OPTION IS NOT AVAILABLE\n. defaulting to attack";
		x = 1;
	}
	return x;
}
void PlayerStatus(Player* playerA, Player* playerB)
{

	cout << "PLAYER 1's HEALTH : " << playerA->GetHealth() << endl;
	cout << "PLAYER 2's HEALTH : " << playerB->GetHealth() << endl;
}
int main()
{
	int damage;
	int specialAbility;
	int specialDamage;
	int heal;
	int option;
	int i = 1;
	//game name disply
	DisplayGameName();
	//chara shown
	DisplayCharacter();
	//player1 choose
	//PLAYER ONE CHARA CREATION
	Player* playerA;
	cout << "PLAYER 1 SELECT CHARACTER ";
	playerA = SelectCharacter();
	playerA->GetHealth();
	//plYER 2 CHOOSE
	//PLAYER 2 CHARA CREATION
	Player* playerB;
	cout << "PLAYER 2 SELECT CHARACTER ";
	playerB = SelectCharacter();
	playerB->GetHealth();
	//while health or player 1 or 2 is lessthan 0 break the loop
	while (playerA->GetHealth() > 0 && playerB->GetHealth() > 0)
	{
		//FIGHT Round
		int x = 1;
		cout << "\n--------------------------------------------";
		cout << "\nROUND :" << i << endl;
		i++;
		PlayerStatus(playerA, playerB);
		Turn(x, playerA);

		option = Option();
		if (option == 1)
		{
			damage = playerA->GetDamage();
			specialDamage = playerA->SpecialAbility(damage);
			playerB->SetDamage(specialDamage);
			cout << "\nPLAYER CAUSE DAMAGE : " << specialDamage << "\n";
		}
		else if (option == 2)
		{
			playerA->SetHeal();
		}
		x++;
		if (playerB->GetHealth() < 0)
			break;
		PlayerStatus(playerA, playerB);
		Turn(x, playerB);

		option = Option();
		if (option == 1)
		{
			damage = playerB->GetDamage();
			specialDamage = playerB->SpecialAbility(damage);
			playerA->SetDamage(specialDamage);
			cout << "\nPLAYER CAUSE DAMAGE : " << specialDamage << "\n";
		}
		else if (option == 2)
		{
			playerB->SetHeal();
		}

		//each round both player get chance to attack and heal
		//players have 2 option heal or attack
			//if attack get the damage value of player and minus that value from the health of opp. player
			//if heal get the hael value of player and add to health of same player
		//dispaly players health 

	}
	//dispaly which player wins
	Winner(playerA, playerB);
	delete playerA;
	delete playerB;

}