using System.Runtime.Serialization;

namespace Lab_04
{
    [Serializable]
    internal class MatrixException : Exception
    {
        public MatrixException()
        {
        }

        public MatrixException(string? message) : base(message)
        {
        }

        public MatrixException(string? message, Exception? innerException) : base(message, innerException)
        {
        }
    }
}