//using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCS
{
    class Program
    {
        static void Main(string[] args)
        {
            //System.Console.WriteLine("hello");
            //System.Console.WriteLine("press any");
            //System.Console.ReadKey();
            int[,] array = new int[4, 2];
            //for (int i = 0; i < 4; i++)
            //    for (int j = 0; j < 2; j++)
            //        array[i, j] = i + j;
            int[,] numbers2D = new int[3, 2] { { 9, 99 }, { 3, 33 }, { 5, 55 } };
            // Or use the short form:
            // int[,] numbers2D = { { 9, 99 }, { 3, 33 }, { 5, 55 } };
            foreach (int i in numbers2D)
            {
                System.Console.Write("{0} ", i);
            }
        }
    }
}