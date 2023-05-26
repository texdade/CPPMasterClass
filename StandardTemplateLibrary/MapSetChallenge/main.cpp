/* The exercise has been exensively modified to respect
 * proper naming and to follow clean code guidelines that
 * are not followed in the course (probably for a practical reason)
*/

#include <iostream>
#include <map>
#include <unordered_map>

class Guest
{
public:
	Guest(){}
	Guest(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }
	~Guest(){}

	void toLog() const
    {
		std::cout << "-----------------------------\n";
        std::cout << "Name: " << name << std::endl;
		std::cout << "Age: " << age << std::endl;
	}

    const std::string& getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }
    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    std::string toString()
    {
        std::string str{this->name + " | " + std::to_string(this->age)};
        return str;
    }

private:
    std::string name;
	int age;
};

//room is made up of 3-4 digits, first (and second if we have four digits) 
//digit is floor, second and third digits are the room number
//hotel has 20 floors with 15 rooms each
bool checkRoom(int floorAndRoom)
{
    std::string roomStr = std::to_string(floorAndRoom);
    
    if(roomStr.length() >= 3)
    {
        int floor = std::stoi(roomStr.substr(0, roomStr.length()-2));
        int room = std::stoi(roomStr.substr(roomStr.length()-2, roomStr.length()));

        std::cout << "floor: " << floor << " room: " << room << std::endl;

        if(floor > 0 && floor <= 20 && room > 0 && room <= 15)
        {
            return true;
        }
    }

    return false;
}

int main()
{
	std::map<int, Guest> hotel;
	int room;
	std::string command;
	std::pair<int, Guest> guestRoomPair;
	
	std::cout << "Inserting...\n";

	while(room>=0){
        Guest guest;
		std::cout << "Enter room number: ";
		std::getline(std::cin, command);
		room = std::stoi(command);
		if(checkRoom(room)){
			guestRoomPair.first= room;

			std::cout << "Enter name: ";
			getline(std::cin, command);
			guest.setName(command);

            std::cout << "Enter age: ";
            std::getline(std::cin, command);
            guest.setAge(std::stoi(command));

            guestRoomPair.second = guest;
			hotel.insert(guestRoomPair);
		}
	}
	
	std::cout << "{   ";
	for(std::map<int, Guest>::iterator it = hotel.begin(); it!=hotel.end(); it++)
    {
		std::cout << it->first << " -> " << it->second.toString() << "   ";
    }

	std::cout << "}\n";
	
	return 0;
}