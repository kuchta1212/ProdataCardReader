using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CardReader
{
    public class Logger
    {
        private static Logger instance;
        private static Queue<Log> logQueue;
        private static string logDir = Application.ExecutablePath;
        private static string logFile = "log";
        private static int queueSize = 1;
        private static DateTime LastFlushed = DateTime.Now;

        /// <summary>
        /// Private constructor to prevent instance creation
        /// </summary>
        private Logger() { }

        /// <summary>
        /// An LogWriter instance that exposes a single instance
        /// </summary>
        public static Logger Instance
        {
            get
            {
                // If the instance is null then create one and init the Queue
                if (instance == null)
                {
                    instance = new Logger();
                    logQueue = new Queue<Log>();
                }
                return instance;
            }
        }


        /// <summary>
        /// Destructor
        /// </summary>
        ~Logger()
        {
            FlushLog();
        }

        /// <summary>
        /// The single instance method that writes to the log file
        /// </summary>
        /// <param name="message">The message to write to the log</param>
        /// <param name="who">Sender of the message</param>>
        public void WriteToLog(string message, string sender, LogType type)
        {
            // Lock the queue while writing to prevent contention for the log file
            lock (logQueue)
            {
                // Create the entry and push to the Queue
                Log logEntry = new Log(message, sender, type);
                logQueue.Enqueue(logEntry);

                // If we have reached the Queue Size then flush the Queue
                if (logQueue.Count >= queueSize || CheckDateFlushed())
                {
                    FlushLog();
                }
            }
        }

        private bool CheckDateFlushed()
        {
            if (DateTime.Now.Day != LastFlushed.Day)
            {
                return true;
            }
            else
            {
                return false;
            }

            //TimeSpan logAge = DateTime.Now - LastFlushed;
            //if (logAge.TotalSeconds >= maxLogAge)
            //{
            //    LastFlushed = DateTime.Now;
            //    return true;
            //}
            //else
            //{
            //    return false;
            //}
        }

        /// <summary>
        /// Flushes the Queue to the physical log file
        /// </summary>
        private void FlushLog()
        {
            while (logQueue.Count > 0)
            {
                Log entry = logQueue.Dequeue();
                string logPath = logDir + "_" + entry.LogDate + "_" + logFile + ".txt";

                // This could be optimised to prevent opening and closing the file for each write
                using (FileStream fs = File.Open(logPath, FileMode.Append, FileAccess.Write))
                {
                    using (StreamWriter log = new StreamWriter(fs))
                    {
                        log.WriteLine(string.Format("{0}\t-\t{1}\t-\t{2}\t-\t{3}", entry.LogTime, entry.Sender, entry.Type.ToString(), entry.Message));
                    }
                }
            }
        }
    }

    /// <summary>
    /// A Log class to store the message and the Date and Time the log entry was created
    /// </summary>
    public class Log
    {
        public string Message { get; set; }
        public string Sender { get; set; }
        public string LogTime { get; set; }
        public string LogDate { get; set; }
        public LogType Type { get; set; }

        public Log(string message, string sender, LogType type)
        {
            Message = message;
            Sender = sender;
            Type = type;
            LogDate = DateTime.Now.ToString("yyyy-MM-dd");
            LogTime = DateTime.Now.ToString("hh:mm:ss.fff tt");
        }
    }

    public enum LogType
    {
        ERROR,
        WARNING,
        INFO
    }
}
