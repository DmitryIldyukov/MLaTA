// Выполнил Ильдюков Дмитрий ПС-22
//
// 1.2.Колорадский жук(4)
// Прямоугольный садовый участок длиной M×N метров (1≤M, N≤5) разбит на квадраты со стороной 1 метр. На этом участке вскопана грядка картошки.
// Грядкой является связанное множество квадратов.  Иными словами, из любого квадрата этой грядки можно попасть в любой другой квадрат этой же грядки,
// последовательно переходя по грядке из квадрата в квадрат через их общую сторону.
// В некоторых квадратах грядки растут кусты картошки. Колорадский жук прилетел на один из кустов.
// Съев все листья, он переходит через общую сторону к какому-либо соседнему свежему кусту той же грядки. Жук не возвращается к тому кусту,
// на котором он уже был, и не приходит в те квадраты, где картошка не посажена. Определить наибольшее количество кустов картошки,
// которые сможет съесть колорадский жук.
//
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
//
// Среда разработки: Visual Studio 2019

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ColoradoBeetle
{
    class Program
    {
        static void Main(string[] args)
        {
            string inPath = "input.txt";
            string outPath = "output.txt";
            string[] input = File.ReadAllLines(inPath);
            string[] numbersStr = input[0].Split(" ");

            int M = int.Parse(numbersStr[0]);
            int N = int.Parse(numbersStr[1]);

            char[][] field = new char[M][];
            for (int i = 0; i < M; i++)
                field[i] = input[i + 1].ToCharArray();

            Stack<Tuple<int, int>> toVisited = new Stack<Tuple<int, int>>();
            Stack<Tuple<int, int>> visited = new Stack<Tuple<int, int>>();
            List<int> ways = new List<int>();

            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (field[i][j] == '#')
                    {
                        toVisited.Push(new Tuple<int, int>(i, j));
                        visited.Push(toVisited.Pop());
                        DFS(ref toVisited, ref visited, field, ref ways, M, N);
                        if (ways[ways.Count - 1] == M * N)
                        {
                            File.WriteAllText(outPath, ways.Max().ToString());
                            return;
                        }
                        visited.Clear();
                        toVisited.Clear();
                    }
                }
            }

            if (ways.Count == 0)
            {
                File.WriteAllText(outPath, "0");
                return;
            }
            File.WriteAllText(outPath, ways.Max().ToString());
        }

        static void DFS(ref Stack<Tuple<int, int>> toVisited, ref Stack<Tuple<int, int>> visited, char[][] field, ref List<int> ways, int M, int N)
        {
            Stack<int> crossroads = new Stack<int>();
            while (true)
            {
                int counterWays = GetPossibleWays(ref toVisited, ref visited, field, visited.Peek(), M, N);
                if (counterWays == 1)
                {
                    visited.Push(toVisited.Pop());
                }
                else if (counterWays > 1)
                {
                    for (int i = 0; i < counterWays - 1; i++)
                    {
                        crossroads.Push(visited.Count);
                    }
                    visited.Push(toVisited.Pop());
                }
                else if (counterWays == 0)
                {
                    ways.Add(visited.Count);

                    if (visited.Count == M*N)
                    {
                        break;
                    }

                    if (crossroads.Count > 0)
                    {
                        int crossroad = crossroads.Pop();
                        for (int i = visited.Count; i > crossroad; i--)
                            visited.Pop();
                    }

                    if (toVisited.Count == 0)
                        break;

                    visited.Push(toVisited.Pop());
                }
            }
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