using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace LR7_2
{
    public partial class Form1 : Form
    {
        private float x = 0; 
        private System.Windows.Forms.Timer timer; 
        float a = 0.0001f;
        private List<PointF> positionList;

        public Form1()
        {
            InitializeComponent();
            timer = new System.Windows.Forms.Timer();
            timer.Interval = 10; 
            timer.Tick += Timer_Tick;
            timer.Start();
            positionList = new List<PointF>();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            x += 0.1f; 
            if (x > 1000) 
                x = 0;

            PointF position = new PointF(x, a * x * x * x); 
            positionList.Add(position);
            Invalidate(); 
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            Graphics g = e.Graphics;

            float rectangleWidth = 50;
            float rectangleHeight = 30;
            float rectangleY = a * x * x * x; 
            RectangleF rectangle = new RectangleF(x, rectangleY, rectangleWidth, rectangleHeight);
            g.FillRectangle(Brushes.Blue, rectangle);

            float circleRadius = 25;
            float circleX = x + rectangleWidth / 2 - circleRadius;
            float circleY = rectangleY + rectangleHeight;
            RectangleF circle = new RectangleF(circleX, circleY, circleRadius * 2, circleRadius * 2);
            g.FillEllipse(Brushes.Red, circle);

            if (positionList.Count > 1)
            {
                using (Pen pen = new Pen(Color.Green, 1))
                {
                    g.DrawLines(pen, positionList.ToArray());
                }
            }
        }
    }
}

