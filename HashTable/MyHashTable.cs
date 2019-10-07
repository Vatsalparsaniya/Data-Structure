// My HashTable in C#

using System;
using System.Collections;
namespace Exemplo2
{
    class Program
    {
        static void Main(string[] args)
        {
            Hashtable hashtable = new Hashtable();
            hashtable.Add(100, "Santos");
            hashtable.Add(200, "Campinas");
            hashtable.Add(300, "Americana");
            hashtable.Add(400, "Lins");
            hashtable.Add(500, "Catanduva");
            // Exibe as chaves
            foreach (int key in hashtable.Keys)
            {
               Console.WriteLine("Chaves : " + key);
            }
            // Exibe os valores
            foreach (string value in hashtable.Values)
            {
               Console.WriteLine("Valores : "  + value);
            }
            Console.ReadKey();
        }
    }
}

// >>> RESULT <<< // 
//Chaves : 300
//Chaves : 200
//Chaves : 500
//Chaves : 100
//Chaves : 400
//Valores : Americana
//Valores : Campinas
//Valores : Catanduva
//Valores : Santos
//Valores : Lins

