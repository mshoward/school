using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Compiler
{
	public class SemanticAnalyzer
	{
		public Dictionary<Token, Type> SymbolTable;
		public Stack<Token> DeclarationStack;


		public SemanticAnalyzer()
		{
			SymbolTable = new Dictionary<Token, Type>();
			DeclarationStack = new Stack<Token>();
		}


	}
}
