using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.IO;



namespace InputFileGen
{

    static class Constants
    {
        public const string filePath = @"C:\Users\ethan\Desktop\InputFile.txt";
    }

    class Program
    {
        static void Main(string[] args)
        {
            
            int xDim, yDim, iterate;
            double multiplier;

            Console.WriteLine("These need to be integers");
            Console.WriteLine("What is the X Dimension of the grid?");
            int.TryParse(Console.ReadLine(), out xDim);      
          
            Console.WriteLine("What is the Y dimension of the grid?");
            int.TryParse(Console.ReadLine(), out yDim);

            Console.WriteLine("How Many Iterations do you want to run?");
            int.TryParse(Console.ReadLine(), out iterate);

            Console.WriteLine("This needs to be a decimal value");
            Console.WriteLine("What is the multiplier you want to use?");
            double.TryParse(Console.ReadLine(), out multiplier);

            double[,] Temps = new double[xDim, yDim];

            Random rng = new Random(DateTime.Now.Millisecond);

            for (int i = 0; i < xDim; i++){
                for (int j = 0; j < yDim; j++)
                {
                    double temp = GetTemperatures(rng);
                    Temps[i, j] = temp; 
                }
            }

            Console.WriteLine("Array populated");

            FileMake();

            FileWrite(Temps, xDim, yDim, iterate, multiplier);
            Console.WriteLine("Wrote things to file");

            Console.WriteLine("Press any key to quit");

            Console.ReadKey();

        }

        static void FileMake()
        {
            string path = Constants.filePath;

            try
            {
                if (File.Exists(path)){
                    Console.WriteLine("File already exists!");
                    Console.WriteLine("Deleting Old File...");
                    File.Delete(path);
                    Console.WriteLine("Making new file...");
                    File.Create(path).Close();
                    Console.WriteLine("New File Made");
                    
                    
                }
                else
                {
                    File.Create(path).Close();
                    Console.WriteLine("File Created!");
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }

        }

        static double GetTemperatures(Random rng)
        {
            double temp;
            temp = (rng.NextDouble()*14)+65;
            temp = Math.Round(temp, 2);
            Console.WriteLine(temp.ToString());

            return temp;
        }

        static void FileWrite(double[,] Temps, int xDim, int yDim, int iterations, double multiplier)
        {
            
            string path = Constants.filePath;

                File.AppendAllText(path, (xDim.ToString() + Environment.NewLine));
                File.AppendAllText(path, (yDim.ToString() + Environment.NewLine));
                File.AppendAllText(path, (iterations.ToString() + Environment.NewLine));
                File.AppendAllText(path, (multiplier.ToString() + Environment.NewLine));

            foreach (double d in Temps)
            {
                File.AppendAllText(path, (d.ToString() + Environment.NewLine));
            }
        }
    }
}
