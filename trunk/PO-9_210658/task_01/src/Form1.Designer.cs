namespace FirstLab1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.redTrackBar = new System.Windows.Forms.TrackBar();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.greenTrackBar = new System.Windows.Forms.TrackBar();
            this.blueTrackBar = new System.Windows.Forms.TrackBar();
            this.redTextBox = new System.Windows.Forms.NumericUpDown();
            this.greenTextBox = new System.Windows.Forms.NumericUpDown();
            this.blueTextBox = new System.Windows.Forms.NumericUpDown();
            this.colorDialog2 = new System.Windows.Forms.ColorDialog();
            this.pic = new System.Windows.Forms.Panel();
            this.textB = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.fontSize = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.redTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.greenTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.blueTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.redTextBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.greenTextBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.blueTextBox)).BeginInit();
            this.pic.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fontSize)).BeginInit();
            this.SuspendLayout();
            // 
            // redTrackBar
            // 
            this.redTrackBar.Location = new System.Drawing.Point(105, 12);
            this.redTrackBar.Maximum = 255;
            this.redTrackBar.Name = "redTrackBar";
            this.redTrackBar.Size = new System.Drawing.Size(241, 90);
            this.redTrackBar.TabIndex = 0;
            this.redTrackBar.ValueChanged += new System.EventHandler(this.redTrackBar_Scroll);
            // 
            // greenTrackBar
            // 
            this.greenTrackBar.Location = new System.Drawing.Point(105, 125);
            this.greenTrackBar.Maximum = 255;
            this.greenTrackBar.Name = "greenTrackBar";
            this.greenTrackBar.Size = new System.Drawing.Size(241, 90);
            this.greenTrackBar.TabIndex = 2;
            this.greenTrackBar.Scroll += new System.EventHandler(this.greenTrackBar_Scroll_1);
            this.greenTrackBar.ValueChanged += new System.EventHandler(this.greenTrackBar_Scroll);
            // 
            // blueTrackBar
            // 
            this.blueTrackBar.Location = new System.Drawing.Point(105, 246);
            this.blueTrackBar.Maximum = 255;
            this.blueTrackBar.Name = "blueTrackBar";
            this.blueTrackBar.Size = new System.Drawing.Size(241, 90);
            this.blueTrackBar.TabIndex = 3;
            this.blueTrackBar.ValueChanged += new System.EventHandler(this.blueTrackBar_Scroll);
            // 
            // redTextBox
            // 
            this.redTextBox.Location = new System.Drawing.Point(12, 12);
            this.redTextBox.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.redTextBox.Name = "redTextBox";
            this.redTextBox.ReadOnly = true;
            this.redTextBox.Size = new System.Drawing.Size(87, 39);
            this.redTextBox.TabIndex = 4;
            this.redTextBox.ValueChanged += new System.EventHandler(this.redTextBox_Change);
            // 
            // greenTextBox
            // 
            this.greenTextBox.Location = new System.Drawing.Point(12, 125);
            this.greenTextBox.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.greenTextBox.Name = "greenTextBox";
            this.greenTextBox.ReadOnly = true;
            this.greenTextBox.Size = new System.Drawing.Size(87, 39);
            this.greenTextBox.TabIndex = 5;
            this.greenTextBox.ValueChanged += new System.EventHandler(this.greenTextBox_Change);
            // 
            // blueTextBox
            // 
            this.blueTextBox.Location = new System.Drawing.Point(12, 247);
            this.blueTextBox.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.blueTextBox.Name = "blueTextBox";
            this.blueTextBox.ReadOnly = true;
            this.blueTextBox.Size = new System.Drawing.Size(87, 39);
            this.blueTextBox.TabIndex = 6;
            this.blueTextBox.ValueChanged += new System.EventHandler(this.blueTextBox_Change);
            // 
            // pic
            // 
            this.pic.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.pic.Controls.Add(this.textB);
            this.pic.Location = new System.Drawing.Point(362, 50);
            this.pic.Name = "pic";
            this.pic.Size = new System.Drawing.Size(400, 200);
            this.pic.TabIndex = 7;
            this.pic.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // textB
            // 
            this.textB.BackColor = System.Drawing.SystemColors.InactiveCaptionText;
            this.textB.ForeColor = System.Drawing.Color.White;
            this.textB.Location = new System.Drawing.Point(3, 3);
            this.textB.Multiline = true;
            this.textB.Name = "textB";
            this.textB.Size = new System.Drawing.Size(394, 194);
            this.textB.TabIndex = 0;
            this.textB.Text = "Text will apear here";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(45, 360);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(150, 46);
            this.button1.TabIndex = 8;
            this.button1.Text = "File";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // fontSize
            // 
            this.fontSize.Location = new System.Drawing.Point(362, 277);
            this.fontSize.Maximum = 20;
            this.fontSize.Minimum = 1;
            this.fontSize.Name = "fontSize";
            this.fontSize.Size = new System.Drawing.Size(400, 90);
            this.fontSize.TabIndex = 10;
            this.fontSize.Value = 1;
            this.fontSize.ValueChanged += new System.EventHandler(this.fontSizeTrackBar_Scroll);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(502, 326);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(108, 32);
            this.label1.TabIndex = 11;
            this.label1.Text = "font-size";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(13F, 32F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.fontSize);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pic);
            this.Controls.Add(this.blueTextBox);
            this.Controls.Add(this.greenTextBox);
            this.Controls.Add(this.redTextBox);
            this.Controls.Add(this.blueTrackBar);
            this.Controls.Add(this.greenTrackBar);
            this.Controls.Add(this.redTrackBar);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.redTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.greenTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.blueTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.redTextBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.greenTextBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.blueTextBox)).EndInit();
            this.pic.ResumeLayout(false);
            this.pic.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fontSize)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private TrackBar redTrackBar;
        private ColorDialog colorDialog1;
        private TrackBar greenTrackBar;
        private TrackBar blueTrackBar;
        private NumericUpDown redTextBox;
        private NumericUpDown greenTextBox;
        private NumericUpDown blueTextBox;
        private ColorDialog colorDialog2;
        private Panel pic;
        private TextBox textB;
        private Button button1;
        private TrackBar fontSize;
        private Label label1;
    }
}