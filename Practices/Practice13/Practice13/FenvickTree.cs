using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice13
{
    class FenvickTree
    {
        public FenvickTree(int[] array)
        {
            Initialization(array);
        }

        private void Initialization(int[] array)
        {
            FenvickArray = new int[array.Length];

            for (int i = 0; i < FenvickArray.Length; i++)
            {
                Add(i, array[i]);
            }
        }

        public void Add(int k, int d)
        {
            while(k < FenvickArray.Length)
            {
                FenvickArray[k] += d;
                k = k | (k + 1);
            }
        }

        public int Rsq(int k)
        {
            int res = 0;

            while (k >= 0)
            {
                res += FenvickArray[k];
                k = (k & (k + 1)) - 1;
            }

            return res;
        }

        public int[] FenvickArray { get; set; }
        public int[] StartArray { get; set; }
    }
}
