#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string yesOrNo = "Yes";

    while (yesOrNo == "Yes")
    {
        std::cout << "Do you want to catch a fish? Yes or No?: " << std::endl;
        std::cin >> yesOrNo;

        if (yesOrNo == "No")
        {
            std::cout << "The program is completed";
        }
        else
        {
            int counter = 0;
            std::string fish ;
            std::cout << "What kind of fish do you want to catch?: " << std::endl;
            std::cin >> fish;
            std::string str;
            std::ifstream fileRiver("river.txt");
            if (!fileRiver.is_open())
            {
                std::cout << "Error!" << std::endl;
            }
            else
            {
                while (std::getline(fileRiver,str))
                {
                    if (str == fish)
                    {
                        counter++;
                    }
                }
                std::ofstream fileBasket("basket.txt", std::ios::app);
                if (!fileBasket.is_open())
                {
                    std::cout << "Error!" << std::endl;
                }
                else
                {
                    fileBasket << fish << ": " << counter << std::endl;
                }
                fileBasket.close();
            }
        }
    }
}
