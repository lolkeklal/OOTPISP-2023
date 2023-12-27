using System;
using System.Drawing;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace FirstLab1
{
    public partial class Form1 : Form 
    {
        public Form1()
        {
            InitializeComponent();
            redTextBox.Maximum = 255;
            greenTextBox.Maximum = 255;
            greenTextBox.Maximum = 255;

            redTextBox.ReadOnly = true;
            greenTextBox.ReadOnly = true;
            blueTextBox.ReadOnly = true;

            redTrackBar.Maximum = 255;
            greenTrackBar.Maximum = 255;
            blueTrackBar.Maximum = 255;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            redTextBox.Text = redTrackBar.Value.ToString();
            greenTextBox.Text = greenTrackBar.Value.ToString();
            redTextBox.Text = blueTrackBar.Value.ToString();

            UpdateColor();
        }

        private void redTrackBar_Scroll(object sender, EventArgs e)
        {
            redTextBox.Text = redTrackBar.Value.ToString();
            UpdateColor();
        }

        private void greenTrackBar_Scroll(object sender, EventArgs e)
        {
            greenTextBox.Text = greenTrackBar.Value.ToString();
            UpdateColor();
        }

        private void blueTrackBar_Scroll(object sender, EventArgs e)
        {
            blueTextBox.Text = blueTrackBar.Value.ToString();
            UpdateColor();
        }

        private void redTextBox_Change(object sender, EventArgs e)
        {
            int val;
            int.TryParse(redTextBox.Value.ToString(), out val);
            redTrackBar.Value = val;
            UpdateColor();
        }
        private void greenTextBox_Change(object sender, EventArgs e)
        {
            int val;
            int.TryParse(greenTextBox.Value.ToString(), out val);
            greenTrackBar.Value = val;
            UpdateColor();
        }
        private void blueTextBox_Change(object sender, EventArgs e)
        {
            int val;
            int.TryParse(blueTextBox.Value.ToString(), out val);
            blueTrackBar.Value = val;
            UpdateColor();
        }
        private void UpdateColor()
        {
            int red = redTrackBar.Value;
            int green = greenTrackBar.Value;
            int blue = blueTrackBar.Value;

            Color color = Color.FromArgb(red, green, blue);
            pic.BackColor = color;
            Color textColor = Color.FromArgb(255 - red,255 - green, 255 - blue);
            textB.BackColor = color;
            textB.ForeColor = textColor;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textB.ScrollBars = ScrollBars.Vertical;
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text files (*.txt)|*.txt";

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string filePath = openFileDialog.FileName;

                try
                {
                    string fileContent = System.IO.File.ReadAllText(filePath);
                    textB.Text = fileContent;
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error while reading file: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void fontSizeTrackBar_Scroll(object sender, EventArgs e)
        {
            int size = fontSize.Value;
            textB.Font = new Font(textB.Font.FontFamily, size, FontStyle.Regular);
        }

        private void greenTrackBar_Scroll_1(object sender, EventArgs e)
        {
            //функция, автоматически созданная Visual studio, нельзя удалять
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            //функция, автоматически созданная Visual studio, нельзя удалять
        }
    }
}
