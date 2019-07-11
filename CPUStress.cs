using System;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

namespace CPUStress {
    class Program {
        static void Main(string[] args) {
            Enumerable.Range(0, 25000).ToList().ForEach(f => {
                // Generic Thread
                Thread thread = new Thread(() => {
                    Console.WriteLine($"Thread Number: {Thread.CurrentThread.ManagedThreadId} started.");
                    Thread.Sleep(1000);
                    for (int i = 0; i < Int32.MaxValue; i++) ;
                    Console.WriteLine($"Thread Number: {Thread.CurrentThread.ManagedThreadId} ended.");
                });

                thread.Start();
            });

            Console.ReadKey();
        }
    }
}
