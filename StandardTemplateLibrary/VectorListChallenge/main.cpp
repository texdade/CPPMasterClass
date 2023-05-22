/* The exercise has been exensively modified to respect
 * proper naming and to follow clean code guidelines that
 * are not followed in the course (probably for a practical reason)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
 
//#define USE_VECTOR
#define USE_LIST 
 
class Guest
{
public:
	Guest(std::string name, std::string gender, int age)
    {
        this->name = name;
        this->gender = gender;
        this->age = age;
    }
	~Guest(){}

    const std::string& getName() const { return name; }
    const std::string& getGender() const { return gender; }
    int getAge() const { return age; }


private:
    std::string name;
	std::string gender;
	int age;
};

#ifdef USE_VECTOR
	typedef std::vector<Guest> myContainer;
#elif defined USE_LIST
	typedef std::list<Guest> myContainer;
#endif

void readFile(myContainer& myGuests)
{
	std::string inStr;
	std::ifstream inFile("my_guests.txt");

	if(inFile.is_open()){
        std::string name;
        std::string gender;
        int age;

        // I don't like this format for data, but it's the way the course does it
		while(getline(inFile, inStr)){
			name=inStr;
			getline(inFile,inStr);
			gender = inStr;
			getline(inFile,inStr);
			age=stoi(inStr);

            Guest myGuest = Guest(name, gender, age);
			myGuests.push_back(myGuest);
		}
		inFile.close();
	}
	else
		std::cout << "Unable to open file!\n\n";
}

void printGuests(const myContainer& myGuests)
{
	auto it = myGuests.begin();
	
	std::cout << "-- Container Content Start --\n";
	std::cout << "-----------------------------\n";

    for(const Guest& guest : myGuests)
    {
        std::cout << "Name: " << guest.getName() << std::endl;
		std::cout << "Gender: " << guest.getGender() << std::endl;
		std::cout << "Age: " << guest.getAge() << std::endl;
		std::cout << "-----------------------------\n";
    }

	std::cout << "--  Container Content End  --\n";
}

int main()
{
	myContainer myGuests = myContainer();
	readFile(myGuests);
	printGuests(myGuests);
	return 0;
}












