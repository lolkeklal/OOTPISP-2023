using System;
using System.Diagnostics;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using DataFormats = System.Windows.DataFormats;
using MessageBox = System.Windows.MessageBox;
using OpenFileDialog = System.Windows.Forms.OpenFileDialog;
using SaveFileDialog = System.Windows.Forms.SaveFileDialog;

namespace Lab_02
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private bool _saveCanExecute = false;
        public bool SaveCanExecute
        {
            get => _saveCanExecute;
            set
            {
                _saveCanExecute = value;
            }
        }

        public string CurrentPath { get; set; } = string.Empty;

        public MainWindow()
        {
            InitializeComponent();
        }

        private ICommand saveCommand = null!;
        public ICommand SaveCommand
        {
            get
            {
                return saveCommand
                    ?? (saveCommand = new SaveCommand(this, Save_Button_Click));
            }
            private set
            {
                saveCommand = value;
            }
        }

        private void SaveCommandCanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = _saveCanExecute;
            e.Handled = true;
        }

        private void SaveCommandExecuted(object sender, ExecutedRoutedEventArgs e)
        {
            var title = this.Title[..^1];
            this.Title = title;

            _saveCanExecute = false;
        }







        private void Exit_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            App.Current.Shutdown();
        }

        private void Close_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void New_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            new MainWindow().Show();
        }

        private void RichTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (!_saveCanExecute)
            {
                this.Title += "*";

                _saveCanExecute = true;
            }
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (_saveCanExecute)
            {
                var message = """
                    The document has been modified, do you want to save changes?
                    otherwise, you will lose all your progress!
                    """;

                MessageBoxResult result =
                  MessageBox.Show(
                    this,
                    message,
                    "Document modified",
                    MessageBoxButton.YesNoCancel,
                    MessageBoxImage.Warning,
                    MessageBoxResult.Yes);


                if (result == MessageBoxResult.Yes)
                {
                    Save_Button_Click(sender, null!);
                    e.Cancel = true;
                }
                else if (result == MessageBoxResult.Cancel)
                {
                    e.Cancel = true;
                }
            }
        }

        private void Font_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            FontDialog fontDialog = new();
            var result = fontDialog.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK)
            {
                var font = fontDialog.Font;

                var fontFamily = new FontFamily(font.Name);
                RichText.Selection.ApplyPropertyValue(FontFamilyProperty, fontFamily);

                double fontSize = font.Size * 96.0 / 72.0;
                RichText.Selection.ApplyPropertyValue(FontSizeProperty, fontSize);

                var fontWeight = font.Bold ? FontWeights.Bold : FontWeights.Regular;
                RichText.Selection.ApplyPropertyValue(FontWeightProperty, fontWeight);

                var fontStyle = font.Italic ? FontStyles.Italic : FontStyles.Normal;
                RichText.Selection.ApplyPropertyValue(FontStyleProperty, fontStyle);

                TextDecorationCollection textDecorations = new();

                if (font.Underline) 
                { 
                    textDecorations.Add(TextDecorations.Underline);
                }
                
                if (font.Strikeout)
                {
                    textDecorations.Add(TextDecorations.Strikethrough);
                }

                if (textDecorations.Count > 0)
                {
                    RichText.Selection.ApplyPropertyValue(Inline.TextDecorationsProperty, textDecorations);
                }
            }
        }

        private void WPF_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            Process.Start(
                new ProcessStartInfo(
                    new Uri(
                        @"https://learn.microsoft.com/en-us/dotnet/desktop/wpf/introduction-to-wpf?view=netframeworkdesktop-4.8")
                    .AbsoluteUri) 
                { UseShellExecute = true });
        }

        private void About_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show(
                "Text editor by Anton Lobarev",
                "About",
                MessageBoxButton.OK,
                MessageBoxImage.Information,
                MessageBoxResult.OK);
        }

        private void Color_MenuItem_Click(object sender, RoutedEventArgs e)
        {
            ColorDialog colorDialog = new();
            var result = colorDialog.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK)
            {
                var color = colorDialog.Color;
                var brush = new SolidColorBrush(Color.FromArgb(color.A, color.R, color.G, color.B));
                RichText.Selection.ApplyPropertyValue(ForegroundProperty, brush);
            }
        }

        private void SaveAs_Button_Click(object sender, RoutedEventArgs e)
        {
            var save = new SaveFileDialog();
            save.Filter = "RTF-файл (*.rtf)|*.rtf|Файл XAML (*.xaml)|*.xaml";

            var result = save.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK)
            {
                // Создание контейнера TextRange для всего документа
                TextRange documentTextRange = new TextRange(
                    RichText.Document.ContentStart, RichText.Document.ContentEnd);

                // Если такой файл существует, он перезаписывается, 
                using FileStream fs = File.Create(save.FileName);

                if (Path.GetExtension(save.FileName).ToLower() == ".rtf")
                {
                    documentTextRange.Save(fs, DataFormats.Rtf);
                }
                else
                {
                    documentTextRange.Save(fs, DataFormats.Xaml);
                }

                CurrentPath = save.FileName;

                this.Title = Path.GetFileNameWithoutExtension(CurrentPath);
                _saveCanExecute = false;
            }
        }

        private void Open_Button_Click(object sender, RoutedEventArgs e)
        {
            var fileDialog = new OpenFileDialog();
            fileDialog.Filter = "RichText files (*.rtf)|*.rtf|All files (*.*)|*.*";

            var result = fileDialog.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK)
            {
                TextRange tr = new TextRange(
                    RichText.Document.ContentStart, RichText.Document.ContentEnd);

                using (FileStream fs = File.Open(fileDialog.FileName, FileMode.Open))
                {
                    tr.Load(fs, DataFormats.Rtf);
                }

                var path = fileDialog.FileName;
                CurrentPath = path;
                this.Title = Path.GetFileNameWithoutExtension(path);
                _saveCanExecute = false;
            }
        }

        private void Save_Button_Click(object sender, RoutedEventArgs e)
        {
            var path = CurrentPath;
            if (!string.IsNullOrEmpty(path))
            {
                var richText = RichText;

                TextRange documentTextRange = new TextRange(
                        richText.Document.ContentStart, richText.Document.ContentEnd);

                using FileStream fs = File.Create(path);

                if (Path.GetExtension(path).ToLower() == ".rtf")
                {
                    documentTextRange.Save(fs, DataFormats.Rtf);
                }
                else
                {
                    documentTextRange.Save(fs, DataFormats.Xaml);
                }

                var title = this.Title[..^1];
                this.Title = title;

                _saveCanExecute = false;
            }
            else
            {
                SaveAs_Button_Click(sender, e);
            }

        }
    }
}
