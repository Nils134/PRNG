using System;
using System.IO;

namespace FileIOApplication {
   class Program {
      static void Main(string[] args) {
          Random random = new Random(42);
    
         while (true) {
            string input = Console.ReadLine();
            if (input != null) {
                for (int i = 0; i < 10000; i++) {
                    string temp = "";
                    for (int y = 0; y < 100; y++) {
                        temp += random.NextDouble().ToString("0.000000000000") + "\n";
                    }
                    Console.Write(temp);
                }
            }
         }
      }
   }
}