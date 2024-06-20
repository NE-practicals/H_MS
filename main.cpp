//Hospital management System
// BY Dorcus Mugisha
//on 20/06/2024


#include<iostream>
#include<string>
using namespace std;

//Define Patient's class
class Patient {
public:
    int patient_id;
    string patientName;
    string dob;
    string gender;
    Patient* next;
    Patient(int id, string patientName, string dob, string gender):patient_id(id),patientName(patientName),dob(dob),gender(gender), next(NULL){}
};
//Define doctor's class
class Doctor {
public:
    int doctor_id;
    string doctorName;
    string specialization;
    Doctor* next;
    Doctor(int id,string name,string specialization):doctor_id(id),doctorName(name),specialization(specialization),next(NULL){}


};
//Define appointmen class
class Appointment {
public:
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment* next;
    Appointment(int id, int p_id, int d_id, string ap_date) {
        appointment_id = id;
        patient_id = p_id;
        doctor_id = d_id;
        appointment_date = ap_date;
        next = NULL;
    }
};


//Patient's functions;
//Register patient
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
bool validatePatientId(Patient *&head, int id)
{
    Patient *temp = head;
    while (temp != NULL )
    {
        if (temp->patient_id == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
//finding patient
Patient* findPatient(Patient*& head, int id) {
    Patient* temp = head;
    while (temp!= NULL) {
        if (temp->patient_id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
//Displaying patients
void displayPatients(Patient*& head) {
    Patient* current = head;
        cout<< "Patients:" << endl;
    while (current!= NULL) {
        std::cout << "Patient_id: " << current->patient_id << ", Name: " << current->patientName<< ", Date of Birth: " << current->dob << ", Gender: " << current->gender << endl;
        current = current->next;
    }
}

// Validate id

//Registering doctor
void addDoctor(Doctor*& head, int id, string n, string s) {
    Doctor* newNode = new Doctor(id, n, s);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Doctor* temp = head;
    while(temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
//Finding doctor
Doctor* findDoctor(Doctor*& head, int id) {
    Doctor* current = head;
    while (current!= NULL) {
        if (current->doctor_id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//Displaying doctors;
void displayDoctors(Doctor*& head) {
    Doctor* temp = head;
    std::cout<< "Doctors:" << endl;
    while (temp!= NULL) {
        std::cout << "Doctor_id: " << temp->doctor_id << ", Name: " << temp->doctorName << ", Specialization: " << temp->specialization << endl;
        temp = temp->next;
    }
}
//validate the doctor's id
bool validateDoctorId(Doctor *&head, int id)
{
    Doctor *temp = head;
    while (temp != NULL)
    {
        if (temp->doctor_id == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void addAppointment(Appointment*& a_head,Patient*& head, Doctor*& doc_head,int id, int p_id, int d_id, string a_date) {

    if (findPatient(head, p_id) == NULL || findDoctor(doc_head, d_id) == NULL) {
        std::cout<< "Entered invalid id s press check again" << endl;
        return;
    }
    Appointment* newNode = new Appointment(id, p_id, d_id, a_date);
    if (a_head == NULL) {
        a_head = newNode;
        return;
    }
    Appointment* temp = a_head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//check if the ID already exits
bool validateAppointmentId(Appointment *&head, int id)
{
    Appointment *temp = head;
    while (temp != NULL)
    {
        if (temp->appointment_id == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void displayAppointments(Appointment*& head){
    Appointment* current = head;
    std::cout<< "Appointments:" << endl;
    while (current!= NULL) {
        cout << "Appointment_id: " << current->appointment_id << ", Patient_id: " << current->patient_id << ", Doctor_id: " << current->doctor_id << ", Appointment Date: " << current->appointment_date << endl;
        current = current->next;
    }
}
int main(){
    //the program will run on menu basis as follows:
    //1. Add a new patient
    //2. Add a new doctor
    //3. Add a new appointment
    //4. Display all patients
    //5. Display all doctors
    //6. Display all appointments
    //7. Exit
    int choice;

    Patient* pHead = NULL;
    Doctor* dHead = NULL;
    Appointment* appHead = NULL;
   //Welcome message
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
        switch (choice) {
            case 1: {
                int id, age;
                string name, dob, gender;
                std::cout<<"PATIENT REGISTRATION" << endl;
                std::cout<<"------------------------" << endl;
                std::cout << "Enter patient_id: ";
                cin >> id;
                std::cout << "Enter patient's name: ";
                cin.ignore();
                getline(cin, name);
                std::cout << "Enter date of birth (YYYY-MM-DD): ";
                cin >> dob;
                std::cout << "Enter patient's gender: ";
                cin >> gender;
                if (!(validatePatientId(pHead,id))){
                     addPatient(pHead, id, name, dob, gender);
                break;
                }else {
                    cout<<""<<endl;
                    cout<<"-----Patient's ID already exist-----"<<endl;
                    cout<<""<<endl;
                    cout<<"---------------Try Again------------"<<endl;
                    break;
                }


            }
            case 2: {
                int id;
                string name, specialization;
                std::cout<<"DOCTOR REGISTRATION" << endl;
                std::cout<<"------------------------" << endl;
                std::cout << "Enter doctor_id: ";
                cin >> id;
                std::cout << "Enter doctor's name: ";
                cin.ignore();
                getline(cin, name);
                std::cout << "Enter doctor's specialization: ";
                cin >> specialization;
                if(!(validateDoctorId(dHead,id))) {
                       addDoctor(dHead, id, name, specialization);
                break;
                }else {
                    cout<<""<<endl;
                    cout<<"-----Doctor's ID already exist-----"<<endl;
                    cout<<""<<endl;
                    cout<<"---------------Try Again------------"<<endl;
                    break;
                }

            }
            case 3: {
                int id, p_id, d_id;
                string a_date;
                std::cout<<"APPOINTMENT REGISTRATION" << endl;
                std::cout<<"------------------------" << endl;
                std::cout << "Enter appointment_id: ";
                cin >> id;
                std::cout << "Enter patient_id: ";
                cin >> p_id;
                std::cout << "Enter doctor_id: ";
                cin >> d_id;
                std::cout << "Enter appointment date (YYYY-MM-DD): ";
                cin >> a_date;
                if(!(validateAppointmentId(appHead,id))) {
                    addAppointment(appHead, pHead, dHead, id, p_id, d_id, a_date);
                break;
                }else {
                    cout<<""<<endl;
                    cout<<"-----Appointment's ID already exist-----"<<endl;
                    cout<<""<<endl;
                    cout<<"---------------Try Again------------"<<endl;
                    break;
                }

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
                std::cout << "Exit" << std::endl;
                return 0;
            }
    }}
    return 0;
}