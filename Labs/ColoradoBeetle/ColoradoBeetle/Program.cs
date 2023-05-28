﻿// Выполнил Ильдюков Дмитрий ПС-22
//
//1.2.Колорадский жук(4)
// Прямоугольный садовый участок длиной M ×N метров (1≤M, N≤5) разбит на квадраты со стороной 1 метр. На этом участке вскопана грядка картошки.
// Грядкой является связанное множество квадратов.  Иными словами, из любого квадрата этой грядки можно попасть в любой другой квадрат этой же грядки,
// последовательно переходя по грядке из квадрата в квадрат через их общую сторону.
// В некоторых квадратах грядки растут кусты картошки. Колорадский жук прилетел на один из кустов.
// Съев все листья, он переходит через общую сторону к какому-либо соседнему свежему кусту той же грядки. Жук не возвращается к тому кусту,
// на котором он уже был, и не приходит в те квадраты, где картошка не посажена. Определить наибольшее количество кустов картошки,
// которые сможет съесть колорадский жук.

// Ввод. В первой строке файла INPUT.TXT находятся числа M и N через пробел. Далее идут M строк по N символов.
// Квадраты грядки с кустами картошки обозначаются символами '#', свободные квадраты – символами '.'.
// Вывод. В единственной строке файла OUTPUT.TXT вывести одно число - наибольшее возможное количество съеденных кустов картошки.
// Пример 
// Ввод
// 3 4
// ####
// .#..
// .###
// Вывод
// 7

// Среда разработки: Visual Studio 2019

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace ColoradoBeetle
{
    class Program
    {

        static void Main(string[] args)
        {
            string path = "input.txt";
            string[] input = File.ReadAllLines(path);
            string[] numbersStr = input[0].Split(" ");

            int M = int.Parse(numbersStr[0]);
            int N = int.Parse(numbersStr[1]);

            char[][] field = new char[M][];
            for (int i = 0; i < M; i++)
                field[i] = input[i + 1].ToCharArray();

            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                    Console.Write(field[i][j]);
                Console.WriteLine();
            }

            Stack<Tuple<int, int>> toVisited = new Stack<Tuple<int, int>>();
            Stack<Tuple<int, int>> visited = new Stack<Tuple<int, int>>();
            List<int> ways = new List<int>();

            bool forBreak = false;
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (field[i][j] == '#')
                    {
                        toVisited.Push(new Tuple<int, int>(i, j));
                        forBreak = true;
                        break;
                    }
                }
                if (forBreak) break;
            }

            if (toVisited.Count == 0)
            {
                Console.WriteLine(0);
                return;
            }

            visited.Push(toVisited.Pop());
            DFSRecurse(ref toVisited, ref visited, field, ref ways, M, N);

            //ways.Sort();
            foreach (var item in ways)
            {
                Console.WriteLine(item);
            }
        }

        static void DFSRecurse(ref Stack<Tuple<int, int>> toVisited, ref Stack<Tuple<int, int>> visited, char[][] field, ref List<int> ways, int M, int N)
        {
            int counter = 1;
            int temp = 0;
            do
            {
                int counterWays = GetPossibleWays(ref toVisited, ref visited, field, visited.Peek(), M, N);
                if (counterWays == 1)
                {
                    counter++;
                    visited.Push(toVisited.Pop());
                }
                else if (counterWays > 1)
                {
                    visited.Push(toVisited.Pop());
                    counter++;
                    temp = visited.Count;
                }
                else
                {
                    ways.Add(counter);
                    counter = temp;
                    if (toVisited.Count == 0) break;
                    visited.Push(toVisited.Pop());
                }
            } while (true);
        }

        static int GetPossibleWays(ref Stack<Tuple<int, int>> toVisited, ref Stack<Tuple<int, int>> visited, char[][] field, Tuple<int, int> curPoint, int M, int N)
        {
            int counterWays = 0;

            if (curPoint.Item1 != M - 1 && field[curPoint.Item1 + 1][curPoint.Item2] == '#')
            {
                Tuple<int, int> t = new Tuple<int, int>(curPoint.Item1 + 1, curPoint.Item2);

                if (!visited.Contains(t))
                {
                    counterWays++;
                    toVisited.Push(t);
                }
            }

            if (curPoint.Item1 != 0 && field[curPoint.Item1 - 1][curPoint.Item2] == '#')
            {
                Tuple<int, int> t = new Tuple<int, int>(curPoint.Item1 - 1, curPoint.Item2);

                if (!visited.Contains(t))
                {
                    counterWays++;
                    toVisited.Push(t);
                }
            }
                
            if (curPoint.Item2 != N - 1 && field[curPoint.Item1][curPoint.Item2 + 1] == '#')
            {
                Tuple<int, int> t = new Tuple<int, int>(curPoint.Item1, curPoint.Item2 + 1);

                if (!visited.Contains(t))
                {
                    counterWays++;
                    toVisited.Push(t);
                }
            }
                
            if (curPoint.Item2 != 0 && field[curPoint.Item1][curPoint.Item2 - 1] == '#')
            {
                Tuple<int, int> t = new Tuple<int, int>(curPoint.Item1, curPoint.Item2 - 1);

                if (!visited.Contains(t))
                {
                    counterWays++;
                    toVisited.Push(t);
                }
            }

            return counterWays;
        }
    }
}