using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace LAB6_MSCV1
{
    public partial class Form1 : Form
    {
        [DllImport("ECCDSA.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "genECCKeyPair")]

        public static extern bool genECCKeyPair(string privateKeyPath, string publicKeyPath, string mode);

        [DllImport("ECCDSA.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "signPdf")]
        public static extern bool signPdf(string chrprivateKeyPath, string cpdfPath, string csignaturePath, string mode);

        [DllImport("ECCDSA.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "verifySignature")]
        public static extern bool verifySignature(string cpublicKeyPath, string cpdfPath, string csignaturePath, string mode);
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox6.Text = fileName;

        }

        private void button5_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox5.Text = fileName;

        }

        private void button4_Click(object sender, EventArgs e)
        {
            string mode = comboBox2.GetItemText(comboBox2.SelectedItem);
            string cpublicKeyPath = textBox6.Text.ToString();
            string pdfPath = textBox5.Text.ToString();
            string signFile = textBox4.Text.ToString();
            if (verifySignature(cpublicKeyPath, pdfPath, signFile, mode))
            {
                MessageBox.Show("verify successfully!");
            }
            else
            {
                MessageBox.Show("Verify failed!");
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox1.Text = fileName;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox2.Text = fileName;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string privatekey = textBox1.Text.ToString();
            string mode = comboBox3.GetItemText(comboBox3.SelectedItem);
            string pdfPath = textBox2.Text.ToString();
            string signFile = textBox3.Text.ToString();
            if (signPdf(privatekey, pdfPath, signFile, mode))
            {
                MessageBox.Show("Sign successfully!");
            }
            else
            {
                MessageBox.Show("Sign failed!");
            }
        }
        private void button7_Click(object sender, EventArgs e)
        {
            string publickey = textBox8.Text.ToString();
            string privatekey = textBox7.Text.ToString();
            string mode = comboBox1.GetItemText(comboBox1.SelectedItem);

            if (genECCKeyPair(privatekey, publickey,mode))
            {
                MessageBox.Show("Genkey successfully!");
            }
            else
            {
                MessageBox.Show("Genkey failed!");
            }
        }
        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
        }

        private void label3_Click(object sender, EventArgs e)
        {
        }

        private void label2_Click(object sender, EventArgs e)
        {
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
        }

        private void label4_Click(object sender, EventArgs e)
        {
        }

        private void label5_Click(object sender, EventArgs e)
        {
        }

        private void label6_Click(object sender, EventArgs e)
        {
        }

       
    }
}
