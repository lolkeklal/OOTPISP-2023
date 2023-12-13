
# Лабораторная работа №6

## Создание интерфейса простых приложений

## Вариант 20

## Цель лабораторной работы

Отработка умений и навыков описания событий в приложениях.

## Задание №10

Постройте UML диаграмму классов для системы управления медицинской клиникой.

## Демонстрация UML диаграммы


```mermaid
classDiagram
    class Patient {
        +getName(): string
        +getAge(): int
        +getAddress(): string
    }

    class Doctor {
        +getName(): string
        +getSpecialization(): string
    }

    class Appointment {
        +getPatient(): Patient
        +getDoctor(): Doctor
        +getDate(): string
    }

    class MedicalRecord {
        +getPatient(): Patient
        // Дополнительные методы для ведения медицинской истории и данных о пациенте
    }

    class MedicalClinic {
        +scheduleAppointment(patient: Patient, doctor: Doctor, date: string): void
        // Дополнительные методы для управления пациентами, врачами и приемами
    }

    Patient --|> MedicalRecord : has
    Appointment --|> Patient : involves
    Appointment --|> Doctor : involves
    MedicalClinic --|> Appointment : schedules
    MedicalClinic --|> Patient : manages
    MedicalClinic --|> Doctor : manages

```



