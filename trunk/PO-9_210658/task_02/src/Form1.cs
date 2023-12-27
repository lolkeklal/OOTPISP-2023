using SecondLab1.Properties;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace SecondLab1
{
    public partial class Form1 : Form 
    {
        private readonly Stack<string> undoStack = new Stack<string>();
        private readonly Stack<string> redoStack = new Stack<string>();
        private bool isUndoing;
        string filePath = "";
        bool firstSave;
        public Form1()
        {
            InitializeComponent();
            redoStack.Push("");
            undoStack.Push("");
            toolTip1.SetToolTip(New, "New\n'Ctrl + N'");
            toolTip1.SetToolTip(open, "Open\n'Ctrl + O'");
            toolTip1.SetToolTip(Save, "Save\n'Ctrl + S'");
            toolTip1.SetToolTip(cut, "Cut\n'Ctrl + X'");
            toolTip1.SetToolTip(copy, "Copy\n'Ctrl + C'");
            toolTip1.SetToolTip(paste, "Paste\n'Ctrl + V'");
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (firstSave)
            {
                Saving();
            }
            else
            {
                SaveAs();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //создано Visual Studio
        }

        private void textBox_TextChanged(object sender, EventArgs e)
        {
            //создано Visual Studio
        }

        private void Undo()
        {
            if (!isUndoing)
            {
                redoStack.Push(textBox.Text);
                isUndoing = true;
                textBox.Text = undoStack.Pop();
                isUndoing = false;
            }
        }

        private void Redo()
        {
            if (redoStack.Count > 0)
            {
                undoStack.Push(textBox.Text);
                isUndoing = true;
                textBox.Text = redoStack.Pop();
                isUndoing = false;
            }
        }
        protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
        {
            if (keyData == (Keys.Control | Keys.Z))
            {
                Undo();
                return true;
            }
            else if (keyData == (Keys.Control | Keys.Y))
            {
                Redo();
                return true;
            }
            else if (keyData == (Keys.Tab))
            {
                textBox.Text = textBox.Text + "    ";
                textBox.SelectionStart = textBox.TextLength;
                return true;
            }
            else if (keyData == (Keys.Control | Keys.F))
            {
                ChangeFont();
                return true;
            }
            else if (keyData == (Keys.Control | Keys.C))
            {
                Copy();
                return true;
            }
            else if (keyData == (Keys.Control | Keys.V))
            {
                textBox.SelectedText = Clipboard.GetText();
                return true;
            }
            else if (keyData == (Keys.Control | Keys.X))
            {
                Cut();
                return true;
            }
            else if (keyData == (Keys.Control | Keys.O))
            {
                Open();
                return true;
            }
            else if (keyData == (Keys.Control | Keys.S))
            {
                Saving();
                return true;
            }
            else if (keyData == (Keys.Control | Keys.N))
            {
                SaveAttention();
                textBox.Text = "";
                return true;
            }
            return base.ProcessCmdKey(ref msg, keyData);
        }
        
        private void Copy()
        {
            if (textBox.SelectedText != "")
            {
                Clipboard.SetText(textBox.SelectedText);
            }
            else
            {
                textBox.SelectAll();
                Clipboard.SetText(textBox.SelectedText);
            }
        }
        private void Cut()
        {
            if (textBox.SelectedText != "")
            {
                Clipboard.SetText(textBox.SelectedText);
            }
            else
            {
                textBox.SelectAll();
                Clipboard.SetText(textBox.SelectedText);
            }
            textBox.SelectedText = "";
        }
        private void ChangeFont()
        {

            string selectedText = textBox.SelectedText;
            undoStack.Push(textBox.Text);
            if (!string.IsNullOrEmpty(selectedText))
            {

                FontDialog fontDialog = new FontDialog();
                if (fontDialog.ShowDialog() == DialogResult.OK)
                {

                    Font selectedFont = fontDialog.Font;

                    textBox.SelectionFont = selectedFont;
                    undoStack.Push(textBox.Text);
                }
            }
        }
        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FontDialog fontDialog = new FontDialog();
            if (fontDialog.ShowDialog() == DialogResult.OK)
            {

                Font selectedFont = fontDialog.Font;

                textBox.SelectionFont = selectedFont;
            }
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("'Ctrl + C' - Copy\n'Ctrl + V' - Paste\n'Ctrl + X' - Cut\n'Ctrl + S' - Save\n'Ctrl + O' - Open\n'Ctrl + N' - New\n'Ctrl + F' - Font\n'Ctrl + Z' - Undo\n'Ctrl + Y' - Redo\n", "Hot keys");
        }

        private void cut_Click(object sender, EventArgs e)
        {
            Cut();
        }

        private void copy_Click(object sender, EventArgs e)
        {
            Copy();
        }

        private void paste_Click(object sender, EventArgs e)
        {
            textBox.SelectedText = Clipboard.GetText();
        }

        private void New_Click(object sender, EventArgs e)
        {
            firstSave = false;
            SaveAttention();
            textBox.Text = "";
        }
        private void Open()
        {
            SaveAttention();
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Special Lab Type(*.slt)|*.slt";

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string file_path = openFileDialog.FileName;

                try
                {
                    string fileContent = System.IO.File.ReadAllText(file_path);
                    textBox.Text = fileContent;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error while reading a file: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
        private void SaveAttention()
        {
            if(textBox.Text != "")
            {
                DialogResult result = MessageBox.Show("Do you want to save this project?", "Saving", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

                if (result == DialogResult.Yes)
                {
                    SaveAs();
                }
            }
        }
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Are you sure you want to exit?", "Attention!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (result == DialogResult.Yes)
            {

                this.Close();
            }
        }
        private void SaveAs()
        {
            firstSave = true;
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Special Lab Type(*.slt)|*.slt";
            saveFileDialog.Title = "Save";

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                filePath = saveFileDialog.FileName;
                System.IO.File.WriteAllText(filePath, textBox.Text);
            }
        }
        private void Saving()
        {
            System.IO.File.WriteAllText(filePath, textBox.Text);
        }
        private void open_Click(object sender, EventArgs e)
        {
            Open();
        }

        private void closeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Are you sure you want to close?", "Attention!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (result == DialogResult.Yes)
            {
                SaveAttention();
                textBox.Text = "";
            }
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Open();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveAttention();
            firstSave = false;
            textBox.Text = "";
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (firstSave)
            {
                Saving();
            }
            else
            {
                SaveAs();
            }
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveAs();
        }
    }
}