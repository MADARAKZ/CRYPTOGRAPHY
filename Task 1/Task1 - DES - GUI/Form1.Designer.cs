namespace Task3
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tabPage3 = new TabPage();
            comboBox3 = new ComboBox();
            label9 = new Label();
            comboBox8 = new ComboBox();
            label10 = new Label();
            comboBox9 = new ComboBox();
            label11 = new Label();
            textBox3 = new TextBox();
            textBox6 = new TextBox();
            textBox7 = new TextBox();
            label12 = new Label();
            comboBox10 = new ComboBox();
            button2 = new Button();
            label15 = new Label();
            label16 = new Label();
            label17 = new Label();
            button4 = new Button();
            button7 = new Button();
            tabPage2 = new TabPage();
            comboBox7 = new ComboBox();
            label14 = new Label();
            comboBox6 = new ComboBox();
            label13 = new Label();
            comboBox5 = new ComboBox();
            label3 = new Label();
            textBox5 = new TextBox();
            textBox2 = new TextBox();
            textBox4 = new TextBox();
            label4 = new Label();
            comboBox4 = new ComboBox();
            button1 = new Button();
            label5 = new Label();
            label6 = new Label();
            label8 = new Label();
            button5 = new Button();
            button6 = new Button();
            tabPage1 = new TabPage();
            textBox1 = new TextBox();
            comboBox1 = new ComboBox();
            button3 = new Button();
            label2 = new Label();
            label1 = new Label();
            tabControl1 = new TabControl();
            tabPage3.SuspendLayout();
            tabPage2.SuspendLayout();
            tabPage1.SuspendLayout();
            tabControl1.SuspendLayout();
            SuspendLayout();
            // 
            // tabPage3
            // 
            tabPage3.Controls.Add(comboBox3);
            tabPage3.Controls.Add(label9);
            tabPage3.Controls.Add(comboBox8);
            tabPage3.Controls.Add(label10);
            tabPage3.Controls.Add(comboBox9);
            tabPage3.Controls.Add(label11);
            tabPage3.Controls.Add(textBox3);
            tabPage3.Controls.Add(textBox6);
            tabPage3.Controls.Add(textBox7);
            tabPage3.Controls.Add(label12);
            tabPage3.Controls.Add(comboBox10);
            tabPage3.Controls.Add(button2);
            tabPage3.Controls.Add(label15);
            tabPage3.Controls.Add(label16);
            tabPage3.Controls.Add(label17);
            tabPage3.Controls.Add(button4);
            tabPage3.Controls.Add(button7);
            tabPage3.Location = new Point(8, 46);
            tabPage3.Name = "tabPage3";
            tabPage3.Padding = new Padding(3);
            tabPage3.Size = new Size(1190, 642);
            tabPage3.TabIndex = 2;
            tabPage3.Text = "Decrypt File";
            tabPage3.UseVisualStyleBackColor = true;
            // 
            // comboBox3
            // 
            comboBox3.FormattingEnabled = true;
            comboBox3.Items.AddRange(new object[] { "DER", "PEM", "HEX" });
            comboBox3.Location = new Point(466, 115);
            comboBox3.Name = "comboBox3";
            comboBox3.Size = new Size(242, 40);
            comboBox3.TabIndex = 49;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(266, 123);
            label9.Name = "label9";
            label9.Size = new Size(135, 32);
            label9.TabIndex = 48;
            label9.Text = "Format Key";
            // 
            // comboBox8
            // 
            comboBox8.FormattingEnabled = true;
            comboBox8.Items.AddRange(new object[] { "DER", "PEM", "HEX" });
            comboBox8.Location = new Point(475, 264);
            comboBox8.Name = "comboBox8";
            comboBox8.Size = new Size(242, 40);
            comboBox8.TabIndex = 47;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(248, 264);
            label10.Name = "label10";
            label10.Size = new Size(210, 32);
            label10.TabIndex = 46;
            label10.Text = "Format Cipher File";
            // 
            // comboBox9
            // 
            comboBox9.FormattingEnabled = true;
            comboBox9.Items.AddRange(new object[] { "DER", "PEM", "HEX", "Text" });
            comboBox9.Location = new Point(484, 418);
            comboBox9.Name = "comboBox9";
            comboBox9.Size = new Size(242, 40);
            comboBox9.TabIndex = 45;
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Location = new Point(275, 426);
            label11.Name = "label11";
            label11.Size = new Size(89, 32);
            label11.TabIndex = 44;
            label11.Text = "Format";
            // 
            // textBox3
            // 
            textBox3.Location = new Point(475, 338);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(245, 39);
            textBox3.TabIndex = 43;
            // 
            // textBox6
            // 
            textBox6.Location = new Point(475, 190);
            textBox6.Name = "textBox6";
            textBox6.Size = new Size(245, 39);
            textBox6.TabIndex = 41;
            // 
            // textBox7
            // 
            textBox7.Location = new Point(481, 496);
            textBox7.Name = "textBox7";
            textBox7.Size = new Size(245, 39);
            textBox7.TabIndex = 38;
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Location = new Point(266, 345);
            label12.Name = "label12";
            label12.Size = new Size(128, 32);
            label12.TabIndex = 42;
            label12.Text = "Cipher File";
            // 
            // comboBox10
            // 
            comboBox10.FormattingEnabled = true;
            comboBox10.Items.AddRange(new object[] { "ECB", "CFB", "CTR", "CBC", "CCM", "GCM", "OFB", "XTS" });
            comboBox10.Location = new Point(466, 39);
            comboBox10.Name = "comboBox10";
            comboBox10.Size = new Size(242, 40);
            comboBox10.TabIndex = 40;
            // 
            // button2
            // 
            button2.Location = new Point(558, 557);
            button2.Name = "button2";
            button2.Size = new Size(150, 46);
            button2.TabIndex = 39;
            button2.Text = "Decrypt";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click_1;
            // 
            // label15
            // 
            label15.AutoSize = true;
            label15.Location = new Point(266, 503);
            label15.Name = "label15";
            label15.Size = new Size(147, 32);
            label15.TabIndex = 37;
            label15.Text = "Decrypt Text";
            // 
            // label16
            // 
            label16.AutoSize = true;
            label16.Location = new Point(266, 197);
            label16.Name = "label16";
            label16.Size = new Size(53, 32);
            label16.TabIndex = 36;
            label16.Text = "Key";
            // 
            // label17
            // 
            label17.AutoSize = true;
            label17.Location = new Point(266, 47);
            label17.Name = "label17";
            label17.Size = new Size(77, 32);
            label17.TabIndex = 35;
            label17.Text = "Mode";
            // 
            // button4
            // 
            button4.Location = new Point(774, 338);
            button4.Name = "button4";
            button4.Size = new Size(150, 46);
            button4.TabIndex = 34;
            button4.Text = "Upload";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // button7
            // 
            button7.Location = new Point(774, 190);
            button7.Name = "button7";
            button7.Size = new Size(150, 46);
            button7.TabIndex = 33;
            button7.Text = "Upload";
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click_1;
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(comboBox7);
            tabPage2.Controls.Add(label14);
            tabPage2.Controls.Add(comboBox6);
            tabPage2.Controls.Add(label13);
            tabPage2.Controls.Add(comboBox5);
            tabPage2.Controls.Add(label3);
            tabPage2.Controls.Add(textBox5);
            tabPage2.Controls.Add(textBox2);
            tabPage2.Controls.Add(textBox4);
            tabPage2.Controls.Add(label4);
            tabPage2.Controls.Add(comboBox4);
            tabPage2.Controls.Add(button1);
            tabPage2.Controls.Add(label5);
            tabPage2.Controls.Add(label6);
            tabPage2.Controls.Add(label8);
            tabPage2.Controls.Add(button5);
            tabPage2.Controls.Add(button6);
            tabPage2.Location = new Point(8, 46);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(1190, 642);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "Encrypt File";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // comboBox7
            // 
            comboBox7.FormattingEnabled = true;
            comboBox7.Items.AddRange(new object[] { "DER", "PEM", "HEX" });
            comboBox7.Location = new Point(419, 107);
            comboBox7.Name = "comboBox7";
            comboBox7.Size = new Size(242, 40);
            comboBox7.TabIndex = 32;
            // 
            // label14
            // 
            label14.AutoSize = true;
            label14.Location = new Point(219, 115);
            label14.Name = "label14";
            label14.Size = new Size(135, 32);
            label14.TabIndex = 31;
            label14.Text = "Key Format";
            // 
            // comboBox6
            // 
            comboBox6.FormattingEnabled = true;
            comboBox6.Items.AddRange(new object[] { "DER", "PEM", "HEX", "Text" });
            comboBox6.Location = new Point(428, 256);
            comboBox6.Name = "comboBox6";
            comboBox6.Size = new Size(242, 40);
            comboBox6.TabIndex = 30;
            // 
            // label13
            // 
            label13.AutoSize = true;
            label13.Location = new Point(228, 264);
            label13.Name = "label13";
            label13.Size = new Size(147, 32);
            label13.TabIndex = 29;
            label13.Text = "Plain Format";
            // 
            // comboBox5
            // 
            comboBox5.FormattingEnabled = true;
            comboBox5.Items.AddRange(new object[] { "DER", "PEM", "HEX" });
            comboBox5.Location = new Point(437, 410);
            comboBox5.Name = "comboBox5";
            comboBox5.Size = new Size(242, 40);
            comboBox5.TabIndex = 28;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(237, 418);
            label3.Name = "label3";
            label3.Size = new Size(166, 32);
            label3.TabIndex = 27;
            label3.Text = "Cipher Format";
            // 
            // textBox5
            // 
            textBox5.Location = new Point(428, 330);
            textBox5.Name = "textBox5";
            textBox5.Size = new Size(245, 39);
            textBox5.TabIndex = 26;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(428, 182);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(245, 39);
            textBox2.TabIndex = 24;
            // 
            // textBox4
            // 
            textBox4.Location = new Point(434, 488);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(245, 39);
            textBox4.TabIndex = 20;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(236, 337);
            label4.Name = "label4";
            label4.Size = new Size(105, 32);
            label4.TabIndex = 25;
            label4.Text = "Plaintext";
            // 
            // comboBox4
            // 
            comboBox4.FormattingEnabled = true;
            comboBox4.Items.AddRange(new object[] { "ECB", "CFB", "CTR", "CBC", "CCM", "GCM", "OFB", "XTS" });
            comboBox4.Location = new Point(419, 31);
            comboBox4.Name = "comboBox4";
            comboBox4.Size = new Size(242, 40);
            comboBox4.TabIndex = 22;
            // 
            // button1
            // 
            button1.Location = new Point(511, 549);
            button1.Name = "button1";
            button1.Size = new Size(150, 46);
            button1.TabIndex = 21;
            button1.Text = "Encrypt";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(242, 495);
            label5.Name = "label5";
            label5.Size = new Size(127, 32);
            label5.TabIndex = 19;
            label5.Text = "CipherText";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(219, 189);
            label6.Name = "label6";
            label6.Size = new Size(53, 32);
            label6.TabIndex = 18;
            label6.Text = "Key";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(219, 39);
            label8.Name = "label8";
            label8.Size = new Size(77, 32);
            label8.TabIndex = 17;
            label8.Text = "Mode";
            // 
            // button5
            // 
            button5.Location = new Point(727, 330);
            button5.Name = "button5";
            button5.Size = new Size(150, 46);
            button5.TabIndex = 16;
            button5.Text = "Upload";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button6
            // 
            button6.Location = new Point(727, 182);
            button6.Name = "button6";
            button6.Size = new Size(150, 46);
            button6.TabIndex = 15;
            button6.Text = "Upload";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(textBox1);
            tabPage1.Controls.Add(comboBox1);
            tabPage1.Controls.Add(button3);
            tabPage1.Controls.Add(label2);
            tabPage1.Controls.Add(label1);
            tabPage1.Location = new Point(8, 46);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(1190, 642);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "GenKey";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(394, 261);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(245, 39);
            textBox1.TabIndex = 11;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "DER", "PEM", "HEX" });
            comboBox1.Location = new Point(397, 144);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(242, 40);
            comboBox1.TabIndex = 9;
            // 
            // button3
            // 
            button3.Location = new Point(386, 422);
            button3.Name = "button3";
            button3.Size = new Size(250, 61);
            button3.TabIndex = 8;
            button3.Text = "Genkey";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(194, 268);
            label2.Name = "label2";
            label2.Size = new Size(53, 32);
            label2.TabIndex = 1;
            label2.Text = "Key";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(205, 152);
            label1.Name = "label1";
            label1.Size = new Size(89, 32);
            label1.TabIndex = 0;
            label1.Text = "Format";
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Controls.Add(tabPage3);
            tabControl1.Location = new Point(103, 13);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(1206, 696);
            tabControl1.TabIndex = 1;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1344, 734);
            Controls.Add(tabControl1);
            Name = "Form1";
            Text = "Form1";
            tabPage3.ResumeLayout(false);
            tabPage3.PerformLayout();
            tabPage2.ResumeLayout(false);
            tabPage2.PerformLayout();
            tabPage1.ResumeLayout(false);
            tabPage1.PerformLayout();
            tabControl1.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private TabPage tabPage3;
        private TabPage tabPage2;
        private TextBox textBox5;
        private TextBox textBox2;
        private TextBox textBox4;
        private Label label4;
        private ComboBox comboBox4;
        private Button button1;
        private Label label5;
        private Label label6;
        private Label label8;
        private Button button5;
        private Button button6;
        private TabPage tabPage1;
        private TextBox textBox1;
        private ComboBox comboBox1;
        private Button button3;
        private Label label2;
        private Label label1;
        private TabControl tabControl1;
        private ComboBox comboBox6;
        private Label label13;
        private ComboBox comboBox5;
        private Label label3;
        private ComboBox comboBox7;
        private Label label14;
        private ComboBox comboBox3;
        private Label label9;
        private ComboBox comboBox8;
        private Label label10;
        private ComboBox comboBox9;
        private Label label11;
        private TextBox textBox3;
        private TextBox textBox6;
        private TextBox textBox7;
        private Label label12;
        private ComboBox comboBox10;
        private Button button2;
        private Label label15;
        private Label label16;
        private Label label17;
        private Button button4;
        private Button button7;
    }
}