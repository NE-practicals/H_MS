// Hospital Management System
// BY Dorcus Mugisha
// on 20/06/2024

#include <iostream>
#include <string>
#include <regex>
using namespace std;

// Define Patient's class
class Patient {
public:
    int patient_id;
    string patientName;
    string dob;
    string gender;
    Patient* next;
    Patient(int id, string patientName, string dob, string gender) : patient_id(id), patientName(patientName), dob(dob), gender(gender), next(NULL) {}
};

// Define Doctor's class
class Doctor {
public:
    int doctor_id;
    string doctorName;
    string specialization;
    Doctor* next;
    Doctor(int id, string name, string specialization) : doctor_id(id), doctorName(name), specialization(specialization), next(NULL) {}
};

// Define Appointment class
class Appointment {
public:
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment* next;
    Appointment(int id, int p_id, int d_id, string ap_date) : appointment_id(id), patient_id(p_id), doctor_id(d_id), appointment_date(ap_date), next(NULL) {}
};

// Patient's functions
// Register patient
void addPatient(Patient*& head, int id, string n, string d, string g) {
    Patient* newNode = new Patient(id, n, d, g);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Patient* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool validatePatientId(Patient*& head, int id) {
    Patient* temp = head;
    while (temp != NULL) {
        if (temp->patient_id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Finding patient
Patient* findPatient(Patient*& head, int id) {
    Patient* temp = head;
    while (temp != NULL) {
        if (temp->patient_id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Displaying patients
void displayPatients(Patient*& head) {
    Patient* current = head;
    cout << "Patients:" << endl;
    while (current != NULL) {
        cout << "Patient_id: " << current->patient_id << ", Name: " << current->patientName << ", Date of Birth: " << current->dob << ", Gender: " << current->gender << endl;
        current = current->next;
    }
}

// Registering doctor
void addDoctor(Doctor*& head, int id, string n, string s) {
    Doctor* newNode = new Doctor(id, n, s);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Doctor* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Finding doctor
Doctor* findDoctor(Doctor*& head, int id) {
    Doctor* current = head;
    while (current != NULL) {
        if (current->doctor_id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Displaying doctors
void displayDoctors(Doctor*& head) {
    Doctor* temp = head;
    cout << "Doctors:" << endl;
    while (temp != NULL) {
        cout << "Doctor_id: " << temp->doctor_id << ", Name: " << temp->doctorName << ", Specialization: " << temp->specialization << endl;
        temp = temp->next;
    }
}

// Validate the doctor's id
bool validateDoctorId(Doctor*& head, int id) {
    Doctor* temp = head;
    while (temp != NULL) {
        if (temp->doctor_id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Add appointment
void addAppointment(Appointment*& a_head, Patient*& head, Doctor*& doc_head, int id, int p_id, int d_id, string a_date) {
    if (findPatient(head, p_id) == NULL || findDoctor(doc_head, d_id) == NULL) {
        cout << "Entered invalid id(s), please check again" << endl;
        return;
    }
    Appointment* newNode = new Appointment(id, p_id, d_id, a_date);
    if (a_head == NULL) {
        a_head = newNode;
        return;
    }
    Appointment* temp = a_head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Check if the ID already exists
bool validateAppointmentId(Appointment*& head, int id) {
    Appointment* temp = head;
    while (temp != NULL) {
        if (temp->appointment_id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Display appointments
void displayAppointments(Appointment*& head) {
    Appointment* current = head;
    cout << "Appointments:" << endl;
    while (current != NULL) {
        cout << "Appointment_id: " << current->appointment_id << ", Patient_id: " << current->patient_id << ", Doctor_id: " << current->doctor_id << ", Appointment Date: " << current->appointment_date << endl;
        current = current->next;
    }
}

// Validate string input
bool validateStringInput(const string& input) {
    return !input.empty() && all_of(input.begin(), input.end(), [](char c) { return isalpha(c) || isspace(c); });
}

// Validate date input (basic check for "YYYY-MM-DD" format)
bool validateDateInput(const string& date) {
    regex date_pattern("\\d{4}-\\d{2}-\\d{2}");
    return regex_match(date, date_pattern);
}

// Validate integer input
bool validateIntegerInput(int input) {
    return input > 0;
}

int main() {
    int choice;

    Patient* pHead = NULL;
    Doctor* dHead = NULL;
    Appointment* appHead = NULL;

    cout << "=============================WELCOME BACK TO============================" << endl;
    cout << "         ==============RUHENGERI REFERAL HOSPITAL================" << endl;
    cout << "              =============MANAGEMENT SYSTEM=============" << endl;

    while (true) {
        cout << "1. Add a new patient" << endl;
        cout << "2. Add a new doctor" << endl;
        cout << "3. Add a new appointment" << endl;
        cout << "4. Display all patients" << endl;
        cout << "5. Display all doctors" << endl;
        cout << "6. Display all appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (!validateIntegerInput(choice)) {
            cout << "Invalid choice. Please try again." << endl;
            cin.clear(); // clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
            continue;
        }

        switch (choice) {
            case 1: {
                int id;
                string name, dob, gender;

                cout << "PATIENT REGISTRATION" << endl;
                cout << "------------------------" << endl;

                cout << "Enter patient_id: ";
                cin >> id;
                if (!validateIntegerInput(id) || validatePatientId(pHead, id)) {
                    cout << "Invalid or existing patient_id. Please enter a valid and unique patient_id." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cin.ignore();
                cout << "Enter patient's name: ";
                getline(cin, name);
                if (!validateStringInput(name)) {
                    cout << "Invalid name. Please enter a valid name." << endl;
                    break;
                }

                cout << "Enter date of birth (YYYY-MM-DD): ";
                cin >> dob;
                if (!validateDateInput(dob)) {
                    cout << "Invalid date format. Please enter date in YYYY-MM-DD format." << endl;
                    break;
                }

                cin.ignore();
                cout << "Enter patient's gender: ";
                getline(cin, gender);
                if (!validateStringInput(gender)) {
                    cout << "Invalid gender. Please enter a valid gender." << endl;
                    break;
                }

                addPatient(pHead, id, name, dob, gender);
                cout << "Patient added successfully!" << endl;
                break;
            }
            case 2: {
                int id;
                string name, specialization;

                cout << "DOCTOR REGISTRATION" << endl;
                cout << "------------------------" << endl;

                cout << "Enter doctor_id: ";
                cin >> id;
                if (!validateIntegerInput(id) || validateDoctorId(dHead, id)) {
                    cout << "Invalid or existing doctor_id. Please enter a valid and unique doctor_id." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cin.ignore();
                cout << "Enter doctor's name: ";
                getline(cin, name);
                if (!validateStringInput(name)) {
                    cout << "Invalid name. Please enter a valid name." << endl;
                    break;
                }

                cout << "Enter doctor's specialization: ";
                getline(cin, specialization);
                if (!validateStringInput(specialization)) {
                    cout << "Invalid specialization. Please enter a valid specialization." << endl;
                    break;
                }

                addDoctor(dHead, id, name, specialization);
                cout << "Doctor added successfully!" << endl;
                break;
            }
            case 3: {
                int id, p_id, d_id;
                string a_date;

                cout << "APPOINTMENT REGISTRATION" << endl;
                cout << "------------------------" << endl;

                cout << "Enter appointment_id: ";
                cin >> id;
                if (!validateIntegerInput(id) || validateAppointmentId(appHead, id)) {
                    cout << "Invalid or existing appointment_id. Please enter a valid and unique appointment_id." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter patient_id: ";
                cin >> p_id;
                if (!validateIntegerInput(p_id) || !findPatient(pHead, p_id)) {
                    cout << "Invalid or non-existing patient_id. Please enter a valid and existing patient_id." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter doctor_id: ";
                cin >> d_id;
                if (!validateIntegerInput(d_id) || !findDoctor(dHead, d_id)) {
                    cout << "Invalid or non-existing doctor_id. Please enter a valid and existing doctor_id." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter appointment date (YYYY-MM-DD): ";
                cin >> a_date;
                if (!validateDateInput(a_date)) {
                    cout << "Invalid date format. Please enter date in YYYY-MM-DD format." << endl;
                    break;
                }

                addAppointment(appHead, pHead, dHead, id, p_id, d_id, a_date);
                cout << "Appointment added successfully!" << endl;
                break;
            }
            case 4: {
                displayPatients(pHead);
                break;
            }
            case 5: {
                displayDoctors(dHead);
                break;
            }
            case 6: {
                displayAppointments(appHead);
                break;
            }
            case 7: {
                cout << "Exit" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}