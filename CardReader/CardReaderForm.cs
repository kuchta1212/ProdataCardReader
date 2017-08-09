using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using GemCard;

namespace CardReader
{
    public partial class CardReaderForm : Form
    {
        private readonly CardController _cardController;
        private readonly Logger _logger = Logger.Instance;


        public CardReaderForm()
        {
            InitializeComponent();
            this._cardController = new CardController();
        }

        private void CardReaderForm_Load(object sender, EventArgs e)
        {
            try
            {
                this.comboBox1.DataSource = this._cardController.GetReaders();
                SetStatusMessage(Properties.Resources.NotConnectStr);
                _logger.WriteToLog("Readers load", "Form", LogType.INFO);
            }
            catch (Exception ex)
            {
                SetStatusMessage("ERROR");
                this.richTextBox1.Text = ex.Message;
                _logger.WriteToLog(ex.Message, ex.StackTrace, LogType.ERROR);
            }
        }

        private void SetStatusMessage(string messge)
        {
            this.toolStripStatusLabel1.Text = messge;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                this.UseWaitCursor = true;
                SetStatusMessage(Properties.Resources.ReadingStr);
                var reader = this.comboBox1.SelectedItem.ToString();
                this._cardController.IsConnect(reader);
                SetStatusMessage(string.Format(Properties.Resources.ConnectStr, reader));
                FillTextBoxes();
                this.UseWaitCursor = false;
                _logger.WriteToLog("Card load", "Form", LogType.INFO);
            }
            catch (Exception ex)
            {
                SetStatusMessage("ERROR");
                this.richTextBox1.Text = ex.Message;
                this.UseWaitCursor = false;
                _logger.WriteToLog(ex.Message, ex.StackTrace, LogType.ERROR);
            }
        }

        private void FillTextBoxes()
        {
            this.textBox1.Text = this._cardController.ATR;
            this.textBox2.Text = this._cardController.VendorName;
            this.textBox4.Text = this._cardController.VendorSerialNum;
            var cryptoData = CryptoController.GetData();
            this.richTextBox1.Text = cryptoData.CertData;
            this.richTextBox2.Text = cryptoData.XmlPublicKey;
        }
    }
}
