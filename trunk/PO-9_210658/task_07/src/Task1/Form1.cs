using System;
using System.Drawing;
using System.Windows.Forms;

namespace LR6
{
    public partial class Form1 : Form
    {
        private System.Windows.Forms.Timer timer;
        private int position;
        private int step;
        private Label label1;

        public Form1()
        {
            InitializeComponent();

            position = Height;
            step = 5;

            timer = new System.Windows.Forms.Timer();
            timer.Interval = 30; 
            timer.Tick += Timer_Tick;
            timer.Start();

            label1 = new Label();
            label1.Text = "Графические примитивы в библиотеке для создания приложений с GUI";

            label1.Font = new Font(label1.Font.FontFamily, 12, FontStyle.Bold); 

            label1.Location = new Point((Width - label1.Width) / 2, position);
            Controls.Add(label1);
        }

        private void Timer_Tick(object sender, EventArgs e)
        {

            position += step;


            if (position > Height + 500)
            {
                position = -label1.Height - 550;
            }

            Invalidate();
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            using (var brush = new SolidBrush(label1.ForeColor))
            {
                using (var format = new StringFormat())
                {
                    format.Alignment = StringAlignment.Center;
                    format.LineAlignment = StringAlignment.Center;
                    format.FormatFlags = StringFormatFlags.DirectionVertical;

                    e.Graphics.TranslateTransform(ClientSize.Width / 20, position);
                    e.Graphics.RotateTransform(180);
                    e.Graphics.DrawString(label1.Text, label1.Font, brush, new Point(0, 0), format);
                }
            }
            
        }
        
    }
}