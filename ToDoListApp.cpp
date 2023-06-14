// Quick little CLI app I created to see what I can do after finishing a C++ book.

#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <string.h>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
 

template <typename T>
void DisplayCont (T& container)
{
	for (auto cont = container.cbegin(); cont != container.cend(); ++ cont)
	{
		std::cout << *cont << std::endl;;
	}
}




class toDo 
{

	std::string Deetz;			// Details of the what to do
	std::string Date;			// Date of when to do

	std::string DeetzDate;
	
public:

	toDo (std::string inputDeetz, std::string inputDate) : Deetz(inputDeetz), Date(inputDate)
	{
	}

	operator const char*()
	{
		std::ostringstream format;
		format << " To Do: " << Deetz << " | Date: " << Date;

		DeetzDate = format.str();
		return DeetzDate.c_str();
	}

	
	

friend std::ostream& operator<<(std::ostream& os, const toDo& dt);





};

template <typename T1>
const toDo& DisplaytoDo(T1& container)
{
	for (auto cont = container.cbegin(); cont != container.cend(); ++ cont)
	{
		std::cout << cont;
	}
}

std::ostream& operator<<(std::ostream& os, const toDo& dt)
{
os << "To Do: " << dt.Deetz << " | Date: " << dt.Date;
return os;
}

template <typename TT>
void DisplayContWIndex (TT& container)
{
int counter = -1;
if (container.size() == 0 || container.size() < 0)
{
	std::cout << "--> List is empty <--" << std::endl;
}

else
{
for (auto element = container.begin(); element != container.end(); ++element)
{
	++counter;
	std::cout << "List Index No. -> |" << counter << "| <- " << *element << std::endl;
}
}
}


int main()
{
	std::string input1;
	std::string input2;
	std::list<toDo>toDoList;

	std::string input1cpy;
	std::string input2cpy;
	std::string doAgain = "e";

	std::string option;
	std::string optioncpy;

	do{
	
	
	std::cout << "This is a to Do List Application" << std::endl;
	std::cout << "To create a to do list, type \"create list\"" << std::endl;
	std::cout << "To access to do list, type \"access list\"" << std::endl;
	std::cout << "To save the to do list, type \"save list\"" << std::endl;
	std::cout << "To exit application, type \"exit\" " << std::endl;
	
	std::getline(std::cin, option);
	optioncpy = option;


	std::transform(optioncpy.begin(), optioncpy.end(), option.begin(), ::tolower);
	if ((option == "1") || (option == "create list") || (option == "create"))
	{
	
	std::cout << "Type in what you need to do: ";
	std::getline(std::cin, input1);
	std::cout << "Type in the date: ";
	std::getline(std::cin, input2);

	toDo inputo1(input1, input2);
	

	std::cout << "Your to do list is: " << inputo1 << std::endl;
	std::cout << "Confirm creation (Y or N)" << std::endl;
	std::string opt1confirm;
	std::getline(std::cin, opt1confirm);
	if (opt1confirm == "y" || opt1confirm == "yeah" || opt1confirm == "yes")
	{
	toDo inputo1Copy(inputo1);
	toDoList.push_back(toDo(inputo1Copy));
	std::cout << std::endl;
	std::cout << "All to do lists are below" << std::endl;
	DisplayCont(toDoList);
	}

	else
	{
		std::cout << "Cancelling creation..." << std::endl;
	}
	}

	else if ((option == "2") || (option == "access list") || (option == "access"))
	{
		if (toDoList.empty())
		{
			std::cout << "|| No to do list has been created ||" << std::endl;
		}
		else
		{
			std::cout << "There are " << toDoList.size() << " lists" << std::endl;
			std::cout << "Current to do list is below: " << std::endl;
			DisplayContWIndex(toDoList);
			std::string choice2Option = "e";
			std::string modifyoption;
			std::cout << "Do you want to modify one of the list? Y or N" << std::endl;
			std::getline(std::cin, modifyoption);
			std::transform(modifyoption.begin(), modifyoption.end(), modifyoption.begin(), :: tolower);
			if (modifyoption == "y" || modifyoption == "Y" || modifyoption == "yes" || modifyoption == "yeah")
			{
				
				std::string modOptionStr;
				std::string modOptionStrCpy;
				std::cout << "Do you want to edit or delete. (Type \"edit\" or \"delete\")" << std::endl;
				std::getline(std::cin, modOptionStr);
				modOptionStrCpy = modOptionStr;
				std::transform(modOptionStr.begin(), modOptionStr.end(), modOptionStr.begin(), :: tolower);

				if (modOptionStr == "edit")
				{
					unsigned int indexOptA = 0;
					DisplayContWIndex(toDoList);
					std::cout << "Type in the index of the list you want to edit" << std::endl;
					std::cin >> indexOptA;
					auto indexOptACheck = toDoList.size();//
				if (indexOptA >= toDoList.size())
				{
					std::cout << "Index: " << indexOptA << " does not exist" << std::endl;
					std::cin.ignore();
				}
				 
				
				else
					{
						std::cout << "Editing to Do List index: " << indexOptA << std::endl;
						auto indexOptAcout = std::next(toDoList.begin(), indexOptA);
						std::string deetzReplace;
						std::string dateReplace;
						std::cout << "You are replacing list index " << indexOptA << std::endl;
						std::cout << "The list contents are: " << *indexOptAcout << std::endl;
						std::cout << "Write the replacement 'To Do' below" << std::endl;
						std::cin.ignore();
						std::getline(std::cin, deetzReplace);
						std::cout << "Write the replacement 'Date' below" << std::endl;
						//
						std::getline(std::cin, dateReplace);
						toDo indexOptACopy(deetzReplace, dateReplace);
						std::cout << "You are replacing To Do list index: " << indexOptA << ". Where Its contents are shown below: " << std::endl;
						std::cout << "Replacing \"" << *indexOptAcout << "\" for new To Do list: \"" << indexOptACopy << "\"" << std::endl;
						std::cout << "Confirm? (Y or N)" << std::endl;
						std::string indexOptAConfirm;
						std::getline(std::cin, indexOptAConfirm);
						std::transform(indexOptAConfirm.begin(), indexOptAConfirm.end(), indexOptAConfirm.begin(),::tolower);
						if (indexOptAConfirm == "y" || indexOptAConfirm == "yes" || indexOptAConfirm == "yeah")
						{
						std::cout << "Now replacing..." << std::endl; 
						auto indexOptAcoutCopy = std::next(toDoList.begin(), (indexOptA));
						auto indexOptAcoutCopy2 = std::next(toDoList.begin(), (indexOptA +1));
						
						if (toDoList.size() < 1)
						{
							toDoList.erase(indexOptAcout);
							toDoList.insert(toDoList.begin(), indexOptACopy);
						}

						else 
						{	
							toDoList.insert(indexOptAcoutCopy2, indexOptACopy);
							toDoList.erase(indexOptAcout);
						}

						
						//
						std::cout << "List Index " <<indexOptA << " has been replaced" << std::endl;
						std::cout << "New To Do list shown below..." << std::endl;
						DisplayContWIndex(toDoList);
						}

						else
						{
							std::cout << "Cancelling replacement... " << std::endl;
						}
					}
				
				}

				else if (modOptionStr == "delete")
				{
					unsigned int indexOptB = 0;
					DisplayContWIndex(toDoList);
					std::cout << "Type in the index of the list you want to delete" << std::endl;
					std::cin >> indexOptB;
					auto indexOptBCheck = toDoList.size();
					
					if (indexOptB >= toDoList.size())
					{
						std::cout << "Index: " << indexOptB << " does not exist" << std::endl;
						std::cin.ignore();
					}

					else
					{
						auto indexOptBcout = std::next(toDoList.begin(), indexOptB);
						std::cout << "Deleting to Do List index: " << indexOptB << std::endl;
						std::cout << "You are deleting to Do List index: " << indexOptB << std::endl;
						std::cout << "This list contents are: " << *indexOptBcout << std::endl;
						std::string indexOptBConfirm;
						std::cout << "Confirm deletion? of \"index: " << indexOptB << " " << *indexOptBcout << "\" (Y or N)" << std::endl;
						std::cin.ignore();
						std::getline(std::cin, indexOptBConfirm);
						std::transform(indexOptBConfirm.begin(), indexOptBConfirm.end(), indexOptBConfirm.begin(), :: tolower);
						if (indexOptBConfirm == "y" || indexOptBConfirm == "yeah" || indexOptBConfirm == "yes")
						{
							std::cout << "Now deleting index " << indexOptB << "..." << std::endl;
							toDoList.erase(indexOptBcout);
							std::cout << "Index " << indexOptB << " has been removed" << std::endl;
							std::cout << "New To Do list is shown below" << std::endl;
							DisplayContWIndex(toDoList);
							
						}

						else
						{
						std::cout << "Cancelling delete for index " << indexOptB << " " << *indexOptBcout << "... " << std::endl;
						}
						
						
					}
				
				}
				
				else
				{
					std::cout << "\""<<modOptionStrCpy<<"\"" << " is an unrecognisable command" << std::endl;
				}

				
			}

	
		}	
			
		}

	else if ((option == "3") || (option == "save list") || (option == "save"))
	{
	if (toDoList.size() <= 0)
	{
		std::cout << "|| No to do list has been created||" << std::endl;
	}

	else
	{
		std::cout << "Your current to do list: " << std::endl;
		DisplayCont(toDoList);
		std::cout << "Do you want to save? (Y or N)" << std::endl;
		std::string saveOpt;
		std::string saveOptcpy(saveOpt);
		std::getline(std::cin, saveOpt);
		std::transform(saveOpt.begin(), saveOpt.end(), saveOpt.begin(), ::tolower);
		if (saveOpt == "yes" || saveOpt == "yeah" || saveOpt == "y")
		{
			std::cout << "You are saving the to do list shown below: " << std::endl;
			DisplayCont(toDoList);
			std::cout << "Confirm? (Y or N)" << std::endl;
			std::string saveConfirm;
			
			std::getline(std::cin, saveConfirm);
			if (saveConfirm == "y" || saveConfirm == "yeah" || saveConfirm == "yes")
			{
				std::string saveConfirmCancel;
				bool saveFinish = 0;
				do
				{
					std::cout << "To cancel type \"/cancel\"" << std::endl;
					std::cout << '\n';
					std::cout << "Type filename" << std::endl;
					std::string saveFileName;
					std::getline(std::cin, saveFileName);
					saveConfirmCancel = saveFileName;
					std::ofstream File;
					std::string txtEnd(".txt");
					
					File.open((saveFileName += txtEnd), std::ios_base::out);
					
					if (File.is_open())
					{
						
						std::cout << "File creation successful" << std::endl;

						File << "To Do List" << std::endl;
						for (auto element = toDoList.begin(); element != toDoList.end(); ++ element)
						{
						File << *element << std::endl;
						}

						std::cout << "File saved succesfully" << std::endl;
						 

						File.close();
					}

					else
					{}
					

					 
					//
					std::transform(saveConfirmCancel.begin(), saveConfirmCancel.end(), saveConfirmCancel.begin(), ::tolower);
					saveFinish = true;
				}while(saveConfirmCancel != "/cancel" && (saveFinish != true));
				if (saveConfirmCancel == "/cancel")
				{
					std::cout << "Cancelling save..." << std::endl;
				}

				else
				{}
			}

			else
			{
				std::cout << "Cancelling save..." << std::endl;
			}
		}

		else
		{
			std::cout << "Cancelling save..." << std::endl;
		}
	}

	}

	else if ((option == "exit"))
	{
	doAgain = option;
		
	}
	
	else
	{
		

		std::cout << "\"" << optioncpy << "\"" << " is an unrecognisable command" << std::endl;
	}
	std::cin.clear();
	if ((option != "exit") )
	{
	
	
	
	std::cout << "Go back to start menu? | Y or N" << std::endl;
	

	
	std::getline(std::cin, doAgain);
	
	std::cin.clear();
	
	}
	std::transform(doAgain.begin(), doAgain.end(), doAgain.begin(), :: tolower);
	} while ((doAgain == "y") || (doAgain == "yes") || (doAgain == "yeah") && (doAgain != "exit") );
	
	std::cout << std::endl;
	std::cout << "Program ending. Goodbye" << std::endl;
	return 0;
}