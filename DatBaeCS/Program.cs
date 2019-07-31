using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatBaeCS
{
    public class Program
    {
        static void Main(string[] args)
        {
            int testCases = Int32.Parse(Console.ReadLine());

            for(int i = 0; i < testCases; i++)
            {
                string[] parameters = Console.ReadLine().Split(' ');
                int workerCount = Int32.Parse(parameters[0]);
                int brokenCount = Int32.Parse(parameters[1]);
                int sendCount = Int32.Parse(parameters[2]);
                Monitor monitor = new Monitor(workerCount, brokenCount, sendCount);

                int sentQueries = 0;
                while(!monitor.FoundAllBroken() && sentQueries < sendCount)
                {
                    monitor.SendQuery();
                }

            }

        }
    }

    /*******************************************/
    /*******************************************/
    public class Monitor
    {
        private int workerCount;
        private int brokenCount;
        private int workingCount;
        private int sendCount;
        // 0 - unknown, 1 - not working, 2 - working
        private int[] workerStatus;
        private int half;
        private List<Query> queries;

        /*******************************************/
        public Monitor(int workerCount, int brokenCount, int sendCount)
        {
            this.workerCount = workerCount;
            this.brokenCount = brokenCount;
            this.sendCount = sendCount;
            this.workingCount = workerCount - brokenCount;
            this.half = workerCount / 2;
            this.queries = new List<Query>();
            workerStatus = new int[workerCount];
        }

        /*******************************************/
        public void AnalyzeData()
        {
            foreach(Query q in queries)
            {
                
            }
        }
        
        /*******************************************/
        public void SendQuery()
        {
            bool sendOnes = true;
            string query = "";
            for(int i = 0; i < workerCount; ++i)
            {
                if(i % half == 0)
                {
                    if (sendOnes)
                        sendOnes = false;
                    else
                        sendOnes = true;
                }
                if (sendOnes)
                    query += '1';
                else
                    query += '0';
            }
            half = half / 2;
            Console.WriteLine(query);
            queries.Add(new Query(query, Console.ReadLine()));
        }

        /*******************************************/
        public bool FoundAllBroken()
        {
            int foundBroken = 0;
            int foundWorking = 0;
            for(int i = 0; i < workerStatus.Length; i++)
            {
                if (workerStatus[i] == 1) {
                    foundBroken++;
                    if (foundBroken == brokenCount)
                        return true;
                }
                if (workerStatus[i] == 2)
                {
                    foundWorking++;
                    if (foundWorking == workingCount)
                        return true;
                }
            }
            return false;
        }

    }


    /*******************************************/
    /*******************************************/
    public class Query
    {
        public string query { get; set; }
        public string response { get; set; }

        public Query(string query, string response)
        {
            this.query = query;
            this.response = response;
        }

        public void Compare()
        {

        }
    }

}
