using Lab_05.Database.Entities;
using Microsoft.EntityFrameworkCore;

namespace Lab_05.Database;

public class MyContext : DbContext
{
    public MyContext()
    {
        Database.EnsureCreated();
    }

    public DbSet<Student> Students { get; set; } = null!;
    public DbSet<Session> Sessions { get; set; } = null!;
    public DbSet<Result> Results { get; set; } = null!;

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseSqlServer(@"Server=(localdb)\mssqllocaldb;Database=lab5db;Trusted_Connection=True;");
    }
}
