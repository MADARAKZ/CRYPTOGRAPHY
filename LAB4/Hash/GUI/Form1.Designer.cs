namespace Hashes
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
            this.tabGenKey = new System.Windows.Forms.TabPage();
            this.cboFormat = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txtoutput = new System.Windows.Forms.TextBox();
            this.txtInput = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btnGen = new System.Windows.Forms.Button();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabGenKey.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabGenKey
            // 
            this.tabGenKey.Controls.Add(this.cboFormat);
            this.tabGenKey.Controls.Add(this.label4);
            this.tabGenKey.Controls.Add(this.label5);
            this.tabGenKey.Controls.Add(this.txtoutput);
            this.tabGenKey.Controls.Add(this.txtInput);
            this.tabGenKey.Controls.Add(this.label2);
            this.tabGenKey.Controls.Add(this.btnGen);
            this.tabGenKey.Location = new System.Drawing.Point(8, 39);
            this.tabGenKey.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.tabGenKey.Name = "tabGenKey";
            this.tabGenKey.Padding = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.tabGenKey.Size = new System.Drawing.Size(1018, 516);
            this.tabGenKey.TabIndex = 0;
            this.tabGenKey.Text = "Hash";
            this.tabGenKey.UseVisualStyleBackColor = true;
            // 
            // cboFormat
            // 
            this.cboFormat.FormattingEnabled = true;
            this.cboFormat.Items.AddRange(new object[] {
            "SHA224",
            "SHA256",
            "SHA384",
            "SHA512",
            "SHA3-224",
            "SHA3-256",
            "SHA3-384",
            "SHA3-512",
            "SHAKE128",
            "SHAKE256"});
            this.cboFormat.Location = new System.Drawing.Point(356, 148);
            this.cboFormat.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.cboFormat.Name = "cboFormat";
            this.cboFormat.Size = new System.Drawing.Size(412, 33);
            this.cboFormat.TabIndex = 10;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(92, 235);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(162, 25);
            this.label4.TabIndex = 9;
            this.label4.Text = "Input_FileName";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(100, 340);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(181, 25);
            this.label5.TabIndex = 8;
            this.label5.Text = "OutPut_FileName";
            // 
            // txtoutput
            // 
            this.txtoutput.Location = new System.Drawing.Point(356, 335);
            this.txtoutput.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.txtoutput.Name = "txtoutput";
            this.txtoutput.Size = new System.Drawing.Size(412, 31);
            this.txtoutput.TabIndex = 7;
            this.txtoutput.TextChanged += new System.EventHandler(this.txtoutput_TextChanged);
            // 
            // txtInput
            // 
            this.txtInput.Location = new System.Drawing.Point(356, 229);
            this.txtInput.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.txtInput.Name = "txtInput";
            this.txtInput.Size = new System.Drawing.Size(412, 31);
            this.txtInput.TabIndex = 6;
            this.txtInput.TextChanged += new System.EventHandler(this.txtInput_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(92, 148);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(102, 25);
            this.label2.TabIndex = 4;
            this.label2.Text = "Algorithm";
            // 
            // btnGen
            // 
            this.btnGen.Location = new System.Drawing.Point(922, 163);
            this.btnGen.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.btnGen.Name = "btnGen";
            this.btnGen.Size = new System.Drawing.Size(112, 37);
            this.btnGen.TabIndex = 3;
            this.btnGen.Text = "Generate";
            this.btnGen.UseVisualStyleBackColor = true;
            this.btnGen.Click += new System.EventHandler(this.button1_Click);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabGenKey);
            this.tabControl1.Location = new System.Drawing.Point(104, 38);
            this.tabControl1.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1034, 563);
            this.tabControl1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1440, 704);
            this.Controls.Add(this.tabControl1);
            this.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tabGenKey.ResumeLayout(false);
            this.tabGenKey.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabPage tabGenKey;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.ComboBox cboFormat;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtoutput;
        private System.Windows.Forms.TextBox txtInput;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnGen;
    }
}

