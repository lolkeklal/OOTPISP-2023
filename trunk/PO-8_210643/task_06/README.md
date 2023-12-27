
# Лабораторная работа № 6 #

## Тема ##

Изучение UML. Диаграмма классов.

## Цель работы ##

Освоить построение диаграммы классов.

## Порядок выполнения ##

1. Изучить теоретический материал из [документации](https://mermaid.js.org/intro/getting-started.html).
2. Выбрать свой вариант.
3. Нарисовать каждый класс отдельно с методами и полями.
4. Оформить отчет.

## Вариант 9  ##

- Постройте UML диаграмму классов для системы управления учебным процессом в школе.

## Диаграмма ##

```mermaid

classDiagram
class Student {
  - string Name
  - string Surname
  - int Age
  - vector ~Subject~ Subjects
  + AddSubject()
}
class Professor {
  - string Name
  - string Surname
  - int Age
  + ManageEducation()
}
class Subject {
  - string Name
  - vector ~Professor~ Professors
  + AddProfessor()
  + GetData()
}
class Group{
  - string groupName
  - vector ~Subject~ Subjects
  - vector ~Student~ Students
  - string StudyPlan
  + AddStudent()
  + AddSubject()
  + ManageSchedule()
}
class University {
  - string SchoolName
  - vector ~Professor~ Professors
  - vector ~Group~ Groups

  + ManageClasses()
  + AddProfessor()
  + AddGroup()
}
University -- Group
Subject--Professor
Group--Subject
Group--Student
University--Professor 
Student--Subject

```

### Вывод ###

Освоила построение диаграммы классов.


