using System;
using System.IO;

namespace Practice13
{
    class Program
    {
        static void Main(string[] args)
        {
            string comandLine = "";
            string path = "input.txt";

            int N;
            int[] array; 

            using (StreamReader input = new StreamReader(path))
            {
                int.TryParse(input.ReadLine(), out N);
                array = new int[N];

                string[] arrayStr = input.ReadLine().Split(" ");

                for (int i = 0; i < N; i++)
                {
                    int.TryParse(arrayStr[i], out array[i]);
                }
            }

            FenvickTree fenvick = new FenvickTree(array);
            
            while (true)
            {
                comandLine = Console.ReadLine();
                string[] comandParts = comandLine.Split(" ");

                string comand = comandParts[0];

                int num1 = 0, num2 = 0;

                if (comandParts.Length == 3)
                {
                    int.TryParse(comandParts[1], out num1);
                    int.TryParse(comandParts[2], out num2);
                }

                if (comand == "Add")
                {
                    fenvick.Add(num1, num2);
                }
                else if (comand == "Out")
                {
                    for (int i = 0; i < fenvick.FenvickArray.Length; i++)
                    {
                        Console.Write(fenvick.FenvickArray[i] + " ");
                    }
                    Console.WriteLine();
                }
                else if (comand == "Rsq")
                {
                    Console.WriteLine((fenvick.Rsq(num2) - fenvick.Rsq(num1)));
                }
                else if (comand == "Exit")
                {
                    break;
                }
            }
        }
    }
}
