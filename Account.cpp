#include "Account"

void Home::Front_Page() {
    int choice;
    std::string file_path = "Users.txt";
    std::cout<<"==============================\n"
             <<"|    WELCOME TO BOOKING APP  |\n"
             <<"==============================\n"
             <<"|                            |\n"
             <<"|                            |\n"
             <<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n"
             <<"|% 1. Log In %  2. Sign Up  %|\n"
             <<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n"
             <<"|                            |\n"
             <<"|                            |\n"
             <<"==============================\n";
    std::cout<<" Enter your Choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout<<"==============================\n"
                 <<"|    WELCOME TO BOOKING APP  |\n"
                 <<"==============================\n"
                 <<"|        LOGIN PANEL         |\n"
                 <<"|                            |\n"
                 <<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n"
                 <<"|% 1. Admin %  2. Customer  %|\n"
                 <<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n"
                 <<"|                            |\n"
                 <<"|                            |\n"
                 <<"==============================\n"; 
        
        std::cout<<" Enter your Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            admin.Input_login_Details();
        } else if (choice == 2) {
            user.Input_login_Details();
        } else {
            std::cout<<"Invalid Choice...\n";
        }
        
    }  else if (choice == 2) {
        std::cout<<"==============================\n"
                 <<"|    WELCOME TO BOOKING APP  |\n"
                 <<"==============================\n"
                 <<"|        SIGNUP PANEL        |\n"
                 <<"|                            |\n"
                 <<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n"
                 <<"|%     Hey New Customer     %|\n"
                 <<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n"
                 <<"|                            |\n"
                 <<"|                            |\n"
                 <<"==============================\n"; 

            user.SignUp(file_path);
    }  else {
        std::cout<<"Invalid choice...\n";
    }   
}

///////////////////////////////////  USERS IMPLEMENTATION  /////////////////////////////////////
// -------------------------------------------------------------------------------------------//
User_Panel::User_Panel() : Username(" "), Password(" ") {}
User_Panel::User_Panel(const std::string &username_parameter, const std::string &password_parameter) 
                       : Username(username_parameter), Password(password_parameter) {}

bool User_Panel::Login_Verification(const std::string &username_parameter, const std::string &password_parameter) {
    if (username_parameter == Username && password_parameter == Password) {
        std::cout<<"Login Successfully"<<std::endl;
        Menu_Panel();
        return true;
    } else {
        std::cout<<"Incorrent Username or Password"<<std::endl;
        return false;
    }
}

void User_Panel::Input_login_Details() {
    std::string username_arg, password_arg;

    std::cout << "Enter username or email: ";
    std::cin >> username_arg;

    std::cout << "Enter password: ";
    std::cin >> password_arg;

    std::ifstream infile("users.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening file for login.\n";
        return;
    }

    std::string line, name, username, password;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::getline(iss, name, ',');
        std::getline(iss, username, ',');
        std::getline(iss, password);

        if (username == username_arg && password == password_arg) {
            std::cout << "Login successful! Welcome, " << name << ".\n";
            Menu_Panel();
            infile.close();
            return;
        }
    }

    std::cout << "Invalid username or password.\n";
    infile.close();
}


#include <unordered_set>


bool IsUsernameTaken(const std::string& file_path, const std::string& username_or_email) {
    std::ifstream infile(file_path);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string name, username, password;
        std::getline(iss, name, ',');
        std::getline(iss, username, ',');
        if (username == username_or_email) {
            infile.close();
            return true;
        }
    }
    infile.close();
    return false;
}

// Signup function
void User_Panel::SignUp(const std::string &file_path) {
    std::string name, username_or_email, password;

    std::cout << "Enter your name: ";
    std::cin.ignore(); // To handle leftover newlines
    std::getline(std::cin, name);

    std::cout << "Enter a username or email: ";
    // std::cin.ignore();
    std::cin >> username_or_email;

    // Check if the username or email is already taken
    if (IsUsernameTaken(file_path, username_or_email)) {
        std::cout << "This username or email is already taken. Please try again." << std::endl;
        return;
    }

    std::cout << "Enter your password: ";
    std::cin >> password;

    // Save the new user to the file
    std::ofstream outfile(file_path, std::ios::app);
    if (!outfile) {
        std::cerr << "Error opening file for signup!" << std::endl;
        return;
    }

    outfile << name << "," << username_or_email << "," << password << std::endl;
    outfile.close();

    std::cout << "Signup successful! You can now log in." << std::endl;
}

///////////////////////////////////  ADMIN IMPLEMENTATION  ///////////////////////////////////////
// ---------------------------------------------------------------------------------------------//
Admin::Admin() : User_Panel(" ", " ") {}

Admin::Admin(const std::string &username_parameter, const std::string &password_parameter) 
             : User_Panel(username_parameter, password_parameter) {}

void Admin::Menu_Panel() {
    std::cout<<"Admin Panel:\n----------------------\n"
             <<"1.View Tickets\n"
             <<"2.Add Tickets\n"
             <<"3.Logout"
             <<std::endl;

            
}


///////////////////////////////////  CUSTOMERS IMPLEMENTATION  /////////////////////////////////////
// -----------------------------------------------------------------------------------------------//
Customer::Customer() : User_Panel(" ", " ") {}

Customer::Customer(const std::string &username_parameter, const std::string &password_parameter) 
                    : User_Panel(username_parameter, password_parameter) {}

void Customer::Menu_Panel() {
    Ticket view;
    std::cout << "\n======= CUSTOMER PANEL =======\n"
                  << "1. View Tickets\n"
                  << "2. Book a Ticket\n"
                  << "3. Exit\n"
                  << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            view.view_tickets();
            break;
        case 2:
            // booking
            break;
        case 3:
            return; 
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

void Account::LoadAccountsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, cardNumber, pin, cvv, expiry;
        double balance;

        std::getline(ss, name, ',');
        std::getline(ss, cardNumber, ',');
        std::getline(ss, pin, ',');
        ss >> balance;
        ss.ignore(); 
        std::getline(ss, cvv, ',');
        std::getline(ss, expiry);

        accounts[cardNumber] = {pin, balance, cvv, expiry};
    }
    file.close();
}

bool Account::IsCardExpired(const std::string& expiryDate) {
    int expMonth, expYear;
    sscanf(expiryDate.c_str(), "%d/%d", &expMonth, &expYear);

    time_t t = time(nullptr);
    tm* currentTime = localtime(&t);

    int currentYear = currentTime->tm_year + 1900;
    int currentMonth = currentTime->tm_mon + 1;

    if (expYear < currentYear || (expYear == currentYear && expMonth < currentMonth)) {
        return true;
    }
    return false;
}


bool Account::IsValidMasterCard(const std::string& cardNumber) {
    int n = cardNumber.length();
    int sum = 0;
    bool alternate = false;

    for (int i = n - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        alternate = !alternate;
    }

    return (sum % 10 == 0);
}


bool Account::ProcessPayment(const std::string& cardNumber, const std::string& enteredPin,
                             const std::string& enteredCvv, const std::string& expiryDate, double amount) {
    auto it = accounts.find(cardNumber);
    if (it == accounts.end()) {
        std::cout << "Card not found!" << std::endl;
        return false;
    }

    const AccountInfo& account = it->second;

    if (!IsValidMasterCard(cardNumber)) {
        std::cout << "Invalid Mastercard!" << std::endl;
        return false;
    }

    if (account.pin != enteredPin) {
        std::cout << "Invalid PIN!" << std::endl;
        return false;
    }

    if (account.cvv != enteredCvv) {
        std::cout << "Invalid CVV!" << std::endl;
        return false;
    }

    if (IsCardExpired(account.expiry)) {
        std::cout << "Card has expired!" << std::endl;
        return false;
    }

    if (account.balance < amount) {
        std::cout << "Insufficient balance!" << std::endl;
        return false;
    }

    accounts[cardNumber].balance -= amount;
    std::cout << "Payment of $" << std::fixed << std::setprecision(2) << amount << " processed successfully!" << std::endl;
    return true;
}
