using Lab_05.Database;
using Lab_05.Database.Entities;
using System.Windows;

namespace Lab_05
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            using var context = new MyContext();
            if (!context.Results.Any())
            {
                InitDB();
            }


            InitializeComponent();
        }

        private static void InitDB()
        {
            using var context = new MyContext();

            var students = new[]
            {
                new Student { Name = "Иванов Иван Иванович" },
                new Student { Name = "Петров Петр Петрович" },
                new Student { Name = "Сидоров Сидор Сидорович" },
                new Student { Name = "Александров Александр Александрович" },
                new Student { Name = "Алексеев Алексей Алексеевич" },
                new Student { Name = "Андреев Андрей Андреевич" },
                new Student { Name = "Антонов Антон Антонович" },
                new Student { Name = "Артемьев Артем Артемьевич" },
                new Student { Name = "Борисов Борис Борисович" },
                new Student { Name = "Вадимов Вадим Вадимович" },
                new Student { Name = "Валентинов Валентин Валентинович" },
                new Student { Name = "Валерьев Валерий Валерьевич" },
                new Student { Name = "Васильев Василий Васильевич" },
                new Student { Name = "Викторов Виктор Викторович" },
                new Student { Name = "Витальев Виталий Витальевич" },
                new Student { Name = "Владимиров Владимир Владимирович" },
                new Student { Name = "Владиславов Владислав Владиславович" },
                new Student { Name = "Вячеславов Вячеслав Вячеславович" },
                new Student { Name = "Геннадиев Геннадий Геннадиевич" },
                new Student { Name = "Георгиев Георгий Георгиевич" },
                new Student { Name = "Германов Герман Германович" },
            };
            context.Students.AddRange(students);
            context.SaveChanges();

            var disciplines = new[]
            {
                "Математика",
                "Физика",
                "Информатика",
                "Химия",
                "Биология",
                "География",
                "История",
                "Литература",
                "Русский язык",
                "Английский язык",
            };

            var types = new[]
            {
                SessionType.Exam,
                SessionType.Credit,
            };

            var sessions = new[]
            {
                new Session { Discipline = disciplines[0], Type = types[0] },
                new Session { Discipline = disciplines[1], Type = types[1] },
                new Session { Discipline = disciplines[2], Type = types[0] },
                new Session { Discipline = disciplines[3], Type = types[1] },
                new Session { Discipline = disciplines[4], Type = types[0] },
                new Session { Discipline = disciplines[5], Type = types[1] },
                new Session { Discipline = disciplines[6], Type = types[0] },
                new Session { Discipline = disciplines[7], Type = types[1] },
                new Session { Discipline = disciplines[8], Type = types[0] },
                new Session { Discipline = disciplines[9], Type = types[1] },
            };

            context.Sessions.AddRange(sessions);
            context.SaveChanges();

            students = context.Students.ToArray();
            sessions = context.Sessions.ToArray();

            foreach (var student in students)
            {
                var passedAll = Random.Shared.Next(0, 3) == 1;
                foreach (var session in sessions)
                {
                    var passed = passedAll || Random.Shared.Next(0, 3) == 1;

                    context.Results.Add(new Result
                    {
                        Student = student,
                        Session = session,
                        Passed = passed,
                    });
                }
            }
            context.SaveChanges();
        }


        private void PassedDataGrid_Initialized(object sender, EventArgs e)
        {
            using var context = new MyContext();

            var students = context.Students;
            var results = context.Results;

            var passed = students
                .Where(student => results
                .Where(result => result.Student == student)
                .All(result => result.Passed == true))
                .ToList();

            PassedDataGrid.ItemsSource = passed;
        }

        private void FailedDataGrid_Initialized(object sender, EventArgs e)
        {
            using var context = new MyContext();

            var students = context.Students;
            var results = context.Results;

            var failed = students
                .Where(student => results
                .Where(result => result.Student == student)
                .Any(result => result.Passed == false))
                .ToList();

            FailedDataGrid.ItemsSource = failed;
        }
    }
}