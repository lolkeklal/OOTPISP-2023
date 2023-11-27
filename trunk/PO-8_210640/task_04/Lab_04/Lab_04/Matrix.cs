using System.Numerics;

namespace Lab_04;

class Matrix<T>(int rows, int columns) where T : INumber<T>
{
    public int Columns { get; init; } = columns;
    public int Rows { get; init; } = rows;

    private readonly T[,] matrix = new T[rows, columns];

    public T this[int row, int column]
    {
        get => matrix[row, column];
        set => matrix[row, column] = value;
    }

    public static Matrix<T> operator +(Matrix<T> a, Matrix<T> b)
    {
        if (a.Rows != b.Rows || a.Columns != b.Columns)
        {
            throw new MatrixException("Matrixes must have the same size");
        }

        var result = new Matrix<T>(a.Rows, a.Columns);

        for (var i = 0; i < a.Rows; i++)
        {
            for (var j = 0; j < a.Columns; j++)
            {
                result[i, j] = a[i, j] + b[i, j];
            }
        }

        return result;
    }

    public static Matrix<T> operator -(Matrix<T> a, Matrix<T> b)
    {
        if (a.Rows != b.Rows || a.Columns != b.Columns)
        {
            throw new MatrixException("Matrixes must have the same size");
        }

        var result = new Matrix<T>(a.Rows, a.Columns);

        for (var i = 0; i < a.Rows; i++)
        {
            for (var j = 0; j < a.Columns; j++)
            {
                result[i, j] = a[i, j] - b[i, j];
            }
        }

        return result;
    }

    public static Matrix<T> operator *(Matrix<T> a, Matrix<T> b)
    {
        if (a.Columns != b.Rows)
        {
            throw new MatrixException("Matrixes must have the same size");
        }

        var result = new Matrix<T>(a.Rows, b.Columns);

        for (var i = 0; i < a.Rows; i++)
        {
            for (var j = 0; j < b.Columns; j++)
            {
                result[i, j] = T.Zero;

                for (var k = 0; k < a.Columns; k++)
                {
                    result[i, j] += a[i, k] * b[k, j];
                }
            }
        }

        return result;
    }

    public T Max()
    {
        return matrix.Cast<T>().Max();
    }

    public T Min()
    {
        return matrix.Cast<T>().Min();
    }
}
