#include "../include/shell.h"
void launch_shell(int n)
{
    int pwAttempts = 0;

    do
    {
        shell();
        if (pw() == 1) // Check password
        {
            string ch = (string)malloc(200);

            do
            {
                print("\nAdagiaOS(");
                print(int_to_string(n));
                print(")> ");
                ch = readStr();

                if (strEql(ch, "cmd"))
                {
                    print("\n A new recursive window has been opened.\n");
                    launch_shell(n + 1);
                }
                else if (strEql(ch, "exit"))
                {
                    print("\nSee you!\n");
                    break; // Exit the inner loop (shell) when "exit" is entered
                }
                else if (strEql(ch, "clear"))
                {
                    clearScreen();
                }
                else if (strEql(ch, "devs"))
                {
                    dev();
                }
				else if (strEql(ch, "temp"))
                {
                    temp();
                }
                else if (strEql(ch, "res"))
                {
                    clearScreen();
                    // Additional actions for restarting, if needed
                    break; // Exit the inner loop (shell) when "res" is entered
                }
                else if (strEql(ch, "ver"))
                {
                    ver();
                }
                else if (strEql(ch, "print"))
                {
                    disp();
                }
                else if (strEql(ch, "calc"))
                {
                    calc();
                }
                else if (strEql(ch, "help"))
                {
                    help();
                }
                else if (strEql(ch, "color"))
                {
                    set_background_color();
                }
                else if (strEql(ch, "info"))
                {
                    info();
                }
                else
                {
                    print("\nPlease enter a valid command.\n");
                }

            } while (1); // Infinite loop; exit conditions handled internally

            if (strEql(ch, "exit"))
            {
                break; // Exit the outer loop when "exit" is entered
            }
        }
        else
        {
            pwAttempts++;

            if (pwAttempts == 3)
            {
                print("\nToo many incorrect attempts. Exiting.\n");
                break; // Exit the outer loop after three false attempts
            }
        }
    } while (1); // Infinite loop for password attempts
}

int pw()
{
    print("\n\nEnter the password: ");
    string password = "admin"; // Predefined password
    string pw = readStr();

    if (strEql(password, pw) == 1)
    {
        print("\n\nLogin successful. Welcome!\n\n");
        return 1;
    }
    else
    {
        clearScreen();
        print("Incorrect password.\nAccess denied. Please try again.\n");
        return 0;
    }
}

void disp()
{
	print("\n");
	string str = readStr();
	print("\n");
	print(str);
	print("\n");
}

void dev()
{
	print("\n\n FROM THE WONDERFUL PROGRAMMING SKILLS OF:\n SENTASAS, David Bryan L. \n CUALBAR, Angel Mae C. \n LA TORRE, Illac Lane S. \n REYES, Gabor Alexander B.\n SOLIS, Anthony Andrei \n TUTANES, Allen Christopher O. \n\n");
}

void info()
{
	print("\n\nThe best OS Project that ever existed in the land of the Philippines. \n");
	print("The AdagiaOS uses a minimalistic approach to provide essential\n");
	print("functionalities for efficient hardware management and user interaction.\n"); 
	print("Typically utilized in resource-constrained environments or educational \n");
	print("settings, the system prioritize simplicity and straightforward functionality.\n\n");
}

void ver()
{
	print("\n\n ADAGIAOS ver 1.0.0. You are updated to the latest version.\n\n *The current system is ran with Cygwin 3.4.9 \n\n");
}

void set_background_color()
{
	print("\nSelect a color : ");
	print("\n0 : black");
	print_colored("\n1 : blue",1,0);
	print_colored("\n2 : green",2,0);
	print_colored("\n3 : cyan",3,0);
	print_colored("\n4 : red",4,0);
	print_colored("\n5 : purple",5,0);
	print_colored("\n6 : orange",6,0);
	print_colored("\n7 : grey",7,0);
	print_colored("\n8 : dark grey",8,0);
	print_colored("\n9 : blue light",9,0);
	print_colored("\n10 : green light",10,0);
	print_colored("\n11 : blue lighter",11,0);
	print_colored("\n12 : red light",12,0);
	print_colored("\n13 : rose",13,0);
	print_colored("\n14 : yellow",14,0);
	print_colored("\n15 : white",15,0);
	
	print("\n\n Input desired text color: ");
	int text_color = str_to_int(readStr());
	print("\n\n Input desired bg color: ");
	int bg_color = str_to_int(readStr());
	set_screen_color(text_color,bg_color);
	clearScreen();
}



void calc()
{
	print("\n\nOPERATIONS AVAILABLE \n1 Add \n2 Subtract \n3 Multiply \n4 Divide \n");
	int input;
	print("\n\nSelect Operation:\n");
	int ope = str_to_int(readStr());	

	if (ope == 1)
	{
		print("\n\nNum 1 :");
		int num1 = str_to_int(readStr());
		print("\nNum 2 :");
		int num2 = str_to_int(readStr());
		print("\n\nResult : ");
		print(int_to_string(num1+num2)); // util.h
		print("\n");
	}

	
	else if (ope == 2)
	{
		print("\n\nNum 1 :");
		int num1 = str_to_int(readStr());
		print("\nNum 2 :");
		int num2 = str_to_int(readStr());
		print("\n\nResult : ");
		print(int_to_string(num1-num2)); // util.h
		print("\n");
	}

	else if (ope == 3)
	{
		print("\n\nNum 1 :");
		int num1 = str_to_int(readStr());
		print("\nNum 2 :");
		int num2 = str_to_int(readStr());
		print("\n\nResult : ");
		print(int_to_string(num1*num2)); // util.h
		print("\n");
	}

	else if (ope == 4)
	{
		print("\n\nNum 1 :");
		int num1 = str_to_int(readStr());
		print("\nNum 2 :");
		int num2 = str_to_int(readStr());
		print("\n\nResult : ");
		print(int_to_string(num1/num2)); // util.h
		print("\n");
	}

	else
	{
		print("\n NOT A VALID OPERATION! TRY AGAIN!");
	}
	
}

void help()
{
	print("\ncmd       : Launch a new recursive shell");
	print("\ninfo      : A short description of the OS");
	print("\nclear     : Clears the screen");
	print("\nver       : Displays the current version");
	print("\nprint     : Displays whatever you type");
	print("\ntemp      : Convert various temperature scales");
	print("\nres       : Restarts the system");
	print("\ndevs      : Displays the list of developers");
	print("\ncalc      : Opens a calculator");
	print("\ncolor     : Modify background color");
	print("\nexit      : Shuts the system down");

	print("\n\n");
}

void temp()
{
	print("\nChoose input unit:\n");
    print("1. Celsius\n");
    print("2. Fahrenheit\n");
    print("3. Kelvin\n");


    print("\nEnter your choice (1, 2, or 3): ");
    int choice = str_to_int(readStr());
 
    print("\n Choose output unit:\n");
    print("1. Celsius\n");
    print("2. Fahrenheit\n");
    print("3. Kelvin\n");
 
    
    print("\nEnter your choice (1, 2, or 3): ");
    int choice2 = str_to_int(readStr());
 
    // Get user input for temperature
    print("\nEnter temperature: ");
    int temperature = str_to_int(readStr());
 
    // Perform temperature conversion
    int convertedTemperature;
    // Perform conversion based on the chosen input and output units

	// Get user input for units
    switch (choice) {
        case 1:  // Celsius
            switch (choice2) {
                case 1:  // Celsius
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string(temperature));
                    break;
                case 2:  // Fahrenheit
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string((temperature * 9 / 5) + 32));
                    break;
                case 3:  // Kelvin
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string(temperature + 273));
                    break;
                default:
                    print("\nInvalid output choice.\n");
                    return;
            }
            break;
        case 2:  // Fahrenheit
            switch (choice2) {
                case 1:  // Celsius
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string((temperature - 32) * 5 / 9));
                    break;
                case 2:  // Fahrenheit
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string(temperature));
                    break;
                case 3:  // Kelvin
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string((temperature - 32) * 5 / 9 + 273));
                    break;
                default:
                    print("\nInvalid output choice.\n");
                    return;
            }
            break;
        case 3:  // Kelvin
            switch (choice2) {
                case 1:  // Celsius
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string((temperature - 273)));
                    break;
                case 2:  // Fahrenheit
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string((temperature - 273) * 9 / 5 + 32));
                    break;
                case 3:  // Kelvin
					print ("\n\nCONVERTED TEMP:");
                    print(int_to_string(temperature));
                    break;
                default:
                    print("\nInvalid output choice.\n");
                    return;
            }
            break;
        default:
            print("\nInvalid input choice.\n");
            return;
    }

}



    
 