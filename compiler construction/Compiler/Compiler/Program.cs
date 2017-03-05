using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Compiler
{
	class Program
	{
		static void Main(string[] args)
		{

			lexical_test("C:\\Users\\mason\\Documents\\school\\school\\compiler construction\\Compiler\\Compiler\\file.txt");
			syntactic_test("C:\\Users\\mason\\Documents\\school\\school\\compiler construction\\Compiler\\Compiler\\file.txt");
			Console.ReadLine();
		}

		static void lexical_test(string filepath)
		{
			StreamReader sr = File.OpenText(filepath);
			LexicalAnalyzer la = new LexicalAnalyzer(sr);
			while(!la.Finished)
			{
				Console.WriteLine("Token: " + la.CurrentToken.lexeme + " Type: " + Enum.GetName(typeof(TokenType), la.CurrentToken.tokenType));
				la.GetNextToken();
			}
			sr.Close();
			sr.Dispose();
			//Console.WriteLine("Token: " + la.NextToken.lexeme);
		}

		static void syntactic_test(string filepath)
		{
			StreamReader sr = File.OpenText(filepath);
			SyntaxAnalyzer sa = new SyntaxAnalyzer(sr);
			Console.WriteLine("SA output is: " + sa.Analyze());
			foreach(string str in sa.errorLog)
			{
				Console.WriteLine(str);
			}
			sr.Close();
			sr.Dispose();
		}
	}
}
