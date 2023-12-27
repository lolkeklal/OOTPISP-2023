#include <iostream>
#include <string>
#include <vector>

class Patient {
public:
    Patient(const std::string& name, int age, const std::string& address)
        : name(name), age(age), address(address) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    std::string getAddress() const {
        return address;
    }

private:
    std::string name;
    int age;
    std::string address;
};

class Doctor {
public:
    Doctor(const std::string& name, const std::string& specialization)
        : name(name), specialization(specialization) {}

    std::string getName() const {
        return name;
    }

    std::string getSpecialization() const {
        return specialization;
    }

private:
    std::string name;
    std::string specialization;
};

class Appointment {
public:
    Appointment(const Patient& patient, const Doctor& doctor, const std::string& date)
        : patient(patient), doctor(doctor), date(date) {}

    Patient getPatient() const {
        return patient;
    }

    Doctor getDoctor() const {
        return doctor;
    }

    std::string getDate() const {
        return date;
    }

private:
    Patient patient;
    Doctor doctor;
    std::string date;
};

class MedicalRecord {
public:
   explicit MedicalRecord(const Patient& patient)
        : patient(patient) {}

    Patient getPatient() const {
        return patient;
    }


private:
    Patient patient;
};

class MedicalClinic {
public:
    void scheduleAppointment(const Patient& patient, const Doctor& doctor, const std::string& date) {
        Appointment appointment(patient, doctor, date);
        appointments.push_back(appointment);
    }

private:
    std::vector<Appointment> appointments;
};

int main() {
    // Пример использования классов
    Patient patient("Alice Smith", 30, "123 Medical St");
    Doctor doctor("Dr. Johnson", "Cardiologist");

    MedicalClinic clinic;
    clinic.scheduleAppointment(patient, doctor, "2023-01-15");

    return 0;
}
