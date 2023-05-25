/* The exercise has been exensively modified to respect
 * proper naming and to follow clean code guidelines that
 * are not followed in the course (probably for a practical reason)
*/

#include <iostream>
#include <stack>

int main(){
	std::stack<std::string> backStack;
    std::stack<std::string> forwardStack;
	std::string command;

    // Initialize the backStack with a default URL
    backStack.push("http://www.google.com");

	while(true)
    {
		std::cout << "[1] Visit URL   [2] Back   [3] Forward" << std::endl;
        std::cout << "Any other command will exit" << std::endl;
		std::cin >> command;

		if(command=="1")
        {
			std::cout << "Enter URL: ";
			std::cin >> command;
			backStack.push(command);
            forwardStack = {};
		}
		else if(command=="2")
        {
            if(backStack.size()==1)
            {
                std::cout << "No back history" << std::endl;
            }
            else
            {
                std::cout << " Going back..." << std::endl;
                forwardStack.push(backStack.top());
                backStack.pop();
            }
		}
        else if(command=="3")
        {
            if(forwardStack.empty())
            {
                std::cout << "No forward history" << std::endl;
            }
            else
            {
                std::cout << " Going forward..." << std::endl;
                backStack.push(forwardStack.top());
                forwardStack.pop();
            }
        }
        else
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        
		std::cout << "Current URL: " << backStack.top() << std::endl;
	}
	
	return 0;
}

