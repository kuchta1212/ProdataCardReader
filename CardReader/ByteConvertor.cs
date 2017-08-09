using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardReader
{
    public class ByteConvertor
    {
        public static string ToIntArray(byte[] array)
        {
            var sb = new StringBuilder();
            foreach (var b in array)
            {
                sb.Append(Convert.ToInt32(b));
            }
            return sb.ToString();
        }

        public static string ToString(byte[] array)
        {
            var sb = new StringBuilder();
            foreach (var b in array)
            {
                sb.Append(Convert.ToChar(b));
            }
            return sb.ToString();
        }
    }
}
