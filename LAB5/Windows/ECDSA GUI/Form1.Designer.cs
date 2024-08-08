namespace LAB6_MSCV1
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
            tabControl1 = new TabControl();
            tabPage1 = new TabPage();
            button3 = new Button();
            button2 = new Button();
            button1 = new Button();
            textBox3 = new TextBox();
            textBox2 = new TextBox();
            textBox1 = new TextBox();
            label3 = new Label();
            label2 = new Label();
            label1 = new Label();
            tabPage2 = new TabPage();
            button4 = new Button();
            button5 = new Button();
            button6 = new Button();
            textBox4 = new TextBox();
            textBox5 = new TextBox();
            textBox6 = new TextBox();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            tabPage3 = new TabPage();
            comboBox1 = new ComboBox();
            button7 = new Button();
            textBox7 = new TextBox();
            textBox8 = new TextBox();
            label7 = new Label();
            label8 = new Label();
            label9 = new Label();
            comboBox2 = new ComboBox();
            label10 = new Label();
            comboBox3 = new ComboBox();
            label11 = new Label();
            tabControl1.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            tabPage3.SuspendLayout();
            SuspendLayout();
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Controls.Add(tabPage3);
            tabControl1.Location = new Point(298, 77);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(896, 562);
            tabControl1.TabIndex = 0;
            tabControl1.SelectedIndexChanged += tabControl1_SelectedIndexChanged;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(comboBox3);
            tabPage1.Controls.Add(label11);
            tabPage1.Controls.Add(button3);
            tabPage1.Controls.Add(button2);
            tabPage1.Controls.Add(button1);
            tabPage1.Controls.Add(textBox3);
            tabPage1.Controls.Add(textBox2);
            tabPage1.Controls.Add(textBox1);
            tabPage1.Controls.Add(label3);
            tabPage1.Controls.Add(label2);
            tabPage1.Controls.Add(label1);
            tabPage1.Location = new Point(8, 46);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(880, 508);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "Sign";
            tabPage1.UseVisualStyleBackColor = true;
            tabPage1.Click += tabPage1_Click;
            // 
            // button3
            // 
            button3.Location = new Point(440, 421);
            button3.Name = "button3";
            button3.Size = new Size(150, 46);
            button3.TabIndex = 8;
            button3.Text = "Signature";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button2
            // 
            button2.Location = new Point(687, 229);
            button2.Name = "button2";
            button2.Size = new Size(150, 46);
            button2.TabIndex = 7;
            button2.Text = "Upload";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button1
            // 
            button1.Location = new Point(687, 133);
            button1.Name = "button1";
            button1.Size = new Size(150, 46);
            button1.TabIndex = 6;
            button1.Text = "Upload";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // textBox3
            // 
            textBox3.Location = new Point(397, 334);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(245, 39);
            textBox3.TabIndex = 5;
            textBox3.TextChanged += textBox3_TextChanged;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(394, 233);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(245, 39);
            textBox2.TabIndex = 4;
            textBox2.TextChanged += textBox2_TextChanged;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(394, 133);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(245, 39);
            textBox1.TabIndex = 3;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(166, 334);
            label3.Name = "label3";
            label3.Size = new Size(153, 32);
            label3.TabIndex = 2;
            label3.Text = "FIleSignature";
            label3.Click += label3_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(166, 240);
            label2.Name = "label2";
            label2.Size = new Size(85, 32);
            label2.TabIndex = 1;
            label2.Text = "PdfFile";
            label2.Click += label2_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(166, 133);
            label1.Name = "label1";
            label1.Size = new Size(125, 32);
            label1.TabIndex = 0;
            label1.Text = "PrivateKey";
            label1.Click += label1_Click;
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(comboBox2);
            tabPage2.Controls.Add(label10);
            tabPage2.Controls.Add(button4);
            tabPage2.Controls.Add(button5);
            tabPage2.Controls.Add(button6);
            tabPage2.Controls.Add(textBox4);
            tabPage2.Controls.Add(textBox5);
            tabPage2.Controls.Add(textBox6);
            tabPage2.Controls.Add(label4);
            tabPage2.Controls.Add(label5);
            tabPage2.Controls.Add(label6);
            tabPage2.Location = new Point(8, 46);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(880, 508);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "Verify";
            tabPage2.UseVisualStyleBackColor = true;
            tabPage2.Click += tabPage2_Click;
            // 
            // button4
            // 
            button4.Location = new Point(386, 430);
            button4.Name = "button4";
            button4.Size = new Size(150, 46);
            button4.TabIndex = 17;
            button4.Text = "Confirm";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // button5
            // 
            button5.Location = new Point(626, 256);
            button5.Name = "button5";
            button5.Size = new Size(150, 46);
            button5.TabIndex = 16;
            button5.Text = "Upload";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button6
            // 
            button6.Location = new Point(626, 170);
            button6.Name = "button6";
            button6.Size = new Size(150, 46);
            button6.TabIndex = 15;
            button6.Text = "Upload";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // textBox4
            // 
            textBox4.Location = new Point(336, 338);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(245, 39);
            textBox4.TabIndex = 14;
            textBox4.TextChanged += textBox4_TextChanged;
            // 
            // textBox5
            // 
            textBox5.Location = new Point(336, 256);
            textBox5.Name = "textBox5";
            textBox5.Size = new Size(245, 39);
            textBox5.TabIndex = 13;
            textBox5.TextChanged += textBox5_TextChanged;
            // 
            // textBox6
            // 
            textBox6.Location = new Point(336, 177);
            textBox6.Name = "textBox6";
            textBox6.Size = new Size(245, 39);
            textBox6.TabIndex = 12;
            textBox6.TextChanged += textBox6_TextChanged;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(110, 341);
            label4.Name = "label4";
            label4.Size = new Size(153, 32);
            label4.TabIndex = 11;
            label4.Text = "FIleSignature";
            label4.Click += label4_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(129, 259);
            label5.Name = "label5";
            label5.Size = new Size(85, 32);
            label5.TabIndex = 10;
            label5.Text = "PdfFile";
            label5.Click += label5_Click;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(122, 177);
            label6.Name = "label6";
            label6.Size = new Size(117, 32);
            label6.TabIndex = 9;
            label6.Text = "PublicKey";
            label6.Click += label6_Click;
            // 
            // tabPage3
            // 
            tabPage3.Controls.Add(comboBox1);
            tabPage3.Controls.Add(button7);
            tabPage3.Controls.Add(textBox7);
            tabPage3.Controls.Add(textBox8);
            tabPage3.Controls.Add(label7);
            tabPage3.Controls.Add(label8);
            tabPage3.Controls.Add(label9);
            tabPage3.Location = new Point(8, 46);
            tabPage3.Name = "tabPage3";
            tabPage3.Padding = new Padding(3);
            tabPage3.Size = new Size(880, 508);
            tabPage3.TabIndex = 2;
            tabPage3.Text = "GenKey";
            tabPage3.UseVisualStyleBackColor = true;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "DER", "PEM" });
            comboBox1.Location = new Point(336, 63);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(242, 40);
            comboBox1.TabIndex = 27;
            // 
            // button7
            // 
            button7.Location = new Point(379, 397);
            button7.Name = "button7";
            button7.Size = new Size(150, 46);
            button7.TabIndex = 26;
            button7.Text = "Genkey";
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click;
            // 
            // textBox7
            // 
            textBox7.Location = new Point(336, 310);
            textBox7.Name = "textBox7";
            textBox7.Size = new Size(245, 39);
            textBox7.TabIndex = 23;
            // 
            // textBox8
            // 
            textBox8.Location = new Point(336, 182);
            textBox8.Name = "textBox8";
            textBox8.Size = new Size(245, 39);
            textBox8.TabIndex = 22;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(137, 313);
            label7.Name = "label7";
            label7.Size = new Size(125, 32);
            label7.TabIndex = 20;
            label7.Text = "PrivateKey";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(137, 63);
            label8.Name = "label8";
            label8.Size = new Size(77, 32);
            label8.TabIndex = 19;
            label8.Text = "Mode";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(137, 182);
            label9.Name = "label9";
            label9.Size = new Size(117, 32);
            label9.TabIndex = 18;
            label9.Text = "PublicKey";
            // 
            // comboBox2
            // 
            comboBox2.FormattingEnabled = true;
            comboBox2.Items.AddRange(new object[] { "DER", "PEM" });
            comboBox2.Location = new Point(336, 76);
            comboBox2.Name = "comboBox2";
            comboBox2.Size = new Size(242, 40);
            comboBox2.TabIndex = 29;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(129, 76);
            label10.Name = "label10";
            label10.Size = new Size(77, 32);
            label10.TabIndex = 28;
            label10.Text = "Mode";
            // 
            // comboBox3
            // 
            comboBox3.FormattingEnabled = true;
            comboBox3.Items.AddRange(new object[] { "DER", "PEM" });
            comboBox3.Location = new Point(397, 35);
            comboBox3.Name = "comboBox3";
            comboBox3.Size = new Size(242, 40);
            comboBox3.TabIndex = 29;
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Location = new Point(174, 43);
            label11.Name = "label11";
            label11.Size = new Size(77, 32);
            label11.TabIndex = 28;
            label11.Text = "Mode";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            AutoSizeMode = AutoSizeMode.GrowAndShrink;
            ClientSize = new Size(1395, 723);
            Controls.Add(tabControl1);
            HelpButton = true;
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            tabControl1.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage1.PerformLayout();
            tabPage2.ResumeLayout(false);
            tabPage2.PerformLayout();
            tabPage3.ResumeLayout(false);
            tabPage3.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TabControl tabControl1;
        private TabPage tabPage1;
        private Button button3;
        private Button button2;
        private Button button1;
        private TextBox textBox3;
        private TextBox textBox2;
        private TextBox textBox1;
        private Label label3;
        private Label label2;
        private Label label1;
        private TabPage tabPage2;
        private Button button4;
        private Button button5;
        private Button button6;
        private TextBox textBox4;
        private TextBox textBox5;
        private TextBox textBox6;
        private Label label4;
        private Label label5;
        private Label label6;
        private TabPage tabPage3;
        private ComboBox comboBox1;
        private Button button7;
        private TextBox textBox7;
        private TextBox textBox8;
        private Label label7;
        private Label label8;
        private Label label9;
        private ComboBox comboBox3;
        private Label label11;
        private ComboBox comboBox2;
        private Label label10;
    }
}