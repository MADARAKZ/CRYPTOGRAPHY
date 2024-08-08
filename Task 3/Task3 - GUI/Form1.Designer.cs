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
            tabControl1 = new TabControl();
            tabPage1 = new TabPage();
            label7 = new Label();
            textBox1 = new TextBox();
            comboBox2 = new ComboBox();
            comboBox1 = new ComboBox();
            button3 = new Button();
            textBox3 = new TextBox();
            label3 = new Label();
            label2 = new Label();
            label1 = new Label();
            tabPage2 = new TabPage();
            textBox5 = new TextBox();
            label4 = new Label();
            textBox2 = new TextBox();
            comboBox4 = new ComboBox();
            button1 = new Button();
            textBox4 = new TextBox();
            label5 = new Label();
            label6 = new Label();
            label8 = new Label();
            button5 = new Button();
            button6 = new Button();
            tabPage3 = new TabPage();
            textBox6 = new TextBox();
            label9 = new Label();
            textBox7 = new TextBox();
            comboBox3 = new ComboBox();
            button2 = new Button();
            textBox8 = new TextBox();
            label10 = new Label();
            label11 = new Label();
            label12 = new Label();
            button4 = new Button();
            button7 = new Button();
            tabPage4 = new TabPage();
            textBox9 = new TextBox();
            label13 = new Label();
            textBox10 = new TextBox();
            comboBox5 = new ComboBox();
            button8 = new Button();
            textBox11 = new TextBox();
            label14 = new Label();
            label15 = new Label();
            label16 = new Label();
            button10 = new Button();
            tabPage5 = new TabPage();
            textBox12 = new TextBox();
            label17 = new Label();
            textBox13 = new TextBox();
            comboBox6 = new ComboBox();
            button9 = new Button();
            textBox14 = new TextBox();
            label18 = new Label();
            label19 = new Label();
            label20 = new Label();
            button12 = new Button();
            tabControl1.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            tabPage3.SuspendLayout();
            tabPage4.SuspendLayout();
            tabPage5.SuspendLayout();
            SuspendLayout();
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Controls.Add(tabPage3);
            tabControl1.Controls.Add(tabPage4);
            tabControl1.Controls.Add(tabPage5);
            tabControl1.Location = new Point(103, 13);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(896, 562);
            tabControl1.TabIndex = 1;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(label7);
            tabPage1.Controls.Add(textBox1);
            tabPage1.Controls.Add(comboBox2);
            tabPage1.Controls.Add(comboBox1);
            tabPage1.Controls.Add(button3);
            tabPage1.Controls.Add(textBox3);
            tabPage1.Controls.Add(label3);
            tabPage1.Controls.Add(label2);
            tabPage1.Controls.Add(label1);
            tabPage1.Location = new Point(8, 46);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(880, 508);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "GenKey";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(194, 169);
            label7.Name = "label7";
            label7.Size = new Size(96, 32);
            label7.TabIndex = 12;
            label7.Text = "SizeKey";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(394, 261);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(245, 39);
            textBox1.TabIndex = 11;
            // 
            // comboBox2
            // 
            comboBox2.FormattingEnabled = true;
            comboBox2.Items.AddRange(new object[] { "3072", "4096", "7086" });
            comboBox2.Location = new Point(397, 169);
            comboBox2.Name = "comboBox2";
            comboBox2.Size = new Size(242, 40);
            comboBox2.TabIndex = 10;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "DER", "Base64" });
            comboBox1.Location = new Point(394, 64);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(242, 40);
            comboBox1.TabIndex = 9;
            // 
            // button3
            // 
            button3.Location = new Point(440, 438);
            button3.Name = "button3";
            button3.Size = new Size(150, 46);
            button3.TabIndex = 8;
            button3.Text = "Signature";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // textBox3
            // 
            textBox3.Location = new Point(397, 363);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(245, 39);
            textBox3.TabIndex = 5;
            textBox3.TextChanged += textBox3_TextChanged;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(197, 370);
            label3.Name = "label3";
            label3.Size = new Size(125, 32);
            label3.TabIndex = 2;
            label3.Text = "PrivateKey";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(194, 268);
            label2.Name = "label2";
            label2.Size = new Size(117, 32);
            label2.TabIndex = 1;
            label2.Text = "PublicKey";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(197, 72);
            label1.Name = "label1";
            label1.Size = new Size(89, 32);
            label1.TabIndex = 0;
            label1.Text = "Format";
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(textBox5);
            tabPage2.Controls.Add(label4);
            tabPage2.Controls.Add(textBox2);
            tabPage2.Controls.Add(comboBox4);
            tabPage2.Controls.Add(button1);
            tabPage2.Controls.Add(textBox4);
            tabPage2.Controls.Add(label5);
            tabPage2.Controls.Add(label6);
            tabPage2.Controls.Add(label8);
            tabPage2.Controls.Add(button5);
            tabPage2.Controls.Add(button6);
            tabPage2.Location = new Point(8, 46);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(880, 508);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "Encrypt File";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // textBox5
            // 
            textBox5.Location = new Point(419, 246);
            textBox5.Name = "textBox5";
            textBox5.Size = new Size(245, 39);
            textBox5.TabIndex = 26;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(227, 253);
            label4.Name = "label4";
            label4.Size = new Size(105, 32);
            label4.TabIndex = 25;
            label4.Text = "Plaintext";
            // 
            // textBox2
            // 
            textBox2.Location = new Point(419, 149);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(245, 39);
            textBox2.TabIndex = 24;
            // 
            // comboBox4
            // 
            comboBox4.FormattingEnabled = true;
            comboBox4.Items.AddRange(new object[] { "DER", "Base64" });
            comboBox4.Location = new Point(419, 31);
            comboBox4.Name = "comboBox4";
            comboBox4.Size = new Size(242, 40);
            comboBox4.TabIndex = 22;
            // 
            // button1
            // 
            button1.Location = new Point(486, 431);
            button1.Name = "button1";
            button1.Size = new Size(150, 46);
            button1.TabIndex = 21;
            button1.Text = "Encrypt";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // textBox4
            // 
            textBox4.Location = new Point(419, 338);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(245, 39);
            textBox4.TabIndex = 20;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(227, 345);
            label5.Name = "label5";
            label5.Size = new Size(127, 32);
            label5.TabIndex = 19;
            label5.Text = "CipherText";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(227, 156);
            label6.Name = "label6";
            label6.Size = new Size(117, 32);
            label6.TabIndex = 18;
            label6.Text = "PublicKey";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(219, 39);
            label8.Name = "label8";
            label8.Size = new Size(89, 32);
            label8.TabIndex = 17;
            label8.Text = "Format";
            // 
            // button5
            // 
            button5.Location = new Point(702, 239);
            button5.Name = "button5";
            button5.Size = new Size(150, 46);
            button5.TabIndex = 16;
            button5.Text = "Upload";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button6
            // 
            button6.Location = new Point(702, 156);
            button6.Name = "button6";
            button6.Size = new Size(150, 46);
            button6.TabIndex = 15;
            button6.Text = "Upload";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // tabPage3
            // 
            tabPage3.Controls.Add(textBox6);
            tabPage3.Controls.Add(label9);
            tabPage3.Controls.Add(textBox7);
            tabPage3.Controls.Add(comboBox3);
            tabPage3.Controls.Add(button2);
            tabPage3.Controls.Add(textBox8);
            tabPage3.Controls.Add(label10);
            tabPage3.Controls.Add(label11);
            tabPage3.Controls.Add(label12);
            tabPage3.Controls.Add(button4);
            tabPage3.Controls.Add(button7);
            tabPage3.Location = new Point(8, 46);
            tabPage3.Name = "tabPage3";
            tabPage3.Padding = new Padding(3);
            tabPage3.Size = new Size(880, 508);
            tabPage3.TabIndex = 2;
            tabPage3.Text = "Decrypt File";
            tabPage3.UseVisualStyleBackColor = true;
            // 
            // textBox6
            // 
            textBox6.Location = new Point(324, 246);
            textBox6.Name = "textBox6";
            textBox6.Size = new Size(245, 39);
            textBox6.TabIndex = 37;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(132, 253);
            label9.Name = "label9";
            label9.Size = new Size(127, 32);
            label9.TabIndex = 36;
            label9.Text = "CipherText";
            // 
            // textBox7
            // 
            textBox7.Location = new Point(324, 149);
            textBox7.Name = "textBox7";
            textBox7.Size = new Size(245, 39);
            textBox7.TabIndex = 35;
            // 
            // comboBox3
            // 
            comboBox3.FormattingEnabled = true;
            comboBox3.Items.AddRange(new object[] { "DER", "Base64" });
            comboBox3.Location = new Point(324, 31);
            comboBox3.Name = "comboBox3";
            comboBox3.Size = new Size(242, 40);
            comboBox3.TabIndex = 34;
            // 
            // button2
            // 
            button2.Location = new Point(391, 431);
            button2.Name = "button2";
            button2.Size = new Size(150, 46);
            button2.TabIndex = 33;
            button2.Text = "Decrypt";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // textBox8
            // 
            textBox8.Location = new Point(324, 338);
            textBox8.Name = "textBox8";
            textBox8.Size = new Size(245, 39);
            textBox8.TabIndex = 32;
            textBox8.TextChanged += textBox8_TextChanged;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(132, 345);
            label10.Name = "label10";
            label10.Size = new Size(126, 32);
            label10.TabIndex = 31;
            label10.Text = "DecrypFile";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Location = new Point(132, 156);
            label11.Name = "label11";
            label11.Size = new Size(125, 32);
            label11.TabIndex = 30;
            label11.Text = "PrivateKey";
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Location = new Point(124, 39);
            label12.Name = "label12";
            label12.Size = new Size(89, 32);
            label12.TabIndex = 29;
            label12.Text = "Format";
            // 
            // button4
            // 
            button4.Location = new Point(607, 239);
            button4.Name = "button4";
            button4.Size = new Size(150, 46);
            button4.TabIndex = 28;
            button4.Text = "Upload";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // button7
            // 
            button7.Location = new Point(607, 145);
            button7.Name = "button7";
            button7.Size = new Size(150, 46);
            button7.TabIndex = 27;
            button7.Text = "Upload";
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click;
            // 
            // tabPage4
            // 
            tabPage4.Controls.Add(textBox9);
            tabPage4.Controls.Add(label13);
            tabPage4.Controls.Add(textBox10);
            tabPage4.Controls.Add(comboBox5);
            tabPage4.Controls.Add(button8);
            tabPage4.Controls.Add(textBox11);
            tabPage4.Controls.Add(label14);
            tabPage4.Controls.Add(label15);
            tabPage4.Controls.Add(label16);
            tabPage4.Controls.Add(button10);
            tabPage4.Location = new Point(8, 46);
            tabPage4.Name = "tabPage4";
            tabPage4.Padding = new Padding(3);
            tabPage4.Size = new Size(880, 508);
            tabPage4.TabIndex = 3;
            tabPage4.Text = "Encrypt Screen";
            tabPage4.UseVisualStyleBackColor = true;
            // 
            // textBox9
            // 
            textBox9.Location = new Point(324, 246);
            textBox9.Name = "textBox9";
            textBox9.Size = new Size(245, 39);
            textBox9.TabIndex = 37;
            // 
            // label13
            // 
            label13.AutoSize = true;
            label13.Location = new Point(132, 253);
            label13.Name = "label13";
            label13.Size = new Size(105, 32);
            label13.TabIndex = 36;
            label13.Text = "Plaintext";
            // 
            // textBox10
            // 
            textBox10.Location = new Point(324, 149);
            textBox10.Name = "textBox10";
            textBox10.Size = new Size(245, 39);
            textBox10.TabIndex = 35;
            // 
            // comboBox5
            // 
            comboBox5.FormattingEnabled = true;
            comboBox5.Items.AddRange(new object[] { "DER", "Base64" });
            comboBox5.Location = new Point(324, 31);
            comboBox5.Name = "comboBox5";
            comboBox5.Size = new Size(242, 40);
            comboBox5.TabIndex = 34;
            // 
            // button8
            // 
            button8.Location = new Point(391, 431);
            button8.Name = "button8";
            button8.Size = new Size(150, 46);
            button8.TabIndex = 33;
            button8.Text = "Encrypt";
            button8.UseVisualStyleBackColor = true;
            button8.Click += button8_Click;
            // 
            // textBox11
            // 
            textBox11.Location = new Point(324, 338);
            textBox11.Name = "textBox11";
            textBox11.Size = new Size(245, 39);
            textBox11.TabIndex = 32;
            // 
            // label14
            // 
            label14.AutoSize = true;
            label14.Location = new Point(132, 345);
            label14.Name = "label14";
            label14.Size = new Size(127, 32);
            label14.TabIndex = 31;
            label14.Text = "CipherText";
            // 
            // label15
            // 
            label15.AutoSize = true;
            label15.Location = new Point(132, 156);
            label15.Name = "label15";
            label15.Size = new Size(117, 32);
            label15.TabIndex = 30;
            label15.Text = "PublicKey";
            // 
            // label16
            // 
            label16.AutoSize = true;
            label16.Location = new Point(124, 39);
            label16.Name = "label16";
            label16.Size = new Size(89, 32);
            label16.TabIndex = 29;
            label16.Text = "Format";
            // 
            // button10
            // 
            button10.Location = new Point(607, 156);
            button10.Name = "button10";
            button10.Size = new Size(150, 46);
            button10.TabIndex = 27;
            button10.Text = "Upload";
            button10.UseVisualStyleBackColor = true;
            button10.Click += button10_Click;
            // 
            // tabPage5
            // 
            tabPage5.Controls.Add(textBox12);
            tabPage5.Controls.Add(label17);
            tabPage5.Controls.Add(textBox13);
            tabPage5.Controls.Add(comboBox6);
            tabPage5.Controls.Add(button9);
            tabPage5.Controls.Add(textBox14);
            tabPage5.Controls.Add(label18);
            tabPage5.Controls.Add(label19);
            tabPage5.Controls.Add(label20);
            tabPage5.Controls.Add(button12);
            tabPage5.Location = new Point(8, 46);
            tabPage5.Name = "tabPage5";
            tabPage5.Padding = new Padding(3);
            tabPage5.Size = new Size(880, 508);
            tabPage5.TabIndex = 4;
            tabPage5.Text = "Decrypt Screen";
            tabPage5.UseVisualStyleBackColor = true;
            // 
            // textBox12
            // 
            textBox12.Location = new Point(324, 246);
            textBox12.Name = "textBox12";
            textBox12.Size = new Size(245, 39);
            textBox12.TabIndex = 48;
            // 
            // label17
            // 
            label17.AutoSize = true;
            label17.Location = new Point(132, 253);
            label17.Name = "label17";
            label17.Size = new Size(127, 32);
            label17.TabIndex = 47;
            label17.Text = "CipherText";
            // 
            // textBox13
            // 
            textBox13.Location = new Point(324, 149);
            textBox13.Name = "textBox13";
            textBox13.Size = new Size(245, 39);
            textBox13.TabIndex = 46;
            // 
            // comboBox6
            // 
            comboBox6.FormattingEnabled = true;
            comboBox6.Items.AddRange(new object[] { "DER", "Base64" });
            comboBox6.Location = new Point(324, 31);
            comboBox6.Name = "comboBox6";
            comboBox6.Size = new Size(242, 40);
            comboBox6.TabIndex = 45;
            // 
            // button9
            // 
            button9.Location = new Point(391, 431);
            button9.Name = "button9";
            button9.Size = new Size(150, 46);
            button9.TabIndex = 44;
            button9.Text = "Decrypt";
            button9.UseVisualStyleBackColor = true;
            button9.Click += button9_Click;
            // 
            // textBox14
            // 
            textBox14.Location = new Point(324, 338);
            textBox14.Name = "textBox14";
            textBox14.Size = new Size(245, 39);
            textBox14.TabIndex = 43;
            // 
            // label18
            // 
            label18.AutoSize = true;
            label18.Location = new Point(132, 345);
            label18.Name = "label18";
            label18.Size = new Size(126, 32);
            label18.TabIndex = 42;
            label18.Text = "DecrypFile";
            // 
            // label19
            // 
            label19.AutoSize = true;
            label19.Location = new Point(132, 156);
            label19.Name = "label19";
            label19.Size = new Size(125, 32);
            label19.TabIndex = 41;
            label19.Text = "PrivateKey";
            // 
            // label20
            // 
            label20.AutoSize = true;
            label20.Location = new Point(124, 39);
            label20.Name = "label20";
            label20.Size = new Size(89, 32);
            label20.TabIndex = 40;
            label20.Text = "Format";
            // 
            // button12
            // 
            button12.Location = new Point(607, 145);
            button12.Name = "button12";
            button12.Size = new Size(150, 46);
            button12.TabIndex = 38;
            button12.Text = "Upload";
            button12.UseVisualStyleBackColor = true;
            button12.Click += button12_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1344, 734);
            Controls.Add(tabControl1);
            Name = "Form1";
            Text = "Form1";
            tabControl1.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage1.PerformLayout();
            tabPage2.ResumeLayout(false);
            tabPage2.PerformLayout();
            tabPage3.ResumeLayout(false);
            tabPage3.PerformLayout();
            tabPage4.ResumeLayout(false);
            tabPage4.PerformLayout();
            tabPage5.ResumeLayout(false);
            tabPage5.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TabControl tabControl1;
        private TabPage tabPage1;
        private Label label7;
        private TextBox textBox1;
        private ComboBox comboBox2;
        private ComboBox comboBox1;
        private Button button3;
        private TextBox textBox3;
        private Label label3;
        private Label label2;
        private Label label1;
        private TabPage tabPage2;
        private Button button5;
        private Button button6;
        private TabPage tabPage3;
        private TextBox textBox5;
        private Label label4;
        private TextBox textBox2;
        private ComboBox comboBox4;
        private Button button1;
        private TextBox textBox4;
        private Label label5;
        private Label label6;
        private Label label8;
        private TextBox textBox6;
        private Label label9;
        private TextBox textBox7;
        private ComboBox comboBox3;
        private Button button2;
        private TextBox textBox8;
        private Label label10;
        private Label label11;
        private Label label12;
        private Button button4;
        private Button button7;
        private TabPage tabPage4;
        private TabPage tabPage5;
        private TextBox textBox9;
        private Label label13;
        private TextBox textBox10;
        private ComboBox comboBox5;
        private Button button8;
        private TextBox textBox11;
        private Label label14;
        private Label label15;
        private Label label16;
        private Button button10;
        private TextBox textBox12;
        private Label label17;
        private TextBox textBox13;
        private ComboBox comboBox6;
        private Button button9;
        private TextBox textBox14;
        private Label label18;
        private Label label19;
        private Label label20;
        private Button button12;
    }
}