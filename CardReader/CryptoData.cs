using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace CardReader
{
    public class CryptoData
    {
        public string XmlPublicKey { get; set; }

        public string CertData { get; set; }

        public X509Certificate2 Cert { get; set; }
    }
}
