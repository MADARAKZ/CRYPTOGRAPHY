using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task3
{
    public partial class Form1 : Form
    {
        [DllImport("DllTask3.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerationAndSaveRSAKeys")]
        public static extern void GenerationAndSaveRSAKeys(int keySize, string format, string privateKeyFile, string publicKeyFile);

        [DllImport("DllTask3.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSAencrypt")]
        public static extern void RSAencrypt(string format, string publicKeyFile, string PlaintextFile, string CipherFile);

        [DllImport("DllTask3.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSADecrypt")]
        public static extern void RSADecrypt(string format, string privateKeyFile, string CipherFile, string PlaintextFile);

        [DllImport("DllTask3.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSAEncryptFromScreen")]
        public static extern void RSAEncryptFromScreen(string plain, string format, string privateKeyFile, string ciphertextFile, string PlaintextFile);

        [DllImport("DllTask3.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSADecryptFromScreen")]
        public static extern void RSADecryptFromScreen(string cipher, string format, string privateKeyFile, string ciphertextFile, string PlaintextFile);
        public Form1()
        {
            InitializeComponent();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox2.Text = fileName;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox5.Text = fileName;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox7.Text = fileName;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox6.Text = fileName;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                string format = comboBox1.SelectedItem.ToString();
                int keysize = Convert.ToInt32(comboBox2.SelectedItem);
                string pub = textBox1.Text;
                string privateKey = textBox3.Text;
                GenerationAndSaveRSAKeys(keysize, format, privateKey, pub);

                MessageBox.Show("RSA keys generated and saved successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string format = comboBox4.SelectedItem.ToString();
                string pub = textBox2.Text;
                string plain = textBox5.Text;
                string cipher = textBox4.Text;
                RSAencrypt(format, pub, plain, cipher);

                MessageBox.Show("Encryption completed successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string format = comboBox3.SelectedItem.ToString();
                string prikey = textBox7.Text;
                string ciphertext = textBox6.Text;
                string decrypt = textBox8.Text;
                RSADecrypt(format, prikey, ciphertext, decrypt);

                MessageBox.Show("Decryption completed successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {

            try
            {
                string format = comboBox6.SelectedItem.ToString();
                string prikey = textBox13.Text;
                string ciphertext = textBox12.Text;
                string decrypt = textBox14.Text;
                RSADecryptFromScreen(ciphertext, format, prikey, "test.txt", decrypt);

                MessageBox.Show("Decryption from screen completed and saved successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void button8_Click(object sender, EventArgs e)
        {

            try
            {
                string format = comboBox5.SelectedItem.ToString();
                string pub = textBox10.Text;
                string plain = textBox9.Text;
                string cipher = textBox11.Text;
                RSAEncryptFromScreen(plain, format, pub, cipher, cipher);

                MessageBox.Show("Encryption from screen completed and saved successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void button10_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox10.Text = fileName;
            
        }

        private void button12_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox13.Text = fileName;
        }
    }
}
