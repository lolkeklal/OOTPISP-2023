
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.Common;
using Microsoft.Data.SqlClient;


namespace lab5wpf;


public static class DataBase
{
    public static readonly string connectionString = "Server=ALEXALAPTOP;Database=lab5;TrustServerCertificate=True; Trusted_Connection=True;";
    

    public static void CreateDb()
    {
        using (var connection = new SqlConnection(connectionString))
        {
            connection.Open();
            SqlCommand command = new SqlCommand();
            command.Connection = connection;
            command.CommandText =
                "CREATE TABLE reys (Id INT IDENTITY  PRIMARY KEY , T_in VARCHAR(10) NOT NULL , T_all VARCHAR(10) NOT NULL, T_out VARCHAR(10) NOT NULL);" +
                "CREATE TABLE machine (Id INT IDENTITY PRIMARY KEY, Nom INT NOT NULL, Id_reys INT, FOREIGN KEY (Id_reys) REFERENCES reys (Id) ON DELETE SET NULL);" +
                "CREATE TABLE states (Id INT IDENTITY PRIMARY KEY, Name VARCHAR(20) NOT NULL );" +
                "CREATE TABLE reys_states (Id INT IDENTITY PRIMARY KEY, Id_reys INT, Id_state INT, FOREIGN KEY (Id_reys) REFERENCES reys(Id) ON DELETE SET NULL , FOREIGN KEY (Id_state) REFERENCES states(Id) ON DELETE SET NULL );";
            command.ExecuteNonQuery();
        }
    }
}