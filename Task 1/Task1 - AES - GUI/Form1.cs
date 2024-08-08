using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task3
{
    public partial class Form1 : Form
    {
        [DllImport("AESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateAndSaveIV_Keys")]
        public static extern void GenerateAndSaveIV_Keys(int KeySize, string KeyFormat, string KeyFileName);

        [DllImport("AESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Encryption")]
        public static extern void Encryption(string mode, string KeyFile, string KeyFormat, string PlaintextFile, string PlaintextFormat, string CipherFile, string CipherFormat);


        [DllImport("AESDLL.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Decryption")]
        public static extern void Decryption(string mode, string KeyFile, string KeyFormat, string RecoveredFile, string RecoveredFormat, string CipherFile, string CipherFormat);
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


        private void button3_Click(object sender, EventArgs e)
        {
            string format = comboBox1.SelectedItem.ToString();
            int keysize = Convert.ToInt32(comboBox2.SelectedItem) / 8;
            string key = textBox1.Text;

            try
            {
                GenerateAndSaveIV_Keys(keysize, format, key);
                MessageBox.Show("Genkey successful.", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string mode = comboBox4.SelectedItem.ToString();
            string formatkey = comboBox7.SelectedItem.ToString();
            string plainformat = comboBox6.SelectedItem.ToString();
            string plain = textBox5.Text;
            string formatcipher = comboBox5.SelectedItem.ToString();
            string cipher = textBox4.Text;
            string key = textBox2.Text;
            try
            {
                Encryption(mode, key, formatkey, plain, plainformat, cipher, formatcipher);
                MessageBox.Show("Encryption successful.", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Encryption error: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            Encryption(mode, key, formatkey, plain, plainformat, cipher, formatcipher);
        }



        private void button2_Click_1(object sender, EventArgs e)
        {
            string mode = comboBox10.SelectedItem.ToString();
            string privateFormat = comboBox3.SelectedItem.ToString();
            string privatekey = textBox6.Text;
            string formatcipher = comboBox8.SelectedItem.ToString();
            string cipher = textBox3.Text;
            string descryptformat = comboBox9.SelectedItem.ToString();
            string decrypt = textBox7.Text;
            try
            {
                Decryption(mode, privatekey, privateFormat, decrypt, descryptformat, cipher, formatcipher);
                MessageBox.Show("Decryption successful.", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Decryption error: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }


        }

        private void button7_Click_1(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox6.Text = fileName;

        }

        private void button4_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.ShowDialog(this);

            string fileName = System.IO.Path.GetFileName(ofd.FileName);
            textBox3.Text = fileName;

        }

        private void label14_Click(object sender, EventArgs e)
        {

        }
    }
}
