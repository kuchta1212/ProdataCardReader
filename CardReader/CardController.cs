using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using GemCard;

namespace CardReader
{
    public class CardController : IDisposable
    {
        private CardNative cardNative;
        private SHARE share = SHARE.Shared;
        private PROTOCOL protocol = PROTOCOL.T0orT1;
        private DISCONNECT disconnect = DISCONNECT.Unpower;

        public CardController()
        {
            this.cardNative = new CardNative();
        }

        public List<string> GetReaders()
        {
            return this.cardNative.ListReaders().ToList();
        }

        public bool IsConnect(string reader)
        {
            try
            {
                this.cardNative.Connect(reader, share, protocol);
            }
            catch (Exception)
            {
                return false;
            }
            return true;
        }


        public string ATR => BitConverter.ToString(this.cardNative.GetAttribute(SCARD_ATTR_VALUE.ATR_STRING));
        
        public string VendorSerialNum => ByteConvertor.ToIntArray(this.cardNative.GetAttribute(65795));
        
        public string VendorName => ByteConvertor.ToString(this.cardNative.GetAttribute(65792));

        public string Protocol => ByteConvertor.ToString(this.cardNative.GetAttribute(SCARD_ATTR_VALUE.CURRENT_PROTOCOL_TYPE));
      
        public string TypePerATR => ByteConvertor.ToString(this.cardNative.GetAttribute(SCARD_ATTR_VALUE.ICC_TYPE_PER_ATR));
      

        public void Dispose()
        {
            this.Disconnect();
        }

        public bool Disconnect()
        {
            try
            {
                this.cardNative.Disconnect(disconnect);
            }
            catch (Exception)
            {
                return false;
            }
            return true;
        }
    }
}
