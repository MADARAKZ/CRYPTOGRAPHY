using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Hashes
{
    public partial class Form1 : Form
    {
        [DllImport("shas.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public static extern void hashes(IntPtr algo, IntPtr input_filename, IntPtr output_filename);

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string algo = cboFormat.SelectedItem.ToString();
            string input_filename = txtInput.Text;
            string output_filename = txtoutput.Text;

            IntPtr algoPtr = Marshal.StringToHGlobalAnsi(algo);
            IntPtr inputPtr = Marshal.StringToHGlobalAnsi(input_filename);
            IntPtr outputPtr = Marshal.StringToHGlobalAnsi(output_filename);

            hashes(algoPtr, inputPtr, outputPtr);

            Marshal.FreeHGlobal(algoPtr);
            Marshal.FreeHGlobal(inputPtr);
            Marshal.FreeHGlobal(outputPtr);

            MessageBox.Show("Hashes Successfully!");
        }

        private void txtInput_TextChanged(object sender, EventArgs e)
        {
        }

        private void txtoutput_TextChanged(object sender, EventArgs e)
        {
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}