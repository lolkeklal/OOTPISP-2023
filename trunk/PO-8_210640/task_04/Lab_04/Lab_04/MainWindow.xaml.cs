using System.Data.Common;
using System.Numerics;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Windows.Media;

namespace Lab_04
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            GenerateCommand.InputGestures.Add(new KeyGesture(Key.G, ModifierKeys.Control));
            PlusCommand.InputGestures.Add(new KeyGesture(Key.OemPlus, ModifierKeys.Control));
            MinusCommand.InputGestures.Add(new KeyGesture(Key.OemMinus, ModifierKeys.Control));
            MultiplyCommand.InputGestures.Add(new KeyGesture(Key.Multiply, ModifierKeys.Control));
        }

        private Matrix<int> MatrixA { get; set; } = new Matrix<int>(3, 3);
        private Matrix<int> MatrixB { get; set; } = new Matrix<int>(3, 3);
        private Matrix<int> MatrixC { get; set; } = new Matrix<int>(3, 3);

        private static void InitializeUniformGrid(UniformGrid uniformGrid, int rows, int columns)
        {
            uniformGrid.Children.Clear();
            uniformGrid.Rows = rows;
            uniformGrid.Columns = columns;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    var textBox = new TextBox
                    {
                        IsReadOnly = true,
                        FontSize = 50,
                        TextAlignment = TextAlignment.Center,
                        ToolTip = "",
                    };

                    textBox.ToolTipOpening += (sender, e) =>
                    {
                        if (sender is TextBox textBox)
                        {
                            textBox.ToolTip = textBox.Text;
                        }
                    };

                    textBox.SizeChanged += (sender, e) =>
                    {
                        if (e.PreviousSize.Height == 0)
                        {
                            return;
                        }
                        
                        ((TextBox)sender).FontSize *= e.NewSize.Height / e.PreviousSize.Height;
                    };

                    textBox.TextChanged += (sender, e) =>
                    {
                        if (sender is TextBox textBox)
                        {
                            var length = textBox.Text.Length;
                            var prevLength = e.Changes.First().RemovedLength;
                            double coef = length switch
                            {
                                0 => 50,
                                1 => 50,
                                2 => 50,
                                3 => 50,
                                4 => 45,
                                5 => 35,
                                6 => 30,
                                _ => 20,
                            };

                            coef /= prevLength switch
                            {
                                0 => 50,
                                1 => 50,
                                2 => 50,
                                3 => 50,
                                4 => 45,
                                5 => 35,
                                6 => 30,
                                _ => 20,
                            };

                            textBox.FontSize *= coef;
                        }
                    };

                    uniformGrid.Children.Add(textBox);
                }
            }
        }

        private static void FillUniformGrid<T>(UniformGrid uniformGrid, Matrix<T> matrix) where T : INumber<T>
        {
            if (uniformGrid.Rows != matrix.Rows || uniformGrid.Columns != matrix.Columns)
            {
                throw new Exception("Matrix and uniform grid dimensions do not match.");
            }

            for (int i = 0; i < uniformGrid.Rows; i++)
            {
                for (int j = 0; j < uniformGrid.Columns; j++)
                {
                    var textBox = (TextBox)uniformGrid.Children[i * matrix.Columns + j];
                    textBox.Text = matrix[i, j].ToString();
                }
            }
        }

        private void UniformGridA_Initialized(object sender, EventArgs e)
        {
            MatrixA = new Matrix<int>(3, 3);

            InitializeUniformGrid(UniformGridA, MatrixA.Rows, MatrixA.Columns);
        }

        private void UniformGridB_Initialized(object sender, EventArgs e)
        {
            MatrixB = new Matrix<int>(3, 3);

            InitializeUniformGrid(UniformGridB, MatrixB.Rows, MatrixB.Columns);
        }

        private void UniformGridC_Initialized(object sender, EventArgs e)
        {
            MatrixC = new Matrix<int>(3, 3);

            InitializeUniformGrid(UniformGridC, MatrixC.Rows, MatrixC.Columns);
        }

        private void Generate_Click(object sender, RoutedEventArgs e)
        {
            FillRandom(MatrixA, 256);
            FillRandom(MatrixB, 256);

            FillUniformGrid(UniformGridA, MatrixA);
            FillUniformGrid(UniformGridB, MatrixB);

            static void FillRandom(Matrix<int> matrix, int max)
            {
                var random = new Random();

                for (int i = 0; i < matrix.Rows; i++)
                {
                    for (int j = 0; j < matrix.Columns; j++)
                    {
                        matrix[i, j] = random.Next(max);
                    }
                }
            }
        }

        private void Add_Click(object sender, RoutedEventArgs e)
        {
            MatrixC = MatrixA + MatrixB;

            FillUniformGrid(UniformGridC, MatrixC);

            HighlightMaxMin(UniformGridC, MatrixC);
        }

        private void Subtract_Click(object sender, RoutedEventArgs e)
        {
            MatrixC = MatrixA - MatrixB;

            FillUniformGrid(UniformGridC, MatrixC);

            HighlightMaxMin(UniformGridC, MatrixC);
        }

        private void Multiply_Click(object sender, RoutedEventArgs e)
        {
            MatrixC = MatrixA * MatrixB;

            FillUniformGrid(UniformGridC, MatrixC);

            HighlightMaxMin(UniformGridC, MatrixC);
        }

        private static void HighlightMaxMin<T>(UniformGrid uniformGrid, Matrix<T> matrix) where T : INumber<T>
        {
            var max = matrix.Max();
            var min = matrix.Min();

            for (int i = 0; i < uniformGrid.Rows; i++)
            {
                for (int j = 0; j < uniformGrid.Columns; j++)
                {
                    var textBox = (TextBox)uniformGrid.Children[i * matrix.Columns + j];
                    var value = matrix[i, j];

                    if (value.Equals(max))
                    {
                        textBox.Foreground = Brushes.Green;
                        textBox.FontWeight = FontWeights.Bold;
                    }
                    else if (value.Equals(min))
                    {
                        textBox.Foreground = Brushes.Red;
                        textBox.FontWeight = FontWeights.Bold;
                    }
                    else
                    {
                        textBox.Foreground = Brushes.Black;
                        textBox.FontWeight = FontWeights.Regular;
                    }
                }
            }
        }

        private void Button_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            if (e.PreviousSize.Height == 0)
            {
                return;
            }

            ((Button)sender).FontSize *= e.NewSize.Height / e.PreviousSize.Height;
        }

        public static readonly RoutedCommand GenerateCommand = new();
        public static readonly RoutedCommand PlusCommand = new();
        public static readonly RoutedCommand MinusCommand = new();
        public static readonly RoutedCommand MultiplyCommand = new();

        private void GenerateCommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Generate_Click(sender, e);
        }
        private void PlusCommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Add_Click(sender, e);
        }
        private void MinusCommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Subtract_Click(sender, e);
        }
        private void MultiplyCommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Multiply_Click(sender, e);
        }
    }
}