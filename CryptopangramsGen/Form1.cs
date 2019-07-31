using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CryptopangramsGen
{
    public partial class Form1 : Form
    {
        int max = 101;

        public Form1()
        {
            InitializeComponent();
        }

        private void GenerateButton_Click(object sender, EventArgs e)
        {
            if(InputField.Text != "")
            {
                List<int> primes = GeneratePrimes();
                OutputField.Text = max + " " + (InputField.Text.Length - 1) + Environment.NewLine;
                int previousPrime = -1;
                foreach (char c in InputField.Text)
                {
                    int currentPrime = GetPrimeForChar(c, primes);
                    if (previousPrime != -1)
                        OutputField.Text += (currentPrime * previousPrime) + " ";
                    previousPrime = currentPrime;
                }
            }
        }

        private int GetPrimeForChar(char c, List<int> primes)
        {
            switch (c.ToString().ToUpper())
            {
                case "A": return primes[0];
                case "B": return primes[1];
                case "C": return primes[2];
                case "D": return primes[3];
                case "E": return primes[4];
                case "F": return primes[5];
                case "G": return primes[6];
                case "H": return primes[7];
                case "I": return primes[8];
                case "J": return primes[9];
                case "K": return primes[10];
                case "L": return primes[11];
                case "M": return primes[12];
                case "N": return primes[13];
                case "O": return primes[14];
                case "P": return primes[15];
                case "Q": return primes[16];
                case "R": return primes[17];
                case "S": return primes[18];
                case "T": return primes[19];
                case "U": return primes[20];
                case "V": return primes[21];
                case "W": return primes[22];
                case "X": return primes[23];
                case "Y": return primes[24];
                case "Z": return primes[25];
                default:
                    break;
            }
            return 0;
        }

        private List<int> GeneratePrimes()
        {
            List<int> primes = new List<int>();
            Random random = new Random();
            for (int i = 0; i < 26; i++)
            {
                int nbr = random.Next(0, max+1);
                while (!isPrime(nbr) || primes.Contains(nbr))
                    nbr = random.Next(0, max+1);
                primes.Add(nbr);
            }
            primes.Sort();
            return primes;
        }

        bool isPrime(int n)
        {
            if (n == 0 || n == 1)
                return false;

            for (int i = 2; i <= n / 2; ++i)
                if (n % i == 0)
                    return false;
            return true;
        }
    }
}
