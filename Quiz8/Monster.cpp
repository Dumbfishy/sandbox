#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <array>

using namespace std;


class Monster
{
public: 
    enum MonsterType
    {
        DRAGON,
        GOBLIN,
        ORGE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES
    };

private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_HP;

public:
    Monster(MonsterType type, std::string name, std::string roar, int HP) : m_type(type), m_name(name), m_roar(roar), m_HP(HP) {}

    std::string getTypeString()
    {
        switch(m_type) {
            case DRAGON:
                return "Dragon";
            case GOBLIN:
                return "Goblin";
            case ORGE:
                return "Orge";
            case ORC:
                return "Orc";
            case SKELETON:
                return "Skeleton";
            case TROLL:
                return "Troll";
            case VAMPIRE:
                return "Vampire";
            case ZOMBIE:
                return "Zombie";
            default:
                return "Unknow";
        }
    }

    void print()
    {
        cout << m_name << " the " << getTypeString() << " has " << m_HP << " hit points and says " << m_roar << endl;
    }
};

class MonsterGenerator
{
public:
    static Monster generateMonster()
    {

	Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0,Monster::MAX_MONSTER_TYPES - 1));
	int HP = getRandomNumber(0,100);

	static string s_names[6] = {"Tom","Dick","Harry","Ben","Chris","Marry"};
	static string s_roars[6] = {"*cough*","*roar*","*yelp*","*gnarl*","*gruggle*","*snap*"};

        return Monster(type, s_names[getRandomNumber(0,6)], s_roars[getRandomNumber(0,6)], HP);
    }

    static int getRandomNumber(int min, int max)
    {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
};


int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    Monster skele(Monster::SKELETON, "Bones", "*rattle*", 4);
    Monster orc(Monster::ORC, "Thrall", "*grub*", 10);
    skele.print();
    orc.print();
    cout << endl;

    Monster m = MonsterGenerator::generateMonster();
    m.print();
    
    return 0;
}
