#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
	int userInput = 0;
	double userSlot = 0.0;
	int numChips = 0;
	double winChips = 0.0;
	double avgWin = 0.0;
	const int RANDOM_SEED = 42;
	const double WIN_0_8 = 100;
	const double WIN_1_7 = 500;
	const double WIN_2_6 = 1000;
	const double WIN_3_5 = 0;
	const double WIN_4 = 10000;
	const double WIDTH = .5;

	srand(RANDOM_SEED);
	cout << "Welcome to the Plinko simulator!  Enter 3 to see options.\n\n";
	cout << "Enter your selection now: ";
	cin >> userInput;
	cout << endl;

	while (userInput != 4) {
		if (userInput == 1) {
			cout << "\n*** Drop a single chip ***\n";
			cout << "\nWhich slot do you want to drop the chip in (0-8)?\n";


			cin >> userSlot;
			

			if ((userSlot >= 0) && (userSlot <= 8)) {
				cout << "*** Dropping chip into slot " << fixed << setprecision(0) << userSlot << " ***\n";

				cout << fixed << setprecision(1) << "Path: [" << userSlot << ", ";

				for (int i = 1; i <= 12; i++) {
					
					if (userSlot == 0) {
						userSlot += WIDTH;
					}
					else if (userSlot == 8){
						userSlot -= WIDTH;
					}
					else {
						double chipPath = rand() % 2;

						if ((chipPath == 0.0)) { //sepearte the or and the &&
							userSlot -= WIDTH;
						}
						else {
							userSlot += WIDTH;
						}
					}

					if (i <= 11) {
						
						cout << fixed << setprecision(1) << userSlot << ", ";
					}
					else {
						
						cout << fixed << setprecision(1) << userSlot << "]\n";
					}


				}
				cout << "Winnings: $";
				if (userSlot == 0.0) {
					cout << fixed << setprecision(2) << WIN_0_8 << endl;
				}

				else if (userSlot == 1.0) {
					cout << fixed << setprecision(2) << WIN_1_7 << endl;
				}
				else if (userSlot == 2.0) {
					cout << fixed << setprecision(2) << WIN_2_6 << endl;
				}
				else if (userSlot == 3.0) {
					cout << fixed << setprecision(2) << WIN_3_5 << endl;
				}
				else if (userSlot == 4.0) {
					cout << fixed << setprecision(2) << WIN_4 << endl;
				}
				else if (userSlot == 5.0) {
					cout << fixed << setprecision(2) << WIN_3_5 << endl;
				}
				else if (userSlot == 6.0) {
					cout << fixed << setprecision(2) << WIN_2_6 << endl;
				}
				else if (userSlot == 7.0) {
					cout << fixed << setprecision(2) << WIN_1_7 << endl;
				}
				else if (userSlot == 8.0) {
					cout << fixed << setprecision(2) << WIN_0_8 << endl;
				}
			}
			else {
				cout << "Invalid slot." << endl;
			}
		} // If user presses 1 ends

		else if (userInput == 2) {
			winChips = 0.0;
			cout << "*** Drop multiple chips ***\n";
			cout << "How many chips do you want to drop (>0)\n?";
			cin >> numChips;
			if (numChips > 0) {
				cout << endl;
				cout << "\nWhich slot do you want to drop the chip in (0-8)?\n";


				cin >> userSlot;
				double dropSlot = userSlot;

				if ((userSlot >= 0.0) && (userSlot <= 8.0)) {
					for (int j = 1; j <= numChips; j++) {

						userSlot = dropSlot;

						if ((userSlot >= 0.0) && (userSlot <= 8.0)) {

							for (int i = 1; i <= 12; i++) {
					
								if (userSlot == 0) {
									userSlot += WIDTH;
								}
								else if (userSlot == 8){
									userSlot -= WIDTH;
								}
								else {
									double chipPath = rand() % 2;

									if ((chipPath == 0.0)) { //sepearte the or and the &&
										userSlot -= WIDTH;
									}

									else {
										userSlot += WIDTH;
									}
								}
					} //for loop ends

						} //if statement ends
						
						if (userSlot == 0.0) {
							winChips = winChips + WIN_0_8;
						}

						else if (userSlot == 1.0) {
							winChips = winChips + WIN_1_7;
						}
						else if (userSlot == 2.0) {
							winChips = winChips + WIN_2_6;
						}
						else if (userSlot == 3.0) {
							winChips = winChips + WIN_3_5;
						}
						else if (userSlot == 4.0) {
							winChips = winChips + WIN_4;
						}
						else if (userSlot == 5.0) {
							winChips = winChips + WIN_3_5;
						}
						else if (userSlot == 6.0) {
							winChips = winChips + WIN_2_6;
						}
						else if (userSlot == 7.0) {
							winChips = winChips + WIN_1_7;
						}
						else if (userSlot == 8.0) {
							winChips = winChips + WIN_0_8;
						}

					} //big for loop ends
					
					cout << "Total winnings on " << numChips << " chips: $" << fixed << setprecision(2) << winChips << endl;
					
					avgWin = winChips / numChips;
					cout << "Average winnings per chip: $" << fixed << setprecision(2) << avgWin << endl;
				}
				else {
					cout << "Invalid slot.";
				}
			}
			else {
				cout << "Invalid number of chips.";
			}
		}


		else if (userInput == 3) {
			cout << "Menu: Please select one of the following options:\n\n";
			cout << "1 - Drop a single chip into one slot\n";
			cout << "2 - Drop multiple chips into one slot\n";
			cout << "3 - Show the options menu\n";
			cout << "4 - Quit the program\n";
		}
		else {
			cout << "Invalid selection.  Enter 3 to see options.";
		}
		cout << "\nEnter your selection now: ";
		cin >> userInput;
		cout << endl;

		
	}

	if (userInput == 4) {
		cout << "Goodbye!";
		return 0;
	}
	
}
