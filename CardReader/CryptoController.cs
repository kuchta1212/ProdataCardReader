using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security;
using System.Security.Cryptography;
using System.Security.Cryptography.X509Certificates;

namespace CardReader
{
    public class CryptoController
    {
        public static CryptoData GetData()
        {
            // Acquire public key stored in the default container of the currently inserted card
            CspParameters cspParameters = new CspParameters(1, "Microsoft Base Smart Card Crypto Provider");
            RSACryptoServiceProvider rsaProvider = new RSACryptoServiceProvider(cspParameters);
            string pubKeyXml = rsaProvider.ToXmlString(false);

            // Find the certficate in the CurrentUser\My store that matches the public key
            X509Store x509Store = new X509Store(StoreName.My, StoreLocation.CurrentUser);
            x509Store.Open(OpenFlags.ReadOnly | OpenFlags.OpenExistingOnly);
            return x509Store.Certificates.Cast<X509Certificate2>().Where(cert => (cert.PublicKey.Key.ToXmlString(false) == pubKeyXml) && cert.HasPrivateKey).Select(cert => new CryptoData()
            {
                CertData = BitConverter.ToString(cert.GetRawCertData()), XmlPublicKey = cert.PublicKey.Key.ToXmlString(false)
            }).FirstOrDefault();
        }
    }
}
