/*****************************************************************************
Program    :  ATM MACHINE
Programmer :  Ajharul Islam Aunik
Last Edited:  10/30/22
Description: This ATM machine program allows users to check, deposit, withdraw, and 
transfer their balance. To transfer money from a user's checking account to his savings
account, he must enter his savings account number: 021000021 and 
routing number: 084009519. This program also allows the user to confirm that the 
transfer amount is accurate; if not, the user is prompted to enter a new amount.
Finally, the program asks the user if he wishes to conduct more transactions. 
If the user does not want to perform additional transactions, the program thanks the 
user and ends the program. 

When transferring funds from the user's checking account to his savings account, 
please input the savings account and routing number: 021000021, 084009519.
********************************************************************************/



#include <iostream> // for basic inputs and outputs
#include <string> // to initiate the string variables
#include <algorithm> // to convert the user's response to lowercase
#include <iomanip> // to manipulate the output

using namespace std;


// use void function to show menu to the user

void menu() {
	//display the menu
	cout << "---------------MENU---------------" << endl;
	cout << "1. Check Balance" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Transfer" << endl;
	cout << "5. Exit" << endl;
	cout << "----------------------------------" << endl;



}

// use void function to confirm user's deposit
void newDeposit() {

	cout << "1. I want to abort this deposit operation & return to the main menu." << endl;
	cout << "2. I want to initiate a new deposit." << endl;

}

int main() {

	//declare variables and initiate them

	enum optionType { Balance = 1, Deposit = 2, Withdraw = 3, Transfer = 4, Exit = 5 }; // use enumerations for inside switch statements
	int option = 0; // to store users input about what kind of transaction they want to do
	double totalBalance = 100000;
	double deposit = 0;
	int newDepositOption = 0;
	string userResponse = "?";
	string userContinue = "Y"; // to initiate the outer while loop
	string defaultResponse = "?";
	double newDepositAmount = 0.00;
	double withdrawAmount = 0.00;
	string savedAccountNumber = "021000021";
	string savingsAccount = "?";
	string savingsRouting = "?";
	string savedRoutingNumber = "084009519";
	string transferResponse = "?";
	string transferConfirmation = "?";
	double transferAmount = 0.00;
	double newTransferAmount = 0.00;


	// start of the outer while loop

	while (userContinue == "Y" || userContinue == "YES") {
		cout << endl;
		cout << "             " << "WELCOME TO JP MORGAN CHASE BANK" << endl;
		cout << endl;
        
		menu(); // initiate the void menu() function to show the menu to the user

		cout << endl;

        cout << "Please choose an option: " << endl;

		while (!(cin >> option)) { // take the user's input and handle the non-integer input
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Your chosen option should be a number. Please enter a number: " <<

				endl;
		}

		system("cls"); // to clear the console


		// start of the switch statement

		switch (option) {

		case Balance:
			cout << "Your current balance: " << "$" << totalBalance << endl;
			break;

		case Deposit: cout << "Please input your deposit amount: " << endl;
			while (!(cin >> deposit)) { // to input the non-integer input

		  cin.clear();

		  cin.ignore(numeric_limits<streamsize>::max(), '\n');

		  cout << "The deposit amount must be a number. Please enter a number: " <<

					endl;

             }

			// show the deposit amount

			cout << "You have made: $" << deposit << " " << "deposit" << endl;
			cout << "Is the deposit amount correct?" << " " << "YES|Y or NO|N" << endl; // confirmation of depsoit
			cin >> userResponse; // take the response of whether it is yes or no

			// convert the user's response to uppercase to avoid case issues

			for_each(userResponse.begin(), userResponse.end(), [](char& c) {

				c = ::toupper(c);

				});


			// show the total balance after deposit if the user says yes

			if (userResponse == "YES" || userResponse == "Y") {

				cout << "Your total balance: $" << totalBalance + deposit << endl;

            }

// if the user says no, show the newDeposit() function to the user 
// to know whether the user wants to initiate another new deposit or return to the main menu
			
	else if (userResponse == "NO" || userResponse == "N") {

		cout << endl;


	    newDeposit(); // show the user whether he wants to initiate another new deposit or retur to the main menu

			cin >> newDepositOption; // to store the value of the new depsosit if the initial depopsit amount is incorrect


			// start of  new switch statements

				switch (newDepositOption) {

				case 1:
					menu();

				case 2:
					cout << "Please input your new deposit amount: " << endl;


					while (!(cin >> newDepositAmount)) { // store the new depsoit amount and handle the non-integer value



	                  cin.clear();

						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						cout << "The new deposit amount should be a number. Please input a number : " <<

							endl;

					} // end of switch statements


					// show the new balance after the new depsoit amount
					cout << "Your new balance: $" << totalBalance + newDepositAmount << endl;

				}


				break;

			}



		case Withdraw:


			cout << "Please input your withdraw amount: " << endl;

			while (!(cin >> withdrawAmount)) { // store the withdraw amount and handle the non-integer input

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "The withdraw amount should be a number. Please input a number : " <<

					endl;

			}

			// if the withdraw amount exceeds the current balance

			if (withdrawAmount > totalBalance) {


				cout << "Insufficient Balance" << endl;

			}

			else {
				cout << endl;

				// show confirmation messages to the user

				cout << "You have withdrawn:" << setw(1) << right << "$" << withdrawAmount << endl;
				cout << "Your new balance: $" << totalBalance - withdrawAmount << endl;
			}

			break;

		case Transfer:

			//assume that the user wants to transfer money from his 
			//current checking account to his savings account.

			cout << "Do you want to transfer money from your checking account to your savings account? YES|Y or NO|N" << endl;

			cin >> transferResponse;// store the user response whether he wants to transfer money

			// convert the user's response to uppercase to get rid of the case sensitivity issues

			for_each(transferResponse.begin(), transferResponse.end(), [](char& c) {

				c = ::toupper(c);

				});

			if (transferResponse == "NO" || transferResponse == "N") {


				exit(0);
			}

			// start of transfer confirmation response

			if (transferResponse == "YES" || transferResponse == "Y") {

				//get user's savings account number
				cout << "Please input your account number: " << endl;
				cin >> savingsAccount;

				cout << endl;

				//get user's savings routing  number

				cout << "Please input your routing number: " << endl;

				cin >> savingsRouting;

				// store the transfer amount

				if (savingsAccount == savedAccountNumber && savingsRouting == savedRoutingNumber) {

					cout << endl;

					cout << "Please input your transfer amount: " << endl;

					cin >> transferAmount;

					// if the transfer amount exceeds the current balance

					if (totalBalance < transferAmount) {

						cout << endl;

						cout << "Unable to transfer money due to insufficient balance" << endl;
						cout << "Please try again from the start" << endl;

						exit(0);

                       }

					else {

						cout << endl;

						// transfer confirmation

						cout << "Is the transfer amount:" << " " << "$" << transferAmount << " " << "correct? YES|Y or NO|N" << endl;

						cin >> transferConfirmation;

						// convert the transfer confirmation response to uppercase

						for_each(transferConfirmation.begin(), transferConfirmation.end(), [](char& c) {

							c = ::toupper(c);

							});


						if (transferConfirmation == "YES" || "Y") {


							cout << "You have transferred :" << " " << "$" << transferAmount << " " << "to your savings account number: 021000021 & routing number: 084009519 " << endl;
							cout << "Your new balance: " << " " << "$" << totalBalance - transferAmount << endl;
							cout << "Thank you for using our ATM" << endl;

							break;

						}

						// take new transfer amount if the previous transfer amount is incorrect
						if (transferConfirmation == "NO" || "N") {

							cout << "Please input new transfer amount" << endl;
							cin >> newTransferAmount;

							cout << "You have transferred :" << " " << "$" << newTransferAmount << "to your savings account number: 021000021 & routing number: 084009519 " << endl;
							cout << "Your new balance: " << " " << "$" << totalBalance - newTransferAmount << endl;


						}





					}



				}


		// if the provided savings account number is wrong
				else if (savingsAccount != savedAccountNumber) {

					cout << "Wrong Account Number" << endl;
					cout << "Please try again from the start." << endl;

					exit(0);

                    }

		// if the provided routing account number is wrong

				else if (savingsRouting != savedRoutingNumber) {

					cout << "Wrong Routing Number" << endl;
					cout << "Please try again from the start." << endl;

					exit(0);


				}






			} // end of transfer confirmation

			break;



		case Exit: // if the user wants to exit from the menu

			exit(0);



		default: // for any unwanted input

			cout << "Invalid Input" << endl;
			cout << "Please start again! Thank you for using our ATM" << endl;

            exit(0);

		} // end of outer swich statments



		// ask the user whether he wants to another transaction

		if (option == 1 || option == 2 || option == 3 || option == 4) {

			cout << endl;
			cout << endl;
			cout << "Do you want to do another transaction? YES|Y or NO|N" << endl;
			cin >> userContinue;

			// convert the user's response to uppercase

			for_each(userContinue.begin(), userContinue.end(), [](char& c) {

				c = ::toupper(c);



				});
			

// thank you user and end the program if the user does not want to continue another transaction

			if (userContinue == "N0" || userContinue == "N") {
				cout << endl;

				cout << "Thank you using JP MORGAN CHASE BANK ATM" << endl;
				cout << "We look forward to seeing you again!" << endl;



			}

		}



	}





}








